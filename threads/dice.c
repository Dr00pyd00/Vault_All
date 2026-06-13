

#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>




void *routine(void *args) {
    (void)args;
    int dice = (rand() % 6) + 1;
    int *res = malloc(sizeof(int));
    *res = dice;
    
    return res;
}


int main(void) {

    srand(time(NULL));
    int i;
    pthread_t th[10];
    int resArr[10];

    for ( i = 0; i < 10; i++ ) {
        pthread_create(&(th[i]), NULL, &routine, NULL );
        printf("thread %d started\n", i);
    }

    for ( i = 0; i < 10; i++ ) {
        void *p;
        pthread_join(th[i], &p);
        resArr[i] = *(int*)p;
        free(p);
        printf("threah %d ended\n", i);
    }

    for ( i = 0; i < 10; i++ ) {
        printf("thread %d dice = %d\n", i, resArr[i] );
    }


    return 0;
}
