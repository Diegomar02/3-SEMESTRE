#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
    fstream archivo;
    char nombre[50];
    int ID;
    string carrera;
    float calificaciones[4];
    int faltas;
    float promedio=0;
    cout<<"BUENOS DIAS VAMOS A CAPTURAR LOS DATOS DE UN USUARIO PARA SU ACTA FINAL = "<<endl;
    cout<<"NOMBRE = ";
    gets(nombre);
    cout << " ID: " ;
    cin  >>  ID;
    cout << " Carrera: " ;
    cin  >>  carrera;
    for(int i=0; i<3;i++){
    cout << "Calificacion del parcial " << i+1 <<" : ";
    cin >> calificaciones[i];
    }
    cout << "Proyecto : " ;
    cin  >> calificaciones[3];
    cout << " Faltas: " ;
    cin  >>  faltas;

    for(int i=0; i<=3;i++){
    promedio += calificaciones[i];
    }
    promedio /= 4;

    archivo.open("CalificacionFinal.txt",ios::out|ios::trunc);
    cout << "creando archivo .... " << endl;
    archivo <<endl<< "                           UAA                       "<<endl;
    archivo << "                                27 de agosto del 2021"<<endl<<endl;
    archivo << " Acta de promedio final                              "<<endl;
    archivo << "     - Alummno  :  " << nombre <<endl;
    archivo << "     - ID       :  " << ID <<endl;
    archivo << "     - Carrera  :  " << carrera <<endl;
    archivo << "     - Promedio :  " << promedio <<endl;
    archivo << "     - Faltas   :  " << faltas <<endl<<endl<<endl<<endl;
    archivo << "Resultado final de materia : ";
    if( faltas>16 || promedio < 6.5){
    archivo << "REPROBADO";
    }else{
    archivo << "APROBADO";
    }
    cout << "archivo generado " << endl;
    archivo.close();
    return 0;
}
