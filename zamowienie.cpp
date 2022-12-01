#include <iostream>
#include "data.h"
#include "kontrola_liczb.h"
#include "paragon.h"
#include "menu.h"
#include <string>

void dodaj_do_tablicy(int tablica_zamowienia[20][2], int id, int porcje)
{
	for (int i = 0; i < 50; i++)
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
	for (int i = 0; i < 50; i++)
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
	for (int i = 0; i < 50; i++)
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
