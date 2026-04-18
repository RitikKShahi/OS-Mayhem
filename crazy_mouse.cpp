#include <ApplicationServices/ApplicationServices.h>
#include <unistd.h>
#include <cstdlib>

int main() {
    while (true) {
        int x = rand() % 1440;
        int y = rand() % 900;

        CGWarpMouseCursorPosition(CGPointMake(x, y));
        usleep(50000);
    }
}