#include <iostream>
#include <string>
#include "kontrola_liczb.h"
#include "input.h"
using namespace std;

int kontrola_liczby() {
	string liczba;
	bool blad = false;
	do 
	{
		cin >> liczba;
		if (sprawdz_numer(liczba) == false)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			blad = true;
			cout << "Podaj liczbe: ";
		}
		else
		{
			return stoi(liczba);
		}
	} while (blad);
}