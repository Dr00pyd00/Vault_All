
// creer 10 threads, chaqun prenant un element du tableau et le print

#include <stdio.h>
#include <pthread.h>


int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19 ,23, 29 };

void *routine(void *args) {
    
    printf("t print the num %d\n", *(int *)args);

    return NULL;
}








int main(void) {
    
    pthread_t th[10];
    int i;


    for ( i = 0; i < 10; i++ ) {
        pthread_create(&(th[i]), NULL, &routine, &(primes[i]));
        printf("t %d started\n", i);
    }

    for ( i = 0; i < 10; i++ ) {
        pthread_join(th[i], NULL);

    }



    return 0;
}
