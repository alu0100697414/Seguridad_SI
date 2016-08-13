#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

// Funcion para comprobar si un numero pertenece a la potencia de dos.
bool comprobar_potencia(int x){

  return (x != 0) && ((x & (x - 1)) == 0);
}

int potencia(int x){
  int cont = 0;

  while(x!=1){
    x /= 2;
    cont ++;
  }

  return cont;
}

// Funcion para comprobar si un numero es primo.
int numero_primo(long int a){
  int cont=0;

  for(int i=1; i<=a; i++){
    if(a%i == 0)
      cont=cont+1;
  }

  if(cont == 2)
    return 1;
  else
    return 0;
}

// Comprueba si los puntos pertenecen una curva eliptica o no.
bool discriminante(int a, int b, long int p){

  if((4*a*a*a + 27*b*b) % p == 0)
    return false;

  else
    return true;
}

// Funcion para introducir el numero p y comprobar si es primo.
void introducir_numero_primo(long int& p){
  cout << "PRACTICA 8: CIFRADO ELGAMAL ELIPTICO." << endl << endl;
  cout << "Introduzca el valor de p (numero primo mayor que 3): ";
  cin >> p;

  while(numero_primo(p) != 1 || p<=3){
    cout << "Ha introducido un valor incorrecto." << endl;
    cout << "Introduzca el valor de p (numero primo mayor que 3): ";

    cin >> p;
  }

  cout << endl;
}

// Funcion para introducir los valores a y b y comprobar si pertenecen a la curva.
void introducir_ab(int& a, int& b, long int p){
  cout << "Introduzca el valor de a: ";
  cin >> a;
  cout << "Ahora, introduzca el valor de b: ";
  cin >> b;

  while(discriminante(a,b,p)==false){
    cout << "Error, los valores de a y b que ha introducido no pertenecen a una curva eliptica." << endl;
    cout << "Introduzca el valor de a: ";
    cin >> a;

    cout << "Ahora, introduzca el valor de b: ";
    cin >> b;
  }

  cout << endl;
}

// Se introduce la clave privada de Bob.
void introducir_dB(int& dB, long int p){
  cout << "Introduzca el valor de dB: ";
  cin >> dB;

  while(dB<0 || dB>p || !comprobar_potencia(dB)){
    cout << "Error, debe ser un entero potencia de 2 dentro de Zp." << endl;
    cout << "Introduzca el valor de dB: ";

    cin >> dB;
  }

  cout << endl;
}

// Introducimos el valor de M.
void introducir_M(int& M){
  cout << "Introduzca el valor de M: ";
  cin >> M;
  cout << endl;
}

// Introducimos el valor de aA.
void introducir_aA(int& aA){
  cout << "Introduzca el valor de aA (potencia de 2): ";
  cin >> aA;

  while(!comprobar_potencia(aA)){
    cout << "Error, aA tiene que ser potencia de 2" << endl;
    cout << "Introduzca el valor de aA (potencia de 2): ";
    cin >> aA;
  }
}

// Calculo del valor de h.
int calcular_h(long int p, int M){
  return p/M;
}

// Introducimos el valor del mensaje en forma de entero.
void introducir_m(int M, int& m){
  cout << "Mensaje original en forma de entero: ";
  cin >> m;

  while(m<=0 || m>M){
    cout << "Error, m debe cumplir que sea mayor que 0 y menor que M." << endl;
    cout << "Mensaje original en forma de entero: ";

    cin >> m;
  }
  cout << endl;
}
