#include <unistd.h>

enum {
    BUFF_SIZE = 4096
};

void copy_file(int in_fd, int out_fd) {
    ssize_t rel_offset, read_counter, written_counter;
    char *buff[BUFF_SIZE];
    while ((read_counter = read(in_fd, buff, sizeof(buff))) > 0) {
        rel_offset = 0;
        while (rel_offset < read_counter) {
            written_counter = write(out_fd, buff + rel_offset, read_counter - rel_offset);
            if (written_counter == -1) {
                break;
            }
            rel_offset += written_counter;
        }
    }
}