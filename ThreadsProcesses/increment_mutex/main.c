#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void *increment(void *a);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int global_number = 0;

int main()
{
        // Allocating memory
        pthread_t *th;
        th = (pthread_t *)malloc(1000 * sizeof(pthread_t));
        // Creating 1000 threads
        int i;
        for (i = 0 ; i < 1000 ; ++i)
        {
                pthread_create(&th[i], NULL, increment, NULL);
        }
        // Waiting for threads
        for (i = 0 ; i < 1000 ; ++i)
        {
                pthread_join(th[i], NULL);
        }

        // Cleanup
        free(th);

        printf("Variable is %d\n", global_number);
        return 0;
}

void *increment(void *a)
{
        // Preventing the 'loss of information' by locking mutex
        pthread_mutex_lock(&mutex);
        int i;
        for (i = 0 ; i < 1000 ; ++i)
                ++global_number;
        // Unlocking mutex when it's done incrementing the variable
        pthread_mutex_unlock(&mutex);
        return NULL;
}
