//DIEGO MARQUEZ
//245119
//PROGRAMACION II

//TENIS
//1. PISADA
//2. MATERIAL
//3. TIPO (CAMINAR, CORRER, FUT, BASQUET, ETC
//4. PRECIO
//5. ACCESIBILIDAD (OBTENER).
//6. PROTECCIÓN

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class tenis{
private:
    string nombre;
    string material;
    int tipo;
    float precio;
    int obtener;
    int proteccion;
public:
    tenis();
    tenis(const tenis&);
    ~tenis();
    
    void menu(int);
    void agregar_datos();
    void mostrar();
    void buscar_nombre(string nombre1);
    void tipo1(string tipo1);
};


int main() {
    tenis X;
    tenis Y;
}

void tenis::menu(int opcion){
    cout<<"1 AGREGAR DATOS"<<endl;
    cout<<"2. MOSTRAR TODO"<<endl;
    cout<<"3. BUSCAR TIPO DE TENIS"<<endl;
    cout<<"4. BUSCAR NOMBRE DE TENIS"<<endl;
    
    cout<<"OPCION = "<<endl;
    cin>>opcion;
    switch(opcion){
        case 1:
            agregar_datos();
        case 2:
            mostrar();
        case 3:
            tipo1(tipo1);
        case 4:
            buscar_nombre(nombre);
            
    }
}

tenis::tenis(){
    cout<<"GENERANDO...";
    menu();
    nombre="";
    material="";
    tipo=0;
    precio=0;
    obtener=0;
    proteccion=0;
}

tenis::tenis(const tenis&a){
    nombre=a.nombre;
    material=a.material;
    tipo=a.tipo;
    precio=a.precio;
    obtener=a.obtener;
    proteccion=a.proteccion;
}

tenis::~tenis(){
    
}

void tenis::agregar_datos(){
    fstream archivo;
    ifstream leerArchivo;
    archivo.open("datos.dat",ios::out|ios::app);
    if(!archivo){//INICIO IF
        cerr<<"No se pudo abrir el archivo"<< endl;
        cin.get();
        }
    cout<<"INGRESE EL NOMBRE = ";
    cin>>nombre;
    cout<<"INGRESA EL MATERIAL = ";
    cin>>material;
    cout<<"INGRESA TIPO 1. Correr 2. Caminar 3. Fut 4. Basquet = ";
    cin>>tipo;
    cout<<"PRECIO = ";
    cin>>precio;
    cout<<"OBTENCION 1. Facil 2. Dificil = ";
    cin>>obtener;
    cout<<"PROTECCION (Tobillo) 1. Si 2. No = ";
    cin>>proteccion;
    archivo<<nombre<<" "<<material<<" "<<tipo<<" "<<precio<<" "<<obtener<<" "<<proteccion<<endl;
    cout<<"Datos Guardados...";
    archivo.close();
}

void tenis::mostrar(){
    fstream archivo;
    archivo.open("datos.dat",ios::out|ios::app);
    cout<<"NOMBRE\tMATERIAL\tTIPO\tPRECIO\tOBTENCIO\tPROTECCION";
}

void tenis::buscar_nombre(string nombre1){
    fstream archivo;
        bool enc=false;
        cout<<"Dame nombre a buscar : ";
        cin>>nombre1;
        archivo.open("tenis.dat",ios::in);
        while(!archivo.eof()){//INICIO WHILE
            archivo<<nombre<<" "<<material<<" "<<tipo<<" "<<precio<<" "<<obtener<<" "<<proteccion<<endl;
            if( !strcmp( nombre ,nombre1) ){//INICIO IF
                enc = true;
                break;
            }//FIN IF
        }//FIN WHILE
        if(enc == false) cout <<"...Usuario no encontrado..." << endl;
        else{//INICIO ELSE
            cout<<"El alumno encontrado fue: "<<endl;
            archivo<<nombre<<" "<<material<<" "<<tipo<<" "<<precio<<" "<<obtener<<" "<<proteccion<<endl;
        }
        archivo.close();
}

void tenis::tipo1(string tipo1){
    fstream archivo;
    
        bool enc=false;
        cout<<"Dame tipo a buscar : ";
        cin>>tipo1;
        archivo.open("tenis.dat",ios::in);
        while(!archivo.eof()){//INICIO WHILE
            archivo<<nombre<<" "<<material<<" "<<tipo<<" "<<precio<<" "<<obtener<<" "<<proteccion<<endl;
            if( !strcmp( tipo ,tipo1) ){//INICIO IF
                enc = true;
                break;
            }//FIN IF
        }//FIN WHILE
        if(enc == false) cout <<"...Usuario no encontrado..." << endl;
        else{//INICIO ELSE
            cout<<"El alumno encontrado fue: "<<endl;
            archivo<<nombre<<" "<<material<<" "<<tipo<<" "<<precio<<" "<<obtener<<" "<<proteccion<<endl;
        }
        archivo.close();
}
