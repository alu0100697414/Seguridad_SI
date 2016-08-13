#include <vector>

#include "punto.hpp"

Punto::Punto(void){

  x_ = 0;
  y_ = 0;
}

Punto::Punto(int x, int y){

  x_ = x;
  y_ = y;
}

Punto::~Punto(void){}

long int Punto::euclides_extendido(long int a, long int b){

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

  while((x[x.size()-1])!=0){  // Mientras el resto no de 0

    x.push_back(x[i-1] % x[i]);

    if( x[x.size() - 1] != 0){
      z.push_back(-(x[i-1] / x[i])*z[i]+z[i-1]);
    }

    i++;
  }

  // Hay que pasarlo a positivo si esta negativo.
  while(z[z.size()-1] < 0){
    z[z.size()-1] += x[0];
  }

  if(x[x.size()-2] == 1){
    return z[z.size()-1];
  }

  return -1;

}


int Punto::landa(int x1, int y1, int x2, int y2, int a, int p){

  int den, aux;

  // Si P==Q:
  if((x1==x2) && (y1==y2)){
    den = (2*y1)%p;

    aux=euclides_extendido(den,p);

    return (((3*x1*x1)+a)*aux)%p;
  }

  // En otro caso, P!=Q:
  else{
    den = (x2-x1)%p;

    aux=euclides_extendido(den,p);

    return ((y2-y1)*aux)%p;
  }
}

Punto Punto::suma_puntos(int x1, int y1, int x2, int y2, int landa, int p){

  Punto aux;

  // Si x1==x2 y -y1==y2, el valor que toma la suma es 0.
  if((x1==x2) && (-y1==y2)){
    aux.set_x(0);
    aux.set_y(0);
  }

  // En otro caso, calculamos los valores de (x3,y3).
  else {
    aux.set_x(((landa*landa) - x1) - x2);

    if(aux.get_x() >= 0){
        aux.get_x() %= p;
    }
    else{
        while(aux.get_x() < 0){
          aux.get_x() += p;
        }
    }

    aux.set_y((landa*(x1-aux.get_x()))-y1);

    if(aux.get_y() >= 0){
        aux.get_y() %= p;
    }
    else{
        while(aux.get_y() < 0){
            aux.get_y() += p;
        }
    }
  }

  return aux;
}



void Punto::set_x(int x){
  x_=x;
}

void Punto::set_y(int y){
  y_=y;
}

int Punto::get_x(void){
  return x_;
}

int Punto::get_y(void){
  return y_;
}

void Punto::to_stream(ostream& os){
  os << "(" << x_ << "," << y_ << ") ";
}

void Punto::from_stream(istream& is){
  cout << "Valor de la coordenada x: ";
  is >> x_;
  cout << "Valor de la coordenada y: ";
  is >> y_;
}
