/******************************************************************************

This program calculates pi by generating random numbers inside a circle of radius 1.
Depending on how many points you give him

This assignment was done by Ethan Kennedy and Alejandro Ferrer
*******************************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>


semaphore rw_mutex = 1;
semaphore mutex = 1;
int read_count = 0;

void *thread_function(void *argv);
pthread_mutex_t work_mutex; /


#DEFINE WORK_SIZE 1024
char work_area[WORK_SIZE];
int time_to_exit = 0;

int main() {

  int res;

}

void 
