#include <iostream>
#include "json.hpp"
#include <fstream>
#include <string>

using namespace std;
using json = nlohmann::json;

namespace ns{
		struct meal_m {
			int id;
			std::string typ;
			std::string name;
			std::string text;;
		};


	void to_json(json &j, const meal_m &m) {
		j = json{ 
			{"id", m.id}, 
			{'typ', m.typ}, 
			{'name', m.name}, 
			{'text', m.text}
		};
	};

	void from_json(const json &j, meal_m &m) {
		j.at("id").get_to(m.id);
		j.at("typ").get_to(m.typ);
		j.at("name").get_to(m.name);
		j.at("text").get_to(m.text);
	};
}
	




int main() {
	std::ifstream f("menu.json");
	json data;
	f >> data;
	string licznik[20] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20" };
	int x = 0;
	for (int i = 0; i <= 20; i++) {
		auto m = data.at("danie"+licznik[x]).get<ns::meal_m>();
		cout << m.id << " " << m.name << " " << m.text << " " << m.typ << endl;
		x++;
	}
	return 0;
}