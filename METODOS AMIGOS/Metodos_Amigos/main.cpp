//DIEGO MARQUEZ GOMEZ
//245119

#include <iostream>
#include <string.h>

using namespace std;

class tenis{
    private:
    string nombre;
    string material;
    string tipo;
    int acce;
    int precio;
    public:
    tenis();
    ~tenis();
    friend ostream&operator<<(ostream&,const tenis&);
    friend istream&operator>>(istream&,tenis&);
};

tenis::tenis(){
    nombre=" - ";
    material=" - ";
    tipo=" - ";
    acce=0;
    precio=0;
}

tenis::~tenis(){
}

ostream&operator<<(ostream&out,const tenis&obj){
    cout<<"\n\nVALORES"<<endl;
    out<<"NOMBRE = "<<obj.nombre<<endl;
    out<<"TIPO DE MATERIAL = "<<obj.material<<endl;
    out<<"TIPO DE TENIS = "<<obj.tipo<<endl;
    out<<"ACCESIBILIDAD = "<<obj.acce<<endl;
    out<<"PRECIO = "<<obj.precio<<endl;
    return out;
}

istream&operator>>(istream&in,tenis&obj){
    cout<<"\n\nINGRESAR VALORES"<<endl;
    cout<<"NOMBRE = ";
    in>>obj.nombre;
    in.ignore();
    cout<<"MATERIAL = ";
    in>>obj.material;
    in.ignore();
    cout<<"TIPO = ";
    in>>obj.tipo;
    in.ignore();
    cout<<"ACCESIBILIDAD = ";
    in>>obj.acce;
    in.ignore();
    cout<<"PRECIO = ";
    in>>obj.precio;
    return in;
}

int main(){
    tenis datos;
    cout<<datos;
    cin>>datos;
    cout<<datos;
    cout<<endl;
}

