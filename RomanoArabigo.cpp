#include <iostream>

using namespace std;

int romanToArabic(char romanNumber) {
  switch (romanNumber) {
    case 'I':
      return 1;
      break;
    case 'V':
      return 5;
      break;
    case 'X':
      return 10;
      break;
    case 'L':
      return 50;
      break;
    case 'C':
      return 100;
      break;
    case 'D':
      return 500;
      break;
    case 'M':
      return 1000;
      break;
    default:
      return 0;
      break;
    }
}

int main() {
  string romanNumber;
  int arabicNumber[romanNumber.length()];
  int finalNumber;
  bool correctNumber = false;
  int repets; 

  while(!correctNumber) {
    cout << "\n\nNumero romano: ";
    cin >> romanNumber;
    repets = 1;

    for(int i = 0; i < romanNumber.length(); i ++) {
      arabicNumber[i] = romanToArabic(romanNumber[i]);

      if(arabicNumber[i] == 0) {
        cout << "Numero invalido: " << romanNumber[i] << endl;
        break;
      }

      if(i > 0) {
        if(arabicNumber[i] == arabicNumber[i - 1]) {
          repets ++;
        }
        
        if(repets > 3) {
          cout << "Numero invalido" << endl;
          cout << "Mismo numero mas de 3 veces: ";
          for(int j = 0; j <= 3; j ++) {
            cout << romanNumber[i];
          }
          cout << endl;
          break;
        }

        if(arabicNumber[i] > arabicNumber[i - 1] && (arabicNumber[i - 1] == 5 || arabicNumber[i - 1] == 50 || arabicNumber[i - 1] == 500)) {
          cout << "Numero invalido" << endl;
          cout << romanNumber[i - 1] << " no puede preceder a un numero mayor: ";
          cout << romanNumber[i - 1] << romanNumber[i] << endl;
          break;
        }

        if(arabicNumber[i] > arabicNumber [i - 1] && repets > 1) {
          cout << "Numero invalido" << endl;
          cout << "Un numero precede mas de una vez a otro mayor: ";
          for(int j = 0; j < repets; j ++) {
            cout << romanNumber[i - 1];
          }
          cout << romanNumber[i] << endl;
          break;
        }

        if(arabicNumber[i] / arabicNumber[i - 1] > 10) {
          cout << "Numero invalido" << endl;
          cout << romanNumber[i -1] << " no puede preceder a " << romanNumber[i] << endl;
          break;
        }

        if(arabicNumber[i] != arabicNumber[i - 1]) {
          repets = 1;
        }
      }

      if(i == romanNumber.length() - 1) {
        correctNumber = true;
      }
    }
  }

  for(int i = romanNumber.length() - 1; i >= 0; i --) {
    if(i == romanNumber.length() - 1) {
      finalNumber = arabicNumber[i];
    }
    else {
      if(arabicNumber[i] >= arabicNumber[i + 1]) {
        finalNumber += arabicNumber[i];
      }
      else {
        finalNumber -= arabicNumber[i];
      }
    }
  }
  
  cout << "Numero arabigo: " << finalNumber << endl << endl;
}