#include <stdio.h>
#include <unistd.h>

enum {
    BUFF_SIZE = 16,
    BASE = 10
};

int
main(void) {
    long long sum = 0;
    int num = 0;
    ssize_t read_counter = 0;
    char buff[BUFF_SIZE];
    int minus = 0;
    while ((read_counter = read(0, buff, BUFF_SIZE)) > 0) {
        for (ssize_t i = 0; i < read_counter; i++) {
            //if (buff[i] == 'g') goto lab;
            if (buff[i] == '-') {
                minus = 1;
            } else if (buff[i] >= '0' && buff[i] <= '9') {
                num = BASE * num + buff[i] - '0';
            } else if (buff[i] != '+') {
                if (minus) {
                    sum -= num;
                } else {
                    sum += num;
                }
                num = 0;
                minus = 0;
            }
        }
    }
    //lab:
    printf("%lli\n", sum);
    return 0;
}

