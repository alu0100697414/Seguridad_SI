/* Hecha por Jose Angel Concepcion Sanchez (alu0100697414) */

#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>

using namespace std;

// Funcion para comprobar si un numero es primo
int numero_primo(int a){
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

// Funcion para hallar el maximo comun divisor de dos numeros
int max_comun_div(int a, int b){
  if(a < b)
    return max_comun_div(b,a);

  if(b == 0)
    return a;

  return max_comun_div(b, a % b);
}


int main(void){

  int p,q,primo,N,S,mcd,it;
  long int V;

  // Pedimos p y comprobamos
  cout << "Introduzca el valor de p (numero primo): ";
  cin >> p;

  primo = numero_primo(p);

  if (primo != 1){
    while(primo != 1){
      cout << "Error, p debe ser un numero primo, introduzca un nuevo valor." << endl;
      cout << "Introduzca el valor de p (numero primo): ";
      cin >> p;

      primo = numero_primo(p);
    }
  }

  // Pedimos q y comprobamos
  cout << "Introduzca el valor de q (numero primo): ";
  cin >> q;

  primo = numero_primo(q);

  if (primo != 1){
    while(primo != 1){
      cout << "Error, q debe ser un numero primo, introduzca un nuevo valor." << endl;
      cout << "Introduzca el valor de q (numero primo): ";
      cin >> q;

      primo = numero_primo(q);
    }
  }

  // Hallamos el valor de N
  N=p*q;

  // Pedimos S y comprobamos
  cout << "Introduzca el valor secreto S (0<S<N && primo de N): ";
  cin >> S;

  mcd = max_comun_div(S,N);

  if (mcd != 1 || S<=0 || S>=N){
    while(mcd != 1 || S<=0 || S>=N){
      cout << "Error, introduzca un valor para S que se ajuste a las especificaciones." << endl;
      cout << "Introduzca el valor secreto S (0<S<N && primo de N): ";
      cin >> S;

      mcd = max_comun_div(S,N);
    }
  }

  // Calculamos V
  V=(S*S)%N;

  // Pedimos numero de iteraciones
  cout << "Introduzca el numero de iteraciones que desee: ";
  cin >> it;

  int x;
  long int y[it],a[it],res[it],e[it];

  for(int i=0; i<it; i++){

    // Compromiso secreto de A
    cout << "Introduzca el valor de X (0<x<N): ";
    cin >> x;

    if (x<=0 || x>=N){
      while(x<=0 || x>=N){
        cout << "Error, introduzca un valor para X que se ajuste a las especificaciones." << endl;
        cout << "Introduzca el valor de X (0<x<N): ";
        cin >> x;
      }
    }

    // Calculo de a
    a[i]=(x*x)%N;

    // Pedir e
    cout << "Introduzca el valor de e (0 || 1): ";
    cin >> e[i];

    if (e[i]<0 || e[i]>1){
      while(e[i]<0 || e[i]>1){
        cout << "Error, la variable e no puede tomar ese valor." << endl;
        cout << "Introduzca el valor de e (0 || 1): ";
        cin >> e[i];
      }
    }

    // Calculo de y
    if(e[i]==0)
      y[i]=x%N;
    else if(e[i]==1)
      y[i]=(x*S)%N;

    // Comprobacion de y
    if(e[i]==0){
      if((((y[i]*y[i])%N))==((a[i]%N)))
        res[i]=1;
      else
        res[i]=0;
    }

    if(e[i]==1){
      if((((y[i]*y[i])%N))==((a[i]*V)%N))
        res[i]=1;
      else
        res[i]=0;

    }

  }

  // Muestro resultados por pantalla
  cout << "N = " << N << endl;
  cout << "V = " << V << endl;

  for(int i=0; i<it; i++){
    cout << "Iteracion " << i+1 << ": a=" << a[i] << " y=" << y[i] << ". ";
    cout << "Comprobamos que ";

    if(e[i]==0)
      cout << "y^2 == a(mod N). ";
    else
      cout << "y^2 == a*v(mod N). ";

    if(res[i]==1)
      cout << "Se da por valida la iteracion." << endl;
    else
      cout << "No se da por valida la iteracion." << endl;
  }

  return 0;
}
