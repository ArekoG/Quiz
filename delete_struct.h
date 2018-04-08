#include <stdio.h>
#include <stdlib.h>

/** \brief Usuniecie struktury pytania.
 *
* Funkcja usuwa strukture pytania
*/

void remove_pytania()
{


    if(head_question)
    {

        struct questions *start=head_question;

        do
        {
            struct questions * next=(head_question)->next;
            free(head_question);
            head_question=next;
        }
        while(head_question!=start);
        head_question=NULL;

    }
}


/** \brief Usuniecie struktury gracze.
 *
* Funkcja usuwa strukture gracze
*/

void remove_players()
{

    if(head_players)
    {

        struct players * start=head_players;

        do
        {
            struct players * next=(head_players)->next;
            free(head_players);
            head_players=next;
        }
        while(head_players!=start);
        head_players=NULL;

    }
}
