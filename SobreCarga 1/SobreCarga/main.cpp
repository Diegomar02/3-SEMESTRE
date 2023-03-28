//Diego Márquez Gómez
//245119

#include <iostream>

using namespace std;

int sumar(int ,int );
float sumar (float , float );
char sumar(char , char );
char sumar(string ,string );

int main(){//INICIO INT MAIN
    string nombre1="Diego";
    string nombre2="Márquez";
    cout<<"RESULTADO ENTEROS = "<<sumar(10,45)<<endl;
    cout<<"\n";
    cout<<"RESULTADO DECIMALES = "<<sumar((float)10.1,(float)10.5)<<endl;
    cout<<"\n";
    sumar('D','L');
    sumar(nombre1,nombre2);
    cout<<"\n";
}//FIN INT MAIN

int sumar(int numero1,int numero2){//INICIO INT SUMA
    float a=numero1+numero2 ;
    return a;
}//FINAL INT SUMA

float sumar(float numero3,float numero4){//INICIO FLOAT SUMA
    float b=numero3+numero4;
    return b;
}//FINAL FLOAT SUMA

char sumar(char nombre1, char nombre2){//INICIO CHAR SUMAR
    cout<<"("<<nombre1<<","<< nombre2<<")"<<'\n'<<'\n';
    return 0;
}//FIN CHAR SUMA

char sumar(string nombre3,string nombre4){//INICIO CHAR SUMAR
    cout<<"("<<nombre3<<","<<nombre4<<")"<<'\n';
    return 0;
}//FIN CHAR SUMA
