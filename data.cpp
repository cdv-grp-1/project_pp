#include <iostream>
#include "data.h"
#include "kontrola_liczb.h"
#include "input.h"
#include <string>

using namespace std;

string podaj_imie() {
	string imie;
	cout << "Podaj swoje imie: ";
	getline(cin, imie);
	input(imie);
	return imie;
};
bool podaj_miejsce()
{
	string odp;
	cout << "Czy chcesz zlozyc zamowienie na miejscu czy z dowozem?" << endl;
	while (true) {
		cout << "M - na miejscu, D - z dowozem: ";
		getline(cin, odp);
		input(odp);
		
		if (odp == "M" || odp == "m")
		{
			return true;
		}
		else if (odp == "D" || odp == "d")
		{
			return false;
		}
		else
		{
			cout << "Podano bledna odpowiedz!" << endl;
		}
	}
};
int nr_stolika() {
	int nr;
	bool blad;
	do
	{
		blad = false;
		cout << "Podaj nr stolika ktory chcesz zajac (1-50)"<<endl;
		nr = kontrola_liczby();
		if (nr > 50 || nr < 1)
		{
			cout << "Bledny numer stolika"<<endl;
			blad = true;
		}
	} 
	while (blad);
	
	return nr;
};
void podaj_adres(string & miejscowosc, string & ulica, int & nr_domu, int & nr_mieszkania)
{
	cout << "Podaj miejscowosc: ";
	getline(cin, miejscowosc);
	input(miejscowosc);
	cout << "ulica: ";
	getline(cin, ulica);
	input(ulica);
	cout << "numer domu: ";
	nr_domu = kontrola_liczby();
	cout << "numer mieszkania : ";
	nr_mieszkania = kontrola_liczby();
	
};
