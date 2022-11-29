#include <iostream>
#include "data.h"
#include "kontrola_liczb.h"
#include "czas.h"
#include "menu.h"
#include "paragon.h"
using namespace std;

int nr, nr_domu, nr_mieszkania, minuta, godzina, dzien_tyg, godz_dow, min_dow;
string imie, miejscowosc, ulica;
bool na_miejscu;


int main() {
    cleanup();
    imie = podaj_imie();
    na_miejscu = podaj_miejsce();
    paragon_imie(imie);
    //Dane
    if (na_miejscu) 
    {
       nr = nr_stolika();
    }
    else
    {
        podaj_adres(miejscowosc, ulica, nr_domu, nr_mieszkania);
        czas(minuta, godzina, dzien_tyg);
        podaj_godzine(godzina, minuta, dzien_tyg, godz_dow, min_dow);

    }
    //menu_nazwa(kontrola_liczby());
    menu_lista();
    menu_dodaj();
    //Koniec programu - zapisanie do TXT
    if (na_miejscu)
    {
        paragon_stolik(nr);
    }
    else
    {
        paragon_godzina(godz_dow, min_dow);
        paragon_adres(miejscowosc, ulica, nr_domu, nr_mieszkania);
    }


    return 0;
}

