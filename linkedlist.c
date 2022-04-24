#include "linkedlist.h"
#include <malloc.h>

void initLinkedList(LinkedList *node) {
    node->next = NULL;
    node->prev = NULL;
    node->first = NULL;
    node->last = NULL;
}

LinkedList* appendNode(const int value, LinkedList *node) {
    return appendNodeWithFirst(value, node, NULL);
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
        if (node->next) {

            return getNode(value, node->next);
        }

        return NULL;
    }

    return node;
}

int updateNode(LinkedList *newNode, LinkedList *node) {
    if (newNode->value != node->value) {
        if (node->next) {
        
            return updateNode(newNode, node->next);
        }

        return 0;
    }


}

int findNthValue(int step, LinkedList *node) {
    if ((step == 0) || (!node->next)) {
        return node->value;
    }

    return findNthValue(--step, node->next);

}

int removeValue(const int value, LinkedList *node) {
    if (!(value == node->value)) {
        if (!node->next) {
            return 0;
        }
        return removeValue(value, node->next);
    }

    LinkedList *nodeToFree = NULL;
    LinkedList *nextNode = NULL;
    LinkedList *prevNode = NULL;

    if (node->next) {
        nextNode = node->next;
    }

    if (node->prev) {
        prevNode = node->prev;
    }

    if (!nextNode && !prevNode) {
        node->value = 0;
        return 0;
    }

    if (nextNode && prevNode) {
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
        nodeToFree = node;
    }

    if (nextNode && !prevNode) {
        nodeToFree = nextNode;

    }

    if (!nextNode && prevNode) {

    }

    free(nodeToFree);

    return 0;
}

int removeFirst(LinkedList *node) {
    int value = node->value;

    if (!node->next) {
        node->value = 0;
        node->first = NULL;
        node->last = NULL;
        return value;
    }

    LinkedList *newFirst = node->next;
    LinkedList *newNext = newFirst->next;

    node->next = newFirst->next;
    node->value = newFirst->value;
    newNext->prev = node;
    free(newFirst);

    return value;
}

int removeLast(LinkedList *node) {
    if (!node->next) {
        int value = node->value;
        node->value = 0;
        node->first = NULL;
        node->last = NULL;
        return value;
    }

    LinkedList *last = node->last;
    LinkedList newLast = last->prev;
    free(Last);
    last = NULL;
    
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
