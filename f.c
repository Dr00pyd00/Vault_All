

#include <stdio.h>
#include <unistd.h>
#include <string.h>



int main() {    
   
    char *path = "toto.txt"; 
    FILE *file;
    
    file = fopen(path, "a");
    if (!file) return 1;

    fputs("bonjour", stdout);

    // ajout de lignes:
    fputs("premiere ligne\n", file);
    int age = 33;
    fprintf(file, "ton age est %d\n", age);

    char *message = "salut je viens du fwrite\n";
    fwrite((void*)message, sizeof(char), strlen(message), file);








    return 0;
}
