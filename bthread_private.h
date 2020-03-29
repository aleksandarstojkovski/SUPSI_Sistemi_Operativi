//
// Created by alesto on 3/29/2020.
//
#include <setjmp.h>
#include <stdio.h>
#include "bthread.h"
#ifndef SISTEMI_OPERATIVI_BTHREAD_PRIVATE_H
#define SISTEMI_OPERATIVI_BTHREAD_PRIVATE_H

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

#endif //SISTEMI_OPERATIVI_BTHREAD_PRIVATE_H
