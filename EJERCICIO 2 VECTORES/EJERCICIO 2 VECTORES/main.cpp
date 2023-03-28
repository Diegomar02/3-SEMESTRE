//DIEGO MARQUEZ GOMEZ
// ID 245119

#include <iostream>

using namespace std;

void menu();
void llenar(int vector1[],int vector2[],int* &puntero);
void suma(int vector1[],int vector2[],int vector3[],int* &puntero);
void mostrar(int vector1[],int vector2[],int vector3[],int* &puntero);

int main(){//INICIO MAIN
    menu();
}//FIN MAIN

void menu(){//INICIO VOID MENU
    int opcion;
    int vector1[10], vector2[10], vector3[10];
    int a=10;
    int* puntero=&a;
    do{//INICIO DO
        cout<<"MENU\n";
        cout<<"1. ENTRADA DE DATOS\n";
        cout<<"2. SUMA DE VECTORES\n";
        cout<<"3. VECTOR FINAL \n";
        cout<<"4. SALIR\n" << endl;
        cout<<"OPCION? = ";
        cin>>opcion;
        switch(opcion){//INICIO SWITCH
            case 1:llenar(vector1,vector2,puntero); break;
            case 2:suma(vector1,vector2,vector3,puntero); break;
            case 3:mostrar(vector1,vector1,vector3,puntero); break;
        }//FIN SWITCH
    }while(opcion!=4); //FIN DO
}//FIN VOID MENU

void llenar(int vector1[],int vector2[],int* &puntero){//INICIO VOID LLENAR
    cout<<"\n";
    cout<<"VECTOR 1";
    cout<<"\n";
    for (int i=0;i<*puntero;i++){//INICIO FOR
        cout<<"Ingresar Dato "<<i+1<<" = ";
        cin>>vector1[i];
    }//FIN FOR
    cout<<"\n";
    cout<<"VECTOR 2";
    cout<<"\n";
    for (int i=0;i<*puntero;i++){//INICIO FOR
        cout<<"Ingresar Dato "<<i+1<<" = ";
        cin>>vector2[i];
    }//FIN FOR
    cout<<"\n";
    cout<<"LISTO"<<endl;
}//FIN VOID LLENAR

void suma(int vector1[],int vector2[],int vector3[],int* &puntero){//INICIO VOID SUMA
    cout<<"\n";
    for (int i=0;i<*puntero;i++){//INICIO FOR
        vector3[i]=vector1[i]+vector2[i];
    }//FIN FOR
    cout<<"SE REALIZO LA SUMA"<<endl;
}//FIN VOID SUMA

void mostrar(int vector1[],int vector2[],int vector3[],int* &puntero){//INICIO VOID MOSTRAR
    cout <<"\n";
    cout << "LA SUMA DE LA LINEAS DE LOS VECTORES ES = " << endl;
    cout << "\n";
    for (int i=0;i<*puntero;i++){//INICIO FOR
        cout<<vector1[i]<<"+"<<vector2[i]<<"="<<vector3[i]<<endl;
    }//INICIO FOR
}//FIN VOID MOSTRAR
