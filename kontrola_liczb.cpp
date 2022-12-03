#include <iostream>
#include <string>
#include "kontrola_liczb.h"
#include "input.h"
using namespace std;

int kontrola_liczby() {
	string liczba = "";
	bool blad = false;
	do 
	{
		getline(cin, liczba);
		if (liczba == "") { liczba = "0"; }
		if (sprawdz_numer(liczba) == false)
		{
			blad = true;
			cout << "Podaj liczbe: ";
		}
		else
		{
			return stoi(liczba);
		}
	} while (blad);
}