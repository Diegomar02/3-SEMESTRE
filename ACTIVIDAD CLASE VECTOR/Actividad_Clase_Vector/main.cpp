//1 constructor (default)
//1 constructor (reciba un vector) // usar this
//1 constructor (copia )// usar this
//mostrar
//sobrecargar el operador + (para vectores)  // usar this
//sobrecargar el operador - (para vectores)  // usar this
//sobrecargar el operador. * (para multiplicar el vector por un numero)  // usar this

//DIEGO MÁRQUEZ GOMEZ
//245119
//22 OCT 2021

#include <iostream>
using namespace std;

class constructor{
    public:
        constructor();
        constructor(int x);
        constructor( const constructor&);
        void mostrar();
        constructor operator+(constructor);
        constructor operator-(constructor);
        constructor operator*(int);
    private:
        int x,y;
    
    
    
};

constructor::constructor(){
    x=y=0;
}

constructor::constructor(int x){
    this->x=x;
    cout<<"CONSTRUCTOR"<<endl;
    mostrar();
    
}

constructor::constructor(const constructor&a){
    cout<<"CREANDO COPIA"<<endl;
    x=a.x;
}

constructor constructor::operator+(constructor obj){
    constructor i;
    i.x=this->x+obj.x;
    return i;
}

constructor constructor::operator-(constructor obj){
    constructor i;
    i.x=this->x-obj.x;
    return obj;
}
constructor constructor::operator*(int a){
    constructor i;
    i.x=this->x*a;
    return a;
}
void constructor::mostrar(){
    cout<<"x = "<<x<<endl;
}

int main() {
    int x;
    constructor vector;
    constructor vector1(28,2);
    constructor vector2(4,3);
    cout<<"SUMA = "<<endl;
    vector=vector1+vector2;
    vector.mostrar();
    cout<<"RESTA = "<<endl;
    vector=vector1-vector2;
    vector.mostrar();
    cout<<"MULTIPLAR = "<<endl;
    vector=vector2*10;
    vector.mostrar();
}

