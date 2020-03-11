/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main()
{
    
    char buf[BUFFER_SIZE]; 
    int size;
    

    printf("Enter a string: "); 
    gets(buf); 
    //printf("string is: %s\n", buf); 
   
    
    char write_msg[BUFFER_SIZE];
    char read_msg[BUFFER_SIZE];
    
    int fd[2];
    pid_t pid;
    
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed");
        return 1;
    }
    
    pid = fork();
    
    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    } 
    
    if (pid > 0) {
        close(fd[READ_END]);
        
        write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
        
        close(fd[WRITE_END]);
        
    }
    else {
        close(fd[WRITE_END]);
        
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("read %s", read_msg);
        
        close(fd[READ_END]);
    }
    

    return 0;
}

