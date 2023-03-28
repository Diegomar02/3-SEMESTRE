//Diego Marquez Gomez
//ID 245119
//EJERCICIO 2

#include <iostream>

using namespace std;

int main() {
    int fil=8,col=5,buscar;
    int matriz[fil][col];
    for(int i=0;i<fil;i++){
        for(int a=0;i<col;a++){
            cout<<"DAME EL VALOR "<<i<<a<<endl;
            cin>>matriz[a][i];
        }
    }
    cout<<"\nMATRIZ\n";
    for(int i=0;i<fil;i++){
        for(int a=0;i<col;a++){
            cout<<matriz[i][a];
        }
        cout<<"\n";
    }
    cout<<"¿CUAL RENGLON DESEA VER? = ";
    cin>>buscar;
    cout<<"REGLON "<<buscar<<" DE LA MATRIZ";
    for(int i=0;i<col;i++){
        cout<<matriz[buscar][i];
    }
    for(int i=7;i>-1;i--){
        cout<<matriz[buscar][i];
    }
    
}
