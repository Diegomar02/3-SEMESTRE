#include <iostream>
using namespace std;

class Animal{
public:
    virtual void sonido(){
        cout<<"-----"<<endl;
    }
};

class Gato:public Animal{
public:
    void sonido(){
        cout<<"Miauuu"<<endl;
    }
};

class Perro:public Animal{
public:
    void sonido(){
        cout<<"Guau guau"<<endl;
    }
    
};
int main() {
    Animal animal;
    Gato gato;
    Perro perro;
    animal.sonido();
    gato.sonido();
    perro.sonido();
    cout<<endl;
    Animal&mascota1=gato;
    Animal*mascota2=&perro;
    mascota1.sonido();
    mascota2->sonido();
}
