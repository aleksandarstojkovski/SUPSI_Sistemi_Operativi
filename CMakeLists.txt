cmake_minimum_required(VERSION 3.10)
project(sistemi_operativi C)

set(CMAKE_C_STANDARD 99)

add_executable(sistemi_operativi bthreadlib/main.c bthreadlib/bthread_private.h bthreadlib/bthread.h bthreadlib/tqueue.c bthreadlib/tqueue.h bthreadlib/test/tqueue_test.c bthreadlib/test/tqueue_test.h bthreadlib/bthread.c bthreadlib/bthread_private.c bthreadlib/test/test_bthread.h bthreadlib/test/test_bthread.c bthreadlib/test/test_tqueue.c bthreadlib/test/test_tqueue.h)