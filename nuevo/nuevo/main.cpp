#include <fstream>
#include <iostream>
using namespace std;

//void capturar_alumno(string nombre,string apellido,string carrera,string semestre,string grupo,int contador1);


class Alumno{
public:
    Alumno();
    string nombre,apellido,carrera,semestre,grupo;
    void alumno(string nombre,string apellido,string carrera,string semestre, string grupo);
};

Alumno::Alumno(){
    this->nombre="";
    this->apellido="";
    this->carrera="";
    this->semestre="";
    this->grupo="";
}

void Alumno::alumno(string nombre,string apellido,string carrera,string semestre, string grupo){
    this->nombre=nombre;
    this->apellido=apellido;
    this->carrera=carrera;
    this->semestre=semestre;
    this->grupo=grupo;
}

class Calificaciones{
public:
    Calificaciones();
    float matematicas,programacion,estructuras;
    void calificaciones(float matematicas,float programacion,float estructuras);
};

Calificaciones::Calificaciones(){
    this->matematicas=0;
    this->programacion=0;
    this->estructuras=0;
}

void Calificaciones::calificaciones(float matematicas,float programacion,float estructuras){
    this->matematicas=matematicas;
    this->programacion=programacion;
    this->estructuras=estructuras;
}



int main() {
    Alumno alumno[1000];
    Calificaciones calificaciones[1000];
    int opcion,contador1=0,contador2=0,contador3=0,contador4=0,contador5=0;
    string nombre,apellido,carrera,semestre,grupo;
    float matematicas,programacion,estructura;
    do{
        cout<<"\nMENU" << endl;
        cout<<"1. Capturar Datos y calicaciones del Alumno"<<endl;
        cout<<"2. Mostrar Datos del Alumno"<<endl;
        cout<<"3. Guardar Datos (Archivo y Copia)"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Selecciona una Opcion = ";
        cin>>opcion;
        switch(opcion){
            case 1:
                //DATOS DEL ALUMNO
                cout<<"\n* CAPTURANDO ALUMNO"<<endl;
                cout<<"Nombre = ";
                cin>>nombre;
                cout<<"Apellido = ";
                cin>>apellido;
                cout<<"Carrera = ";
                cin>>carrera;
                cout<<"Semestre = ";
                cin>>semestre;
                cout<<"Grupo = ";
                cin>>grupo;
                alumno[contador1].alumno(nombre,apellido,carrera,semestre,grupo);
                contador1++;
                alumno[contador1].
                //CALIFICACIONES DEL ALUMNO
                cout<<"* CALIFICACIONES"<<endl;
                for(int i=0;i<3;i++){
                    cout<<"Parcial "<<i+1<<endl;
                    cout<<"     Matematicas = ";
                    cin>>matematicas;
                    cout<<"     Programación = ";
                    cin>>programacion;
                    cout<<"     Estructuras = ";
                    cin>>estructura;
                    calificaciones[contador2].calificaciones(matematicas,programacion,estructura);
                    contador2++;
                }
                cout<<"\nALUMNO GUARDADO"<<endl;
                break;
            case 2:
                cout<<"\n";
                cout<<"MOSTRANDO TODOS LOS ALUMNOS"<<endl;
                for(int i=0;i<contador1;i++){
                    cout<<"\n** Alumno "<<i+1<<" ** \nNombre = "+alumno[i].nombre<<" "+alumno[i].apellido<<"\nCarrera = "<<alumno[i].carrera<<"\nSemestre = "<<alumno[i].semestre<<"\nGrupo = "<<alumno[i].grupo<<endl;
                    for (int j=0;j<3;j++){
                        cout<<"Parcial "<<j+1<<"\n    Matematicas = "<<+calificaciones[contador3].matematicas<<"\n    Programacion = "<<+calificaciones[contador3].programacion<<"\n    Estructuras = "<<+calificaciones[contador3].estructuras<<endl;
                        contador3++;
                    }
                }
                break;
            case 3:
                fstream Arch;
                Arch.open("Datos Alumno.txt", ios::out|ios::trunc);
                for(int i=0;i<contador1;i++){
                    cout<<"\nDATOS DEL ALUMNO "<<i+1<<endl;
                    cout<<"Nombre del Alumno = "<<alumno[i].nombre<<" "<<alumno[i].apellido<<endl;
                    cout<<"Carrera = "<<alumno[i].carrera << endl;
                    cout<<"Semestre = "<<alumno[i].semestre<< endl;
                    cout<<"Grupo = "<<alumno[i].grupo<< endl;
                    cout<<i<<endl;
                    cout<<"\nCalificaciones Parciales"<<endl;
                    for(int j=0;j<3;j++){
                        cout<<"\nPARCIAL "<<j+1<<endl;
                        cout<<"Matematicas =  "<<calificaciones[contador4].matematicas<<endl;
                        cout<<"Programacion = "<<calificaciones[contador4].programacion<<endl;
                        cout<<"Estructuras: "<<calificaciones[contador4].estructuras<<endl;
                        contador4++;
                    }
                    Arch.close();
                }
                cout<<"\nDATOS GUARDADOS EN ARCHIVO DE TEXTO .TXT"<<endl;
                cout<<"\n";
                Arch.open("Datos Alumno (Copia).dat", ios::out|ios::trunc);
                for(int i=0;i<contador1;i++){
                    cout<<"\nDATOS DEL ALUMNO "<<i+1<<endl;
                    cout<<"Nombre del Alumno = "<<alumno[i].nombre[i]<<" "<<alumno[i].apellido[i]<<endl;
                    cout<<"Carrera = "<<alumno[i].carrera<<endl;
                        cout<<"Semestre = "<<alumno[i].semestre<<endl;
                        cout<<"Grupo = "<<alumno[i].grupo<<endl;
                        cout<<i<<endl;
                        cout<<"\nCalificaciones Parciales: \n"<<endl;
                        for(int j=0;j<3;j++){
                            cout<<"\nPARCIAL "<<j+1<<endl;
                            cout<<"Matematicas = "<<calificaciones[contador5].matematicas<<endl;
                            cout<<"Programacion = "<<calificaciones[contador5].programacion<<endl;
                            cout<<"Estructuras =  "<<calificaciones[contador5].estructuras<<endl;
                            contador5++;
                        }
                    Arch.close();
                    }
                    cout<<"DATOS GUARDADOS EN ARCHIVO BINARIO .DAT"<<endl;
                break;
        }
    }while(opcion!=4);
}

//void capturar_alumno(string nombre,string apellido,string carrera,string semestre,string grupo,int contador1){
//    Alumno alumno[1000];
//    cout<<"\n* CAPTURANDO ALUMNO"<<endl;
//    cout<<"Nombre = ";
//    cin>>nombre;
//    cout<<"Apellido = ";
//    cin>>apellido;
//    cout<<"Carrera = ";
//    cin>>carrera;
//    cout<<"Semestre = ";
//    cin>>semestre;
//    cout<<"Grupo = ";
//    cin>>grupo;
//    alumno[contador1].alumno(nombre,  apellido,  carrera,  semestre,  grupo);
//    contador1++;
//}
