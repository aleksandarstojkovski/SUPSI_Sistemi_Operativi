//
// Created by alesto on 3/30/2020.
//

#include "bthread_private.h"
#include <stdio.h>
#include <stdlib.h>

/*
This private function creates, maintains and returns a static pointer to the singleton instance of
__bthread_scheduler_private. Fields of this structure need to be initialized as NULL.
Other functions will call this method to obtain this pointer. This function should not be accessible
outside the library.
*/

__bthread_scheduler_private* bthread_get_scheduler(){
    static __bthread_scheduler_private * scheduler = NULL;
    if (scheduler == NULL){
        scheduler = malloc(sizeof(__bthread_scheduler_private));
    }
    return scheduler;
}
