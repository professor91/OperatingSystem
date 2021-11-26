// gcc 5b_sender.c -o 5b_sender -lrt

#include "5a_shared_mem.h"

int main(){

    // name of the shared memory object
    const char *name = "OS";

    // strings written to shared memory
    const char *message0 = "Hello";
    const char *message1 = "World!\n";

    // shared memory file descriptor
    int shmfd;

    // pointer to shared memory obect
    void *ptr;

    // create the shared memory object
    shmfd = shm_open(name, O_CREAT | O_RDWR, 0666);

    // configure the size of the shared memory object
    ftruncate(shmfd, SIZE);

    // memory map the shared memory object
    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shmfd, 0);

    // write to the shared memory object
    sprintf(ptr, "%s", message0);
    ptr += strlen(message0);

    sprintf(ptr, "%s", message1);
    ptr += strlen(message1);

return 0;
}