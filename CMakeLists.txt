cmake_minimum_required(VERSION 3.10)
project(sistemi_operativi C)

set(CMAKE_C_STANDARD 99)

add_executable(sistemi_operativi main.c bthread_private.h bthread.h tqueue.c tqueue.h tqueue_test.c tqueue_test.h)