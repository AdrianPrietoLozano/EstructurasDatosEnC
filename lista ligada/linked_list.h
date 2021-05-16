#include <stdlib.h>
#include <stdio.h>


struct listNode {
    int val;
    struct listNode* next;   
};


struct linkedList {
    struct listNode* head;
    struct listNode* tail;
    int size;
};


typedef struct listNode ListNode;
typedef struct linkedList LinkedList;


ListNode* createNode(int val, ListNode* next) {
    ListNode* node = malloc(sizeof(ListNode));
    if (node == NULL) return NULL;
    
    node->val = val;
    node->next = next;
    
    return node;
}


LinkedList* createLinkedList() {
    LinkedList* list = malloc(sizeof(LinkedList));
    if (list == NULL)
        exit(-1);
    
    ListNode* start = createNode(-1, NULL);
    if (start == NULL)
        exit(-1);
    
    list->head = start;
    list->tail = start;
    list->size = 0;
    
    return list;
}

/** Get the value of the index-th node in the linked list.
If the index is invalid, return -1. */
int getAtIndex(LinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;
    
    ListNode* temp = obj->head;
    for (int i = 0; i < index; i++)
        temp = temp->next;
    
    return temp->next->val;
    
}

/** Add a node of value val before the first element of the linked list.
After the insertion, the new node will be the first node of the linked list. */
void addAtHead(LinkedList* obj, int val) {
    obj->head->next = createNode(val, obj->head->next);
    
    if (obj->size == 0)
        obj->tail = obj->head->next;
    
    obj->size++;
}


void addAtTail(LinkedList* obj, int val) {
    obj->tail = obj->tail->next = createNode(val, NULL);
    obj->size++;
}

/** If index equals to the length of linked list, the node will be appended to the end of linked list.
If index is greater than the length, the node will not be inserted. */
void addAtIndex(LinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size) return;
    
    if (index == obj->size) {
        addAtTail(obj, val);
        return;
    }

    ListNode* temp = obj->head;
    for (int i = 0; i < index; i++)
        temp = temp->next;
    
    temp->next = createNode(val, temp->next);
    obj->size++;
}


void deleteAtIndex(LinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;
    
    ListNode* temp = obj->head;
    for (int i = 0; i < index; i++)
        temp = temp->next;
    
    ListNode* del = temp->next;
    temp->next = temp->next->next;
    
    if (del == obj->tail)
        obj->tail = temp;
    
    free(del);
    
    obj->size--;
    
}

void freeListNodes(LinkedList* obj) {
    ListNode* temp;
    
    while (obj->head != NULL) {
        temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    }
}


void freeList(LinkedList* obj) {
    freeListNodes(obj);
    free(obj);
}


