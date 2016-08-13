#include <iostream>

using namespace std;

class Punto {

  private:

    int x_;
    int y_;

  public:

    Punto(void);
    Punto(int x, int y);
    ~Punto(void);

    long int euclides_extendido(long int n1, long int n2);

    int landa(int x1, int y1, int x2, int y2, int a, int p);
    Punto suma_puntos(int x1, int y1, int x2, int y2, int landa, int p);

    virtual void to_stream(ostream& os);
    virtual void from_stream(istream& is);

    void set_x(int x);
    void set_y(int y);

    int get_x(void);
    int get_y(void);

};
