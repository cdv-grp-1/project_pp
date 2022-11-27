#include <iostream>
#include <fstream>
#include "paragon.h"
#include <string>  
#include <ios>
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
    file.close();
};
void  paragon_imie (string word1) {

    file.open("ticket.txt", ios::app);
    file << "----------------------" << endl;
    file <<"Imie:"<< word1 << endl;
    file << "----------------------" << endl;
    file.close();
};
void  paragon_adres(string miejsc, string uli, int nrdom, int nrmie) {
    file.open("ticket.txt", ios::app);
    file << "----------------------" << endl;
    file << "Adres: " << miejsc << ", " << uli << " " << nrdom << "/" << nrmie << endl;
    file << "----------------------" << endl;
    file.close();
};
void paragon_pozycja(string nazwa, int price, int porcja, int suma)
{
    file.open("ticket.txt", ios::app);
    file << "----------------------" << endl;
    file << "Pozycja:" << nazwa<<"|"<< "Cena:" << price<< "|" <<"Ilosc:" << porcja << "|" << suma << endl;
    file.close();
};
