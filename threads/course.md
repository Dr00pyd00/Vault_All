

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

**Attend** que le thread finisse.

- `arg 2`: la valeur retourner par la routine.



## Mutex 

Sert a lock des morceaux pour pas qu'il se marchent dessus.  

#### Mutex Setup 

```C
pthread_mutex_t mutex;

// dans le main:

pthread_mutex_init(&mutex);

    // tout 
    // le 
    // code

pthread_mutex_destroy(&mutex); // sorte de free() 
```

Ensuite il faut entourer les morceaux de code que l'on veut proteger.

```C
pthread_mutex_lock(&mutex);
    // code 
    // code 
pthread_mutex_unlock(&mutex);
```









