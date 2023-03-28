//DIEGO MARQUEZ
//ID 245119

#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

int main (){//INICIO PROGRAMA
    fstream archivo;
    ifstream leerArchivo;
    archivo.open("datos.txt",ios::out|ios::app);
    if(!archivo){//INICIO IF
        cerr<<"No se pudo abrir el archivo"<< endl;
        cin.get();
        return 1;
    }//FIN IF
    int opcion;
    int id;
    char nombre[30];
    char correo[30];
    float promedio;
    cout<<"MENU";
    cout<<"\n1. INGRESAR LOS DATOS";
    cout<<"\n2. MOSTRAR CUANTOS USUARIOS HAY REGISTRADOS";
    cout<<"\n3. BUSCAR UN USUARIO";
    cout<<"\n4. SALIR";
    cout<<"\n¿QUE OPCION DESEA? = ";
    cin>>opcion;
    if (opcion==1){//INICIO IF
        cout<<"A CONTINUACION SE VAN INGRESAR LOS SIGUIENTES DATOS (NOMBRE, ID, CORREO Y PROMEDIO\n";
            cout<<"ID = ";
            cin>>id;
            cout<<"NOMBRE = ";
            cin>>nombre;
            cout<<"CORREO = ";
            cin>>correo;
            cout<<"PROMEDIO = ";
            cin>>promedio;
            archivo<<id<<" "<<nombre<<" "<<correo<<" "<<promedio<<endl;
        
        return main();
        }//FIN IF
    if (opcion==2){//INICIO IF
        int cantidad=0;
        leerArchivo.open("datos.txt");
        leerArchivo>>id;
        while(!leerArchivo.eof()){//INICIO WHILE
                cantidad=cantidad+1;
        }//FIN WHILE
        cout<<"TENEMOS "<<cantidad<<" USUARIOS REGISTRADOS";
        return main();
    }//FIN IF
    if (opcion==3){//INICIO IF
        int usuario;
        cout<<"¿USUARIO QUE SE QUIERE ENCONTRAR (ID)? = ";
        cin>>usuario;
        leerArchivo.open("datos.txt");
        while(leerArchivo.eof()){//INICIO WHILE
            leerArchivo>>id;
            if (id==usuario){//INICIO IF
                cout<<"USUARIO EXISTENTE";
            }//FIN IF
            else{//INICIO ELSE
                cout<<"USUARIO NO REGISTRADO CON ESE ID";
            }//FIN ELSE
        }//FIN WHILE
    }//FIN IF
    if (opcion==4){//INICIO IF
        cout<<"GRACIAS!! VUELVA PRONTO";
    }//FIN IF
        archivo.close();
}//FIN PROGRAMA
