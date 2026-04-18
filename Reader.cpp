#include <iostream>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char* name = "/my_shared_mem";
    const int SIZE = 4096;

    int fd = shm_open(name, O_RDONLY, 0666);

    void* ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0);

    std::cout << "Read: " << (char*)ptr << "\n";

    close(fd);
}