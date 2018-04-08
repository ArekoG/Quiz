
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include<stdbool.h>


/** \brief add_players
 *
* Dodawanie graczy do listy

*/


struct players *add_players()   //dodawanie graczy
{

    puts("\nPodaj nick gracza:\n");
    struct players *new_players = (struct players *)malloc(sizeof(struct players));
    printf("--->");
    scanf("%s",new_players->nick);

    new_players->liczba_pkt=0;
    if(head_players)
    {

        new_players->next=head_players->next;
        head_players->next=new_players;
    }
    else
    {

        new_players->next=new_players;
        head_players=new_players;

    }

    return head_players;
}


/** \brief add_questions
 *
* dodawanie pytan do listy
* \param j linijka od ktorej bedzie wczytywane pytanie
* \param quiz nazwa kategorii

*/
struct questions *add_questions(int j,char *quiz)
{
    struct questions *head=head_question;
    struct questions *new_question = (struct questions *)malloc(sizeof(struct questions));

    if(new_question)
    {
        new_question->kategoria[N]=read_file(j,quiz);
        new_question->trudnosc_pytania[N]=read_file(j+1,quiz);
        new_question->tresc_pytania[N]=read_file(j+2,quiz);
        new_question->odp_a[N]=read_file(j+3,quiz);
        new_question->odp_b[N]=read_file(j+4,quiz);
        new_question->odp_c[N]=read_file(j+5,quiz);
        new_question->odp_d[N]=read_file(j+6,quiz);
        new_question->odp_poprawna[N]=read_file(j+7,quiz);


        if(head)
        {
            new_question->next=head->next;
            head->next=new_question;
        }
        else
        {

            new_question->next=new_question;
            head=new_question;

        }
    }
    return head;

}



/** \brief how_many_players
 *
* funkcja pyta sie uzytkownika ilu graczy ma wziac udzial w quizie
* \param number_of_players liczba graczy


*/

int how_many_players(int number_of_players)
{

    int i;
    puts("Ilu graczy ma wziac udzial w quizie?\n");
    printf("--->");
    while(scanf("%d", &number_of_players) != 1 || number_of_players==0)
    {

        puts("Niepoprawna wartosc!\nPodaj liczbe graczy jeszcze raz!\n");
        printf("--->");
        int c;
        while((c = getchar()) != '\n' && c != EOF);
    }

    for(i=0; i<number_of_players; i++)
    {
        head_players=add_players();
    }


    return number_of_players;
}



/** \brief repeat_questions
 *
* funkcja zapobiega powtarzaniu sie pytan
* \param tab tablica z indeksami kategorii i pytania
* \param kat numer kategorii
* \param pyt numer pytania
*/

bool repeat_questions(int *tab,int kat,int pyt)
{
    int i,flaga=0;

    for(i=0; i<200; i+=2)
    {
        if(kat==tab[i] && pyt==tab[i+1]) flaga-=1;
    }


    if(flaga==0)return true;
    else return false;
}

