#include <iostream>
#include <fstream>
#include <string>
#include "restauracja_dane.h"

using namespace std;

void dane_restauracji()
{
    fstream file;
    file.open("restauracja.txt", ios::in);
    if (file.is_open())
    {
        string tp;
        while (getline(file, tp)) 
        { 
            cout << tp << endl; 
        }
        file.close();
    }
    
}