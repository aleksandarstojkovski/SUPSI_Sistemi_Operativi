//
// Created by alesto on 3/29/2020.
//
#include <setjmp.h>
#include <stdio.h>
#include "bthread.h"
#include "tqueue.h"

#ifndef SISTEMI_OPERATIVI_BTHREAD_PRIVATE_H
#define SISTEMI_OPERATIVI_BTHREAD_PRIVATE_H

typedef enum {
    __BTHREAD_READY = 0,
    __BTHREAD_BLOCKED,
    __BTHREAD_SLEEPING,
    __BTHREAD_ZOMBIE
} bthread_state;

typedef struct {
    bthread_t tid;
    bthread_routine body;
    void* arg;
    bthread_state state;
    bthread_attr_t attr;
    char* stack;
    jmp_buf context;
    void* retval;
} __bthread_private;

typedef struct {
    TQueue queue;
    TQueue current_item;
    jmp_buf context;
    bthread_t current_tid;
} __bthread_scheduler_private;

__bthread_scheduler_private* bthread_get_scheduler(); // private
static int bthread_check_if_zombie(bthread_t bthread, void **retval);
static TQueue bthread_get_queue_at(bthread_t bthread);
void bthread_cleanup(); // private

#endif //SISTEMI_OPERATIVI_BTHREAD_PRIVATE_H
