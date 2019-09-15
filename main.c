#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
//char *getcwd(char *buf, size_t size);

int main(int argc, char *argv[]) {
    char buff[16];
    int read_counter = read(0, buff, 14);
    printf("%d\n", read_counter);
    for (int i = 0; i < read_counter; i++) {
        printf("%c\n", buff[i]);
    }
    return 0;
}