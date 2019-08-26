#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define NMax 101

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int current_line = 0;

void *add_line(void *context);

int a[NMax][NMax], b[NMax][NMax], c[NMax][NMax], n;

int main()
{
        // Reading the size of the matrices
        printf("Input the size of the 2 square matrices.\n");
        scanf("%d", &n);

        int i, j;

        // Reading the first matrix
        printf("Input the first matrix.\n");
        for (i = 1 ; i <= n ; ++i)
                for (j = 1 ; j <= n ; ++j)
                        scanf("%d", &a[i][j]);

        // Reading the second matrix
        printf("Input the second matrix.\n");
        for (i = 1 ; i <= n ; ++i)
                for (j = 1 ; j <= n ; ++j)
                        scanf("%d", &b[i][j]);

        // Allocating memory
        pthread_t *th;
        th = (pthread_t *)malloc(n * sizeof(pthread_t));

        for (i = 0 ; i < n ; ++i)
        {
                pthread_create(&th[i], NULL, add_line, NULL);
        }

        for (i = 0 ; i < n ; ++i)
        {
                pthread_join(th[i], NULL);
        }

        // Printing the result to the screen
        printf("The resulting matrix is: \n");
        for (i = 1 ; i <= n ; ++i)
        {
                for (int j = 1 ; j <= n ; ++j)
                        printf("%d ", c[i][j]);
                printf("\n");
        }

        // Cleanup
        free(th);

        return 0;
}

void *add_line(void *context)
{
        // Because each thread is responsible for adding the lines having the index (++current_line),
        // The mutex will only be locked while incrementing the global variable
        int i, j;
        pthread_mutex_lock(&mutex);
        if (current_line < n)
        {
                i = ++current_line;
        }
        else
        {
                return NULL;
        }
        pthread_mutex_unlock(&mutex);

        // Adding the two lines

        for (j = 1 ; j <= n ; ++j)
        {
                c[i][j] = a[i][j] + b[i][j];
        }
        return NULL;
}
