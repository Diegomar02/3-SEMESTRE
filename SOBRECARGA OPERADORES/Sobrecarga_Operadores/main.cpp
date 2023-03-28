#include <iostream>
using namespace std;

class Ejemplo{
    public:
        Ejemplo();
        Ejemplo(int x, int y);
        ~Ejemplo();
        void Funcion1(int x1,int y1);
        void Funcion2(int x,int y);
        void Mostrar();
        Ejemplo operator+ ( Ejemplo );
        Ejemplo operator- ( Ejemplo );
        Ejemplo operator* ( Ejemplo );
        Ejemplo operator+ ( int );
        Ejemplo operator* ( int );
        Ejemplo operator++ ();
        Ejemplo operator-- ();
        //void set_X(int x){ this->x = x;}
        //void set_Y(int y){ this->y = y;}
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
    cout << endl <<  "constructor con datos ..." << endl ;
    Mostrar();
}

Ejemplo::~Ejemplo(){
   // cout << "adios" << endl;
   // Mostrar();
}

Ejemplo Ejemplo::operator+ (Ejemplo obj)
{
    Ejemplo temp;
    temp.x = this->x + obj.x;
    temp.y = this->y + obj.y;
    return temp;
}
Ejemplo Ejemplo::operator- (Ejemplo obj)
{
    Ejemplo temp;
    temp.x = this->x - obj.x;
    temp.y = this->y - obj.y;
    return temp;
}
Ejemplo Ejemplo::operator* (Ejemplo obj)
{
    Ejemplo temp;
    temp.x = this->x * obj.x;
    temp.y = this->y * obj.y;
    return temp;
}
Ejemplo Ejemplo::operator+ (int x)
{
    Ejemplo temp;
    temp.x = this->x + x;
    temp.y = this->y + x;
    return temp;
}
Ejemplo Ejemplo::operator* (int x)
{
    Ejemplo temp;
    temp.x = this->x * x;
    temp.y = this->y * x;
    return temp;
}
Ejemplo Ejemplo::operator++ ()
{
    this->x = this->x + 1;
    this->y = this->y + 1;
    //++this->x; // incremento prefijo
    //++this->y;
    return *this;
}
Ejemplo Ejemplo::operator-- ()
{
    //this->x = this->x - 1;
    //this->y = this->y - 1;
    --this->x; // incremento prefijo
    --this->y;
    return *this;
}

int main(){
    int x;
    Ejemplo dato;
    Ejemplo dato2(28,2);
    Ejemplo dato3(4,3);

    cout<< "Suma de los objetos:" << endl;
    dato = dato2 + dato3;
    dato.Mostrar();

    cout<< "Resta de los objetos:" << endl;
    dato = dato2 - dato3;
    dato.Mostrar();

    cout<< "Multiplicacion de los objetos:" << endl;
    dato = dato2 * dato3;
    dato.Mostrar();

    cout<< "Suma a un objeto :" << endl;
    dato = dato2 + 10;
    dato.Mostrar();

    cout<< "Multiplicar a un objeto :" << endl;
    dato = dato3 * 9;
    dato.Mostrar();

    cout<< "++ a un objeto :" << endl;
    ++dato;
    dato.Mostrar();

    cout<< "++ a un objeto :" << endl;
    --dato;
    dato.Mostrar();
    
    /*
    if(dato2 == dato3 ){
        cout << "los datos de los objeto son iguales ";
    }else{
        cout << "los datos de los objeto NO son iguales ";
    }
    */
    cout << endl << "fin" << endl;
}

