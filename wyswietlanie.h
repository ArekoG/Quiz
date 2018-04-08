#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include<stdbool.h>
bool nagla_smierc=false;
bool milionerzy=false;

int main();


/** \brief ending_function
 *
*  funkcja kasuje struktury oraz plik zle_odpowiedzi.txt


*/
void ending_function()
{
    kasowanie_zawartosci_pliku();
    remove_pytania();
    remove_players();
}


/** \brief change_record
 *
*  zamiana rekordu naglej smierci
* \param wynik ilosc punktow zdobyta przez gracza w naglej smierci

*/
void change_record(int wynik)
{

    FILE *plik = fopen("nagla_smierc.txt","w");

    if(plik==NULL)
    {
        puts("Blad otwarcia pliku");
        exit(0);
    }

    fprintf(plik,"%d dobrych odpowiedzi z rzedu - rekord nalezacy do gracza o nicku: %s",wynik,head_players->nick);

    if(fclose(plik)!=0)printf("Blad zamkniecia pliku");

}


/** \brief show_mistake
 *
*  pokazanie blednych odpowiedzi

*/

void show_mistake()
{

    system("cls");
    puts("-------------------------------------------------------------------------------");
    puts("                       Pytania na ktore odpowiedziano blednie:");
    puts("-------------------------------------------------------------------------------\n");
    char c;

    FILE *plik=fopen("zle_odpowiedzi.txt","r");

    if(plik==NULL)
    {
        puts("Blad otwarcia pliku");
        exit(0);
    }

    do
    {
        c = getc(plik);
        putchar(c);

    }
    while(c!=EOF);
    puts("\n\n\nNacisnij dowolny klawisz aby wrocic do glownego menu!");

    if(fclose(plik)!=0)puts("Blad zamkniecia pliku");

}

/** \brief show_record
 *
*  pokazanie rekordu naglej smierci

*/
void show_record()
{

    system("cls");
    char c;

    FILE *plik=fopen("nagla_smierc.txt","r");
    if(plik==NULL)
    {
        puts("Blad otwarcia pliku");
        exit(0);
    }
    puts("-------------------------------------------------------------------------------");
    puts("                             Rekord Naglej Smierci");
    puts("-------------------------------------------------------------------------------\n");
    do
    {
        c = getc(plik);
        putchar(c);

    }
    while(c!=EOF);


    if(fclose(plik)!=0)puts("Blad zamkniecia pliku");

}

/** \brief show_results
 *
*  pokazanie wyników gry

*/

void show_results()
{
    bool remis=false;
    struct players * start = head_players;
    int wynik=head_players->liczba_pkt;
    char zwyciezca[N],decyzja;

    strncpy(zwyciezca, head_players->nick,N);
    puts("Wyniki:\n");

    do
    {

        printf("%s:%dpkt\n",head_players->nick,head_players->liczba_pkt);
        if(wynik<head_players->liczba_pkt)
        {
            strncpy(zwyciezca, head_players->nick,N);
            wynik=head_players->liczba_pkt;
        }
        head_players=head_players->next;

    }
    while(head_players!=start);

    if(head_players->liczba_pkt==head_players->next->liczba_pkt)remis=true;

    puts("\n");
    if(remis==false)printf("Wygrywa gracz %s z wynikiem %d pkt\n",zwyciezca,wynik);
    else if(head_players!=head_players->next)printf("Remis!!!\n");
    puts("Czy chcesz zobaczyc pytania na ktore odpowiedziano blednie?\n");
    puts("t/n");
    scanf(" %c",&decyzja);

    if(decyzja=='t')show_mistake();
    getch();
}

/** \brief check_answer
 *
*  sprawdzanie czy uzytkownik udzielil poprawanej odpowiedzi
* \param *odpowiedz_uzytkownika
* \param *odp_poprawna

*/


int check_answer(char *odpowiedz_uzytkownika,char *odp_poprawna)
{

    if(!strncmp(odpowiedz_uzytkownika,odp_poprawna,1))return 1;

    else return 0;


}
/** \brief compare_results
 *
* porównuje wynik gracza z rekordem naglej smierci
* \param wynik


*/

void compare_results(int wynik)
{

    printf("Twoj wynik to:%d\n",wynik);



    int record;

    FILE *plik=fopen("nagla_smierc.txt","r");
    if(plik==NULL)
    {
        puts("Blad otwarcia pliku");
        exit(0);
    }


    do
    {
        fscanf(plik,"%d ",&record);
    }
    while(feof(plik));


    getch();

    if(fclose(plik)!=0)puts("Blad zamkniecia pliku");


    if(wynik>record)
    {

        puts("Brawo udalo Ci sie pobic rekord Naglej smierci!\n");
        change_record(wynik);

    }

    else puts("Nie udalo Ci sie pobic rekordu!Moze nastepnym razem!\n");
    ending_function();

    puts("Nacisnij dowolny klawisz aby wrocic do glownego menu!\n");

    getch();
   main();

}


/** \brief print_pytanie
 *
* pokazuje pytania

*/
void print_pytanie()
{
    int i=1;
    struct questions *head=head_question;
    char odp_uzytkownika[1];

    if(head && head_players)
    {
        struct questions * start = head->next;

        do
        {
            system("cls");
            printf("Tura gracza:%s\n",head_players->nick);
            puts("\n");
            printf("Kategoria:%s",start->kategoria[N]);
            printf("%s",start->trudnosc_pytania[N]);
            printf("%d.%s",i,start->tresc_pytania[N]);
            printf("%s",start->odp_a[N]);
            printf("%s",start->odp_b[N]);
            printf("%s",start->odp_c[N]);
            printf("%s",start->odp_d[N]);
            puts("\n");
            i++;
            puts("Podaj odpowiedz:");
            printf("--->");
            scanf(" %c",odp_uzytkownika);
            if(check_answer(odp_uzytkownika,start->odp_poprawna[N])==1)head_players->liczba_pkt+=1;
            else if(nagla_smierc==true)compare_results(head_players->liczba_pkt);
            else zapisywanie_bledow(start);


            start=start->next;
            head_players=head_players->next;
        }
        while(head->next!=start);

        puts("");
    }
    show_results();

}

/** \brief show_results_milionerzy
 *
* pokazuje ile gracz wygral w milionerach
* \param i kwota


*/

void show_results_milionerzy(int i)
{
    system("cls");
    puts("-------------------------------------------------------------------------------");
    if(i<1)printf("                           Nie wygrales nic!\n");
    else if(i>=1 && i<6)printf("                            Wygrales 1000 zl!\n");
    else if(i>=6 && i<=11)printf("                            Wygrales 40000zl!\n");
    puts("-------------------------------------------------------------------------------\n\n");
    puts("\n\nNacisnij dowolny klawisz aby wrocic do glownego menu!");
    getch();
    ending_function();
    main();
}


/** \brief check_win
 *
* sprawdza czy gracz wygral 1mln zlotych
* \param i kwota


*/

void check_win(int i)
{
    if(i==11)
    {

        system("cls");
        puts("-------------------------------------------------------------------------------");
        printf("                     WYGRALES MILION ZLOTYCH! BRAWO!\n");
        puts("-------------------------------------------------------------------------------\n\n");
        puts("\n\nNacisnij dowolny klawisz aby wrocic do glownego menu!");
        getch();
        ending_function();
        main();
    }
}


/** \brief print_milionerzy
 *
* pokazuje pytania w trybie "milionerzy"



*/

void print_milionerzy()
{

    struct questions *head=head_question;
    char odp_uzytkownika[1];
    int i=0;
    int kwoty[12]= {500,1000,2000,5000,10000,20000,40000,75000,125000,250000,500000,1000000};
    if(head && head_players)
    {
        struct questions * start = head->next;

        do
        {
            system("cls");
            printf("Gracz:%s\n",head_players->nick);
            puts("-------------------------------------------------------------------------------");
            if(i==1 || i==6 )printf("             Przed Toba pytanie za gwarantowane %d zlotych\n",kwoty[i]);
            else printf("                       Przed Toba pytanie za %d zlotych\n",kwoty[i]);
            puts("-------------------------------------------------------------------------------\n\n");
            printf("%d.%s",i+1,start->tresc_pytania[N]);
            printf("%s",start->odp_a[N]);
            printf("%s",start->odp_b[N]);
            printf("%s",start->odp_c[N]);
            printf("%s",start->odp_d[N]);
            puts("\n");



            puts("Podaj odpowiedz:");
            printf("--->");
            scanf(" %c",odp_uzytkownika);


            if(check_answer(odp_uzytkownika,start->odp_poprawna[N])==1)check_win(i);
            else show_results_milionerzy(i);

            i++;
            start=start->next;
        }
        while(head->next!=start);

        puts("");
    }

}


