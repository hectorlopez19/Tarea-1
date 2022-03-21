#include <iostream>

using namespace std;

int main() {
  int number;
  bool nCorrect = false;
  bool primeNumber;

  while(!nCorrect) {
    cout << "\nNumeros primos de 1 hasta n" << endl;
    cout << "n: ";
    cin >> number;
    
    if(number > 0) {
      nCorrect = true;
    }
    else {
      cout << "n invalido" << endl;
    }
  }
  
  for(int i = 1; i <= number; i ++) {
    primeNumber = true;
    for(int j = i - 1; j > 1; j --) {
      if(i % j == 0) {
        primeNumber = false;
        break;
      }
    }

    if(!primeNumber) {
      continue;
    }

    cout << i << " ";
  }
}