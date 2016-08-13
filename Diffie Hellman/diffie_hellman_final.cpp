/* Hecha por Jose Angel Concepcion Sanchez (alu0100697414) */

#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int exponenciacion_rapida(int x, int n, int mod){
  int exp = 1;

  while(n != 0){
    if (n%2 != 0){
      n = n-1;
      exp = (x*exp)%mod;
    }
    else {
      n = n/2;
      x = (x*x)%mod;
    }
  }

  return exp;
}

int main(void){

  int p,alfa,xA,xB;

  cout << "Introduzca el numero primo (p): ";
  cin >> p;

  cout << "Introduzca el valor de alfa (alfa < p): ";
  cin >> alfa;

  if (alfa>=p){
    while(alfa>=p){
      cout << "Por favor, alfa debe ser menor que p, introduzca otro numero." << endl;
      cout << "Introduzca el valor de alfa (alfa < p): ";
      cin >> alfa;
    }
  }

  cout << "Introduzca el valor del secreto Xa: ";
  cin >> xA;

  cout << "Introduzca el valor del secreto Xb: ";
  cin >> xB;

  int yA,yB,k;

  yA = exponenciacion_rapida(alfa,xA,p);
  yB = exponenciacion_rapida(alfa,xB,p);

  k = exponenciacion_rapida(yB,xA,p);

  cout << endl;
  cout << "El valor de yA resultante es: " << yA << endl;
  cout << "El valor de yB resultante es: " << yB << endl;
  cout << "El valor de k es: " << k << endl;

  return 0;
}
