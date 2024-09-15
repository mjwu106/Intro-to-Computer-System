#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

struct dllNodec;
struct dllNodes;
struct dllListc;
struct dllLists;

typedef struct dllNodec {
  char data;
  struct dllNodec *next;
  struct dllNodec *prev;
} dllNodec;

typedef struct dllNodes {
  char *data;
  struct dllNodes *next;
  struct dllNodes *prev;
} dllNodes;

void dllDetachc(dllNodec *self);
void dllDetachs(dllNodes *self);


typedef struct dllListc {
  dllNodec *head, *tail;
} dllListc;

typedef struct dllLists {
  dllNodes *head, *tail;
} dllLists;


void dllInitc(dllListc *self);
void dllInits(dllLists *self);

dllNodec *dllFindc(const dllListc *self, const char value);
dllNodes *dllFinds(const dllLists *self, const char *value);

void dllClearc(dllListc *self);
void dllClears(dllLists *self);

char dllPopc(dllListc *self, char ifEmpty);
char *dllPops(dllLists *self, char *ifEmpty);

char dllShiftc(dllListc *self, char ifEmpty);
char *dllShifts(dllLists *self, char *ifEmpty);

void dllPushc(dllListc *self, char value);
void dllPushs(dllLists *self, char *value);

void dllEnqueuec(dllListc *self, char value);
void dllEnqueues(dllLists *self, char *value);

#endif

