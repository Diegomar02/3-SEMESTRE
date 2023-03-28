#include <iostream>
#include <fstream>

using namespace std;
void agregar();
int cantidad();
void mostrar();
void buscarXid(int idUsuario);
void respaldo();

int main() {
    fstream archivo;
    int opcion,idUsuario;
    archivo.open("calificaciones.txt",ios::in|ios::app);
    archivo<<"Ingenieria en Sistemas Computacionales"<<endl;
    archivo<<"Universidad Autonoma de Aguascalientes"<<endl;
    archivo<<"Programacion II"<<endl;
    archivo<<"ID - "<<"PARCIAL 1 - "<<"PARCIAL 2 - "<<"PARCIAL 3 - "<<"PROYECTO"<<endl;
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
        cout<<"5. HACER UN RESPALDO"<<endl;
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
                respaldo();
                break;
    
        }//FIN SWITCH
    }while(opcion!=0);
    archivo.close();
    cout<<"VUELVA PRONTO, GRACIAS!!!"<<endl;
    return 0;
}//FIN MAIN

void agregar(){//INICIO AGREGAR
    int id;
    float p1,p2,p3,pro4,promedioFinal;
    fstream archivo;
    archivo.open("calificaciones.txt",ios::out|ios::app);
    cout<<"INGRESE EL ID = ";
    cin>>id;
    cout<<"CALIFICACION PARCIAL 1= ";
    cin>>p1;
    cout<<"CALIFICACION PARCIAL 2 = ";
    cin>>p2;
    cout<<"CALIFICACION PARCIAL 3 = ";
    cin>>p3;
    cout<<"CALIFICACION PARCIAL 4 = ";
    cin>>pro4;
    promedioFinal=(p1*2.5/10)+(p2*2.5/10)+(p3*2.5/10)+(pro4*2.5/10);
    archivo<<id<<" "<<p1<<" "<<p2<<" "<<p3<<" "<<pro4<<endl;
    archivo.close();
}

int cantidad(){
    fstream archivo;
    int aux=0;
    int id;
    float p1,p2,p3,pro4,promedioFinal;
    archivo.open("calificaciones.txt",ios::in);
    while(archivo>>id>>p1>>p2>>p3>>pro4){
        aux++;
    }//FIN WHILE
    archivo.close();
    return aux;
}//FIN CANTIDAD

void mostrar(){//INICIO MOSTRAR
    fstream archivo;
    int id;
    float p1,p2,p3,pro4,promedioFinal;
    archivo.open("calificaciones.txt",ios::in);
    cout<<"id\tnombre\tcorreo\tpromedio"<<endl;
    while(archivo>>id>>p1>>p2>>p3>>pro4){//INICIO WHILE
        cout<<id<<"\t"<<p1<<"\t"<<p2<<"\t"<<p3<<"\t"<<pro4<<endl;
    }//FIN WHILE
    archivo.close();
}//FIN MOSTRAR

void buscarXid(int idUsuario){//INICIO BUSCARXID
    fstream archivo;
    int id,res;
    bool enc=false;
    float p1,p2,p3,pro4,promedioFinal;
    archivo.open("calificaciones.txt",ios::in);
    while(!archivo.eof()){//INICIO WHILE
        archivo>>id>>p1>>p2>>p3>>pro4;
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
        cout<<id<<", "<<p1<<", "<<p2<<", "<<p3<<", "<<pro4<<endl;
        archivo.close();
    }//FIN ELSE
}//FIN BUSCARXID

void respaldo(){//INICIO RESPALDO
    ifstream original("calificaciones.txt");
    ofstream copia("calificaciones_copia.txt");
    string a;
    while(getline(original,a))
        copia<<a<<endl;
    original.close();
    copia.close();
    cout<<"RESPALDO GENERADO..."<<endl;
}//FIN RESPALDO


