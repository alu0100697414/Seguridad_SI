#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

// Funcion para quitarle los espacios a la cadena
void quitar_espacios(char *linea){
 int i;
 int j;

 for (i = j = 0; linea[i] != '\0'; i++)
   if (linea[i] != ' ')
     linea[j++] = linea[i];
   linea[j] = '\0';
}


// Funcion de exponenciacion rapida
long int exponenciacion_rapida(long int x, long int n, long int mod){
  long int exp = 1;

  while(n != 0){
    if (n%2 != 0){  // Si es impar
      n = n-1;
      exp = (x*exp)%mod;
    }
    else {  // Si es par
      n = n/2;
      x = (x*x)%mod;
    }
  }

  return exp;
}

// Funcion Lehman Peralta
bool lehman_peralta(long int n){

  int elementos = 5;
  int val[5] = {2,3,5,7,11};

  for(int i=0; i<elementos; i++){
    if (n==val[i])
      return true;  // Es un valor primo

    if(n%val[i]==0)
      return false; // Es un numero compuesto, por lo que no es primo
  }

  srand(time(NULL));

  vector<int> V;
  int tam;

  if(n<101) // Si n es menor de 100, cogemos los valores hasta n
    tam = n;
  else
    tam = 100;

  for(int i=0; i<tam; i++){
    if(tam==n)  // Si n es menor de 100, cogemos todos los valores hasta n
      V.push_back(i+1);
    else
      V.push_back(rand() % (n-1)+1); // Numeros aleatorios entre 1 y (n-1)
  }

  int cont=0;

  for(int i=0; i<tam; i++){
    int r = exponenciacion_rapida(V[i], (n-1)/2, n);

    if(r==1)
      cont++;

    if((r!=(n-1)) && (r!=1))
      return false; // No es primo, no hace falta seguir mirando
  }

  if(cont == tam) // Si para toda i, el resultado es 1, no es primo
    return false;

  return true; //en otro caso, es primo
}

long int euclides_extendido(long int a, long int b){

  // Inicializamos los valores del dividendo y divisor asi como de z.
  vector<long int> x,z;

  if(a>b){
    x.push_back(a);
    x.push_back(b);
  }

  else {
    x.push_back(b);
    x.push_back(a);
  }

  z.push_back(0);
  z.push_back(1);

  int i=1;

  while((x[i-1]%x[i])!=0){  // Mientras el resto no de 0

    x.push_back(x[i-1] % x[i]);
    z.push_back(-(x[i-1] / x[i])*z[i]+z[i-1]);
    i++;
  }

  if (x[i]==1){
    return z[i];
  }

  return -1;
}

// Funcion para hallar el tamaño del bloque
int tam_bloque(long int n){

  int b = 26;
  int j = 0;
  int i = 0;

  while(pow(b, j) <= n){
      j = i;
      i++;
  }

  return j - 1;
}
