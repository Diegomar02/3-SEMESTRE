

#include <iostream>
using namespace std;

class Base{
public:
    void metodo(){
        cout<<"Base::metodo()"<<endl;
    }
    virtual void metodoVirtual(){
        cout<<"Base:metodoVirtual"<<endl;
    }
};

class Hija:public Base{
public:
    void metodo(){
        cout<<"Hija::metodo()"<<endl;
    }
    void metodoVirtual(){
        cout<<"Hija:metodoVirtual"<<endl;
    }
    
};

int main(int argc, const char * argv[]) {
    Base base;
    Hija hija;
    
    
}
