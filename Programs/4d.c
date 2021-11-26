// Before terminating, the Parent waits for the Child to finish its task

#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;
    pid = fork();

    if (pid< 0){
        printf( "Fork Failed");
        return 1;
    }
    else if (pid == 0){
        printf("Hello, I am Child\n");
    }
    else{
        wait(NULL);
        printf("Hello, I am Parent\n");
    }
    
return 0;
}