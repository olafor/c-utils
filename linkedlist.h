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
LinkedList* appendNode(const int, LinkedList*);
LinkedList* appendNodeWithFirst(const int, LinkedList*, LinkedList*);
LinkedList* getNode(const int, LinkedList*);

int updateNode(LinkedList*, LinkedList*);

int findNthValue(int, LinkedList*);

int removeValue(const int, LinkedList*);
int removeFirst(LinkedList*);
int removeLast(LinkedList*);

void clearLinkedList(LinkedList*);

#endif
