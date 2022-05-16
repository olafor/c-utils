#include "linkedlist.h"
#include <malloc.h>

void initLinkedList(LinkedList *node) {
    node->next = NULL;
    node->prev = NULL;
    node->first = NULL;
    node->last = NULL;
}

LinkedList* appendNode(const int value, LinkedList *node) {
    return appendNodeWithFirst(value, node, node);
}

LinkedList* appendNodeWithFirst(const int value, LinkedList *node, LinkedList *first) {
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
    node->last = newNode;

    newNode->first = first;
    newNode->next = NULL;
    newNode->prev = node;
    newNode->value = value;

    return newNode;
}

LinkedList* getNode(const int value, LinkedList *node) {
    if (value != node->value) {
        if (node->next)
            return getNode(value, node->next);

        return NULL;
    }

    return node;
}

int findNthValue(int step, LinkedList *node) {
    if ((step == 0) || (!node->next))
        return node->value;

    return findNthValue(--step, node->next);

}

void setLast(LinkedList *node, LinkedList *last) {
    node->last = last;
    if (node->next)
        setLast(node->next, last);
}

int removeValue(const int value, LinkedList *node) {
    if (!(value == node->value)) {
        if (!node->next)
            return 0;

        return removeValue(value, node->next);
    }

    LinkedList *nextNode = NULL;
    LinkedList *prevNode = NULL;
    node->value = 0;

    if (node->next)
        nextNode = node->next;

    if (node->prev)
        prevNode = node->prev;

    if (!nextNode && !prevNode) {
        node->first = NULL;
        node->last = NULL;
        return value;
    }

    if (nextNode && !prevNode) {
        node->value = nextNode->value;
        node->next = nextNode->next;
        nextNode->value = 0;
        free(nextNode);
        nextNode = NULL;
        return value;
    }

    if (!nextNode && prevNode) {
        setLast(node->first, node->prev);
        prevNode->next = NULL;
    }

    if (nextNode && prevNode) {
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
    }

    free(node);
    node = NULL;

    return value;
}

int removeFirst(LinkedList *node) {
    LinkedList *nodeFirst = node->first;
    int value = nodeFirst->value;

    if (!nodeFirst->next) {
        nodeFirst->value = 0;
        nodeFirst->first = NULL;
        nodeFirst->last = NULL;
        return value;
    }

    LinkedList *nodeNext = nodeFirst->next;
    nodeFirst->value = nodeNext->value;
    nodeFirst->next = nodeNext->next;

    free(nodeNext);
    nodeNext = NULL;

    return value;
}

int removeLast(LinkedList *node) {
    LinkedList *nodeLast = node->last;
    int value = nodeLast->value;
    nodeLast->value = 0;

    if (!nodeLast->prev) {
        nodeLast->first = NULL;
        nodeLast->last = NULL;
        return value;
    }

    nodeLast->prev->next = NULL;
    setLast(nodeLast->first, nodeLast->prev);

    free(nodeLast);
    nodeLast = NULL;
    
    return value;
}

void clearLinkedList(LinkedList *node) {
    if (node->next) {
        clearLinkedList(node->next);
        free(node->next);
        node->next = NULL;
    }

    node->value = 0;
    node->prev = NULL;
    node->first = NULL;
    node->last = NULL;
}
