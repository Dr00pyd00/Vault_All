

# Thread in C 


## Basics 

```C
#include <pthread.h>
```
Posix threading.

```C
pthread_t t1;
```
- `t1`: identifiant d'un thread.

```C
if ( pthread_create( &t1, NULL, &routine, NULL) != 0 ) return 1;
```
**Create** and **start to run** the thread

- `arg 1`: pointeur vers l'identifiant du thread
- `arg 2`: struct pour les options (quasi jamais utilise) 
- `arg 3`: fonction routine a executer
- `arg 4`: endroit ou passer les args pour la routine -> peut etre une struct complexe

```C
if ( pthread_join(t1, NULL) != 0 ) return 2;
```




