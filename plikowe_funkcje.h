#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/** \brief Usuniecie zawartosci pliku
 *
* Usuniecie zawartosci pliku zle_odpowiedzi.txt
*/
void kasowanie_zawartosci_pliku()
{

    FILE *plik = fopen("zle_odpowiedzi.txt","w");

    if(plik==NULL)
    {
        puts("Blad otwarcia pliku");
        exit(0);
    }

    fprintf(plik,"%s"," ");

    if(fclose(plik)!=0)printf("Blad zamkniecia pliku");
}



/** \brief Wczytanie pliku
 *
*  Wczytanie pliku z pytaniami
* \param line_to_read linia z pliku do wczytania
* \param *quiz nazwa kategorii
*/
char *read_file(int line_to_read,char *quiz)
{

    char *element=calloc(sizeof(char),N);
    int j=0;
    char napis[N];
    FILE *plik = fopen(quiz,"r");

    if(plik==NULL)
    {
        puts("Blad otwarcia pliku do odczytu.");
        exit(0);
    }

    while (fgets(napis, sizeof(napis), plik))
    {
        if(j==line_to_read)
        {
            strncpy(element,napis,N);
        }
        j++;
    }


    if(fclose(plik)!=0)puts("Blad zamkniecia pliku.");


    return element;
    free(element);
}


/** \brief zapisywanie_bledow
 *
*  zapisywanie_blednych odpowiedzi do pliku
* \param *tmp wskaznik na pytanie na ktore udzielono blednej odpowiedzi

*/

void zapisywanie_bledow(struct questions *tmp)
{

    FILE *plik = fopen("zle_odpowiedzi.txt","a");

    if(plik==NULL)
    {
        puts("Blad otwarcia pliku do zapisu.");
        exit(0);
    }

    fprintf(plik,"%s",tmp->kategoria[N]);
    fprintf(plik,"%s",tmp->trudnosc_pytania[N]);
    fprintf(plik,"%s",tmp->tresc_pytania[N]);
    fprintf(plik,"%s",tmp->odp_a[N]);
    fprintf(plik,"%s",tmp->odp_b[N]);
    fprintf(plik,"%s",tmp->odp_c[N]);
    fprintf(plik,"%s",tmp->odp_d[N]);
    fprintf(plik,"Poprawna odpowiedz na to pytanie to odpowiedz:%s\n\n",tmp->odp_poprawna[N]);

    if(fclose(plik)!=0)puts("Blad zamkniecia pliku.");


}

