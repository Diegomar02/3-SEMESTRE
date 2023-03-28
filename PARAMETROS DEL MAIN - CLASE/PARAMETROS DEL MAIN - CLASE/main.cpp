#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

int funcion1 (char* dato){
int r;
if( !strcmp(dato, "1")) r = 1;
if( !strcmp(dato, "2")) r = 2;
if( !strcmp(dato, "3")) r = 3;
if( !strcmp(dato, "4")) r = 4;
if( !strcmp(dato, "5")) r = 5;
if( !strcmp(dato, "6")) r = 6;
if( !strcmp(dato, "7")) r = 7;
if( !strcmp(dato, "8")) r = 8;
if( !strcmp(dato, "9")) r = 9;
if( !strcmp(dato, "0")) r = 0;
return r;
}

int main (int argc, char* argv[]){
    int resultado ;
    if(argc <= 3){
        cout << "Error faltan parametros ." << endl;
    }else if( !strcmp(argv[1], "+") || !strcmp(argv[1], "x") ){
            cout << "operacion bien "<< endl;
            int resultado = funcion1(argv[2]) ;
            if(!strcmp(argv[1], "+") ){
                for(int i=3 ; i< argc ; i++){
                resultado += funcion1(argv[i]) ;
                }
            }else{
                for(int i=3 ; i< argc ; i++){
                    resultado *= funcion1(argv[i]) ;
                }
            }
        cout << "Resultado es : "<<resultado<<endl;
    }else{
        cout << "operacion MAL X_X "<< endl;
        cout << " -> " << argv[1] << endl;
    }
}
