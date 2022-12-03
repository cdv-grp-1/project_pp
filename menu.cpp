#include <iostream>
#include "json.hpp"
#include <fstream>
#include <string>
#include "paragon.h"
#include "kontrola_liczb.h"
#include "zamowienie.h"

using namespace std;
using json = nlohmann::json;


namespace ns {
	struct meal_m {
		int id;
		std::string type;
		std::string name;
		std::string text;
		double price;
		std::string ingr;
	};


	void to_json(json& j, const meal_m& m) {
		j = json{
			{"id", m.id},
			{'type', m.type},
			{'name', m.name},
			{'text', m.text},
			{"price", m.price},
			{"ingr", m.ingr}
		};
	};

	void from_json(const json& j, meal_m& m) {
		j.at("id").get_to(m.id);
		j.at("type").get_to(m.type);
		j.at("name").get_to(m.name);
		j.at("text").get_to(m.text);
		j.at("price").get_to(m.price);
		j.at("ingr").get_to(m.ingr);
	};
}


void menu_lista() {
	
	ifstream f("menu.json");
	json data = json::parse(f);
	f.close();
	string licznik[21] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20" };
	
	cout << "~~MENU~~" << endl;
	for (int i = 1; i <= 20; i++) {
		auto m = data.at("danie" + licznik[i]).get<ns::meal_m>();
		cout << "------------------------------------------------------------";
		cout << "---------------------------------------------------------" << endl;
		cout << "Pozycja nr. " << setw(2) << m.id << setw(100) << m.price << "PLN" << endl;
		cout << m.type << endl;
		cout << m.name << " " << m.text << endl;
		cout << "Skladniki: " << m.ingr << endl;
		
	};
	cout << "------------------------------------------------------------";
	cout << "---------------------------------------------------------" << endl;

};
string menu_nazwa(int id)

{
	ifstream f("menu.json");
	string licznik[21] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20" };
	json data = json::parse(f);
	f.close();
	auto m = data.at("danie" + licznik[id]).get<ns::meal_m>();
	return m.name;
};
double menu_cena(int id)
{
	ifstream f("menu.json");
	string licznik[21] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20" };
	json data = json::parse(f);
	f.close();
	auto m = data.at("danie" + licznik[id]).get<ns::meal_m>();
	return m.price;
};

void menu_glowne(int tablica_zamowienia[20][2])
{
	int wybor = 0;
	int id = 0;
	int porcje = 0;
	int blad = false;
	do
	{
		cout << endl;
		cout << "1.Dodaj danie 2.Wyswietl menu 3.Wyswietl zamowienie 4.Usun danie 5. Anuluj zamowienie 6.Sfinalizuj zamowienie" << endl;
		wybor = kontrola_liczby();
		switch (wybor)
		{
		case 1:
		{
			do {
				cout << "Wybierz danie" << endl;
				id = kontrola_liczby();
				if (id < 1 || id > 20) {
					cout << "Nie ma takiego dania" << endl;
					blad = true;
				}
				else
				{
					blad = false;
				}
			} while (blad);

			do {
			cout << "Ile porcji?" << endl;
			porcje = kontrola_liczby();
			if (porcje < 1 || porcje > 20) 
			{
				cout << "Mozesz zamowic maksymalnie 20 porcji tego dania" << endl;
				blad = true;
			}
			else
			{
				blad = false;
			}
			} while (blad);

			if (dodaj_do_tablicy(tablica_zamowienia, id, porcje))
			{
				cout << "Pomyslnie dodano danie do zamowienia " << endl;
			}
			
			break;
		}
		case 2:
		{
			menu_lista();
		}
		
		case 3:
		{
			cout << endl;
			wyswietl_zamowienia_z_tablicy(tablica_zamowienia);
			break;
		}
		case 4:
		{
			cout << endl;
			wyswietl_zamowienia_z_tablicy(tablica_zamowienia);
			do
			{
				cout << "Ktore danie chcesz usunac?" << endl;
				id = kontrola_liczby();
			} while (!(czy_jest_dodane(tablica_zamowienia, id)));

			cout << "Ile porcji usunac?" << endl;
			porcje = kontrola_liczby();
			usun_z_tablicy(tablica_zamowienia, id, porcje);
			break;
		}
		case 5:
		{
			do
			{
				cout << "czy anulowac?" << endl;
				cout << "1.Tak 2.Nie" << endl;
				wybor = kontrola_liczby();
				if (wybor == 1) 
				{ 
					wyzeruj_tablice(tablica_zamowienia); 
					cout << "Pomyslnie anulowano zamowienie" << endl;
				}
				
			} while (wybor != 1 && wybor != 2);
			break;

		}
		case 6:
		{
			cout << "----------------" << endl;
			cout << "ZYCZYMY SMACZNEGO" << endl;
			cout << "----------------" << endl;
			break;
		}
		
		} 
	} while (wybor !=6);
};

void menu_dodaj(int tablica_zamowienia[20][2])
{
	/*ifstream f("menu.json");
	cout << "Wybierz danie" << endl;
	int id = kontrola_liczby();
	string licznik[21] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20" };
	json data = json::parse(f);
	f.close();
	auto m = data.at("danie" + licznik[id]).get<ns::meal_m>();
	cout << "Nazwa: " << m.name << endl;
	cout << "Rodzaj: " << m.type << endl;
	cout << "Cena: " << m.price << endl;
	cout << "Czy chcesz dodac to danie za: " << m.price << "?" << endl;
	cout << "1.Tak 2.Nie " << endl;
	int wybor = kontrola_liczby();
	if (wybor == 1)
	{
		cout << "Ile porcji?" << endl;
		int porcje = kontrola_liczby();
		double suma = porcje * m.price;
		double razem=0;
		cout << "Razem: " << suma << endl;
		//cout << "Czy zatwierdzic?" << endl;
		//cout << "1.Tak 2.Nie " << endl;
		wybor = kontrola_liczby();
		if (wybor == 1)
		{
			dodaj_do_tablicy(tablica_zamowienia, id, porcje);
			paragon_pozycja(m.name, m.price, porcje, suma);
			cout << "----------------" << endl;
			cout << "dodano: " << m.name << " " << "Cena: " << m.price << " " << "Porcje: " << " " << porcje << endl;
			cout << "----------------" << endl;
			cout << "Suma: " << suma << endl;
			cout << "----------------" << endl;

		}
	}*/
};
