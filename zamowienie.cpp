#include <iostream>
#include "data.h"
#include "kontrola_liczb.h"
#include "paragon.h"
#include "menu.h"
#include <string>

void dodaj_do_tablicy(int tablica_zamowienia[20][2], int id, int porcje)
{
	for (int i = 0; i < 20; i++)
	{
		if (tablica_zamowienia[i][0] == id)
		{
			tablica_zamowienia[i][1] += porcje;
			break;
		}
		else
		{
			if (tablica_zamowienia[i][0] == 0)
			{
				tablica_zamowienia[i][0] = id;
				tablica_zamowienia[i][1] = porcje;
				break;
			}
		}

	}
};
bool czy_jest_dodane(int tablica_zamowienia[20][2], int id)
{
	for (int i = 0; i < 20; i++)
	{
		if (tablica_zamowienia[i][0] == id)
		{
			return true;
		}
	}
	cout << "Nie zamawiales takiego dania!" << endl;
	return false;

};
void usun_z_tablicy(int tablica_zamowienia[20][2], int id, int porcje)
{
	for (int i = 0; i < 20; i++)
	{
		if (tablica_zamowienia[i][0] == id)
		{
			tablica_zamowienia[i][1] -= porcje;
			if (tablica_zamowienia[i][1] < 0)
			{
				tablica_zamowienia[i][1] = 0;
			}
			break;
		}
	}
};
void wyswietl_zamowienia_z_tablicy(int tablica_zamowienia[20][2])
{
	double cana_jednostkowa = 0;
	double cena_zbiorcza = 0;
	string nazwa_dania = "";
	for (int i = 0; i < 20; i++)
	{
		if (tablica_zamowienia[i][0] != 0)
		{
			cana_jednostkowa = menu_cena(tablica_zamowienia[i][0]);
			cena_zbiorcza = cana_jednostkowa * tablica_zamowienia[i][1];
			nazwa_dania = menu_nazwa(tablica_zamowienia[i][0]);
			cout << setw(50) << nazwa_dania << " - ";
			cout << setw(10) << cana_jednostkowa <<"PLN";
			cout << setw(10) << "x" << tablica_zamowienia[i][1];
			cout << setw(10) << cena_zbiorcza<<"PLN";
			cout << endl;

		}
	}
}
