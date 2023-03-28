//DIEGO MARQUEZ GOMEZ
//245119

#include <iostream>

using namespace std;

int triangulo(int,int,int);
int cuadrado(int);
double circulo(double,double,double);

int main(){
    cout<<"TRIANGULO = "<<triangulo(10,8,11)<<endl<<endl;
    cout<<"CUADRADO = "<<cuadrado(8)<<endl<<endl;
    cout<<"CIRCULO =  "<<circulo(24.7,5.89,10.7)<<endl<<endl;
}

int triangulo(int lado1,int lado2,int lado3){
    return lado1+lado2+lado3;
}

int cuadrado(int lado1){
    return lado1*4;
}

double circulo(double c1,double c2,double c3){
    double resultado=((c1*c2)+c3);
    return resultado;
}

