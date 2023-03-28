#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

int main (int argc, char* argv[]){
    int resultado ;
    if(argc <= 3){
        cout << "Error faltan parametros ." << endl;
    }else if( !strcmp(argv[1], "+") || !strcmp(argv[1], "x") ){
        cout << "operacion bien "<< endl;
        string tmp_string(argv[2]);
        int resultado = atoi(tmp_string.c_str()) ;
        if(!strcmp(argv[1], "+") ){
            for(int i=3 ; i< argc ; i++){
                string tmp_string(argv[i]);
                resultado += atoi(tmp_string.c_str()) ;
            }
        }else{
            for(int i=3 ; i< argc ; i++){
                string tmp_string(argv[i]);
                resultado *= atoi(tmp_string.c_str()) ;
            }
        }
        cout << "Resultado es : " << resultado << endl;
    }else{
        cout << "operacion MAL X_X "<< endl;
        cout << " -> " << argv[1] << endl; // probar con *
    }
}
