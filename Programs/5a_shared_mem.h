#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 
#include <fcntl.h> 
#include <sys/shm.h> 
#include <sys/mman.h> 
#include <sys/stat.h> 

// the size (in bytes) of shared memory object
#define SIZE 4096