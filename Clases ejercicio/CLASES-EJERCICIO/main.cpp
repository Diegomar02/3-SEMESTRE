
//Diego Marquez Gomez
//ID = 245119
//15 OCT 2021

#include<iostream>
#include <math.h>
using namespace std;

class Matriz{//INICIO CLASS MATRIZ
    private://PRIVATE
        int x;
        int y;
        int **matriz;
    public://PUBLIC
        Matriz();
        Matriz(int,int);
        Matriz(const Matriz &); //CONSTRUCTOR COPIA
        ~Matriz();
        void Capturar(int,int,int);//UN DATO EN ESPECIFICO
        void Capturar();//VALIDAR SI YA ESTA DECLARADA LA MATRIZ
        void Mostrar();//TODO
        void Mostrar(int,int);//MOSTRAR UN DATO EN PARTICULAR
        void Mostrar(char,int);//C o R, NUMERO DE COLUMNA O RENGLON
        void Editar(int,int);
        void Suma(Matriz,Matriz);//VALIDAR QUE SE PUEDA
        void Buscar(int);
    
};//FIN CLASS MATRIZ

//MENU EN EL MAIN
int main() {
    Matriz A,B(3,3);
    cout<<"\n";
    cout<<"CAPTURANDO MATRIZ A"<<endl;
    A.Capturar();
    cout<<"\n";
    cout<<"CAPTURANDO MATRIZ B"<<endl;
    B.Capturar();
    cout<<"\n";
    cout<<"MOSTRANDO MATRIZ A"<<endl;
    A.Mostrar();
    cout<<"\n";
    cout<<"MOSTRANDO MATRIZ B"<<endl;
    B.Mostrar();
    cout<<"\n";
    cout<<"EDITANDO MATRIZ A 0,0"<<endl;
    A.Editar(0,0);
    cout<<"\n";
    cout<<"MOSTRANDO NUEVA MATRIZ A"<<endl;
    A.Mostrar();
    cout<<"\n";
    cout<<"BUSCAR 2 EN MATRIZ B"<<endl;
    B.Buscar(2);
    Matriz C;
    C.Suma(A,B);//NO SUPE HACER EL DE SUMAR
    Matriz D(C);
    D.Mostrar('R',0);
    
}

//MATRIZ

Matriz::Matriz(){
    matriz=NULL;
    x=3;
    y=3;
    matriz=new int*[x];
    for(int i=0;i<x;i++){
        matriz[i]=new int[y];
    }
    cout<<"MATRIZ GENERADA 3X3"<<endl;
}

Matriz::Matriz(int renglones,int columnas){
    x=renglones;
    y=columnas;
    matriz=new int*[x];
    for(int i=0;i<x;i++){
        matriz[i]=new int[y];
    }
    //CON COLUMNAS Y RENGLONES
    cout<<"GENERANDO MATRIZ"<<endl;
}

Matriz::Matriz(const Matriz &a){
    y=a.y;
    x=a.x;
    matriz=new int*[x];
    for(int i=0;i<x;i++){
        matriz[i]=new int[y];
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            matriz[i][j]=a.matriz[x][y];//ME MARCA ERROR = Thread 1: EXC_BAD_ACCESS (code=EXC_I386_GPFLT)
        }
    }
}

Matriz::~Matriz(){
    for(int i=0;i<x;i++){
        delete[]matriz[i];
    }
    delete[]matriz;
}


//FUNCIONES

void Matriz::Capturar(int renglones,int columnas,int dato){
    if(renglones<=x&&columnas<=x){
        matriz[renglones][columnas]=dato;
        cout<<"VALOR "<<renglones<<" - "<<columnas;
    }
}

void Matriz::Mostrar(){
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<matriz[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

void Matriz::Editar(int x, int y){
    int editar=0;
    cout<<"EDITAR VALOR = ";
    cin>>editar;
    matriz[x][y]=editar;
}

void Matriz::Buscar(int buscar){
    int contador=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(matriz[i][j]==contador){
                contador++;
            }
        }
    }
}

void Matriz::Suma(Matriz, Matriz){
    
}

void Matriz::Mostrar(char cr,int numero){
    bool mostrar=false;
    if(cr=='R'){
        mostrar=true;
        if(numero<=x){
            cout<<"RENGLON "<<numero<<" = ";
            for(int i=0;i<x;i++){
                cout<<matriz[numero][i]<<"   ";
            }
            
        }else{
            cout<<"ERROR EN RENGLON"<<endl;
        }
    }
    if(cr=='C'){
        mostrar=true;
        if(numero<=y){
            cout<<"RENGLON "<<numero<<" = ";
            for(int i=0;i<x;i++){
                cout<<matriz[i][numero]<<"   ";
            }
        }else{
            cout<<"ERROR EN COLUMNAS"<<endl;
        }
    }
}

void Matriz::Capturar(){
    cout<<"CAPTURANDO"<<endl;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<"VALOR "<<i<<" - "<<j<<" = ";
            cin>>matriz[i][j];
        }
    }
}






