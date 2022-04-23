#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>

// currently only for ints!
typedef struct LinkedList LinkedList;

struct LinkedList {
    int value;
    LinkedList *next;
    LinkedList *prev;
    LinkedList *first;
    LinkedList *last;
};

void initLinkedList(LinkedList*);
LinkedList* appendNode(int, LinkedList*);
LinkedList* appendNodeWithFirst(int, LinkedList*, LinkedList*);
int findNthValue(int, LinkedList*);

int removeValue(int, LinkedList*);
int removeFirst(LinkedList*);
int removeLast(LinkedList*);

void clearLinkedList(LinkedList*);

#endif
