#include <iostream>

using namespace std;

int main() {
int limite, numero1 = 0, numero2 = 1, suma = 0;

cout << "\nSerie de Fibonacci\n\n";
cout << "Cantidad de numeros: ";
cin >> limite;
cout << endl;

  for(int i = 1; i <= limite; i ++) {
    numero1 = numero2;
    numero2 = suma;
    suma = numero1 + numero2;
    cout << suma << " ";
  }

  cout << endl << endl;
}