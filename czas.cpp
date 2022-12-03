#include<iostream>
#include<ctime>
#include "czas.h"
#include "kontrola_liczb.h"
#include "menu.h"
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
void czas_przygotowania(bool na_miejscu, int godzina, int minuta, int dzien_tyg, int godz_dow, int min_dow)
{
	cout << "Twoje zamowienie bedzie gotowe za ok 45 minut" << endl;
	if (!na_miejscu)
	{
		podaj_godzine(godzina, minuta, dzien_tyg, godz_dow, min_dow);
	}

};
void ktora_godzina(int godzina, int minuta, bool & na_miejscu)
{
	int odp = 0;
	if (godzina < 10)
	{
		cout << "Restauracja jest czynna w godzinach 10:00-23:00 "<<endl;
		cout << "Czy mimo to chcesz zlozyc zamowienie? Zamowienia beda realizowane od godziny 10:00 " << endl;
		cout << "1.TAK 2.NIE" << endl;
		odp = kontrola_liczby();
		do
		{
			if (odp == 2)
			{
				exit(0);
			}
		} while (odp != 1 && odp != 2);
	}
	if (godzina > 22)
	{
		cout << "Restauracja jest czynna w godzinach 10:00-23:00 " << endl;
		cout << "Zamowienia beda realizowane od godziny 10:00 " << endl;
		do
		{
		cout << "Czy chcesz przejrzec menu?"<< endl;
		cout << "1.TAK 2.NIE" << endl;
		odp = kontrola_liczby();
		
			if (odp == 1)
			{
				menu_lista();
			}
			
		} while (odp != 1 && odp != 2);
		exit(0);
	}
	if ((godzina == 22 && minuta > 0 && minuta <=15 ))
	{
		cout << "Zamowienia z dowozem realizujemy tylko do godziny 22:00" << endl;
		
		do
		{
			cout << "Czy chcesz zamowic na miejscu?" << endl;
			cout << "1.TAK 2.NIE" << endl;
			odp = kontrola_liczby();

			if (odp == 2)
			{
				exit(0);
			}
			if (odp == 1)
			{
				na_miejscu = true;
			}
		} while (odp != 1 && odp != 2);
	}
	if (godzina == 22 && minuta > 15)
	{
		cout << "Zamowienia w lokalu realizujemy tylko do godziny 22:15" << endl;
		do
		{
			cout << "Czy chcesz przejrzec menu?" << endl;
			cout << "1.TAK 2.NIE" << endl;
			odp = kontrola_liczby();

			if (odp == 1)
			{
				menu_lista();
			}

		} while (odp != 1 && odp != 2);
		exit(0);
	}
}