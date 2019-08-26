#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
        if (argc < 2)
        {
                printf("No file name given!\n");
                return 1;
        }

        // Determining the file size
        FILE *file = fopen(argv[1], "r");
        fseek(file, 0, SEEK_END);
        int size = ftell(file);
        rewind(file);
        // Allocating enough memory to read the whole file
        char *buffer = malloc(size);
        if (buffer == NULL)
        {
                printf("Can't malloc %d bytes\n", size);
                return 2;
        }

        // Can the whole file be read?
        if (fread(buffer, 1, size, file) != size)
        {
                printf("Can't fread %d bytes\n", size);
                return 3;
        }

        // Declaring and setting up pipes

        int p2c[2];
        int c2p[2];
        pipe(p2c);
        pipe(c2p);

        if (fork())
        {
                // Parent
                // Write the buffer to the child process
                int s = 0;
                while (s < size)
                {
                        int x = write(p2c[1], (char *)((size_t)buffer + s), size - s);
                        printf("Parent wrote %d bytes\n", x);
                        s += x;
                }

                // Read from child and print on screen
                s = 0;
                while (s < size)
                {
                        int x = read(c2p[0], (char *)((size_t)buffer + s), size - s);
                        printf("Parent read %d bytes\n", x);
                        s += x;
                }

                for (s = 0 ; s < size ; ++s)
                {
                        printf("%c", buffer[s]);
                }

                // Cleanup
                free(buffer);
                fclose(file);
        }
        else
        {
                // Child
                int s = 0;
                // Malloc a new buffer for child
                char *buff = malloc(size);
                if (buff == NULL)
                {
                        printf("Child can't malloc %d bytes\n", size);
                        exit(4);
                }

                // Read the buffer from parent
                s = 0;
                while (s < size)
                {
                        int x = read(p2c[0], (char *)((size_t)buff + s), size - s);
                        printf("Child read %d bytes\n", x);
                        s += x;
                }

                // Change text to uppercase
                for (s = 0 ; s < size ; ++s)
                {
                        if ((buff[s] >= 'a') && (buff[s] <= 'z'))
                        {
                                buff[s] -= ('a' - 'A');
                        }
                }

                // Write the buffer to parent
                s = 0;
                while (s < size)
                {
                        int x = write(c2p[1], (char *)((size_t)buff + s), size - s);
                        printf("Child written %d bytes\n", x);
                        s += x;
                }

                // Cleanup
                free(buff);
        }
        return 0;
}
