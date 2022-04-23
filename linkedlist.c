#include "linkedlist.h"
#include <malloc.h>

void initLinkedList(LinkedList* node) {
    node->next = NULL;
    node->prev = NULL;
    node->first = NULL;
    node->last = NULL;
}

LinkedList* appendNode(int value, LinkedList* node) {
    return appendNodeWithFirst(value, node, NULL);
}

LinkedList* appendNodeWithFirst(int value, LinkedList *node, LinkedList *first) {
    if (node->next) {
         node->last = appendNodeWithFirst(value, node->next, first);

         return node->last;
    } 

    if (!node->first) {
        node->first = node;
        node->prev = NULL;
        node->last = node;
        node->value = value;

        return node;
    }

    LinkedList *newNode = malloc(sizeof(LinkedList));
    node->next = newNode;

    newNode->first = first;
    newNode->next = NULL;
    newNode->prev = node;
    newNode->value = value;

    return newNode;
}

int findNthValue(int step, LinkedList* node) {
    if ((step == 0) || (!node->next)) {
        return node->value;
    }

    return findNthValue(--step, node->next);

}

void clearLinkedList(LinkedList *node) {
    if (node->next) {
        clearLinkedList(node->next);
        free(node->next);
        node->next = NULL;
        node->last = NULL;
    }

    node->prev = NULL;
    node->first = NULL;
}
