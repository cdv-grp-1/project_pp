#include <iostream>
#include "data.h"
#include "kontrola_liczb.h"
#include "czas.h"
#include "menu.h"
#include "paragon.h"
#include "zamowienie.h"
#include "restauracja_dane.h"
using namespace std;

int nr, nr_domu, nr_mieszkania, minuta, godzina, dzien_tyg, godz_dow, min_dow;
string imie, miejscowosc, ulica;
bool na_miejscu;
int tablica_zamowienia[20][2] = { {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},
                                  {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0} };


int main() {
    //wyczyszczenie paragonu
    cleanup();

    dane_restauracji();

    //Dane
    imie = podaj_imie();
    na_miejscu = podaj_miejsce();
    
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
    
    //menu programu
    menu_glowne(tablica_zamowienia);

    //Koniec programu - zapisanie paragonu do TXT
    paragon_imie(imie);
    if (na_miejscu)
    {
        paragon_stolik(nr);
    }
    else
    {
        paragon_godzina(godz_dow, min_dow);
        paragon_adres(miejscowosc, ulica, nr_domu, nr_mieszkania);
    }
    paragon_dania(tablica_zamowienia);
    


    return 0;
}

