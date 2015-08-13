//producer.c

/* Program: Producer Parent class
   Purpose: Exercise 3
   File: producer.c
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
#include <string.h>
#include <fcntl.h>

#include "common.h"

/*
    Method I found online to append a character to end of string.
    http://ubuntuforums.org/showthread.php?t=1016188
*/
void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

/* Function: main
   Uses library: stdlib.h, stdio.h, string.h, sys/stat.h, sys/type.h, errno.h, mqueue.h, unistd.h
   Recieves: void
   Returns: int
*/

int main(void)
{
    int cur_char;
    char str_e[MAX_SIZE];
    int num_e = 0; 
    //char str_total[MAX_SIZE];
    int total_length = 0;
    
    mqd_t mq;
    
    // Open Message Queue
    mq = mq_open("/queue", O_CREAT | O_RDONLY, 0644, NULL);
    if ( (mqd_t) -1 == mq )
    {
        printf("Msg not open: %d\n ", errno);
    }
    //CHECK((mqd_t)-1 != mq);
    
  pid_t  pid;

  /* Output from both the child and the parent process
   * will be written to the standard output,
   * as they both run at the same time.
   */
  pid = fork();

  if (pid == -1)
    {
      /* Error:
       * When fork() returns -1, an error happened
       * (for example, number of processes reached the limit).
       */
      fprintf(stderr, "can't fork, error %d\n", errno);
      exit(EXIT_FAILURE);
    }
  else if (pid == 0)
    {
      /* Child process:
       * When fork() returns 0, we are in
       * the child process.
       */
	  // printf("child: %d\n", j);
	  //sleep(1);
	  char *cmd[] = {NULL, NULL, (char *)0};
	  execv("consumer", cmd); // executes consumer file
      _exit(0);  /* Note that we do not use exit() */
    }
  else
    {
      /* When fork() returns a positive number, we are in the parent process
       * (the fork return value is the PID of the newly created child process)
       * Again we count up to ten.
       */
    
    
    
        
    //for (;;)
	//{  
        printf("Hey you made it here(1)!\n"); 
        FILE *my_file;
        my_file = fopen("randStrings", "r");
        
        cur_char = fgetc(my_file);
        
        while (cur_char != EOF) {
            if ( cur_char == 101 ) {
                append(str_e, (char)cur_char);
                num_e++;
                total_length++;
            }
            else if (cur_char != 10) {
                total_length++;
            }
            //append(str_total, (char)cur_char);
            //printf("%d\n", cur_char);
            cur_char = fgetc(my_file);
        }
        printf("Hey you made it here(2)!\n"); 
        // testing to see if the string is correct
        //int i = 0;
        //for (i = 0; i < 1000; i++)
        //{
        //    printf("%c", str_e[i]);
        //}
        
        // Send message
        //CHECK(0 <= mq_send(mq, str_e, sizeof(int), 0));
        mq_send(mq, str_e, sizeof(int), 0);
        
        // Delay
        sleep(5);
        
        // Send second message
        //sent = mq_send(mq, total_length, sizeof(int), 0);
        //if (sent != 0 )
        //{
        //    printf("Message not sent: error");
        //}
        
        //sleep(5);
      printf("Hey you made it here(3)!\n");  
	  //printf("parent: %d\n", i);
	  //sleep(1);
	//}
    
    waitpid(pid, NULL, 0);
    
    /* cleanup */
    //CHECK((mqd_t)-1 != mq_close(mq));
    //mq_close(mq);
    
    // Test to see if the printed number is correct amount
    //printf("%d\n", num_e);
    //printf("%d\n", total_length);
      exit(0);
    }
  return 0;
}
