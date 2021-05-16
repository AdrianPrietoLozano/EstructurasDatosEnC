#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"


void printList(LinkedList* list);
int randNum();


int main() {
    LinkedList* list = createLinkedList();
    int const SIZE = 20;
    srand(time(NULL));

    puts("INSERTING...");
    for (int i = 0; i < SIZE; i++) {
    	if (i % 2 == 0)
    		addAtHead(list, randNum());
    	else
    		addAtTail(list, randNum());

    	printList(list);
    }

    addAtIndex(list, 10, 200);
    printList(list);
    addAtIndex(list, 1, 99);
    printList(list);
    addAtIndex(list, 14, 66);
    printList(list);

    printf("\nsize: %d\n", list->size);
    printf("head: %d\n", getAtIndex(list, 0));
    printf("tail: %d\n", getAtIndex(list, list->size - 1));

    puts("\n---------------------------------------------------------\n");

    puts("DELETING...");
    int list_size = list->size;
    for (int i = 0; i < list_size; i++) {
    	deleteAtIndex(list, 0);
    	printList(list);
    }


    printf("\nsize: %d\n", list->size);
    printf("head: %d\n", getAtIndex(list, 0));
    printf("tail: %d\n", getAtIndex(list, list->size - 1));


    freeList(list);
    return 0;
}


void printList(LinkedList* list) {
    ListNode* temp = list->head->next;

    while (temp != NULL) {
        printf("%d", temp->val);
        temp = temp->next;

        if (temp != NULL)
        	printf(" -> ");
    }

    printf("\n");
}

int randNum() {
	return (0 + ( rand() % 1000 ));
}