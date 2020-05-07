//
// Created by alesto on 3/29/2020.
//

#ifndef SISTEMI_OPERATIVI_TQUEUE_H
#define SISTEMI_OPERATIVI_TQUEUE_H

struct TQueueNode;

typedef struct TQueueNode* TQueue;

/* Adds a new element at the end of the list, returns its position */
unsigned long int tqueue_enqueue(TQueue* q, void* data);

/* Removes and returns the element at the beginning of the list, NULL if the
eue is empty */
void* tqueue_pop(TQueue* q);

/* Returns the number of elements in the list */
unsigned long int tqueue_size(TQueue q);

/* Returns a 'view' on the list starting at (a positive) offset distance,
* NULL if the queue is empty */
TQueue tqueue_at_offset(TQueue q, unsigned long int offset);

/* Returns the data on the first node of the given list */
void* tqueue_get_data(TQueue q);

#endif //SISTEMI_OPERATIVI_TQUEUE_H
