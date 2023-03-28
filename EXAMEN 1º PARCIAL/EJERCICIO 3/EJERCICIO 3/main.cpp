
#include <iostream>

using namespace std;

int main() {
    int fil,col;
    int **d1,**d2;
    cout<<"NUMERO DE FILAS = ";
    cin>>fil;
    cout<<"NUMERO DE COLUMNAS = ";
    cin>>col;
    d1=(int**)malloc(fil*sizeof(int));
    if(d1==NULL){
        cout<<"NO SE RESERVO EL ESPACIO";
        exit(1);
    }
    for(int i=0;i<fil;i++){
        d1[i]=(int*)malloc(col*sizeof(int));
        if(d1==NULL){
            cout<<"NO SE RESERVO EL ESPACIO";
            exit(1);
        }
    }
    for(int i=0;i<fil;i++){
        for(int a=0;)
    }
    
}

//Falta codigo...
