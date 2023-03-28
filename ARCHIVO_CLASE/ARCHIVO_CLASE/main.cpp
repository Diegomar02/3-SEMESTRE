//DIEGO MÁRQUEZ GÓMEZ
//ID 245119

#include <iostream>
#include <fstream>

using namespace std;
void agregar();
int cantidad();
void mostrar();
void buscarXid(int idUsuario);
void buscarXnombre();
void respaldo();

void cambio();
void modificar(int idModificar);

int main() {//INICIO MAIN
    fstream archivo;
    int opcion,idUsuario,idModificar;
    archivo.open("usuarios.txt",ios::in|ios::app);
    if(!archivo){//INICIO IF
        cerr<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return 1;
    }//FIN IF
    do{//INICIO DO
        cout<<"MENU"<<endl;
        cout<<"1. AGREGAR USUARIO"<<endl;
        cout<<"2. SABER CUANTOS USUARIOS ESTA REGISTRADOS"<<endl;
        cout<<"3. MOSTRAR USUARIOS"<<endl;
        cout<<"4. BUSCAR USUARIO (ID)"<<endl;
        cout<<"5. BUSCAR USUARIO (NOMBRE)"<<endl;
        cout<<"6. HACER UN RESPALDO"<<endl;
        cout<<"7. MODIFICAR"<<endl;
        cout<<"0. SALIR"<<endl;
        cout<<"¿CUAL OPCION DESEA? = ";
        cin>>opcion;
        switch(opcion){//INICIO SWITCH
            case 1:
                agregar();
                break;
            case 2:
                cout<<cantidad()<<endl;
                break;
            case 3:
                mostrar();
                break;
            case 4:
                cout<<"INGRESE EL ID DEL USUARIO PARA BUSCARLO"<<endl;
                cin>>idUsuario;
                buscarXid(idUsuario);
                break;
            case 5:
                buscarXnombre();
                break;
            case 6:
                respaldo();
                break;
            case 7:
                cout<<"INGRESAR ID A MODIFICAR"<<endl;
                cin>>idModificar;
                modificar(idModificar);
                break;
        }//FIN SWITCH
    }while(opcion!=0);
    archivo.close();
    cout<<"VUELVA PRONTO, GRACIAS!!!"<<endl;
    return 0;
}//FIN MAIN

void agregar(){//INICIO AGREGAR
    string nombre,correo;
    int id;
    float promedio;
    fstream archivo;
    archivo.open("usuarios.txt",ios::out|ios::app);
    cout<<"INGRESE EL ID = ";
    cin>>id;
    cout<<"INGRESE EL NOMBRE DEL USUARIO = ";
    cin>>nombre;
    cout<<"INGRESE EL CORREO = ";
    cin>>correo;
    cout<<"INGRESE EL PROMEDIO = ";
    cin>>promedio;
    archivo<<id<<" "<<nombre<<" "<<correo<<" "<<promedio<<endl;
    archivo.close();
}//FIN AGREGAR

int cantidad(){//INICIO CANTIDAD
    fstream archivo;
    int aux=0;
    string nombre,correo;
    int id;
    float promedio;
    archivo.open("usuarios.txt",ios::in);
    while(archivo>>id>>nombre>>correo>>promedio){//INICIO WHILE
        aux++;
    }//FIN WHILE
    archivo.close();
    return aux;
}//FIN CANTIDAD

void mostrar(){//INICIO MOSTRAR
    fstream archivo;
    string nombre, correo;
    int id;
    float promedio;
    archivo.open("usuarios.txt",ios::in);
    cout<<"id\tnombre\tcorreo\tpromedio"<<endl;
    while(archivo>>id>>nombre>>correo>>promedio){//INICIO WHILE
        cout<<id<<"\t"<<nombre<<"\t"<<correo<<"\t"<<promedio<<endl;
    }//FIN WHILE
    archivo.close();
}//FIN MOSTRAR

void buscarXid(int idUsuario){//INICIO BUSCARXID
    fstream archivo;
    int id,res;
    bool enc=false;
    float promedio;
    string nombre,correo;
    archivo.open("usuarios.txt",ios::in);
    while(!archivo.eof()){//INICIO WHILE
        archivo>>id>>nombre>>correo>>promedio;
        if(id==idUsuario){//INICIO IF
            res=id;
            enc=true;
            break;
        }//FIN IF
    }//FIN WHILE
    if(enc==false)
        cout<<"USUARIO NO ENCONTRADO"<<endl;
    else{//INICIO ELSE
        cout<<"USUARIO ENCONTRADO"<<endl;
        cout<<id<<", "<<nombre<<", "<<correo<<", "<<promedio<<endl;
        archivo.close();
    }//FIN ELSE
}//FIN BUSCARXID

void buscarXnombre(){//INICIO BUSCARXNOMBRE
    fstream archivo;
    int id, res;
    bool enc=false;
    float promedio;
    char nombre[30], correo[30];
    char buscar_nombre[30];
    cout << "Dame nombre a buscar : ";
    cin >> buscar_nombre;
    archivo.open("usuarios.txt",ios::in);
    while(!archivo.eof()){//INICIO WHILE
        archivo >> id>> nombre >> correo >> promedio;
        if( !strcmp( nombre , buscar_nombre ) ){//INICIO IF
            res=id;
            enc = true;
            break;
        }//FIN IF
    }//FIN WHILE
    if(enc == false) cout <<"...Usuario no encontrado..." << endl;
    else{//INICIO ELSE
        cout<<"El alumno encontrado fue: "<<endl;
        cout<<id<<", "<<nombre<<", "<<correo<<", "<<promedio<<endl;
    }//FIN ELSE
    archivo.close();
}//FIN BUSCARXNOMBRE

void respaldo(){//INICIO RESPALDO
    ifstream original("usuarios.txt");
    ofstream copia("usuarios_copia.txt");
    string a;
    while(getline(original,a))
        copia<<a<<endl;
    original.close();
    copia.close();
    cout<<"RESPALDO GENERADO..."<<endl;
}//FIN RESPALDO

void cambio(){//INICIO CAMBIO
    ifstream original("usuarios_copia.txt");
    ofstream copia("usuarios.txt");
    string s;
    while(getline(original,s))
        copia<<s<<endl;
    original.close();
    copia.close();
}//FIN CAMBIO

void modificar(int idModificar){//INICIO MODIFICAR
    ifstream original("usuarios.txt");
    ofstream copia("usuarios_copia.txt");
    int id;
    float promedio;
    string nombre,correo;
    while(original>>id>>nombre>>correo>>promedio){//INICIO WHILE
        if(id!=idModificar)
            copia<<id<<" "<<nombre<<" "<<correo<<" "<<promedio;
        else{//INICIO ELSE
            cout<<"INGRESAR EL ID = ";
            cin>>id;
            cout<<"INGRESAR EL NOMBRE DEL USUARIO = ";
            cin>>nombre;
            cout<<"INGRESAR EL CORREO = ";
            cin>>correo;
            cout<<"INGRESA EL PROMEDIO = ";
            cin>>promedio;
        }//FIN ELSE
    }//FIN WHILE
    cambio();
    original.close();
    copia.close();
}//FIN MODIFICAR
