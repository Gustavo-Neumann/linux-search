#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int file = open(argv[2], O_RDONLY);

    char buffer[128];
    int bytes;

    char *search = argv[1];
    char line[64];
    int lineIndex = 0;

    while ((bytes = read(file, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes] = '\0';

        for (int i = 0; i < bytes; i++) {
            line[lineIndex++] = buffer[i];

            if (buffer[i] == '\n' || lineIndex >= sizeof(line) - 1) {
                line[lineIndex] = '\0';

                if (strstr(line, search) != NULL) {
                    printf("\n\nencontrado: %s \n\n", line);
                }

                lineIndex = 0;
            }
        }
        printf("%s", buffer);
    }

    close(file);
    return 0;
}

