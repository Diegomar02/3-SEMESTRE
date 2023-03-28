// DIEGO MARQUEZ GOMEZ
// ID 245119

#include <iostream>
#include <cstdlib>

using namespace std;
int main(){
    int cantidad,i,suma=0,multiplicacion=1;
    cout<<"¿CUANTOS NUMEROS TIENE LA OPERACION? = ";
    cin>>cantidad;
    int a[cantidad];
    cout<<"¿1. SUMA  O 2. MULTIPLICACIÓN? = ";
    cin>>a[0];
    //QUISE HACER LA VALIDACION DEL IF CON EL + Y * PERO NO FUNCIONO AL HACERLOS ASI A[0]=='+' EN LA SUMA Y A[O]=='X' EN LA MULTIPLICACION
    if (a[0]==1){
        for (i=1;i<=cantidad;i++){
            cout<<"DAME EL NUMERO "<<i<<" = ";
            cin>>a[i];
            suma=suma+a[i];
        }
        cout<<"EL RESULTADO ES "<<suma;
    }
    if (a[0]==2){
        for (i=1;i<=cantidad;i++){
            cout<<"DAME EL NUMERO "<<i<<" = ";
            cin>>a[i];
            multiplicacion=multiplicacion*a[i];
        }
        cout<<"EL RESULTADO ES "<<multiplicacion;
        cout<<"\n";
    }
}
