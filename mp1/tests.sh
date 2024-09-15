#!/bin/sh

score=0
banned="$(grep -v include dll.c | cpp | grep -v \# | xargs echo | grep -Eo '\S+ ?\(' | tr -d ' *!~-' | sort -u | grep -v '^dll' | grep -Ev '^([cm]alloc|free|if|while|for|sizeof|strcmp)\(')"
if [ -z "$banned" ]
then
  echo ✅ library function limitations
  score=$((score+1))
else
  echo ❌ library function limitation violated by $banned
fi

make --silent clean
make --silent dll_c

if [ -f dll_c ]
then

  echo ✅ built without warnings or errors
  score=$((score+1))
  
  if [ "$(./dll_c e)" = " e" ]
  then score=$((score+1)); echo ✅ single character argument
  else echo "❌ wrong output for single character argument"
  fi

  if [ "$(./dll_c e f)" = " e f" ]
  then score=$((score+1)); echo ✅ two single character arguments
  else echo "❌ wrong output for two character arguments"
  fi
  
  if [ "$(./dll_c one)" = " eno" ]
  then score=$((score+1)); echo ✅ single word argument
  else echo "❌ wrong output for single word argument"
  fi

  if [ "$(./dll_c one two three four five six)" = " eno owt eerht ruof evif xis" ]
  then score=$((score+1)); echo ✅ several arguments
  else echo "❌ wrong output for several arguments"
  fi
  
  if [ "$(./dll_c --help)" = "This program is a simple linked-list demo; run it with arguments." ]
  then score=$((score+1)); echo ✅ --help respected
  else echo "❌ didn't find --help as only argument"
  fi
  
  if [ "$(./dll_c one --help two)" = "This program is a simple linked-list demo; run it with arguments." ]
  then score=$((score+1)); echo ✅ --help respected even if not first
  else echo "❌ didn't find --help argument"
  fi
  
  leak0="$(valgrind --leak-check=full --show-leak-kinds=all ./dll_c 2>&1 >/dev/null | tail -1)"
  if [ "${leak0% 0 errors.*}" != "leak0" ]
  then score=$((score+1)); echo ✅ valgrind with no arguments
  else echo ❌ valgrind with no arguments
  fi

  leak6="$(valgrind --leak-check=full --show-leak-kinds=all ./dll_c Now I even I, would celebrate 2>&1 >/dev/null | tail -1)"
  if [ "${leak6% 0 errors.*}" != "leak6" ]
  then score=$((score+1)); echo ✅ valgrind with six arguments
  else echo ❌ valgrind with six arguments
  fi

  
  
else

  echo ❌ failed to build with $(grep CFLAGS Makefile)
  echo "(no further tests possible)"

fi

echo "SCORE: $score / 10"
