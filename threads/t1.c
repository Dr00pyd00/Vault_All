




#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>


void* routine(void* args) {
    int num = *(int*)args;
    int* res = malloc(sizeof(int));
    *res = num * 10;
    return res;
}

void createT(int num_to_multi, void* (*func)(void*)) {
    
    pthread_t t;
    pthread_create(&t, NULL, func, &num_to_multi);
    void *retu;
    pthread_join(t, &retu);
    int res = *(int*)retu;
    printf("res for num %d => %d\n", num_to_multi, res);
    free(retu);
}


int main() {    

    for ( int i = 0; i < 10; i++ ) {

        createT(i, &routine);

    }

       return 0;
}
