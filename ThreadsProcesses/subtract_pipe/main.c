#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char **argv)
{
        // Checking if an argument was given
        if (argc < 2)
        {
                printf("No number given!\n");
                return -1;
        }

        // Checking if the argument given is a number
        int n;
        if (sscanf(argv[1], "%d", &n) != 1)
        {
                printf("Argument %s is not a number!\n", argv[1]);
                return -2;
        }

        struct timeval tv;
        gettimeofday(&tv, NULL);
        // Seeds the next rand
        srand(tv.tv_usec);
        printf("Parent seed: %d\n", (int)tv.tv_usec);

        // Declaring and initializing the pipes
        int p2c[2];
        int c2p[2];
        pipe(p2c);
        pipe(c2p);

        if (fork())
        {
                // Parent
                close(c2p[1]);  // Child can no longer write
                close(p2c[0]);  // Child can no longer read
                printf("Parent starts with %d\n", n);

                for (;;)
                {
                        int d = rand() % 100;
                        n -= d;
                        if (n > 0)
                        {
                                printf("Writes: %d(rand = %d)\n", n, d);
                                write(p2c[1], &n, sizeof(n));
                                if (read(c2p[0], &n, sizeof(n)) <= 0)
                                {
                                        printf("Parent can't read, child has terminated!\n");
                                        break;
                                }
                                printf("Parent reads: %d\n", n);
                        }
                        else
                        {
                                printf("Reached %d, terminating...(rand = %d)\n", n, d);
                                break;
                        }
                }
        }
        else
        {
                // Child

                struct timeval tv;
                gettimeofday(&tv, NULL);
                srand(tv.tv_usec);
                printf("C seed: %d\n", (int)tv.tv_usec);

                close(p2c[1]);  // Parent can no longer write
                close(c2p[0]);  // Parent can no longer read

                n = 0;
                for (;;)
                {
                        if (read(p2c[0], &n, sizeof(n)) <= 0)
                        {
                                printf("Child can't read, parent has terminated!\n");
                                break;
                        }
                        printf("Child reads: %d\n", n);
                        int d = rand() % 100;
                        n -= d;
                        if (n > 0)
                        {
                                printf("Writes: %d(rand = %d)\n", n, d);
                                write(c2p[1], &n, sizeof(n));
                        }
                        else
                        {
                                printf("Reached %d, terminating...(rand = %d)\n", n, d);
                                break;
                        }
                }
        }
        return 0;
}
