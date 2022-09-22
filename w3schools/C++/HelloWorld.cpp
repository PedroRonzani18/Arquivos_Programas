#include <iostream>

using namespace std;

int main() {
  
  int x=5, y=6, z=7, age;
  const int PI = 3;

  cout << "Digite sua idade: ";

  cin >> age;

  cout << "Eu tenho "<< age<< " anos e " << x+y+z << " neurônios\n";

  cout << "Verdadeiro: " << (2>1) << " Falso: " << (2<1) << "\n";
  
  return 0;
} 