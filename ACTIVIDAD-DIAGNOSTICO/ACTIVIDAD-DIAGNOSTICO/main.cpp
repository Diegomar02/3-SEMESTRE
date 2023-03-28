//Generar un programa con las siguiente funciones : (C++)
//1. Menú ( Función que muestre el menú  void void , funciones a,b,c y salir )
//2. a- Función que reciba un numero y obtenga el factorial
//3. b- Función que reciba 3 numero y regrese el mayor
//4. c- Función que capture un vector de datos [5] y regrese el promedio

//DIEGO MÁRQUEZ GOMEZ ID=245119
//ACTIVIDAD-DIAGNOSTICO
//10/08/2021

#include <iostream>
using namespace std;

void menu();
void factorial();
void mayor();
void promedio();

int main() {
    menu();
}

void factorial(){
    int a, factorial=1;
    cout<<"DAME EL NUMERO = ";
    cin>>a;
    for(int i=1;i<=a;i++){
        factorial=factorial*i;
    }
}
void mayor(){
    int numero1, numero2, numero3;
    cout<<"Dame el valor del numero 1 = ";
    cin>>numero1;
    cout<<"Dame el valor del numero 2 = ";
    cin>>numero2;
    cout<<"Dame el valor del numero 3 = ";
    cin>>numero3;
    if (numero1>=numero2&&numero1>=numero3)
        cout<<"ES EL MAYOR = " <<numero1;
        else
            if(numero2>numero3)
                cout<<"ES EL MAYOR = " <<numero2;
        else
                cout<<"ES EL MAYOR = " <<numero3;
}
void promedio(){
    float suma,promedio;
    int vector[5],o;
    
    for (o=0;o<5;o++){
        cout<<"INGRESE EL NUMERO "<<vector[o]<<" = ";
        cin>>vector[o];
    }
    suma=vector[0]+vector[1]+vector[2]+vector[3]+vector[4];
    promedio=suma/4;
    cout<<"EL PROMEDIO DE LOS NUMEROS DADOS ES DE "<<promedio;
}
void menu(){
    int opciones;
    cout<<"¿CUAL OPCION DESEA?\n";
    cout<<"1. FACTORIAL\n";
    cout<<"2. MAYOR\n";
    cout<<"3. PROMEDIO\n";
    cin>>opciones;
    switch (opciones) {
        case 1:
            factorial();
        case 2:
            mayor();
        case 3:
            promedio();
    }
    while (opciones!=3);
    cout<<"GRACIAS";
        
    }
