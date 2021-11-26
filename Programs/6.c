// InterProcess Communication (IPC) between parent and child using pipe system call.

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void)
{
    char write_msg[BUFFER_SIZE] = "\nGreetings\n";
    char read_msg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;
    
    //create the pipe
    if(pipe(fd) == -1){
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    //fork a child process
    pid = fork();

    // error occurred
    if(pid< 0){
        fprintf(stderr, "Fork failed");
        return 1;
    }
    
    //parent process
    if(pid> 0){
        close(fd[READ_END]);                                    //close the unused end of the pipe
        write(fd[WRITE_END], write_msg, strlen(write_msg)+1);   //write to the pipe
        close(fd[WRITE_END]);                                   //close the write end of the pipe
    }
    //child process
    else{
        close(fd[WRITE_END]);                                   //close the unused end of the pipe
        read(fd[READ_END], read_msg, BUFFER_SIZE);              //read from the pipe
        printf("read %s", read_msg);
        close(fd[READ_END]);                                    //close the write end of the pipe
    }

return 0;
}