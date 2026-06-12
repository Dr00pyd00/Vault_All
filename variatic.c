

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>


void varF(int count, ...) {
    
    va_list args;
    va_start(args, count);
    
    int i;
    for ( i = 0; i < count; i++ ) {
        printf("arg %d => %d\n", i, va_arg(args, int));
    }
}


int main() {    


    varF(3,5,6,4,6,6,7);
    
    







    return 0;
}
