//
// Created by alesto on 3/29/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "tqueue.h"

int pos;

typedef struct TQueueNode {
    struct TQueueNode* next;
    void* data;
} TQueueNode;

// TQueue = *TQueueNode
// typedef struct TQueueNode *TQueue;

TQueueNode * tail_of_queue(TQueue* q){
    pos=0;
    TQueueNode * previous = (*q);
    TQueueNode * current = (*q)->next;
    while (current != *q){
        pos++;
        current = current->next;
        previous = previous->next;
    }
    return previous;
}

unsigned long int tqueue_enqueue(TQueue* q, void* data){

        // q == **TQueueNode
        // *q == *TQueueNode

        pos = 0;

        if (q == NULL){
            return pos;
        }

        if (*q == NULL){
            // lista vuota
            *q = malloc(sizeof(TQueueNode));
            (*q)->data = data;
            (*q)->next = *q;
        } else {
            // lista non vuota
            TQueueNode * tail = tail_of_queue(q);
            TQueueNode * head = tail->next;
            tail->next = malloc(sizeof(TQueueNode));
            tail->next->data = data;
            tail->next->next = head;
            pos++;
        }
        return pos;
}

unsigned long int tqueue_size(TQueue q){

    // TQueue = *TQueueNode

    if (q == NULL){
        return 0;
    }

    int size = 1;
    TQueueNode * tail = q->next;
    while (tail != q){
        tail = tail->next;
        size++;
    }
    return size;

}

void* tqueue_pop(TQueue* q){

    if(q == NULL)
        return NULL;

    TQueueNode* head = (*q);
    void* data = NULL;
    if(head != NULL) {
        data = head->data;
        if(head == head->next) {
            // single node in queue
            *q = NULL;
        } else {
            TQueueNode *current = head;
            // search previous node
            while(current->next != head) {
                current = current->next;
            }
            // bypass head
            current->next = head->next;
            *q = current->next;
        }
        free(head);
    }
    return data;
}

/* Returns the data on the first node of the given list */
void* tqueue_get_data(TQueue q){
    if(q == NULL)
        return NULL;

    return q->data;
}

/* Returns a 'view' on the list starting at (a positive) offset distance,
* NULL if the queue is empty */
TQueue tqueue_at_offset(TQueue q, unsigned long int offset){

    // TQueue = *TQueueNode

    int i;

    if (offset>tqueue_size(q)-1){
        return NULL;
    }

    TQueueNode * head = q;

    for (i=0;i<=tqueue_size(q)-1;i++){
        if (i == offset)
            break;
        head = head->next;
    }

    return head;

}