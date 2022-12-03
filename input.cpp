#include <iostream>
#include <string>
#include "paragon.h"

using namespace std;

bool sprawdz_numer(string str) {
    if (str == "exit")
    {
        exit(0);   
    }
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}

string input(string str)
{
    sprawdz_numer(str);
    return str;
}