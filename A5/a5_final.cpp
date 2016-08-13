#include <iostream>

using namespace std;

int main(void){

  int R1[19],R2[22],R3[23];

  // Inicializamos la clave
  int clave[64]={1,0,0,1,0,0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,0,0,0,0,1,1,1,1};

  int k=0,reloj,z,mayoria;

  // Inicializamos R1
  for(int i=18;i>=0;i--){
    R1[i]=clave[k];
    k++;
  }

  // Inicializamos R2
  for(int i=21;i>=0;i--){
    R2[i]=clave[k];
    k++;
  }

  // Inicializamos R3
  for(int i=22;i>=0;i--){
    R3[i]=clave[k];
    k++;
  }

  reloj=0;
  cout << "Introduzca el valor que desee de clock: ";
  cin >> reloj;
  cout << endl;

  int cifrado[reloj];

  for(int c=0;c<reloj;c++){

    // Calculo el valor de la funcion mayoria
    mayoria=0;
    mayoria=(R1[8]*R2[10]) xor (R1[8]*R3[10]) xor (R2[10]*R3[10]);

    cout << "Mayoria[" << c+1 << "]= " << mayoria << endl;

    // Calculo el valor de z
    z=(R1[18]) xor (R2[21]) xor (R3[22]);
    cifrado[c]=z;

    cout << "z(t)="<< z << endl;

    cout << "Las cadenas que desplazamos son: ";

    // Muevo los LFSR necesarios
    // R1
    if(R1[8]==mayoria){

      cout << "R1 ";

      int ec1=(R1[13]) xor (R1[16]) xor (R1[17]) xor (R1[18]);

      for(int i=18;i>0;i--){
        R1[i]=R1[i-1];
      }
      R1[0]=ec1;
    }


    // R2
    if(R2[10]==mayoria){

      cout << "R2 ";

      int ec2=(R2[20]) xor (R2[21]);

      for(int i=21;i>0;i--){
        R2[i]=R2[i-1];
      }
      R2[0]=ec2;
    }


    // R3
    if(R3[10]==mayoria){

      cout << "R3 ";

      int ec3=(R3[7]) xor (R3[20]) xor (R3[21]) xor (R3[22]);

      for(int i=22;i>0;i--){
        R3[i]=R3[i-1];
      }
      R3[0]=ec3;
    }

    cout << endl << endl;

  }

  cout << "Cadena resultante: [";
  for(int i=0;i<reloj-1;i++){
    cout << cifrado[i] << " ";
  }
  cout << cifrado[reloj-1] << "]" << endl;

}
