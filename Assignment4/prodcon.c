sem_t
/******************************************************************************
This programme uses a multithreaded proccess in which a "producer"
thread writes into a share memory and a "consumer" thread reads the
shared memory as many times as the user input.

This assignment was done by Ethan Kennedy and Alejandro Ferrer
*******************************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//./prodcon <memsize> <ntimes>
//memzise determines the size and number of blocls of shared memory in the region
//ntimes  indicaes the number of times the producer wirtes to and the consumer reads from the shared memory region
sem_t mutex = 1;
sem_t empty = n;
sem_t full = 0;
int memsize;
int ntimes;
//MAIN
int main(int argc, char *argv[])
{
  // 3 comand line arguments as input
  //initalize the mutex sem_t
  //initalize the counting semaphore
  sem_t empty = n;

  void *producer(void *param);
  void *consumer(void *param);



/* comand line input  here
  memsize =
  ntimes =
*/

  int *sharedMem[memsize]; // shared memory

  //int ntimes = ;//command line input
  //initalize the semaphores
  int res = sem_init(&full, 0, 0);
    if (res < 0)
    {
        perror("Semaphore initialization failed");
        exit(0);
    }
    if (sem_init(&empty, 0, 1)) /* initially unlocked */
    {
        perror("Semaphore initialization failed");
        exit(0);
    }

  //create producer thread
  //creat consumer thread

  //wait for both threads to finish
  for(int i = 0; i < ntimes; i++)
  {
    //call PRODUCER
    //call consumer

  }
}

// PRODUCER thread
void *producer(void *param)
{
  wait(empty);
  wait(mutex);

  int checksum = 0;
  srand(time(0));
  for(int j = 0; j < memsize - 1; j++)  //create 30 bytes of random data (0-255)
  {
    sharedMem[j] = rand();
  }
  for(int k = 0; k < memsize - 1; k++)
  {
    checksum += sharedMem[k];
  }
  sharedMen[memsize-1] = checksum; // store the checksum in the last 2 bytes of the shared memoy block

  signal(mutex);
  signal(full);
  pthread_exit(0);
  //repeat ntimes synchronizing with the consumer
}



//CONSUMER thread
void *consumer(void *param)
{
  wait(full);
  wait(mutex);
  int checksum = 0;
  //read the shared memory buffer of 30 bytes
  //calculate the checksum based on the 30 bytes
  //compare it to the value in the shared memory buffer to check if data is corrupted
  for(int j = 0; j < memsize - 1; j++)  //create 30 bytes of random data (0-255)
  {
    checksum += sharedMem[j];
  }
  if(checksum != sharedMem[memsize])
  {
    perror("Data is corrupted");
    exit(EXIT_FAILURE);
  }

  signal(mutex);
  signal(empty);
  pthread_exit(0);
  //repeat ntimes synchronizing with the producer
}
