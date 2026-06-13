
#include <stdio.h>
#include <pthread.h>

int count = 0;

pthread_mutex_t mutex;


void *routine(void *args) {
    (void)args;

    for (int i = 0; i < 100000000; i++ ) {
        pthread_mutex_lock(&mutex);
        count++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}




int main(void) {
    
    int i;

    pthread_t threads[4]; 

    pthread_mutex_init(&mutex, NULL);

    for ( i = 0; i < 4; i++ ) {
        pthread_create(&(threads[i]), NULL, &routine, NULL);
        printf("thread %d started\n", i);
    }

    for ( i = 0; i < 4; i++ ) {
        pthread_join((threads[i]), NULL);
        printf("thread %d ended\n", i);
    }


    printf("total count = %d\n", count);

    pthread_mutex_destroy(&mutex);


    return 0;
}
