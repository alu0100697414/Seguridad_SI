/* Hecha por Jose Angel Concepcion Sanchez (alu0100697414) */

#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "funciones.hpp"

using namespace std;

// MAIN
int main(void){
  system("clear");

  cout << "PRACTICA 7: CIFRADO RSA." << endl << endl;

  bool menu = true;

  while (menu) {
    int opc;

    cout << "Indique la opcion que desea ejecutar." << endl << endl;
    cout << "1. Cifrado del RSA." << endl;
    cout << "2. Descifrado del RSA." << endl;
    cout << "3. Salir." << endl << endl;
    cout << "Introduzca la opcion que desea elegir: ";
    cin >> opc;

    switch (opc){

      case 1:
      {
      // Introducir cadena
      cout << endl << "Introduzca el mensaje que desea cifrar: ";

      char mensaje[100];

      cin.ignore();

      fgets(mensaje, 100, stdin);
      quitar_espacios(mensaje);

      // Declaramos el alfabeto con el que vamos a trabajar
      char alfabeto[26];

      for(int i=0; i<26; i++){
        alfabeto[i] = i + 65;
      }

      long int p,q,o,d,n,e;

      // Introducimos el valor de p y comprobamos que es primo
      cout << "Introduzca el valor de p (numero primo): ";
      cin >> p;

      while(lehman_peralta(p)!=true){
        cout << "Error, p debe ser un numero primo, introduzca un nuevo valor." << endl;
        cout << "Introduzca el valor de p (numero primo): ";

        cin >> p;
      }


      // Introducimos el valor de q y comprobamos que es primo
      cout << "Introduzca el valor de q (numero primo): ";
      cin >> q;

      while(!lehman_peralta(q)){
        cout << "Error, q debe ser un numero primo, introduzca un nuevo valor." << endl;
        cout << "Introduzca el valor de q (numero primo): ";

        cin >> q;
      }


      // Calculamos o
      o = (p-1)*(q-1);


      // Introducimos el valor de d y comprobamos que es primo con o
      cout << "Introduzca el valor de d (coprimo de o): ";
      cin >> d;

      e = euclides_extendido(d,o);

      while(e == -1){
        cout << "Error, introduzca un valor para d que se ajuste a las especificaciones." << endl;
        cout << "Introduzca el valor de d (coprimo de o): ";

        cin >> d;

        e = euclides_extendido(d,o);
      }

      if(e<0)
        e += o;


      // Calculo de n
      n = p*q;


      // Cojo mensaje y lo paso a bloques de numeros
      vector<int> bloques;

      int tam_bloques = tam_bloque(n);

      cout << endl << "Tamaño de bloque: " << tam_bloques << endl;

      // Convertimos los bloques de letras en numeros
      int val = 0;
      for(unsigned int i=0; i<strlen(mensaje); i=i+tam_bloques){
        val = 0;
        for(int j=0; j<tam_bloques; j++){
          int letra = 0;
          for(int k=0; k<26; k++){
            if(mensaje[i+j] == alfabeto[k]){
              letra = k;
              break;
            }
          }
          val += letra * pow(26, tam_bloques - j - 1);
        }
        bloques.push_back(val);
      }

      // Muestra por pantalla los valores de los bloques antes de cifrarlos
      cout << endl << "Bloques numericos antes del cifrado: ";
      for(unsigned int i=0; i<bloques.size()-1; i++){
        cout << bloques[i] << " ";
      }
      cout << endl;


      // Cifrado de los bloques
      for(unsigned int i=0; i<bloques.size(); i++){
        bloques[i] = exponenciacion_rapida(bloques[i], e, n);
      }


      // Mostrando el valor de los bloques
      cout << endl << "Bloques numericos cifrados: ";
      for(unsigned int i=0; i<bloques.size()-1; i++){
        cout << bloques[i] << " ";
      }
      cout << endl << endl;


      cout << "o = " << o << endl;
      cout << "n = " << n << endl;
      cout << "e = " << e << endl;
      cout << endl;
      }
      break;

      case 2:
      {
      // Introducir cadena cifrada
      vector<int> bloques;
      char cadena_cifrada[100];

      cout << endl << "Introduzca el mensaje cifrado: ";
      cin >> cadena_cifrada;

      char* token;
      token = strtok(cadena_cifrada,","); // Divido la cadena en tokens

      while(token != NULL){
        bloques.push_back(atoi(token));
        token = strtok(NULL, ",");
      }

      // Declaramos el alfabeto con el que vamos a trabajar
      char alfabeto[26];

      for(int i=0; i<26; i++){
        alfabeto[i] = i + 65;
      }

      long int p,q,o,d,n,e;

      // Introducimos el valor de p y comprobamos que es primo
      cout << "Introduzca el valor de p (numero primo): ";
      cin >> p;

      while(lehman_peralta(p)!=true){
        cout << "Error, p debe ser un numero primo, introduzca un nuevo valor." << endl;
        cout << "Introduzca el valor de p (numero primo): ";

        cin >> p;
      }


      // Introducimos el valor de q y comprobamos que es primo
      cout << "Introduzca el valor de q (numero primo): ";
      cin >> q;

      while(!lehman_peralta(q)){
        cout << "Error, q debe ser un numero primo, introduzca un nuevo valor." << endl;
        cout << "Introduzca el valor de q (numero primo): ";

        cin >> q;
      }


      // Calculamos o
      o = (p-1)*(q-1);


      // Introducimos el valor de d y comprobamos que es primo con o
      cout << "Introduzca el valor de d (coprimo de o): ";
      cin >> d;

      e = euclides_extendido(d,o);

      while(e == -1){
        cout << "Error, introduzca un valor para d que se ajuste a las especificaciones." << endl;
        cout << "Introduzca el valor de d (coprimo de o): ";

        cin >> d;

        e = euclides_extendido(d,o);
      }

      if(e<0)
        e += o;


      // Calculo de n
      n = p*q;


      // Muestra por pantalla los valores de los bloques antes de cifrarlos
      cout << endl << "Bloques numericos antes del descifrado: ";
      for(unsigned int i=0; i<bloques.size(); i++){
        cout << bloques[i] << " ";
      }
      cout << endl;


      // Descifrado de los bloques
      for(unsigned int i=0; i<bloques.size(); i++){
        bloques[i] = exponenciacion_rapida(bloques[i], d, n);
      }


      // Mostrando el valor de los bloques
      cout << endl << "Bloques numericos despues del descifrado: ";
      for(unsigned int i=0; i<bloques.size(); i++){
        cout << bloques[i] << " ";
      }
      cout << endl << endl;

      // Calculo el tamaño de cada bloque
      int tam_bloques = tam_bloque(n);

      cout << "Tamaño del bloque: " << tam_bloques << endl << endl;

      vector<int> caracteres;

      // Paso a caracteres el valor de cada bloque
      for(int i=0; i<bloques.size(); i++){

        int val = bloques[i];
        int letra[tam_bloques];
        
        for(int j=0; j<tam_bloques; j++){
          letra[j] = val % 26;
          val = (val - letra[j]) / 26;
        }

        for(int j=tam_bloques-1; j>=0; j--)
          caracteres.push_back(letra[j]);

      }

      // Paso cada numero en su letra correspondiente
      char men_descifrado[caracteres.size()];
      for(int i = 0; i < caracteres.size(); i++)
        men_descifrado[i] = alfabeto[caracteres[i]];


      // Muestro el mensaje descifrado
      cout << "Mensaje descifrado: ";
      for(int i = 0; i < caracteres.size(); i++)
        cout << men_descifrado[i];

      cout << endl << endl;


      cout << "o = " << o << endl;
      cout << "n = " << n << endl;
      cout << "e = " << e << endl;
      cout << endl;
      }
      break;

      case 3:
      menu = false;
      break;

    }

  }

  return 0;
}
