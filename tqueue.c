//
// Created by alesto on 3/29/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "tqueue.h"

typedef struct TQueueNode {
    struct TQueueNode* next;
    void* data;
} TQueueNode;

// TQueue = *TQueueNode
// typedef struct TQueueNode *TQueue;

TQueueNode* tail_of_queue(TQueue* q){
    TQueueNode * tail = (*q)->next;
    while (tail != *q){
        tail = tail->next;
    }
    return tail;
}

unsigned long int tqueue_enqueue(TQueue* q, void* data){

        // q == **TQueueNode
        // *q == *TQueueNode

        if (q == NULL){
            return -1;
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
        }

}

unsigned long int tqueue_size(TQueue q){
    // TQueue = *TQueueNode
    int size = 1;
    TQueueNode * tail = q->next;
    while (tail != q){
        tail = tail->next;
        size++;
    }
    return size;
}

void* tqueue_pop(TQueue* q){

    // q == **TQueueNode, *q == *TQueueNode

    if (*q == NULL){
        return NULL;
    }

    TQueueNode * head = *q;
    *q = (*q)->next;
    free(head);
    return q;

}

/* Returns the data on the first node of the given list */
void* tqueue_get_data(TQueue q){
    return q->data;
}

/* Returns a 'view' on the list starting at (a positive) offset distance,
* NULL if the queue is empty */
TQueue tqueue_at_offset(TQueue q, unsigned long int offset){
    // TODO:
}