#include <iostream>
#include <fstream>
#include "paragon.h"
#include <string>  
#include <ios>
#include "menu.h"
using namespace std;
fstream file;
void cleanup()
{
    file.open("ticket.txt", ios::out);
    file.close();
}

string int_to_string(int k)
{
    std::string str = std::to_string(k);
    return str;
}

void paragon_godzina (int godzina, int minuta) {
    file.open("ticket.txt", ios::app);
    file << "----------------------" << endl;
    file << "Godzina: " << int_to_string(godzina) << ":" <<int_to_string(minuta) << endl;
    file << "----------------------" << endl;
    file.close();
};

void  paragon_stolik (int line) {
    file.open("ticket.txt", ios::app);
    file <<"Nr stolika: "<< line << endl;
    file << "----------------------" << endl;
    file.close();
};
void  paragon_imie (string word1) {

    file.open("ticket.txt", ios::app);
    file << "----------------------" << endl;
    file <<"Imie:"<< word1 << endl;
    file << "----------------------" << endl;
    file.close();
};
void paragon_adres(string miejsc, string uli, int nrdom, int nrmie) {
    file.open("ticket.txt", ios::app);
    file << "----------------------" << endl;
    file << "Adres: " << miejsc << ", " << uli << " " << nrdom << "/" << nrmie << endl;
    file << "----------------------" << endl;
    file.close();
};
void paragon_pozycja(string nazwa, double price, int porcja, double suma)
{
    file.open("ticket.txt", ios::app);
    file << setfill('.') << left << setw(40) << nazwa << "|" << setw(2) << porcja << " x " << setw(5) << price << "|" << setw(7) << suma << "PLN" << endl;
    file.close();
};
void paragon_dania(int tablica_zamowienia[20][2])
{
    double cana_jednostkowa = 0;
    double cena_zbiorcza = 0;
    string nazwa_dania = "";
    int porcja = 0;
    double suma = 0;
    for (int i = 0; i < 20; i++)
    {
        if (tablica_zamowienia[i][0] != 0)
        {
            porcja = tablica_zamowienia[i][1];
            cana_jednostkowa = menu_cena(tablica_zamowienia[i][0]);
            cena_zbiorcza = cana_jednostkowa * porcja;
            nazwa_dania = menu_nazwa(tablica_zamowienia[i][0]);
            paragon_pozycja(nazwa_dania, cana_jednostkowa, porcja, cena_zbiorcza);
            suma += cena_zbiorcza;
        }


    }
    file.open("ticket.txt", ios::app);
    file << "----------------------" << endl;
    file << "Razem: " << right << setw(51) << suma << "PLN" << endl;
    file.close();
    
};

