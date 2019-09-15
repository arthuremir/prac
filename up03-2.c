#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int
main(int argc, char *argv[]) {
    int file_descriptor = creat(argv[1], 0600);
    unsigned short number;
    while (scanf("%hu", &number) != EOF) {
        number = (number << 8) | (number >> 8);
        write(file_descriptor, &number, sizeof(number));
    }
}