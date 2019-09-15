#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
    double rem = strtof(argv[1], NULL);
    double dep_st = (strtof(argv[2], NULL) + 100) / 100;
    double cred_st = (strtof(argv[3], NULL) + 100) / 100;
    for (int i = 4; i < argc; i++) {
        rem += strtof(argv[i], NULL);
        if (rem >= 0) {
            rem *= dep_st;
        } else {
            rem *= cred_st;
        }
    }
    printf("%.10g\n", rem);
    return 0;
}