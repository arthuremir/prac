#include <sys/types.h>
#include <fcntl.h>

struct Node {
    int32_t key;
    int32_t left_idx;
    int32_t right_idx;
};

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) return 1;

}