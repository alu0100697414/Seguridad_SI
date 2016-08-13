#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "funciones.hpp"
#include "punto.hpp"

using namespace std;

int main(void){

  system("clear");

  bool menu = true;

  while (menu) {
    int opc;

    cout << endl;
    cout << "PRACTICA 8: CIFRADO ELGAMAL ELIPTICO." << endl << endl;
    cout << endl;
    cout << "Escoja una de las siguientes opciones del menu:" << endl;
    cout << "1: Cifrado con mensaje en forma de punto." << endl;
    cout << "2: Cifrado con mensaje en forma de numero." << endl;
    cout << "3: Descifrado." << endl;
    cout << "4: Salir." << endl;
    cout << endl;
    cout << "Introduzca la opcion que desee: ";
    cin >> opc;
    cout << "" << endl;

    switch (opc){

      case 1:
      {
        system("clear");

        // Introducimos el numero p y comprobamos si es primo.
        long int p;
        introducir_numero_primo(p);


        // Introducimos los valores de a y b, y comprobamos si pertenecen a una curva eliptica.
        int a, b;
        introducir_ab(a,b,p);


        // Introducimos el punto base.
        cout << "Punto base:" << endl;

        Punto P;
        P.from_stream(cin);

        cout << endl;

        // Introducimos dB
        int dB;
        introducir_dB(dB,p);

        // Ahora hallamos la clave publica dB*P.
        Punto dBP=P;
        int dB_exp=potencia(dB);
        int cont = 0;
        int lambda = 0;

        while(cont<dB_exp){
          cont++;
          lambda= dBP.landa(dBP.get_x(),dBP.get_y(),P.get_x(),P.get_y(),a,p);
          dBP= dBP.suma_puntos(dBP.get_x(),dBP.get_y(),P.get_x(),P.get_y(),lambda,p);
        }


        // Ahora introducimos el mensaje original en forma de punto qM.
        cout << "Mensaje original en forma de punto:" << endl;
        Punto qM;

        qM.from_stream(cin);

        cout << endl;

        // Introducimos el valor de M.
        int M;
        introducir_M(M);

        // Introducimos el valor de aA.
        int aA;
        introducir_aA(aA);
        cout << endl;

        // Calculamos los puntos de la curva E y los mostramos por pantalla.
        int ecuacion[p];
        int y_cuadrado[p];

        vector<Punto> puntos;

        for(int i=0; i<p; i++){
          ecuacion[i] = (i*i*i + a*i + b)%p;
          y_cuadrado[i] = (i*i)%p;
        }

        for(int i=0; i<p; i++){
          for(int j=0; j<p; j++){
            if(ecuacion[i] == y_cuadrado[j]){
              puntos.push_back(Punto(i, j));
            }
          }
        }

        cout << "RESULTADOS:" << endl;
        cout << "Los puntos de la curva E son: ";
        for(int i=0; i<puntos.size(); i++){
          puntos[i].to_stream(cout);
        }
        cout << endl << endl;

        // Mostramos la clave publica por pantalla
        cout << "La clave publica dB*P es: ";
        dBP.to_stream(cout);

        cout << endl << endl;

        // Calculamos h y lo mostramos por pantalla.
        int h = calcular_h(p,M);

        cout << "h: " << h << endl << endl;

        // Cifrado.
        Punto ppunto = dBP;

        lambda = 0;
        cont = 0;
        int aA_exp = potencia(aA);

        while(cont<aA_exp){
          cont++;
          lambda= ppunto.landa(ppunto.get_x(),ppunto.get_y(),dBP.get_x(),dBP.get_y(),a,p);
          ppunto= ppunto.suma_puntos(ppunto.get_x(),ppunto.get_y(),dBP.get_x(),dBP.get_y(),lambda,p);
        }

        lambda= ppunto.landa(ppunto.get_x(),ppunto.get_y(),qM.get_x(),qM.get_y(),a,p);
        ppunto= ppunto.suma_puntos(ppunto.get_x(),ppunto.get_y(),qM.get_x(),qM.get_y(),lambda,p);

        cout << "Primer punto del mensaje cifrado: ";
        ppunto.to_stream(cout);
        cout << endl;

        // Segundo punto del cifrado
        Punto spunto = P;

        lambda = 0;
        cont = 0;

        while(cont<aA_exp){
          cont++;
          lambda= spunto.landa(spunto.get_x(),spunto.get_y(),P.get_x(),P.get_y(),a,p);
          spunto= spunto.suma_puntos(spunto.get_x(),spunto.get_y(),P.get_x(),P.get_y(),lambda,p);
        }

        cout << "Segundo punto del mensaje cifrado: ";
        spunto.to_stream(cout);
        cout << endl;
      }
      break;

      case 2:
      {
        system("clear");

        // Introducimos el numero p y comprobamos si es primo.
        long int p;
        introducir_numero_primo(p);

        // Introducimos los valores de a y b, y comprobamos si pertenecen a una curva eliptica.
        int a, b;
        introducir_ab(a,b,p);

        // Introducimos el punto base.
        cout << "Punto base:" << endl;

        Punto P;
        P.from_stream(cin);

        cout << endl;

        // Introducimos dB
        int dB;
        introducir_dB(dB,p);

        // Ahora hallamos la clave publica dB*P.
        Punto dBP=P;
        int dB_exp=potencia(dB);
        int cont = 0;
        int lambda = 0;

        while(cont<dB_exp){
          cont++;
          lambda= dBP.landa(dBP.get_x(),dBP.get_y(),P.get_x(),P.get_y(),a,p);
          dBP= dBP.suma_puntos(dBP.get_x(),dBP.get_y(),P.get_x(),P.get_y(),lambda,p);
        }

        // Introducimos el valor de m.
        int M;
        introducir_M(M);

        // Ahora introducimos el mensaje original en forma de entero.
        int m;
        introducir_m(M,m);

        // Introducimos el valor de aA.
        int aA;
        introducir_aA(aA);
        cout << endl;

        // Calculamos los puntos de la curva E y los mostramos por pantalla.
        int ecuacion[p];
        int y_cuadrado[p];

        vector<Punto> puntos;

        for(int i=0; i<p; i++){
          ecuacion[i] = (i*i*i + a*i + b)%p;
          y_cuadrado[i] = (i*i)%p;
        }

        for(int i=0; i<p; i++){
          for(int j=0; j<p; j++){
            if(ecuacion[i] == y_cuadrado[j]){
              puntos.push_back(Punto(i, j));
            }
          }
        }

        // Calculamos h
        int h = calcular_h(p,M);

        // Pasamos m a punto
        bool parada = false;
        Punto qM;

        int i=0;
        while(i<p && !parada){
          int j=0;
          while(j<p && !parada){
            if((m*h + j)==puntos[i].get_x()){
              parada=true;
              qM.set_x(puntos[i].get_x());
              qM.set_y(puntos[i].get_y());
            }
            j++;
          }
          i++;
        }

        cout << "RESULTADOS:" << endl;
        cout << "Los puntos de la curva E son: ";
        for(int i=0; i<puntos.size(); i++){
          puntos[i].to_stream(cout);
        }
        cout << endl << endl;

        cout << "El mensaje m en forma de punto es: ";
        qM.to_stream(cout);
        cout << endl << endl;

        // Mostramos la clave publica por pantalla
        cout << "La clave publica dB*P es: ";
        dBP.to_stream(cout);

        cout << endl << endl;

        // Cifrado.
        Punto ppunto = dBP;

        lambda = 0;
        cont = 0;
        int aA_exp = potencia(aA);

        while(cont<aA_exp){
          cont++;
          lambda= ppunto.landa(ppunto.get_x(),ppunto.get_y(),dBP.get_x(),dBP.get_y(),a,p);
          ppunto= ppunto.suma_puntos(ppunto.get_x(),ppunto.get_y(),dBP.get_x(),dBP.get_y(),lambda,p);
        }

        lambda= ppunto.landa(ppunto.get_x(),ppunto.get_y(),qM.get_x(),qM.get_y(),a,p);
        ppunto= ppunto.suma_puntos(ppunto.get_x(),ppunto.get_y(),qM.get_x(),qM.get_y(),lambda,p);

        cout << "Primer punto del mensaje cifrado: ";
        ppunto.to_stream(cout);
        cout << endl;

        // Segundo punto del cifrado
        Punto spunto = P;

        lambda = 0;
        cont = 0;

        while(cont<aA_exp){
          cont++;
          lambda= spunto.landa(spunto.get_x(),spunto.get_y(),P.get_x(),P.get_y(),a,p);
          spunto= spunto.suma_puntos(spunto.get_x(),spunto.get_y(),P.get_x(),P.get_y(),lambda,p);
        }

        cout << "Segundo punto del mensaje cifrado: ";
        spunto.to_stream(cout);
        cout << endl;
      }
      break;

      case 3:
      {
        // Introducimos el numero p y comprobamos si es primo.
        long int p;
        introducir_numero_primo(p);

        // Introducimos los valores de a y b, y comprobamos si pertenecen a una curva eliptica.
        int a, b;
        introducir_ab(a,b,p);

        // Introducimos el valor de aA.
        int dB;
        introducir_dB(dB,p);

        // Introducimos el valor de m.
        int M;
        introducir_M(M);

        // Calculamos h
        int h = calcular_h(p,M);

        // Introducimos el mensaje cifrado
        Punto ppunto, spunto;

        cout << "Introduzca el primer punto del mensaje cifrado:" << endl;
        ppunto.from_stream(cin);

        cout << endl;

        cout << "Introduzca el segundo punto del mensaje cifrado:" << endl;
        spunto.from_stream(cin);

        spunto.set_y(-(spunto.get_y())); // Niego la b del segundo punto para le descifrado

        // Descifrado.
        Punto aux = spunto;

        int lambda = 0;
        int cont = 0;
        int dB_exp = potencia(dB);

        while(cont<dB_exp){
          cont++;
          lambda= aux.landa(aux.get_x(),aux.get_y(),spunto.get_x(),spunto.get_y(),a,p);
          aux= aux.suma_puntos(aux.get_x(),aux.get_y(),spunto.get_x(),spunto.get_y(),lambda,p);
        }

        lambda= aux.landa(ppunto.get_x(),ppunto.get_y(),aux.get_x(),aux.get_y(),a,p);
        aux= aux.suma_puntos(ppunto.get_x(),ppunto.get_y(),aux.get_x(),aux.get_y(),lambda,p);

        cout << endl << "Mensaje descifrado: ";
        aux.to_stream(cout);
        cout << endl;

        cout << endl << "m: " << aux.get_x()/h << endl;
      }
      break;

      case 4:
      system("clear");
      menu = false;
      break;

    }

  }

  return 0;
}
