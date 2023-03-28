/*Clase Matriz
Maricela Jacqueline Renovato Ramirez ID:291218 Fecha: 15/10/2021
*/

#include<iostream>
#include <math.h>

//1 2 3 4 5 6 7 8 9

using namespace std;

class Matriz{
    private:
        int x;
        int y;
        int **matriz;
    
    public:
        Matriz(); // constructor
        Matriz(int, int); //
        Matriz(const Matriz &); //constructor copia
        ~Matriz(); //destructor
        
        void Capturar(int ,int ,int); // un dato en especifico
        void Capturar(); //validar si ya esta declarado (verificar si ya tengo valores en
        void Mostrar(); // todo
        void Mostrar(int, int); // un dato en particular
        void Mostrar(char, int); // C o R, numero de la columna o del renglon
        void Editar(int, int ); // Capture esa posicion
        void Buscar(int); // Encontro el numero y cuantas veces
        void Suma(Matriz matA, Matriz matB); //validar que se pueda
};

int main(){
    Matriz A, B(3,3);
    A.Capturar();
    cout << "\n\n\nMATRIZ A..." << endl;
    A.Mostrar();
    A.Editar(1,1);
    A.Mostrar();
    A.Mostrar('R', 2);
    A.Mostrar(1,1);
    A.Buscar(5);
    cout << "\nMATRIZ B..." << endl;
    B.Capturar();
    cout << "\nMATRIZ B..." << endl;
    B.Mostrar();
    B.Capturar(2,2,5);
    B.Mostrar();
    B.Buscar(5);
    cout << "\n\nMatriz C" << endl;
    Matriz C;
    cout << "\nSUMA\n";
    C.Suma(A,B);
    cout << "\nMATRIZ C..." << endl;
    C.Mostrar();
    cout << "\nCopia..." << endl;
    Matriz D(C);
    cout << "\nMATRIZ D..." << endl;
    D.Mostrar();
    
}

Matriz::Matriz(){
    cout << "\nInicializando matriz..." << endl;
    x = 0;
    y = 0;
    matriz = NULL;
    cout << "Numero de renglones: ";
    cin >> x;
    cout << "Numero de columnas: ";
    cin >> y;
    matriz = new int*[x];
    for(int i=0; i<x; i++){
        matriz[i] = new int[y];
    }
    cout << "La matriz de " << x << "x" << y << " fue creada...\n";
}

Matriz::Matriz(int ren, int col){
    cout << "\n\nGenerando matriz de " << ren << "x" << col << "...\n\n";
    x = ren;
    y = col;
    matriz = new int*[x];
    for(int i=0; i<x; i++){
        matriz[i] = new int[y];
    }
}

Matriz::Matriz(const Matriz &X){
    x = X.x;
    y = X.y;
    matriz = new int*[x];
    for(int i=0; i<x; i++){
        matriz[i] = new int[y];
    }
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            matriz[i][j] = X.matriz[i][j];
        }
    }
}

Matriz::~Matriz(){
    for(int i=0; i<x; i++){
        delete [] matriz[i];
    }
    delete [] matriz;
}

//Capturar un dato en una posicion en especifico
void Matriz::Capturar(int ren,int col,int n){
    cout << "\nCapturando...\n";
    if(ren<=x && col<=y){
        matriz[ren][col] = n;
        cout << "Valor [" << ren << "][" << col << "]: " << n << endl;
    } else{
        cout << "El valor [" << ren << "][" << col << "] no existe" << endl;
    }
}

//Capturar la matriz,verificar si no tiene valores
void Matriz::Capturar(){
    cout << "\nCapturando valores...\n";
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            cout << "Valor [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

//Mostrar toda la matriz
void Matriz::Mostrar(){
    cout << "\n";
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

// Mostrar un dato en particular
void Matriz::Mostrar(int ren, int col){
    cout << "\n\n";
    if(ren <= x && col <= y){
        cout << "Valor [" << ren << "][" << col << "]: " << matriz[ren][col];
    } else{
        cout << "El valor [" << ren << "][" << col << "] no existe" << endl;
    }
    
}

// C o R, numero de la columna o del renglon
void Matriz::Mostrar(char w,int z){
    cout << "\n";
    bool most = false;
    if(w == 'R'){
        most = true;
        if(z <= x){
            cout << "Renglon ["<< z << "]: " << endl;
            for(int i=0; i<x; i++){
                cout << matriz[z][i] << "\t";
            }
            cout << endl;
        } else{
            cout << "Eror, el numero es mayor a la cantidad de renglones!" << endl;
        }
    }
    if(w == 'C'){
        most = true;
        if(z <= y){
            cout << "Columna ["<< z << "]: " << endl;
            for(int i=0; i<y; i++){
                cout << matriz[i][z] << "\t";
            }
            cout << endl;
        } else{
            cout << "Eror, el numero es mayor a la cantidad de renglones!" << endl;
        }
    }
    if(most == false){
        cout << "Se debe indicar R (renglon) o C (columna)" << endl;
    }
}

// Capturar esa posicion
void Matriz::Editar(int x,int y){
    int aux;
    cout << "\nEditando..." << endl;
    cout << "Ingresa el nuevo valor: ";
    cin >> aux;
    matriz[x][y] = aux;
}

// Cuantas veces encontrÛ el numero
void Matriz::Buscar(int l){
    cout << "\n\nBuscando..." << endl;
    int cont = 0;
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            if(matriz[i][j] == l){
                cont++;
            }
        }
    }
    cout << "El numero [" << l << "] aparece " << cont << " veces" << endl;
}

// Validar que se pueda sumar y sumarlo
void Matriz::Suma(Matriz matA, Matriz matB){
    cout << "\nSumando...\n";
    matA.Mostrar();
    cout << "+";
    matB.Mostrar();
    if(matA.x == matB.x && matA.y == matB.y && matA.x == x && matA.y == y && matB.x == x && matB.y == y){
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                matriz[i][j] = matA.matriz[i][j] + matB.matriz[i][j];
            }
        }
    }
}


