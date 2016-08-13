#include <iostream>
#include <vector>

using namespace std;

// Pedimos la semilla por pantalla
void insertar_semilla(vector<int> &clave){

  int tam=0;

  cout << "Introduzca el tamaño de la semilla: ";
  cin >> tam;
  cout << endl;

  clave.resize(tam);

  for(unsigned i=0; i<clave.size(); i++){
    cout << "Introduzca la posicion " << i << " de la semilla: ";
    cin >> clave[i];
  }

  cout << endl;
}

// Pedimos la cadena por pantalla
void insertar_cadena(vector<int> &cadena){

  int tam=0;

  cout << "Introduzca el tamaño de la cadena: ";
  cin >> tam;
  cout << endl;

  cadena.resize(tam);

  for(unsigned i=0; i<cadena.size(); i++){
    cout << "Introduzca la posicion " << i << " de la cadena: ";
    cin >> cadena[i];
  }

  cout << endl;
}

// Pedimos la cadena cifrada por pantalla
void insertar_cadena_cifrada(vector<int> &cadena_cifrada){

  int tam=0;

  cout << "Introduzca el tamaño de la cadena cifrada: ";
  cin >> tam;
  cout << endl;

  cadena_cifrada.resize(tam);

  for(unsigned i=0; i<cadena_cifrada.size(); i++){
    cout << "Introduzca la posicion " << i << " de la cadena cifrada: ";
    cin >> cadena_cifrada[i];
  }

  cout << endl;
}


// Inicializamos los vectores S y K y KSA
void ksa(vector<int>&K, vector<int>&S, vector<int>clave){

  S.resize(256);
  K.resize(256);

  // Inicializamos los vectores S y K con sus valores correspondientes
  for (unsigned i=0; i<S.size(); i++){
    S[i]=i;
    K[i]=clave[i % clave.size()];
  }

  int j=0;

  // Hallamos la posicion j y desordenamos el vector S
  for (unsigned i = 0; i < S.size(); i++){
    j = (j + S[i] + K[i]) % 256;
    swap(S[i],S[j]);
  }
}

// PRGA cifrado
void prga(vector<int> S, vector<int> cadena, vector<int> &cadena_cifrada){

  int i = 0;
  int j = 0;
  int t = 0;

  for (unsigned k = 0; k < cadena.size(); k++){
    i = (i + 1) % 256;
    j = (j + S[i]) % 256;
    swap(S[i],S[j]);

    // por cada posicion se hace una xor para codificar usando t y cadena.
    t = (S[i] + S[j]) % 256;
    cadena_cifrada.push_back(S[t] xor cadena[k]);
  }
}


// Hallamos el numero en binario
void binario(int n){

  if (n !=0){
    binario(n/2);
    cout << n % 2;
  }
}


// Funcion para convertir
void paso_a_binario (vector <int> cadena_cifrada){

  cout << "El mensaje cifrado es:  "  << endl << endl;

  for (unsigned i = 0 ; i < cadena_cifrada.size(); i++){
    cout << "C[" << i << "] = " << cadena_cifrada[i] << "  ";
    cout << "Binario: ";
    binario(cadena_cifrada[i]);
    cout << endl;
  }

  cout << endl;
}

// Funcion para convertir
void paso_a_binario_descifrado (vector <int> cadena_cifrada){

  cout << "El mensaje descifrado es:  "  << endl << endl;

  for (unsigned i = 0 ; i < cadena_cifrada.size(); i++){
    cout << "C[" << i << "] = " << cadena_cifrada[i] << "  ";
    cout << "Binario: ";
    binario(cadena_cifrada[i]);
    cout << endl;
  }

  cout << endl;
}


int main(){

  vector <int> cadena;  // Cadena
  vector <int> clave;  // Clave
  vector <int> cadena_cifrada;  // Cadena cifrada
  vector <int> K;  // K
  vector <int> S;  // S

  cout << "--------------------------------------------" << endl;
  cout << "Practica RC4 - Jose Angel Concepcion Sanchez" << endl;
  cout << "--------------------------------------------" << endl;

  int opc=0;
  bool in=true;

  while (in){

  cout << "Elija una de las siguientes opciones:" << endl;
  cout << "1. Cifrado." << endl;
  cout << "2. Descifrado." << endl;
  cout << "3. Salir." << endl;
  cout << "Introduzca la opcion deseada: ";

  cin >> opc;

    switch(opc){

      case 1:
        insertar_semilla(clave); // Conseguimos la clave

        insertar_cadena(cadena);  // Conseguimos el mensaje

        ksa(K,S,clave); // KSA

        prga(S,cadena,cadena_cifrada);  // PRGA

        paso_a_binario(cadena_cifrada);  // Se pasa a binario

        cadena.clear();
        cadena_cifrada.clear();
        clave.clear();
        K.clear();
        S.clear();
      break;

      case 2:
        insertar_semilla(clave); // Conseguimos la clave

        insertar_cadena_cifrada(cadena_cifrada);  // Conseguimos el mensaje cifrado

        ksa(K,S,clave); // KSA

        prga(S,cadena_cifrada,cadena);  // PRGA

        paso_a_binario_descifrado(cadena);  // Se pasa a binario

        cadena.clear();
        cadena_cifrada.clear();
        clave.clear();
        K.clear();
        S.clear();
      break;

      case 3:
        in=false;
      break;
    }
  }

  return 0;
}
