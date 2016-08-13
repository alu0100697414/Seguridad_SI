/* Hecha por Jose Angel Concepcion Sanchez (alu0100697414) */

#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

void Cifrar(void){
  int tam_palabra,tam_clave,i,j,k,A[64],B[64],C[64];
  int cont=0;
  char palabra[64],clave[64],res[64];

  cout << "Ha elegido cifrar mediante Vigenere sin la ñ." << endl;
  cout << "Introduzca la palabra o el texto a cifrar sin espacios y en mayusculas: ";
  cin >> palabra;
  cout << "" << endl;
  cout << "Introduzca la clave para cifrar en mayusculas: ";
  cin >> clave;
  cout << "" << endl;

  tam_palabra=strlen(palabra);  // strlen devuelve el tamaño de la cadena
  tam_clave=strlen(clave); // Tamaño de la clave

  if(tam_palabra<=64) {

    cout << "La palabra a cifrar es: " << palabra << endl;
    cout << "La clave para cifrar es: " << clave << endl;

    for(i=0;i<=tam_palabra-1;i++){
      A[i]=palabra[i]-65;
    }  // Pasa de mayusculas a numeros la cadena

    for(i=0;i<=tam_clave-1;i++){
      B[i]=clave[i]-65;
    }  // Pasa de mayusculas a numeros la cadena

    j=0;k=0;  // Inicializamos el contador de la clave

    for(i=0;i<tam_palabra;i++){
      if(j!=tam_clave){
        C[i]=(A[i]+B[j])%26;
        j++;
      }
      else{
        C[i]=(A[i]+A[k])%26;
        k++;
      }
    }  // Calculo de la equivalencia

    for(i=0;i<=tam_palabra-1;i++){
      res[i]=C[i]+65;
    }  // Paso a mayusculas de nuevo

    cout << "La palabra cifrada es: ";
    for(i=0;i<=tam_palabra-1;i++){
      cout << res[i];
    }  // Muestro por pantalla

    cout << "" << endl;
  }

  if(tam_palabra>=65)
    cout << "El tamaño de la palabra es demasiado grande." << endl;
}


void Descifrar(void){
  int tam_palabra,tam_clave,i,j,A[64],B[64],C[64];
  int cont=0;
  char palabra[64],clave[64],res[64];

  cout << "Ha elegido descifrar mediante Vigenere sin la ñ." << endl;
  cout << "Introduzca la palabra o el texto a descifrar sin espacios y en mayusculas: ";
  cin >> palabra;
  cout << "" << endl;
  cout << "Introduzca la clave para descifrar en mayusculas: ";
  cin >> clave;
  cout << "" << endl;

  tam_palabra=strlen(palabra);  // strlen devuelve el tamaño de la cadena
  tam_clave=strlen(clave); // Tamaño de la clave

  if(tam_palabra<=64) {

    cout << "La palabra a descifrar es: " << palabra << endl;
    cout << "La clave para descifrar es: " << clave << endl;

    for(i=0;i<=tam_palabra-1;i++){
      A[i]=palabra[i]-65;
    }  // Pasa de mayusculas a numeros la cadena

    for(i=0;i<=tam_clave-1;i++){
      B[i]=clave[i]-65;
    }  // Pasa de mayusculas a numeros la cadena

    j=0; // Inicializamos el contador de la clave

    for(i=0;i<=tam_palabra;i++){
      C[i]=((A[i]-B[j])+26)%26;
      j++;
      if(j==tam_clave)
        j=0;
    }  // Calculo de la equivalencia

    for(i=0;i<=tam_palabra-1;i++){
      res[i]=C[i]+65;
    }  // Paso a mayusculas de nuevo

    cout << "La palabra descifrada es: ";
    for(i=0;i<=tam_palabra-1;i++){
      cout << res[i];
    }  // Muestro por pantalla

    cout << "" << endl;
  }

  if(tam_palabra>=65)
    cout << "El tamaño de la palabra es demasiado grande." << endl;
}

void Cifrar_Con_Enie(void){
  int tam_palabra,tam_palabra_mod,tam_clave,i,j,A[64],B[64],C[64];
  int cont=0;
  char palabra[64],palabra_mod[64],clave[64],res[64];

  for (i=0; i<64; i++){
    palabra[i]='\0';
    palabra_mod[i]='\0';
    clave[i]='\0';
    res[i]='\0';
  }  // Inicializo todo a vacio para no tener basura

  cout << "Ha elegido cifrar mediante Vigenere con la ñ." << endl;
  cout << "Introduzca la palabra o el texto a cifrar sin espacios y en mayusculas: ";
  cin >> palabra;
  cout << "" << endl;
  cout << "Introduzca la clave para cifrar en mayusculas: ";
  cin >> clave;
  cout << "" << endl;

  tam_palabra=strlen(palabra);  // Tamaño de la cadena
  tam_clave=strlen(clave); // Tamaño de la clave

  j=0; i=0;
  while(j<tam_palabra){
    if(palabra[j]>=65 && palabra[j]<=90){
      palabra_mod[i]=palabra[j];
      i++;
      j++;

    } else {
      palabra_mod[i]=palabra[j];
      i++;
      j++;
      j++;
    }
  }  // Guardamos en palabra_mod la cadena sin una de las posiciones de la ñ

  tam_palabra_mod=strlen(palabra_mod);  // Tamaño de la cadena modificada

  if(tam_palabra<=64) {

    cout << "La palabra a cifrar es: " << palabra << endl;
    cout << "La clave para cifrar es: " << clave << endl;

    j=0;
    while(j<tam_palabra_mod){
      if(palabra_mod[j]>=65 && palabra_mod[j]<=78){
        A[j]=palabra_mod[j]-65;
        j++;
      }

      else if(palabra_mod[j]>=79 && palabra_mod[j]<=90){
        A[j]=palabra_mod[j]-64;
        j++;
      }

      else if(palabra_mod[j]=-91){
        A[j]=palabra_mod[j]+105;
        j++;
      }
    }  // Pasa de mayusculas a numeros la cadena

    for(i=0;i<=tam_clave-1;i++){
      if(clave[i]>=65 && clave[i]<=78)
        B[i]=clave[i]-65;

      else if(clave[i]>=79 && clave[i]<=90)
        B[i]=clave[i]-64;

      else if(clave[i]=-91)
        B[i]=clave[i]+105;
    }  // Pasa de mayusculas a numeros la clave

    j=0;
    for(i=0;i<=tam_palabra_mod;i++){
      C[i]=(A[i]+B[j])%27;
      j++;
      if(j==tam_clave)
        j=0;
    }  // Calculo de la equivalencia

    for(i=0;i<=tam_palabra_mod-1;i++){
      if(C[i]>=0 && C[i]<=13)
        res[i]=C[i]+65;

      else if(C[i]>=15 && C[i]<=26)
        res[i]=C[i]+64;

      else if(C[i]=14)
        res[i]=-91;
    }  // Paso a mayusculas de nuevo

    cout << "La palabra cifrada es: ";

    j=0;
    while (j<tam_palabra_mod){
      if(res[j]!=(-91)){
        cout << res[j];
        j++;

      } else {
        cout << "Ñ";
        j++;
      }
    } // Mostramos por pantalla la cadena cifrada

    cout << "" << endl;
  }

  if(tam_palabra>=65)
    cout << "El tamaño de la palabra es demasiado grande." << endl;
}

void Descifrar_Con_Enie(void){
  int tam_palabra,tam_palabra_mod,tam_clave,i,j,A[64],B[64],C[64];
  int cont=0;
  char palabra[64],palabra_mod[64],clave[64],res[64];

  for (i=0; i<64; i++){
    palabra[i]='\0';
    palabra_mod[i]='\0';
    clave[i]='\0';
    res[i]='\0';
  }  // Inicializo todo a vacio para no tener basura

  cout << "Ha elegido descifrar mediante Vigenere con la ñ." << endl;
  cout << "Introduzca la palabra o el texto a descifrar sin espacios y en mayusculas: ";
  cin >> palabra;
  cout << "" << endl;
  cout << "Introduzca la clave para descifrar en mayusculas: ";
  cin >> clave;
  cout << "" << endl;

  tam_palabra=strlen(palabra);  // strlen devuelve el tamaño de la cadena
  tam_clave=strlen(clave); // Tamaño de la clave

  j=0; i=0;
  while(j<tam_palabra){
    if(palabra[j]>=65 && palabra[j]<=90){
      palabra_mod[i]=palabra[j];
      i++;
      j++;

    } else {
      palabra_mod[i]=palabra[j];
      i++;
      j++;
      j++;
    }
  }  // Guardamos en palabra_mod la cadena sin una de las posiciones de la ñ

  tam_palabra_mod=strlen(palabra_mod);  // Tamaño de la cadena modificada

  if(tam_palabra<=64) {

    cout << "La palabra a descifrar es: " << palabra << endl;
    cout << "La clave para descifrar es: " << clave << endl;

    j=0;
    while(j<tam_palabra_mod){
      if(palabra_mod[j]>=65 && palabra_mod[j]<=78){
        A[j]=palabra_mod[j]-65;
        j++;
      }

      else if(palabra_mod[j]>=79 && palabra_mod[j]<=90){
        A[j]=palabra_mod[j]-64;
        j++;
      }

      else if(palabra_mod[j]=-91){
        A[j]=palabra_mod[j]+105;
        j++;
      }
    }  // Pasa de mayusculas a numeros la cadena

    for(i=0;i<=tam_clave-1;i++){
      if(clave[i]>=65 && clave[i]<=78)
        B[i]=clave[i]-65;

      else if(clave[i]>=79 && clave[i]<=90)
        B[i]=clave[i]-64;

      else if(clave[i]=-91)
        B[i]=clave[i]+105;
    }  // Pasa de mayusculas a numeros la clavea

    j=0; // Inicializamos el contador de la clave
    for(i=0;i<=tam_palabra_mod;i++){
      C[i]=((A[i]-B[j])+27)%27;
      j++;
      if(j==tam_clave)
        j=0;
    }  // Calculo de la equivalencia

    for(i=0;i<=tam_palabra_mod-1;i++){
      if(C[i]>=0 && C[i]<=13)
        res[i]=C[i]+65;

      else if(C[i]>=15 && C[i]<=26)
        res[i]=C[i]+64;

      else if(C[i]=14)
        res[i]=-91;
    }  // Paso a mayusculas de nuevo

    cout << "La palabra descifrada es: ";
    j=0;
    while (j<tam_palabra_mod){
      if(res[j]!=(-91)){
        cout << res[j];
        j++;

      } else {
        cout << "Ñ";
        j++;
      }
    } // Mostramos por pantalla la cadena descifrada

    cout << "" << endl;
  }

  if(tam_palabra>=65)
    cout << "El tamaño de la palabra es demasiado grande." << endl;
}


int main () {

  bool menu = true;

  while (menu) {
    int opc;

    cout << endl;
    cout << "Cifrado de Vigenere" << endl;
    cout << endl;
    cout << "Escoja una de las siguientes opciones del menu:" << endl;
    cout << "1: Cifrar texto sin la ñ." << endl;
    cout << "2: Descifrar texto sin la ñ." << endl;
    cout << "3: Cifrar texto con la ñ." << endl;
    cout << "4: Descifrar texto con la ñ." << endl;
    cout << "5: Salir del programa." << endl;
    cout << endl;
    cout << "Introduzca la opcion que desee: ";
    cin >> opc;
    cout << "" << endl;

    switch (opc){

      case 1:
      Cifrar();
      break;

      case 2:
      Descifrar();
      break;

      case 3:
      Cifrar_Con_Enie();
      break;

      case 4:
      Descifrar_Con_Enie();
      break;

      case 5:
      menu = false;
      break;

    }

  }

}
