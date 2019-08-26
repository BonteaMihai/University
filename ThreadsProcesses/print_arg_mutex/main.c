#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void *print(void *a);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char **argv)
{
        // Allocating memory
        pthread_t *th;
        th = (pthread_t *)malloc(argc * sizeof(pthread_t));

        int i;

        // Creating a thread for each command line argument
        for (i = 1 ; i < argc ; ++i)
        {
                pthread_create(&th[i], NULL, print, (void *)argv[i]);
        }

        // Waiting for threads
        for (i = 1 ; i < argc ; ++i)
        {
                pthread_join(th[i], NULL);
        }

        free(th);
        return 0;
}

void *print(void *a)
{
        char *aux;
        aux = (char *)a;
        // Lock the mutex before printing, so text doesn't overlap for bigger inputs
        pthread_mutex_lock(&mutex);
        int i;
        for (i = 0 ; i < strlen(aux) ; ++i)
        {
                printf("%c", aux[i]);
        }
        printf("\n");
        // Unlock the mutex once printing is done
        pthread_mutex_unlock(&mutex);
        return NULL;
}
