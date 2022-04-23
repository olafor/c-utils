#include "linkedlist.h"

int main() {
    LinkedList list;
    initLinkedList(&list);
    appendNode(13, &list);
    appendNode(99, &list);
    if (findNthValue(0, &list) == 13)
        printf("Ja, för 0th!\n");
    else
        printf("(0): fail\n");

    if (findNthValue(1, &list) == 99)
        printf("Ja, för 1th!\n");
    else
        printf("(1): fail\n");

    if (findNthValue(7, &list) == 99)
        printf("Out of range as expected!\n");
    else
        printf("(out-of-range): fail\n");

    clearLinkedList(&list);

    if (!list.next && !list.prev && !list.first && !list.last) 
        printf("Linked List properly cleared\n");
}
