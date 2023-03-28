// PROYECTO "PROGRAMACION II Y ESTRUCTURAS DE DATOS"...

/* INTEGRANTES:

- MARQUEZ GOMEZ DIEGO...
- DELGADO RAMIREZ FERNANDA FABIOLA...
- ESPARZA SEGOVIA DAVID MIGUEL...
*/
#include <iostream>
#include <fstream>

using namespace std;
// CLASE...
class Alumno{
    private:
        string Nombre;
        string Apellido;
        string Carrera;
        int Semestre;
        char Grupo;
        int* HorasAcumuladas;
        // LISTA LIGADA...
        struct Calificaciones{
            int Parcial;
            float Matematicas[];
            float Estructuras[];
            float Programacion[];
            Calificaciones *Siguiente;
        };
        
    public:
        Alumno();
        Alumno(string, string, string, int, char);
        Alumno(const Alumno &);
        ~Alumno();
        void Menu();
        void Captura(Calificaciones *&);
        void Mostrar(Calificaciones *);
        void Guardar(Calificaciones *);
};

Alumno::Alumno(){
    string Nombre, Apellido, Carrera = " ";
    int Semestre = 0;
    char Grupo = ' ';
    
    Menu();

}

Alumno::Alumno(string Nombre, string Apellido, string Carrera, int Semestre, char Grupo){
    
    Menu();
}

Alumno::Alumno(const Alumno & P1){
    
    this -> Nombre = P1.Nombre;
    this -> Apellido = P1.Apellido;
    this -> Carrera = P1.Carrera;
    this -> Semestre = P1.Semestre;
    this -> Grupo = P1.Grupo;
    Menu();

}

Alumno::~Alumno(){
    
}

void Alumno::Menu(){
    Calificaciones *Parciales = NULL;
    int opcion;
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
                Captura(Parciales);
                break;
            case 2: Mostrar(Parciales);
                break;
            case 3: Guardar(Parciales);
                break;
        }
    } while (opcion != 4);
    cout<<"VUELVA PRONTO"<<endl;
}

void Alumno::Captura(Calificaciones *&Parciales){
    int Aux;
    float Aux1;
    float Aux2;
    float Aux3;
    HorasAcumuladas=new int [3];
    cout<<endl;
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
    cout<<"Horas Acumuladas"<<endl;
    cout<<" Formacion Humanista = ";
    cin >> HorasAcumuladas[0];
    cout<<" Servicio Social = ";
    cin>>HorasAcumuladas[1];
    cout<<" Practicas Profesionales: ";
    cin>>HorasAcumuladas[2];
    Calificaciones*AUX;
    cout<<"\nCalificaciones Parciales = \n"<<endl;
    for (int i=0;i<3;i++){
        cout<<"\n";
        cout<<"Calificacion Matematicas (Parcial "<<i+1<<") = ";
        cin>>Aux1;
        cout<<"Calificacion Programacion (Parcial "<<i+1<<") = ";
        cin>>Aux2;
        cout<<"Calificacion Estructuras (Parcial "<<i+1<<") = ";
        cin>>Aux3;
        Calificaciones *Nuevo=new Calificaciones();
        Nuevo->Parcial=i+1;
        Nuevo->Matematicas=Aux1;
        Nuevo->Programacion=Aux2;
        Nuevo->Estructuras=Aux3;
        Nuevo->Siguiente=NULL;
        if(Parciales==NULL){
            Parciales=Nuevo;
        }
        else{
            AUX = Parciales;
            while(AUX -> Siguiente != NULL){
                AUX = AUX -> Siguiente;
            }
            AUX -> Siguiente = Nuevo;
        }
    }
    cout << "\n";
}

void Alumno::Mostrar(Calificaciones *Parciales){
    cout << "\nDATOS DEL ALUMNO" << endl;
    
    cout << "Nombre del Alumno = " << Nombre << " " << Apellido << endl;
    cout << "Carrera = " << Carrera << endl;
    cout << "Semestre = " << Semestre << endl;
    cout << "Grupo = " << Grupo << endl;
    cout << "Horas Acumuladas: \n" << endl;
    cout << "Formacion Humanista: " << HorasAcumuladas [0];
    cout << "Servicio Social: " << HorasAcumuladas [1];
    cout << "Practicas Profesionales: " << HorasAcumuladas [2] << endl;
    cout << "Calificaciones Parciales: \n" << endl;
    
    Calificaciones *AUX = Parciales;
    
    while(AUX != NULL){
        
        cout <<"\nPARCIAL " << Parciales -> Parcial << " : \n" << endl;
        cout <<"Matematicas: " << Parciales -> Matematicas << endl;
        cout <<"Programacion: " << Parciales -> Programacion << endl;
        cout <<"Estructuras: " << Parciales -> Estructuras << endl;
        AUX = AUX -> Siguiente;
    }
    cout << "\n" << endl;
}
void Alumno::Guardar(Calificaciones *Parciales){
    fstream Arch;
    Arch.open("Datos Alumno.txt", ios::out|ios::trunc);
    Arch << "Nombre del Alumno: " << Nombre << " " << Apellido << endl;
    Arch << "Carrera: " << Carrera << endl;
    Arch << "Semestre: " << Semestre << endl;
    Arch << "Grupo: " << Grupo << endl;
    Arch << "Horas Acumuladas: \n" << endl;
    Arch << "Formacion Humanista: " << HorasAcumuladas [0];
    Arch << "Servicio Social: " << HorasAcumuladas [1];
    Arch << "Practicas Profesionales: " << HorasAcumuladas [2] << endl;
    Arch << "\nCalificaciones Parciales: \n" << endl;
    Calificaciones *AUX = Parciales;
    while(AUX != NULL){
        Arch << "\nPARCIAL " << Parciales -> Parcial << " : \n" << endl;
        Arch << "Matematicas: " << Parciales -> Matematicas << endl;
        Arch << "Programacion: " << Parciales -> Programacion << endl;
        Arch << "Estructuras: " << Parciales -> Estructuras << endl;
        AUX = AUX -> Siguiente;
    }
    cout << "\nDATOS GUARDADOS EN ARCHIVO DE TEXTO - " << endl;
    cout << "\n";
    Arch.close();
    Arch.open("Datos Alumno (Copia).dat", ios::out|ios::trunc);
    Arch << "Nombre del Alumno: " << Nombre << endl;
    Arch << "Carrera: " << Carrera << endl;
    Arch << "Semestre: " << Semestre << endl;
    Arch << "Grupo: " << Grupo << endl;
    Arch << "Calificaciones Parciales: \n" << endl;
    Calificaciones *AUX2 = Parciales;
    while(AUX2 != NULL){
        Arch << "\nPARCIAL " << Parciales -> Parcial << " : \n" << endl;
        Arch << "Matematicas: " << Parciales -> Matematicas << endl;
        Arch << "Programacion: " << Parciales -> Programacion << endl;
        Arch << "Estructuras: " << Parciales -> Estructuras << endl;
        AUX2=AUX2->Siguiente;
    }
    cout<<"\n DATOS GUARDADOS EN ARCHIVO BINARIO - " << endl;
    cout<<"\n";
    Arch.close();
}

int main(){
    Alumno P0;
    Alumno P1;
}

