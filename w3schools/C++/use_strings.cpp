#include <iostream>
#include <string>

using namespace std;

int main (void){

    string n1 = "Pedro ", n2 = "Augusto";

    string nt = n1 + n2;       //concatenar em C++ é T R A N Q U I L O

    cout << "O nome inteiro \"" << nt << "\"" << " mede " << nt.length() << "\n";

    for(int i=0; i<nt.size(); i++)
        cout << nt[i];
        cout << "\n";

    string full_name;

    cout << "Digite seu nome por completo: ";

    getline(cin,full_name);

    cout << full_name << "\n";

}