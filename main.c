#include <stdio.h>
#include <stdlib.h>
#include "struktury.h"
#include "delete_struct.h"
#include "plikowe_funkcje.h"
#include "wyswietlanie.h"
#include "add_to_struct.h"
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include<conio.h>
#define N 255
#define LICZBA_PYTAN 10





int main()
{
    system("COLOR 1f");
    srand(time(0));
    char quiz[N];
    nagla_smierc=false,milionerzy=false;
    int i,wybor=0,level=0,number_of_players=0,kategoria=0,tab[N],l=0,pyt=0,kat=0;


    system("cls");
    puts("-------------------------------------------------------------------------------");
    puts("                              Wybierz tryb gry!\n-------------------------------------------------------------------------------\n");
    puts("[1]Losowa rozgrywka!                           [2]Wybierz poziom trudnosci!\n");
    puts("[3]Wybierz kategorie!                          [4]Nagla smierc!\n");
    puts("[5]Milionerzy                                  [6]Rekordzista Naglej Smierci!\n");
    puts("[7]Zobacz opis trybow gry                      [8]Wyjdz z quizu\n");
    puts("[9]O quizie\n");
    printf("\n--->");
    scanf("%d",&wybor);
    puts("\n");

    switch(wybor)
    {
        int czyszczenie_bufora;
        while((czyszczenie_bufora = getchar()) != '\n' && czyszczenie_bufora != EOF);


    case 1:
        system("cls");
        puts("-------------------------------------------------------------------------------");
        puts("                     Aktualny tryb gry : Losowa rozgrywka");
        puts("-------------------------------------------------------------------------------\n");
        number_of_players=how_many_players(number_of_players);


        for(i=0; i<LICZBA_PYTAN*number_of_players; i++)
        {


            do
            {
                kat = rand()%15;
                pyt=rand()%20 * 8;

            }
            while(repeat_questions(tab,kat,pyt)==false);

            tab[l++]=kat;
            tab[l++]=pyt;




            if(kat==0)  strncpy(quiz,"pytania/sport_1.txt",N);
            else if (kat==1)  strncpy(quiz,"pytania/sport_2.txt",N);
            else if (kat==2)  strncpy(quiz,"pytania/sport_3.txt",N);
            else if (kat==3)  strncpy(quiz,"pytania/historia_1.txt",N);
            else if (kat==4)  strncpy(quiz,"pytania/historia_2.txt",N);
            else if (kat==5)  strncpy(quiz,"pytania/historia_3.txt",N);
            else if (kat==6)  strncpy(quiz,"pytania/film_1.txt",N);
            else if (kat==7)  strncpy(quiz,"pytania/film_2.txt",N);
            else if (kat==8)  strncpy(quiz,"pytania/film_3.txt",N);
            else if (kat==9)  strncpy(quiz,"pytania/technologia_1.txt",N);
            else if (kat==10) strncpy(quiz,"pytania/technologia_2.txt",N);
            else if (kat==11) strncpy(quiz,"pytania/technologia_3.txt",N);
            else if (kat==12)  strncpy(quiz,"pytania/zwierzeta_1.txt",N);
            else if (kat==13) strncpy(quiz,"pytania/zwierzeta_2.txt",N);
            else if (kat==14) strncpy(quiz,"pytania/zwierzeta_3.txt",N);
            head_question=add_questions(pyt,quiz);

        }

        break;


    case 2:
        system("cls");
        puts("-------------------------------------------------------------------------------");
        puts("      Aktualny tryb gry : Wybieranie poziomu trudnosci przez uzytkownika");
        puts("-------------------------------------------------------------------------------\n");
        puts("Wybierz poziom trudnosci:\n\n[1]Easy   [2]Medium   [3]Hard\n");
        printf("--->");
        scanf("%d",&level);


        while((czyszczenie_bufora = getchar()) != '\n' && czyszczenie_bufora != EOF);

        number_of_players=how_many_players(number_of_players);

        if(level==1)
        {

            for(i=0; i<LICZBA_PYTAN*number_of_players; i++)
            {

                do
                {
                    kat = rand()%6;
                    pyt=rand()%20 * 8;

                }

                while(repeat_questions(tab,kat,pyt)==false);
                tab[l++]=kat;
                tab[l++]=pyt;


                if(kat==0)  strncpy(quiz,"pytania/sport_1.txt",N);
                else if (kat==1) strncpy(quiz,"pytania/historia_1.txt",N);
                else if (kat==2) strncpy(quiz,"pytania/zwierzeta_1.txt",N);
                else if (kat==3) strncpy(quiz,"pytania/technologia_1.txt",N);
                else if (kat==4) strncpy(quiz,"pytania/film_1.txt",N);
                else if (kat==5)  strncpy(quiz,"pytania/zwierzeta_1.txt",N);
                head_question=add_questions(pyt,quiz);
            }

        }

        if(level==2)
        {


            for(i=0; i<LICZBA_PYTAN*number_of_players; i++)
            {

                do
                {
                    kat = rand()%6;
                    pyt=rand()%20 * 8;

                }

                while(repeat_questions(tab,kat,pyt)==false);
                tab[l++]=kat;
                tab[l++]=pyt;


                if(kat==0)  strncpy(quiz,"pytania/sport_2.txt",N);
                else if (kat==1) strncpy(quiz,"pytania/historia_2.txt",N);
                else if (kat==2) strncpy(quiz,"pytania/zwierzeta_2.txt",N);
                else if (kat==3) strncpy(quiz,"pytania/technologia_2.txt",N);
                else if (kat==4) strncpy(quiz,"pytania/film_2.txt",N);
                else if (kat==5)  strncpy(quiz,"pytania/zwierzeta_2.txt",N);
                head_question=add_questions(pyt,quiz);
            }



        }

        if(level==3)
        {


            for(i=0; i<LICZBA_PYTAN*number_of_players; i++)
            {

                do
                {
                    kat = rand()%6;
                    pyt=rand()%20 * 8;

                }

                while(repeat_questions(tab,kat,pyt)==false);
                tab[l++]=kat;
                tab[l++]=pyt;


                if(kat==0)  strncpy(quiz,"pytania/sport_3.txt",N);
                else if (kat==1) strncpy(quiz,"pytania/historia_3.txt",N);
                else if (kat==2) strncpy(quiz,"pytania/zwierzeta_3.txt",N);
                else if (kat==3) strncpy(quiz,"pytania/technologia_3.txt",N);
                else if (kat==4) strncpy(quiz,"pytania/film_3.txt",N);
                else if (kat==5)  strncpy(quiz,"pytania/zwierzeta_3.txt",N);
                head_question=add_questions(pyt,quiz);

            }



        }

        break;



    case 3:
        system("cls");
        puts("-------------------------------------------------------------------------------");
        puts("           Aktualny tryb gry : Wybieranie kategorii przez uzytkownika");
        puts("-------------------------------------------------------------------------------\n");
        puts("Wybierz kategorie:\n\n[1]Sport      [2]Zwierzeta\n\n[3]Historia   [4]Technologia\n\n[5]Film\n");
        printf("--->");
        scanf("%d",&kategoria);

        while((czyszczenie_bufora = getchar()) != '\n' && czyszczenie_bufora != EOF);


        number_of_players=how_many_players(number_of_players);


        if(kategoria==1)
        {


            for(i=0; i<LICZBA_PYTAN*number_of_players; i++)
            {

                do
                {
                    kat = rand()%3;
                    pyt=rand()%20 * 8;

                }
                while(repeat_questions(tab,kat,pyt)==false);
                tab[l++]=kat;
                tab[l++]=pyt;

                if(kat==0)  strncpy(quiz,"pytania/sport_1.txt",N);
                else if (kat==1) strncpy(quiz,"pytania/sport_2.txt",N);
                else if (kat==2) strncpy(quiz,"pytania/sport_3.txt",N);

                head_question=add_questions(pyt,quiz);
            }


        }

        if(kategoria==2)
        {

            for(i=0; i<LICZBA_PYTAN*number_of_players; i++)
            {

                do
                {
                    kat = rand()%3;
                    pyt=rand()%20 * 8;

                }
                while(repeat_questions(tab,kat,pyt)==false);
                tab[l++]=kat;
                tab[l++]=pyt;

                if(kat==0)  strncpy(quiz,"pytania/zwierzeta_1.txt",N);
                else if (kat==1) strncpy(quiz,"pytania/zwierzeta_2.txt",N);
                else if (kat==2) strncpy(quiz,"pytania/zwierzeta_3.txt",N);

                head_question=add_questions(pyt,quiz);
            }

        }

        if(kategoria==3)
        {

            for(i=0; i<LICZBA_PYTAN*number_of_players; i++)
            {

                do
                {
                    kat = rand()%3;
                    pyt=rand()%20 * 8;

                }
                while(repeat_questions(tab,kat,pyt)==false);
                tab[l++]=kat;
                tab[l++]=pyt;

                if(kat==0)  strncpy(quiz,"pytania/historia_1.txt",N);
                else if (kat==1) strncpy(quiz,"pytania/historia_2.txt",N);
                else if (kat==2) strncpy(quiz,"pytania/historia_3.txt",N);

                head_question=add_questions(pyt,quiz);
            }


        }

        if(kategoria==4)
        {


            for(i=0; i<LICZBA_PYTAN*number_of_players; i++)
            {

                do
                {
                    kat = rand()%3;
                    pyt=rand()%20 * 8;

                }
                while(repeat_questions(tab,kat,pyt)==false);
                tab[l++]=kat;
                tab[l++]=pyt;

                if(kat==0)  strncpy(quiz,"pytania/technologia_1.txt",N);
                else if (kat==1) strncpy(quiz,"pytania/technologia_2.txt",N);
                else if (kat==2) strncpy(quiz,"pytania/technologia_3.txt",N);

                head_question=add_questions(pyt,quiz);
            }


        }

        if(kategoria==5)
        {


            for(i=0; i<LICZBA_PYTAN*number_of_players; i++)
            {

                do
                {
                    kat = rand()%3;
                    pyt=rand()%20 * 8;

                }
                while(repeat_questions(tab,kat,pyt)==false);
                tab[l++]=kat;
                tab[l++]=pyt;

                if(kat==0)  strncpy(quiz,"pytania/film_1.txt",N);
                else if (kat==1) strncpy(quiz,"pytania/film_2.txt",N);
                else if (kat==2) strncpy(quiz,"pytania/film_3.txt",N);

                head_question=add_questions(pyt,quiz);
            }


        }

        break;

    case 4:
        system("cls");
        puts("-------------------------------------------------------------------------------");
        puts("                     Aktualny tryb gry : Nagla smierc");
        puts("-------------------------------------------------------------------------------\n");
        nagla_smierc=true;
        head_players=add_players();

        for(i=0; i<200; i++)
        {


            do
            {
                kat = rand()%15;
                pyt=rand()%20 * 8;
            }
            while(repeat_questions(tab,kat,pyt)==false);

            tab[l++]=kat;
            tab[l++]=pyt;

            if(kat==0)  strncpy(quiz,"pytania/sport_1.txt",N);
            else if (kat==1) strncpy(quiz,"pytania/sport_2.txt",N);
            else if (kat==2) strncpy(quiz,"pytania/sport_3.txt",N);
            else if (kat==3) strncpy(quiz,"pytania/historia_1.txt",N);
            else if (kat==4) strncpy(quiz,"pytania/historia_2.txt",N);
            else if (kat==5) strncpy(quiz,"pytania/historia_3.txt",N);
            else if (kat==6) strncpy(quiz,"pytania/film_1.txt",N);
            else if (kat==7) strncpy(quiz,"pytania/film_2.txt",N);
            else if (kat==8) strncpy(quiz,"pytania/film_3.txt",N);
            else if (kat==9)  strncpy(quiz,"pytania/technologia_1.txt",N);
            else if (kat==10) strncpy(quiz,"pytania/technologia_2.txt",N);
            else if (kat==11) strncpy(quiz,"pytania/technologia_3.txt",N);
            else if (kat==12)  strncpy(quiz,"pytania/zwierzeta_1.txt",N);
            else if (kat==13) strncpy(quiz,"pytania/zwierzeta_2.txt",N);
            else if (kat==14) strncpy(quiz,"pytania/zwierzeta_3.txt",N);

            head_question=add_questions(pyt,quiz);

        }

        break;

    case 5:
        head_players=add_players();
        milionerzy=true;
        for(i=0; i<4; i++)
        {


            do
            {
                kat = rand()%5;
                pyt=rand()%20 * 8;
            }
            while(repeat_questions(tab,kat,pyt)==false);

            tab[l++]=kat;
            tab[l++]=pyt;

            if(kat==0)  strncpy(quiz,"pytania/sport_3.txt",N);
            else if (kat==1) strncpy(quiz,"pytania/historia_3.txt",N);
            else if (kat==2) strncpy(quiz,"pytania/film_3.txt",N);
            else if (kat==3) strncpy(quiz,"pytania/technologia_3.txt",N);
            else if (kat==4) strncpy(quiz,"pytania/zwierzeta_3.txt",N);

            head_question=add_questions(pyt,quiz);

        }

        for(i=0; i<4; i++)
        {


            do
            {
                kat = rand()%5;
                pyt=rand()%20 * 8;
            }
            while(repeat_questions(tab,kat,pyt)==false);

            tab[l++]=kat;
            tab[l++]=pyt;

            if(kat==0)  strncpy(quiz,"pytania/sport_2.txt",N);
            else if (kat==1) strncpy(quiz,"pytania/historia_2.txt",N);
            else if (kat==2) strncpy(quiz,"pytania/film_2.txt",N);
            else if (kat==3) strncpy(quiz,"pytania/technologia_2.txt",N);
            else if (kat==4) strncpy(quiz,"pytania/zwierzeta_2.txt",N);


            head_question=add_questions(pyt,quiz);

        }

        for(i=0; i<4; i++)
        {


            do
            {
                kat = rand()%5;
                pyt=rand()%20 * 8;
            }
            while(repeat_questions(tab,kat,pyt)==false);

            tab[l++]=kat;
            tab[l++]=pyt;

            if(kat==0)  strncpy(quiz,"pytania/sport_1.txt",N);
            else if (kat==1) strncpy(quiz,"pytania/historia_1.txt",N);
            else if (kat==2) strncpy(quiz,"pytania/film_1.txt",N);
            else if (kat==3) strncpy(quiz,"pytania/technologia_1.txt",N);
            else if (kat==4) strncpy(quiz,"pytania/zwierzeta_1.txt",N);

            head_question=add_questions(pyt,quiz);

        }

        break;

    case 6:
        show_record();
        puts("\n\n\nNacisnij dowolny klawisz aby wrocic do glownego menu!");
        getch();
        main();

        break;

    case 7:
        system("cls");
        puts("-------------------------------------------------------------------------------\n");
        puts("Losowa rozgrywka - Kazdy gracz odpowiada na 10 pytan. Kategoria oraz poziom     trudnosci kazdego pytania sa losowe!!\n");
        puts("-------------------------------------------------------------------------------\n");
        puts("Wybierz poziom trudnosc - wybierasz poziom trudnosc,a nastepnie kazdy gracz\nodpowiada na 10 losowych pytan z 5 losowych kategorii!\n");
        puts("-------------------------------------------------------------------------------\n");
        puts("Wybierz kategorie - wybierasz kategorie a nastepnie kazdy gracz odpowiada na 10 losowych pytan o losowym poziomie trudnosci z danej kategorii!\n");
        puts("-------------------------------------------------------------------------------\n");
        puts("Nagla smierc - tryb jednoosobowy, w ktorym odpowiadasz tak dlugo na pytania az  nie podasz blednej odpowiedzi!\n");
        puts("-------------------------------------------------------------------------------\n\n");
        puts("Milionerzy - tryb jednoosobowy. Masz 12 pytan do miliona. Co 4 pytania poziom   trudnosci pytan rosnie!!\n");
        puts("-------------------------------------------------------------------------------\n\n");
        puts("Nacisnij dowolny klawisz aby wrocic do glownego menu!\n");
        getch();
        main();


        break;

    case 8:
        exit(0);
        break;


    case 9:
        system("cls");
        puts("-------------------------------------------------------------------------------");
        puts("Aktualnie nasz quiz posiada 300 pytan z 5 kategorii:\n\n-sport\n-technologia\n-zwierzeta\n-historia\n-film\n\nKazda z kategorii posiada dodatkowo podzial na 3 poziomy trudnosci:\n-easy\n-medium\n-hard");
        puts("-------------------------------------------------------------------------------\n");
        puts("Autorzy quizu:\nArkadiusz Gajda oraz Albert Kozera\n");
        puts("\n\nNacisnij dowolny klawisz aby wrocic do glownego menu!");
        getch();
        main();

        break;

    default:
        puts("Nie ma takiego trybu!");
        exit(0);

    }

    if(milionerzy==true)print_milionerzy();
    else print_pytanie();
    ending_function();

    return main();

}

