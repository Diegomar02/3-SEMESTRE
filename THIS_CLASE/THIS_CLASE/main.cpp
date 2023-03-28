
#include <iostream>
using namespace std;

class Ejemplo{
    public:
        Ejemplo();
        Ejemplo(int x, int y);
        void Funcion1(int x1,int y1);
        void Funcion2(int x,int y);
        void Mostrar();
    private:
        int x,y;
};

void Ejemplo::Funcion1(int x1, int y1){
    x = x1;
    y = y1;
}

void Ejemplo::Funcion2(int x, int y){
    this->x = x;
    this->y = y;
}

void Ejemplo::Mostrar(){
    cout << "x : " << x << endl;
    cout << "y : " << y << endl << endl;
}

Ejemplo::Ejemplo(){
    x=y=0;
}

Ejemplo::Ejemplo(int x, int y){
    this->x = x;
    this->y = y;
    cout << endl << "constructor con datos ..." << endl ;
    Mostrar();
}

int main(){
    Ejemplo dato;
    dato.Mostrar();
    dato.Funcion1(1,2);
    dato.Mostrar();
    dato.Funcion2(8,5);
    dato.Mostrar();
    cout << " Caso del constructor con datos : "<< endl ;
    Ejemplo dato2(4,3);
    Ejemplo dato3(99,0);
}
