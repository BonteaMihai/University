#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{

        // Declaring and initializing pipes
        int p2c[2];
        int c2p[2];
        pipe(p2c);
        pipe(c2p);
        int a, b, s, pid;

        pid = fork();

        if (pid == 0)
        {
                // Child
                read(p2c[0], &a, sizeof(int));
                read(p2c[0], &b, sizeof(int));
                s = a + b;

                write(c2p[1], &s, sizeof(int));

                close(p2c[0]);
                close(p2c[1]);
                close(c2p[0]);
                close(c2p[1]);
                exit(0);
        }
        a = 3;
        b = 7;
        write(p2c[1], &a, sizeof(int));
        write(p2c[1], &b, sizeof(int));

        read(c2p[0], &s, sizeof(int));
        printf("%d + %d = %d\n", a, b, s);

        close(p2c[0]);
        close(p2c[1]);
        close(c2p[0]);
        close(c2p[1]);

        wait(0);
        return 0;
}
