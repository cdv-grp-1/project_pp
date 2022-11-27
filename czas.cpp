#include<iostream>
#include<ctime>
#include "czas.h"
#include "kontrola_liczb.h"
using namespace std;

void czas(int& minuta, int& godzina, int& dzien_tyg)
{
	time_t teraz;
	struct tm czas;

	teraz = time(NULL);
#pragma warning(suppress : 4996)
	czas = *localtime(&teraz);
	minuta = czas.tm_min;
	godzina = czas.tm_hour;
	dzien_tyg = czas.tm_wday;
};

void podaj_godzine(int godzina, int minuta, int dzien_tyg, int& godz_dow, int& min_dow)
{
	if ((godzina > 21 || godzina < 10) || (godzina == 21 && minuta > 45))
	{
		cout << "Zamowienie mozna zlozyc tylko w godzinach 10:00-21:45" << endl;
	}
	else
	{
		do
		{
			cout << "Wybierz godzine dostawy z zakresu " << godzina + 1 << ":" << minuta << " - 22:45" << endl;
			cout << "Godzina: ";
			godz_dow = kontrola_liczby();
			cout << "Minuta: ";
			min_dow = kontrola_liczby();
		} while ((godz_dow < godzina + 1) || (godz_dow == godzina + 1 && min_dow < minuta) || (godz_dow > 22 || godz_dow == 22 && min_dow > 45) || min_dow > 59);
		cout << "Wybrano godzine: " << godz_dow << ":" << min_dow << endl;
	}


}