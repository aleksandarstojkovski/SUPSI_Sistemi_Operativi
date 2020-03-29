#include <stdio.h>
#include "bthread.h"
#include "bthread_private.h"
#include "tqueue.h"

typedef struct {
    int num;
} Number;

int main() {

    TQueue queue1 = NULL;
    TQueue queue2 = NULL;

    Number n = {1};

    tqueue_enqueue(&queue1,&n);
    tqueue_enqueue(&queue1,&n);
    tqueue_enqueue(&queue1,&n);
    tqueue_enqueue(&queue1,&n);

    tqueue_enqueue(&queue2,&n);
    tqueue_enqueue(&queue2,&n);


    printf("Queue 1 size: %ld\n",tqueue_size(queue1));
    printf("Queue 2 size: %ld\n",tqueue_size(queue2));

    queue1 = tqueue_pop(&queue1);

    printf("Queue 1 size: %ld\n",tqueue_size(queue1));

    return 0;

}
