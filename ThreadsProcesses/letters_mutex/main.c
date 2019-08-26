#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int vf[26];

void *funct(void *arg)
{
        int i;
        char *word = (char *)arg;
        for (i = 0 ; i < strlen(word) ; ++i)
        {
                pthread_mutex_lock(&mutex);
                vf[word[i] - 'a']++;
                pthread_mutex_unlock(&mutex);
        }
        return NULL;
}

int main(int argc, char **argv)
{
        pthread_t *th;
        th = (pthread_t *)malloc((argc - 1) * sizeof(pthread_t));

        int i;
        for (i = 0 ; i < argc - 1 ; ++i)
        {
                pthread_create(&th[i], NULL, funct, (void *)argv[i + 1]);
        }

        for (i = 0 ; i < argc - 1 ; ++i)
        {
                pthread_join(th[i], NULL);
        }

        // Printing the letters which appear at least once
        for (i = 0 ; i < 26 ; ++i)
        {
                if (vf[i] != 0)
                {
                        printf("%c : %d \n", 'a' + i, vf[i]);
                }
        }

        // Cleanup
        free(th);

        return 0;
}
