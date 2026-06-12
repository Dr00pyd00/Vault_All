

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
 
    int add(int a, int b) {
        return a + b;
    }

    int prod(int a, int b) {
        return a * b;
    }

    void MyFunc(int (*func) (int, int)) {

        srand(time(NULL));
        int x = rand() % 100;
        int y = rand() % 100;

        printf("res  x:%d and y:%d = %d\n", x, y , func(x,y));
    }

    void base() {
        printf("Hello World\n");
    }
    
    void pbase(void (*func)(void)) {
        func();
    }

 

int main() {    

    pbase(&base);
    



    return 0;
}
