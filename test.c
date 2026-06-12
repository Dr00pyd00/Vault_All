



#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>


typedef enum {
    TYPE_INT,
    TYPE_CHAR,
} DataType;

// envoyer un int = expliquer le type
// envoyer un int = nombre element a recevoir au prochain coup
// envoyer les données.

int main() {

    int p[2];
    if (pipe(p) == -1) return 1;

    int pid = fork();
    if (pid == -1) return 2;


    if (pid == 0) {
        // child  &
        close(p[0]);

        // truc a envoyer:
        int arr[5] = {10,11,12,13,14};
            // c'est TYPE_INT;
        DataType type = TYPE_INT;
        int arrSize = sizeof(arr) / sizeof(int);

        // 1 envoyer le type:
        if (write(p[1], &type, sizeof(DataType)) == -1) return 5;

        // 2 envoyer le nombre d'elements:
        if (write(p[1], &arrSize, sizeof(arrSize)) == -1) return 6;

        // 3 envoyer le tableau:
        int total = 0;
        int toSend = sizeof(arr);
        while (total < toSend) {
            int w = write(p[1], (char*)arr + total, toSend - total);
            if (w < 0) return 5;
            total += w;
        }

        close(p[1]);



    }
    else {
        // parent 
        close(p[1]); 

        // choper le type:
        DataType t;
        if (read(p[0], &t, sizeof(DataType)) == -1) return 7;
        int size;
        if ( t == TYPE_INT) size = 4;
        if ( t == TYPE_CHAR ) size = 1;

        printf("P: size = %d\n", size);
        
        // choper le nombre d'element:
        int el;
        if (read(p[0], &el, sizeof(el)) == -1) return 8;
        printf("nombre d'elements: %d\n", el);


        // choper tout le arr
        
        int total = 0;
        int bytesToRecv = size * el;
        int *tableau = malloc(bytesToRecv);
        if (!tableau) return 9;
        
        while (total < bytesToRecv) {
            int r = read(p[0], (char*)tableau + total, bytesToRecv - total);
            if ( r < 0 ) return 10;
            total += r;
        }
        
        printf("P: tout le tableau recu\n");

        for (int i = 0; i < el; i++ ) {
            printf("index %d ==> %d\n", i, tableau[i]);
        }
        

        free(tableau);
        close(p[0]);


    }




    return 0;
}
