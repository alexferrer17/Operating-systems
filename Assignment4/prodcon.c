/******************************************************************************

This programme uses a multithreaded proccess in which a "producer"
thread writes into a share memory and a "consumer" thread reads the
shared memory as many times as the user input.

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
pthread_mutex_t work_mutex;


#DEFINE WORK_SIZE 1024
char work_area[WORK_SIZE];
int time_to_exit = 0;

int main() {
  int res;
  pthread_t a_thread;
  void *thread_result;
  res = pthread_mutex_init(&work_mutex, NULL);
  if (res != 0) {
      perror("Mutex initialization failed");
      exit(EXIT_FAILURE);
  }
  res = pthread_create(&a_thread, NULL, thread_function, NULL);
  if (res != 0) {
      perror("Thread creation failed");
      exit(EXIT_FAILURE);
  }
  pthread_mutex_lock(&work_mutex);
  printf("Input some text. Enter 'end' to finish\n");
  while(!time_to_exit) {
      fgets(work_area, WORK_SIZE, stdin);
      pthread_mutex_unlock(&work_mutex);
      while(1) {
          pthread_mutex_lock(&work_mutex);
          if (work_area[0] != '\0') {
              pthread_mutex_unlock(&work_mutex);
              sleep(1);
          }
          else {
              break;
          }
      }
    }
    pthread_mutex_unlock(&work_mutex);
    printf("\nWaiting for thread to finish...\n");
    res = pthread_join(a_thread, &thread_result);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    printf("Thread joined\n");
    pthread_mutex_destroy(&work_mutex);
    exit(EXIT_SUCCESS);
}


void *thread_function(void *arg) {
    sleep(1);
    pthread_mutex_lock(&work_mutex);
    while(strncmp("end", work_area, 3) != 0) {
        printf("You input %d characters\n", strlen(work_area) -1);
        work_area[0] = '\0';
        pthread_mutex_unlock(&work_mutex);
        sleep(1);
        pthread_mutex_lock(&work_mutex);
        while (work_area[0] == '\0' ) {
            pthread_mutex_unlock(&work_mutex);
            sleep(1);
            pthread_mutex_lock(&work_mutex);
        }
    }
    time_to_exit = 1;
    work_area[0] = '\0';
    pthread_mutex_unlock(&work_mutex);
    pthread_exit(0);
}
