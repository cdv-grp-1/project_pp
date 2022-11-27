#include <iostream>
#include <fstream>

using namespace std;

void paragon_single_item_add (string line) {
    fstream file;
    file.open("ticket.txt", ios::out);	
    file << line << endl;
}

