//consumer.c

/* Program: Consumer Child class
   Purpose: Exercise 3
   File: consumer.c
   Programmer: Raymond Luu
   Date: 10/22/2013
   Description: 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <mqueue.h>
#include <unistd.h>

#include "common.h"

struct bundle
{
    long mtype;
    struct msg_info {
        int num_e;
        int total_length;
    } info;
};

/* Function: main
   Uses library: stdio.h,stdlib.h,sys/msg.h, stddef.h
   Recieves: void
   Returns: int
*/

int main(void) {
    mqd_t mq;
    char str_e[MAX_SIZE];
    char str_total[MAX_SIZE];
    
    // Structure for Queue attributes
    struct mq_attr attr;
    
    /* initialize the queue attributes */
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_SIZE;
    attr.mq_curmsgs = 0;
    
    // Create message queue
    mq = mq_open(QUEUE_NAME, O_CREAT | O_RDONLY, 0644, &attr);

    
    for(;;)
    {
    printf("Hey you made it here(10)!\n"); 
    sleep(1);
    
    // Receive message
    mq_receive(mq, str_e, sizeof(int), NULL);
    
    int i = 0;
    for (i = 0; i < sizeof(int); i++)
    {
    printf("%c", str_e[i]);
    }
    
    }
    
        /* cleanup */
    //CHECK((mqd_t)-1 != mq_close(mq));
    //CHECK((mqd_t)-1 != mq_unlink(QUEUE_NAME));
    mq_close(mq);
    mq_unlink(QUEUE_NAME);
    
    //printf("%c", num_e);
    //printf("%d\n%d", b.info.num_e, b.info.total_length);
}