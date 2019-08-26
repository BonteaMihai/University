#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void *print_index(void *a);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char **argv)
{
        // Input validation
        if (argc < 2)
        {
                printf("No argument given!\n");
                return 1;
        }
        int n;
        if (sscanf(argv[1], "%d", &n) != 1)
        {
                printf("Argument %s is not a number!\n", argv[1]);
                return 2;
        }
        pthread_t *th;
        th = (pthread_t *)malloc(n * sizeof(pthread_t));

        // Creating n threads
        int i;
        for (i = n - 1 ; i >= 0 ; --i)
        {
                // The pointer to n is sent and decremented while protected by a mutex
                // the pointer to i is unreliable to send because it can decrement
                // Faster than the thread can print it
                pthread_create(&th[i], NULL, print_index, (void *)&n);
        }

        for (i = n - 1 ; i >= 0 ; --i)
        {
                pthread_join(th[i], NULL);
        }

        // Cleanup
        free(th);

        return 0;
}

void *print_index(void *a)
{
        pthread_mutex_lock(&mutex);
        --*((int *)a);
        printf("%d ", *((int *)a));
        pthread_mutex_unlock(&mutex);
        return NULL;
}
