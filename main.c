#include <stdio.h>
#include "bthread.h"
#include "bthread_private.h"
#include "tqueue.h"
#include "tqueue_test.h"

int main() {
    test_tqueue_size();
    test_tqueue_push_pop();
    test_tqueue_get_data();
    test_tqueue_offset_at();
}
