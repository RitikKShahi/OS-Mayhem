#include <iostream>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

int main() {
    const char* name = "/my_shared_mem";
    const int SIZE = 4096;

    int fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, SIZE);

    void* ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, fd, 0);

    const char* message = "Hello from Process A 👀";
    strcpy((char*)ptr, message);

    std::cout << "Written to shared memory\n";

    close(fd);
}