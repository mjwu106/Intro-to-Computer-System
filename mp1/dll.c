#include "dll.h" 
#include <string.h>  // for strlen
#include <stdlib.h> // for stral, malloc, free
#include <stdio.h> // for printf

void dllInitc(dllListc *self) {
    self->head = NULL;
    self->tail = NULL;
}


void dllInits(dllLists *self) {
    self->head = NULL;
    self->tail = NULL;
}

void dllPushs(dllLists *self, char *value) {

    dllNodes *node = malloc(sizeof(dllNodes));  

    int len = 0;
    while (value[len] != '\0') {
        len++;
    }

    // Allocate memory for the string in the node
    node->data = malloc(len + 1);  
    for (int i = 0; i < len; i++) {
        node->data[i] = value[i];
    }
    node->data[len] = '\0';  
    node->next = self->head;
    node->prev = NULL;
    if (self->head != NULL) {
        self->head->prev = node;
    }
    self->head = node;
    if (self->tail == NULL) {
        self->tail = node;
    }
}

char *dllPops(dllLists *self, char *ifEmpty) {     
    if (self->head == NULL) {
        return ifEmpty;
    }
    dllNodes *node = self->head;
    char *value = node->data;
    self->head = node->next;
    if (self->head != NULL) {
        self->head->prev = NULL;
    } else {
        self->tail = NULL;
    }
    free(node);
    return value;
}
void dllDetachs(dllNodes *self) {
    if (self->prev) self->prev->next = self->next;
    if (self->next) self->next->prev = self->prev;
    self->prev = self->next = NULL;
}

dllNodes *dllFinds(const dllLists *self, const char *value) {
    dllNodes *current = self->head;
    while (current != NULL) {
        if (strcmp(current->data, value) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}


void dllEnqueuec(dllListc *self, char value) {
    dllNodec *node = malloc(sizeof(dllNodec));  // Allocate memory
    node->data = value;  
    node->next = NULL;
    node->prev = self->tail;
    if (self->tail != NULL) {
        self->tail->next = node;
    }
    self->tail = node;
    if (self->head == NULL) {
        self->head = node;
    }
}

char dllShiftc(dllListc *self, char ifEmpty) {     
        if (self->tail == NULL) {
        return ifEmpty;
    }
    dllNodec *node = self->tail;
    char value = node->data;
    self->tail = node->prev;
    if (self->head != NULL) {
        self->head->prev = NULL;
    } else {
        self->tail = NULL;
    }
    free(node);
    return value;
    
}
    /*
    if (self->head == NULL) {
        return ifEmpty;
    }
    dllNodec *node = self->head;
    char value = node->data;
    self->head = node->next;
    if (self->head != NULL) {
        self->head->prev = NULL;
    } else {
        self->tail = NULL;
    }
    free(node);
    return value;
}*/
