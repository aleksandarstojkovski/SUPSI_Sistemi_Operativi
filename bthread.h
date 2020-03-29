//
// Created by alesto on 3/29/2020.
//

#ifndef SISTEMI_OPERATIVI_BTHREAD_H
#define SISTEMI_OPERATIVI_BTHREAD_H

typedef enum { __BTHREAD_READY = 0, __BTHREAD_BLOCKED, __BTHREAD_SLEEPING,__BTHREAD_ZOMBIE} bthread_state;

typedef unsigned long int bthread_t;

typedef struct {
} bthread_attr_t;

typedef void *(*bthread_routine) (void *);

#endif //SISTEMI_OPERATIVI_BTHREAD_H
