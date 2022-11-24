#include <iostream>
#include <fstream>
using namespace std;

int paragon (int id,string typ, string name, string text, int cena) {
    ofstream myfile;
    myfile.open ("paragon.txt");
    myfile << "----------------------"<< endl;
    myfile << "ID: "<< id << " " << "Nazwa: " << name << " " << "Cena :" << cena << endl;
    myfile.close();
    return 0;
}

int main() 
{
    //*sample wczytywanie z 
    string name = "Śledź zagrycha";
    string text ="w zaprawie z selera naciowego";
    string typ = "przystawki";
    int cena = 3;
    int id= 0;
    cout<<"Wybierz numer dania:";
    cin >> id;
    //Tu będzie wybieranie po ID z pliku JSON
    if (id=1)
     {
        paragon(id,name,text,typ,cena);
     }
    	
    system("pause");
	return 0;
}