// Different programs

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid;
    pid = fork();
    
    if (pid < 0){
        printf("Fork Failed");
    }
    else if (pid == 0){
        execlp("/bin/ls","ls",NULL);
    }
    else{
        printf("Child Complete");
        exit(0);
    }
    
return 0;
}