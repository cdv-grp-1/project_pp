#include <iostream>
#include "json.hpp"
#include <fstream>
#include <string>
#include "paragon.h"

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
	json data;
	f >> data;
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