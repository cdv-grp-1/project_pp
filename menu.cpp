#include <iostream>
#include "json.hpp"
#include <fstream>
#include <string>
#include "paragon.h"
#include "kontrola_liczb.h"

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
	int x = 0;
	cout << "~~MENU~~" << endl;
	for (int i = 0; i <= 20; i++) {
		auto m = data.at("danie" + licznik[x]).get<ns::meal_m>();
		cout << "Pozycja nr. " << m.id << endl;
		cout << m.type << endl;
		cout << m.name << " " << m.text << endl;
		cout << "Skladniki: " << m.ingr << endl;
		cout << "Cena: " << m.price << endl;
		cout << "------------------" << endl;
		x++;
	}

};
string menu_nazwa(int id)

{
	ifstream f("menu.json");
	string licznik[21] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20" };
	json data = json::parse(f);
	f.close();
	auto m = data.at("danie" + licznik[id]).get<ns::meal_m>();
	cout << "Nazwa: " << m.name<<" Opis: " << m.type << " Cena: " << m.price;
	return m.name, m.type;
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

void menu_dodaj()
{
	ifstream f("menu.json");
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
		cout << "Czy zatwierdzic?" << endl;
		cout << "1.Tak 2.Nie " << endl;
		wybor = kontrola_liczby();
		if (wybor == 1)
		{
			paragon_pozycja(m.name, m.price, porcje, suma);
			cout << "----------------" << endl;
			cout << "dodano: " << m.name <<" " << "Cena: " << m.price << " " << "Porcje: " << " " << porcje << endl;
			cout << "----------------" << endl;
			cout << "Suma: " << suma << endl;
			cout << "----------------" << endl;
			cout << "1.Kontynuuj 2.To wszystko 3.Anuluj zamowienie 4.Wyjdz" << endl;
			wybor = kontrola_liczby();
			if (wybor == 1) 
				{ 
				menu_dodaj();
				
				}
			if (wybor == 2) 
				{
					cout << "----------------" << endl;
					cout << "ZYCZYMY SMACZNEGO" << endl;
					cout << "----------------" << endl;
				}
			if (wybor == 3) 
				{	wybor = kontrola_liczby(); 
					cout << "czy anulować?" << endl;
					cout << "1.Tak 2.Nie" << endl;
					if (wybor == 1) { cleanup(); }
					if (wybor == 2) { menu_dodaj(); }
				}
			if (wybor == 4) 
				{  

				}
		}
	}

};
