#include <iostream>
#include "data.h"
#include "kontrola_liczb.h"
#include "paragon.h"
#include "menu.h"
#include <string>
void dodaj(string nazwa, int portion, int price)
{
	int suma;
	cout << "Podaj ile porcji chcesz zamowic: ";
	portion = kontrola_liczby();
	suma = price * portion;
	cout << "Do zamowienia dodano " << nazwa << " w cenie: " << price << endl;
	cout << "Suma: " << suma << endl;
	paragon_pozycja(nazwa, price, portion, suma);
}