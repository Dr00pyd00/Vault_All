

#include <stdio.h>
#include <unistd.h>
#include <string.h>



int main() {

    char *filename = "toto.txt";

    FILE *file = fopen(filename, "a");

    if (!file) return 1;

    int re = fprintf(
            file,
            "premiere ligne\ndeuxieme ligne\ntroisieme ligne\n"
           );

    if (re == 0) return 2;

    fclose(file);


    file = fopen(filename, "r");
    if (!file) return 3;
    
    char buf[4096];
    while ( fgets( buf, sizeof(buf), file)) {
        printf("%s", buf);
    }

    fclose(file);
    


    





    return 0;
}
