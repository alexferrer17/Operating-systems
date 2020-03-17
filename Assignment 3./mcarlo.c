/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <pthread.h>

int sum;
void *runner(void *param);


int main(int argc, char *argv[])
{
    printf("My first threaded applitcation");
    pthread_t tid; //thread id
    pthread_attr_t attr; // set of threads attributes 
    
    if (argc != 2) {
        fprintf(stderr,"usage: a.out < integer value >\n");
        return -1;
    }
    if (atoi(argv[1] < 0)){
        fprintf(stderr, "%d must be >= 9\n", atoi(argv[1]));
        return -1;
    }
    //get the default attributes
    pthread_attr_init(&attr);
    /*creates thread*/
    pthread_create(&tid, &attr, runner, argv[1]);
    //waits for the thread to exit 
    pthread_join(tid, NULL);
    
    
    printf("sum is: %d \n", sum);
    
    return 0;
}

void *runner(void *param) {
    //arithmetic operations
    
    int i, upper = atoi(param);
    sum = 0;
    
    for( i = 1; i <= upper; i++) {
        sum += i;
    }
    
    pthread_exit(0);
}
