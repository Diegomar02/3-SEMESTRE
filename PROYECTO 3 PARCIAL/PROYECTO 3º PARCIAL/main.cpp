// PROYECTO "PROGRAMACION II Y ESTRUCTURAS DE DATOS"...

/* INTEGRANTES:

- MARQUEZ GOMEZ DIEGO
- DELGADO RAMIREZ FERNANDA FABIOLA
- HERNANDEZ SEPULVEDA JOSE ANDRES
- ESPARZA SEGOVIA DAVID MIGUEL */

#include <iostream>

using namespace std;
// CLASE...

class Alumno{
    private:
        string Nombre;
        string Apellido;
        string Carrera;
        int Semestre;
        char Grupo;
        // LISTA LIGADA...
        struct Calificaciones{
            int Parcial[3];
            float Matematicas[3];
            float Estructuras[3];
            float Programacion[3];
            Calificaciones*Siguiente;
        };
        
    public:
        Alumno();
        Alumno(string, string, string, int, char);
        Alumno(const Alumno &);
        ~Alumno();
        void Menu();
        void Captura(Calificaciones *&);
        void Mostrar(Calificaciones *);
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
    int Op;
    do{ // OPCIONES DISPONIBLES...
        cout<<"\n \t\t - MENU - \n" << endl;
        cout<<" - Capturar Datos del Alumno ................................ 1 \n";
        cout<<" - Mostrar Datos del Alumno ................................. 2 \n";
        cout<<" - Editar Datos ............................................. 3 \n";
        cout<<" - Guardar Datos ............................................ 4 \n";
        cout<<" - Leer Datos ............................................... 5 \n" << endl;
        cout << " - Salir .................................................... 6 \n" << endl;
        cout << " - Selecciona una Opcion: ";
        cin >> Op;
        switch(Op){ // SELECCION DE OPCION...
            case 1: Captura(Parciales); system("pause"); break;
            case 2: Mostrar(Parciales) ; system("pause"); break;
        }
        system("cls");
    } while (Op != 6);
    cout << "\n";
    cout << " - VUELVA PRONTO - ";
}

void Alumno::Captura(Calificaciones *&Parciales){
    int Aux;
    float Aux1;
    float Aux2;
    float Aux3;
    system("cls");
    cout << "\n" << endl;
    cout << " - Nombre del Alumno: ";
    cin >> Nombre;
    cout << " - Apellido del Alumno: ";
    cin >> Apellido;
    cout << " - Carrera: ";
    cin >> Carrera;
    cout << " - Semestre: ";
    cin >> Semestre;
    cout << " - Grupo: ";
    cin >> Grupo;
    Calificaciones *AUX;
    cout << " - Calificaciones Parciales: \n" << endl;
    for (int i=1;i<=3;i++){
        cout << "\n";
        cout << " - Calificacion Matematicas (Parcial "<<i<< "): ";
        cin >> Aux1;
        cout << " - Calificacion Programacion (Parcial " << i<< "): ";
        cin >> Aux2;
        cout << " - Calificacion Estructuras (Parcial " << i << "): ";
        cin >> Aux3;
        Calificaciones*Nuevo=new Calificaciones();
        Nuevo -> Parcial[i]=i;
        Nuevo -> Matematicas[i]=Aux1;
        Nuevo -> Programacion[i]=Aux2;
        Nuevo -> Estructuras[i]=Aux3;
        Nuevo -> Siguiente = NULL;
        if(Parciales == NULL){
            Parciales = Nuevo;
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
    system("cls");
    cout << "\n - DATOS DEL ALUMNO - \n" << endl;
    cout << " - Nombre del Alumno: " << Nombre << " " << Apellido << endl;
    cout << " - Carrera: " << Carrera << endl;
    cout << " - Semestre: " << Semestre << endl;
    cout << " - Grupo: " << Grupo << endl;
    cout << " - Calificaciones Parciales: \n" << endl;
    for (int i=1;i<=3;i++){
        cout << "\n        PARCIAL " << Parciales-> Parcial[i] << " : \n" << endl;
        cout << "         - Matematicas: " << Parciales -> Matematicas[i] << endl;
        cout << "         - Programacion: " << Parciales -> Programacion[i] << endl;
        cout << "         - Estructuras: " << Parciales -> Estructuras[i] << endl;
    }
    cout << "\n" << endl;
}

int main(){
    Alumno P0;
    
}

