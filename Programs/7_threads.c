// Write programs to understand working of Pthread library.
// gcc 7_threads.c -o 7_threads -lpthread

#include<pthread.h>
#include<stdio.h>


// #include<pthread.h>
// #include <stdio.h>

int sum,fact;
void *runner(void *param);

int main(int argc, char *argv[]){
    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner,argv[1]);
    pthread_join(tid, NULL);
    
    //printf("Sum = %d\n",sum);
    printf("Factorial = %d\n",fact);
}

// void *runner(void *param)
// {
//     int i , upper = 100;
//     sum = 0;
//     for ( i = 1; i <= upper; i++)
//         sum +=i;

//     pthread_exit(0);
// }

void *runner(void *param)
{
    int i , upper = 10;
    fact = 1;
    for ( i = 1; i <= upper; i++)
        fact *=i;

    pthread_exit(0);
}