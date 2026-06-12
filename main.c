


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>

void sigHandler( int sig ) {
    printf("\nSIGNALEMENT\n");
}


int main() {

    // sig
    struct sigaction sa;
    sa.sa_handler = &sigHandler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa, NULL);

    int p[2];
    if (pipe(p) == -1) {
        perror("pipe failed create");
        return 1;
    }

    int pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return 2;
    }

    if (pid == 0) {
        // child 
        close(p[0]);
        srand(time(NULL));
        int i,n;
        n = rand() % 10 +1;
        printf("C: le n = %d\n", n);

        int arr[n];
        for (i = 0 ; i < n ; i++) {
            arr[i] = rand() % 10;
            printf("C: index %d ==> %d\n", i , arr[i]);
        }

        // envoyer nre element array :
        if (write(p[1], &n, sizeof(int)) == -1) {
            perror("C write 1 failed");
            return 3;
        }
        // test sig
        kill(getpid(), SIGUSR1);

        // envoyer l'arr lui meme :
        if (write(p[1], arr, sizeof(arr)) == -1) {
            perror("C write 2 failed");
            return 4;
        }

        printf("C travail terminé!\n");
        close(p[0]);
    }
    else {
        // parent
        close(p[1]);

        int pN,i, sum = 0;

        // recup le nbre element:
        if (read(p[0], &pN, sizeof(int)) == -1) {
            perror("P read 1 failed");
            return 5;
        }
        printf("P: recv n => %d\n", pN);
        
        // recup le arr
        int *pArr = malloc(sizeof(*pArr) * pN);
        if (read(p[0], pArr, (sizeof(*pArr) * pN)) == -1 ) {
            perror("P: read 2 failed");
            return 6;
        }

        printf("P: tableau recup\n");

        for (i = 0; i < pN; i++ ) {
            printf("P: index %d ---> %d\n", i, *(pArr + i));
        }
        
        free(pArr);
        close(p[0]);
        

        //wait child...
        wait(NULL);
    }

    



    return 0;
}
