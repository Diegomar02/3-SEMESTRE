#include <iostream>
#include <fstream>

using namespace std;
// CLASE...

class Alumno{
    public:
    //ALUMNO
        string Nombre,Apellido,Carrera,Grupo,Semestre;
    //CALIFICACIONES
        float Parcial1_M,Parcial1_E,Parcial1_P,Parcial2_M,Parcial2_E,Parcial2_P,Parcial3_M,Parcial3_E,Parcial3_P;
    
        Alumno();
        void alumno(string Nombre,string Apellido,string Carrera,string Grupo,string Semestre,float Parcial1_M,float Parcial1_E,float Parcial1_P,float Parcial2_M,float Parcial2_E,float Parcial2_P,float Parcial3_M,float Parcial3_E,float Parcial3_P);
        ~Alumno();
    
        void Menu();
//ALUMNO
        void capturar(string Nombre,string Apellido,string Carrera,string Grupo,string Semestre,float Parcial1_M,float Parcial1_E,float Parcial1_P,float Parcial2_M,float Parcial2_E,float Parcial2_P,float Parcial3_M,float Parcial3_E,float Parcial3_P,int contador1,Alumno alumno[1000]);
        
    
        void mostrar(int contador1,Alumno alumno[1000]);
        void guardar_archivo();
};

Alumno::Alumno(){
    this->Nombre="";
    this->Apellido="";
    this->Carrera="";
    this->Grupo="";
    this->Semestre="";
    
    this->Parcial1_M=0;
    this->Parcial1_E=0;
    this->Parcial1_P=0;
    this->Parcial2_M=0;
    this->Parcial2_E=0;
    this->Parcial2_P=0;
    this->Parcial2_M=0;
    this->Parcial2_E=0;
    this->Parcial2_P=0;
};

void Alumno::alumno(string Nombre,string Apellido,string Carrera,string Grupo,string Semestre,float Parcial1_M,float Parcial1_E,float Parcial1_P,float Parcial2_M,float Parcial2_E,float Parcial2_P,float Parcial3_M,float Parcial3_E,float Parcial3_P){
    this->Nombre=Nombre;
    this->Apellido=Apellido;
    this->Carrera=Carrera;
    this->Grupo=Grupo;
    this->Semestre=Semestre;
    
    this->Parcial1_M=Parcial1_M;
    this->Parcial1_E=Parcial1_E;
    this->Parcial1_P=Parcial1_P;
    this->Parcial2_M=Parcial2_M;
    this->Parcial2_E=Parcial2_E;
    this->Parcial2_P=Parcial2_P;
    this->Parcial3_M=Parcial3_M;
    this->Parcial3_E=Parcial3_E;
    this->Parcial3_P=Parcial3_P;
}


Alumno::~Alumno(){
    
}

void Alumno::Menu(){
    Alumno alumno[1000];
    int opcion,contador1=0,contador2=0,contador3=0,contador4=0,contador5=0;
    string Nombre,Apellido,Carrera,Semestre,Grupo;
    float Matematicas,Estructuras,Programacion;
    do{
        cout<<"\nMENU" << endl;
        cout<<"1. Capturar Datos del Alumno"<<endl;
        cout<<"2. Mostrar Datos del Alumno"<<endl;
        cout<<"3. Guardar Datos (Archivo y Copia)"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Selecciona una Opcion = ";
        cin>>opcion;
        switch(opcion){
            case 1:
                
                break;
            case 2:
                capturar(Nombre,Apellido,Carrera,Grupo,Semestre,Parcial1_M,Parcial1_E,Parcial1_P,Parcial2_M,  Parcial2_E,Parcial2_P,Parcial3_M,Parcial3_E,Parcial3_P,contador1,alumno);
                break;
            case 3:
                guardar_archivo();
                break;
        }
    } while (opcion != 4);
    cout<<"VUELVA PRONTO"<<endl;
}

void Alumno::capturar(string Nombre,string Apellido,string Carrera,string Grupo,string Semestre,float Parcial1_M,float Parcial1_E,float Parcial1_P,float Parcial2_M,float Parcial2_E,float Parcial2_P,float Parcial3_M,float Parcial3_E,float Parcial3_P,int contador1,Alumno alumno[1000]){
    cout<<endl;
    cout<<"\nDATOS DEL ALUMNO\n";
    cout<<"Nombre del Alumno = ";
    cin>>Nombre;
    cout<<"Apellido del Alumno = ";
    cin>>Apellido;
    cout<<"Carrera = ";
    cin>>Carrera;
    cout<<"Semestre = ";
    cin>>Semestre;
    cout<<"Grupo = ";
    cin>>Grupo;
    cout << "\nCALIFICACIONES PARCIALES\n";
    cout<<"Parcial 1"<<endl;
    cout<<"Matematicas = ";
    cin>>Parcial1_M;
    cout<<"Estructuras =";
    cin>>Parcial1_E;
    cout<<"Programación = ";
    cin>>Parcial1_P;
    //PARCIAL 2
    cout<<"Parcial 2"<<endl;
    cout<<"Matematicas = ";
    cin>>Parcial2_M;
    cout<<"Estructuras =";
    cin>>Parcial2_E;
    cout<<"Programación = ";
    cin>>Parcial2_P;
    //PARCIAL 3
    cout<<"Parcial 3"<<endl;
    cout<<"Matematicas = ";
    cin>>Parcial3_M;
    cout<<"Estructuras =";
    cin>>Parcial3_E;
    cout<<"Programación = ";
    cin>>Parcial3_P;
    alumno[contador1].alumno(Nombre,Apellido,Carrera,Grupo,Semestre,Parcial1_M,Parcial1_E,Parcial1_P,  Parcial2_M,Parcial2_E,Parcial2_P,Parcial3_M,Parcial3_E,Parcial3_P);
    contador1++;
}




void Alumno::mostrar(int contador1,Alumno alumno[1000]){
    //Verificar cuantos alumnos hay registrados
    cout<<"MOSTRANDO TODOS LOS ALUMNOS"<<endl;
    for(int i=0;i<contador1;i++){
        cout<<"\n** Alumno "<<i+1<<" ** \nNombre = "+alumno[i].Nombre<<" "+alumno[i].Apellido<<"\nCarrera = "<<alumno[i].Carrera<<"\nSemestre = "<<alumno[i].Semestre<<"\nGrupo = "<<alumno[i].Grupo<<"\n\nParcial "<<i+1<<"\nMatematicas = "+alumno[i].Nombre<<endl;
    }
}

void Alumno::guardar_archivo(){
    fstream Arch;
    Arch.open("Datos Alumno.txt", ios::out|ios::trunc);
    Arch << "Nombre del Alumno: " << Nombre << " " << Apellido << endl;
    Arch << "Carrera: " << Carrera << endl;
    Arch << "Semestre: " << Semestre << endl;
    Arch << "Grupo: " << Grupo << endl;
    Arch << "\nCalificaciones Parciales: \n" << endl;
//    Arch << "\nPARCIAL " << Parciales -> Parcial << " : \n" << endl;
//    Arch << "Matematicas: " <<Matematicas << endl;
//    Arch << "Programacion: " <<Programacion << endl;
//    Arch << "Estructuras: " << Estructuras << endl;

    cout << "\nDATOS GUARDADOS EN ARCHIVO DE TEXTO - " << endl;
    cout << "\n";
    Arch.close();
    Arch.open("Datos Alumno (Copia).dat", ios::out|ios::trunc);
    Arch << "Nombre del Alumno: " << Nombre << endl;
    Arch << "Carrera: " << Carrera << endl;
    Arch << "Semestre: " << Semestre << endl;
    Arch << "Grupo: " << Grupo << endl;
    Arch << "Calificaciones Parciales: \n" << endl;
//    Arch << "\nPARCIAL " << Parciales -> Parcial << " : \n" << endl;
//    Arch << "Matematicas: " <<Matematicas << endl;
//    Arch << "Programacion: " << Programacion << endl;
//    Arch << "Estructuras: " <<  Estructuras << endl;
    cout<<"\n DATOS GUARDADOS EN ARCHIVO BINARIO - " << endl;
    cout<<"\n";
    Arch.close();
}

int main(){
    Alumno P1;
    Alumno P0;
}
