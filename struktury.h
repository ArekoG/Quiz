#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#define N 255
#define LICZBA_PYTAN 10

struct questions              //lista pytan
{

    char *kategoria[N];
    char *tresc_pytania[N];
    char *trudnosc_pytania[N];
    char *odp_a[N];
    char *odp_b[N];
    char *odp_c[N];
    char *odp_d[N];
    char *odp_poprawna[2*N];

    struct questions *next;
}*head_question ;

struct players  //lista graczy
{

    char nick[20];
    int liczba_pkt;

    struct players *next;
}*head_players;



