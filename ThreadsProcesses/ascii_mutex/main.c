#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int even_numbers = 0;
int odd_numbers = 0;
int reached_end = 0;

void *read_and_update(void *a);
pthread_mutex_t mutex;

int main(int argc, char **argv)
{
        // Checking if an argument was given
        if (argc < 2)
        {
                printf("No argument given!\n");
                return 1;
        }
        // Checking if the file name is valid
        FILE *file = fopen(argv[1], "r");
        if (file == NULL)
        {
                printf("%s is an invalid file name!\n", argv[1]);
                return 2;
        }

        // Allocating memory for 5 threads
        pthread_t *th;
        th = (pthread_t *)malloc(5 * sizeof(pthread_t));

        // Creating the 5 threads
        int i;
        for (i = 0 ; i < 5 ; ++i)
        {
                pthread_create(&th[i], NULL, read_and_update, (void *)file);
        }

        // Waiting for the 5 threads
        for (i = 0 ; i < 5 ; ++i)
        {
                pthread_join(th[i], NULL);
        }

        // Printing the results
        printf("There are %d even numbers.\n", even_numbers);
        printf("There are %d odd numbers.\n", odd_numbers);

        // Cleanup
        free(th);

        return 0;
}

void *read_and_update(void *a)
{
        int fread_result;
        char c;
        while (!reached_end)
        {
                // Locking the mutex
                pthread_mutex_lock(&mutex);

                // Reading a character
                fread_result = fread(&c, 1, 1, (FILE *)a);

                // EOF reached, let the other threads know
                if (fread_result == 0)
                {
                        reached_end = 1;
                }
                else
                {
                        // Check whether the ASCII code is even or odd
                        if (c % 2 == 0)
                        {
                                ++even_numbers;
                        }
                        else
                        {
                                ++odd_numbers;
                        }
                }

                // Unlock the mutex
                pthread_mutex_unlock(&mutex);
        }
        return NULL;
}
