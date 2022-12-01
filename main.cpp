#include <iostream>
#include "data.h"
#include "kontrola_liczb.h"
#include "czas.h"
#include "menu.h"
#include "paragon.h"
#include "dodawanie.h"
using namespace std;

int nr, nr_domu, nr_mieszkania, minuta, godzina, dzien_tyg, godz_dow, min_dow;
string imie, miejscowosc, ulica;
bool na_miejscu;
int tablica_zamowienia[20][2] = { {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},
                                  {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0} };


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
    menu_dodaj(tablica_zamowienia);

    // Podglad tablicy
    for (int i = 0; i < 20; i++)
    {  
        if (tablica_zamowienia[i][0] != 0)
        {
            cout << "nr id: " << tablica_zamowienia[i][0];
            cout << "   ilosc:  " << tablica_zamowienia[i][1];
            cout << endl;
        }
    }
    //
    
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

