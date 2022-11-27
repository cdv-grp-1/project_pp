#include <iostream>
#include <fstream>
#include "paragon.h"
using namespace std;

void paragon_godzina (string godzina,string minuta) {
    fstream file;
    file.open("ticket.txt", ios::out);	
    file <<"Godzina: "<<godzina<<":"<<minuta<< endl;
};
void  paragon_stolik (string line) {
    fstream file;
    file.open("ticket.txt", ios::out);	
    file <<"Nr stolika: "<< line << endl;
};
void  paragon_imie (string word1) {
    fstream file;
    file.open("ticket.txt", ios::out);	
    file <<"Imie:"<< word1 << endl;
};

void  paragon_adres (string miejsc ,string uli ,string nrdom ,string nrmie) {
    fstream file;
    file.open("ticket.txt", ios::out);	
    file <<"Adres: " << miejsc <<"Ulica"<< uli <<"Nr domu"<< nrdom << "/"<< nrmie <<endl;
};
