#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void correo(string&);
void numero(char&);

size_t encontrar;

int main() {
    int opcion;
    cout<<"1. CORREO"<<endl;
    cout<<"2. NUMERO"<<endl;
    cout<<"QUE OPCION DESEA?"<<endl;
    cin>>opcion;
    switch(opcion){
        case 1:
            string correox;
            cout<<"INGRESE EL CORREO = ";
            cin>>correox;
            correo(correox);
            cout<<"\n";
            break;
        case 2:
            char numerox;
            cout<<"INGRESE EL NUMERO = ";
            cin>>numerox;
            numero(numerox);
            cout<<"\n";
    }
}

void correo(string& correo1){
    encontrar=correo1.find("@");
    if(encontrar!=string::npos){
        cout<<"SE HA ENCONTRADO EL @";
        return;
    }
    else{
        cout<<"\nNO SE ENCONTRO EL @";
        return;
    }
}
    
    
void numero(char& numero1){
    cout<<"INGRESE EL NUMERO = ";
    cin>>numero1;
    int tamaño=0;
    tamaño=strlen(numero1);
    if(tamaño==12){
        cout<<"EL NUMERO SI TIENE 12 DIGITOS";
    }
    if(tamaño<12){
        cout<<"EL NUMERO TIENE MENOS DE 12 DIGITOS";
    }
    if(tamaño>12){
        cout<<"EL NUMERO TIENE MAS DE 12 DIGITOS";
    }
}
