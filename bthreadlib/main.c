#include <stdio.h>
#include "bthread.h"
#include "bthread_private.h"
#include "tqueue.h"
#include "test/tqueue_test.h"
#include "test/test_bthread.h"
#include "test/test_tqueue.h"


int main() {
    test_tqueue_size();
    test_tqueue_push_pop();
    test_tqueue_get_data();
    test_tqueue_offset_at();
    test_tqueue_one_element();
    test_tqueue_many_elements();
    test_tqueue_null();
    test_bthread_create();
}
