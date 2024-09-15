#!/bin/bash

make tester

if ./tester 
then    echo "SCORE: 1 / 1"
else    echo "SCORE: 0 / 1"
fi