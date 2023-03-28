#include <iostream>
using namespace std;
void leer_valor(int a,int b);

int main(){
    int a = 11111;
    int b = 22222;
    cin.exceptions(std::ios_base::failbit);
    leer_valor(a,b);
}

void leer_valor(int a, int b){
    bool LECTURA;
    do{
        LECTURA=true;
    try{
        std::cout << "Pon un valor numérico A : ";
        std::cin >> a;
        std::cout << "Pon un valor numérico B : ";
        std::cin >> b;
    }
    catch (std::ios_base::failure &error){
        cout << "Algo ha pasado al leer!" << endl;
        cout << "cin.fail() : " << cin.fail() << endl;
        cin.clear();
        fflush(stdin);
        //cin.ignore(10000,'\n');
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "cin.fail() : " << cin.fail() << endl;
    }
    }while(LECTURA!=true);
    cout << "El valor a es: " << a << '\n'
    << "El valor b es: " << b << '\n';
}

