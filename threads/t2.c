

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <string.h>

struct MyArgs {
    int num;
    char *name;
    int id;
};

void *routine(void *args) {
    
    struct MyArgs *s_a;
    memset(&s_a, 0, sizeof(s_a));
    s_a = (struct MyArgs*)args;
    printf("le name: %s / le num: %d / le id: %d\n",
            s_a->name, s_a->num, s_a->id);
    return NULL;
}


int main() {    

    struct MyArgs s_args;
    memset(&s_args, 0, sizeof(s_args));
    
    s_args.num = 888;
    s_args.name = "koko";
    s_args.id = 1;

    pthread_t t1;

    if ( pthread_create(&t1, NULL, routine, &s_args ) != 0 ) return 1;

    if ( pthread_join(t1, NULL) != 0 ) return 2;




       return 0;
}
