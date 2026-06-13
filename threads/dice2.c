
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>



void* routine(void *args) {
    (void)args;
    int random = (rand() % 6) +1;
    int* res = malloc(sizeof(int));
    *res = random;

    return res;
}

int main(void) {

    srand(time(NULL));
    pthread_t th[100];
    
    int rest[100];
    int i = 0;

    for ( i = 0; i < 100; i++ ) {
        pthread_create(&(th[i]), NULL, routine, NULL);
        printf("t start %d\n", i);
    }

    for ( i = 0; i < 100; i++ ) {
        void *p;
        pthread_join(th[i], &p );
        rest[i] = *(int*)p;
        free(p);
        printf("t end %d dice = %d\n", i, rest[i]);
    }

    int sum = 0;
    for ( i = 0; i < 100; i++ ) {
        sum += rest[i];
    }
    printf("res = %d\n", sum);




    return 0;
}
