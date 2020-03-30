//
// Created by alesto on 3/29/2020.
//

#include <stdio.h>
#include "tqueue.h"

typedef struct {
    int number;
} myTestStruct;

void test_tqueue_size(){
    TQueue queue = NULL;
    // enqueue 5 elements
    tqueue_enqueue(&queue, NULL);
    tqueue_enqueue(&queue, NULL);
    tqueue_enqueue(&queue, NULL);
    tqueue_enqueue(&queue, NULL);
    tqueue_enqueue(&queue, NULL);
    // size must be 5
    if (tqueue_size(queue) != 5){
        printf("ERROR: test 1 of test_tqueue_size() failed.\n");
        return;
    }
    printf( "PASSED: test_tqueue_size().\n");
}

void test_tqueue_push_pop(){
    TQueue queue = NULL;
    myTestStruct mts1 = {1};
    myTestStruct mts2 = {2};
    // enqueue two items
    tqueue_enqueue(&queue, &mts1);
    tqueue_enqueue(&queue, &mts2);
    // remove one item
    tqueue_pop(&queue);
    // 2-1 -> size should be 1
    if (tqueue_size(queue) != 1){
        printf("ERROR: test 1 of test_pop() failed.\n");
        return;
    }
    // remove one item
    tqueue_pop(&queue);
    // 1 - 1 = 0 --> queue is NULL, size must be -1
    if (tqueue_size(queue) != -1){
        printf("ERROR: test 2 of test_pop() failed.\n");
        return;
    }
    // enqueue two items
    tqueue_enqueue(&queue, &mts2);
    tqueue_enqueue(&queue, &mts1);
    // get data of first item
    void * data = tqueue_pop(&queue);
    // data of first item contains number 2
    if (((myTestStruct*)data)->number != 2){
        printf("ERROR: test 3 of test_pop() failed.\n");
        return;
    }
    printf( "PASSED: test_tqueue_push_pop().\n");
}

void test_tqueue_get_data(){
    TQueue queue = NULL;
    myTestStruct mts1 = {1};
    // enqueue two items
    tqueue_enqueue(&queue, &mts1);
    if (((myTestStruct*)tqueue_get_data(queue))->number != 1){
        printf("ERROR: test 1 of test_tqueue_get_data() failed.\n");
        return;
    }
    printf( "PASSED: test_tqueue_get_data().\n");
}

void test_tqueue_offset_at(){
    TQueue queue = NULL;
    myTestStruct mts1 = {1};
    myTestStruct mts2 = {2};
    tqueue_enqueue(&queue, &mts1);
    tqueue_enqueue(&queue, &mts2);
    if (tqueue_at_offset(queue,0) != queue){
        printf("ERROR: test 1 of test_tqueue_offset_at() failed.\n");
        return;
    }
    if (((myTestStruct*)tqueue_get_data(tqueue_at_offset(queue,1)))->number != 2){
        printf("ERROR: test 2 of test_tqueue_offset_at() failed.\n");
        return;
    }
    printf( "PASSED: test_tqueue_offset_at().\n");
}