/* INTEGRANTES:
- MARQUEZ GOMEZ DIEGO...
- DELGADO RAMIREZ FERNANDA FABIOLA...
- ESPARZA SEGOVIA DAVID MIGUEL...
*/
#include <iostream>
#include <fstream>

using namespace std;
// CLASE...
class Escuela{
    private:
        // LISTA LIGADA...
    struct Alumno{
        string* Nombre;
        string* Apellido;
        string* Id;
        string* Carrera;
        char* Grupo;
        int* Semestre;
    };
    struct Calificaciones{
        float* Parcial1_M;
        float* Parcial1_E;
        float* Parcial1_P;
        float* Parcial2_M;
        float* Parcial2_E;
        float* Parcial2_P;
        float* Parcial3_M;
        float* Parcial3_E;
        float* Parcial3_P;
    };
    struct Promedio{
        float* Promedio;
    };
        
public:
    Escuela();
    Escuela(string, string, string, int, char);
    ~Escuela();
    void Menu();
    void Captura_alumno(struct Alumno&alumno,int contador1);
    void Captura_calificaciones(struct Calificaciones&calificaciones,int contador1);
    void Mostrar(struct Alumno&alumno,struct Calificaciones&calificaciones,int contador1);
    void Guardar(struct Alumno&alumno,struct Calificaciones&calificaciones,struct Promedio&promedio,int contador1);
    void Promedio(struct Alumno&alumno,struct Calificaciones&calificaciones,struct Promedio&promedio,int contador1);
    
    void Busqueda(struct Alumno&alumno,int contador1,string encontrar);
    void Ordenar(struct Alumno&alumno,struct Calificaciones&calificaciones,struct Promedio&promedio,int contador1,int ordenar,int ordenar1);
};
Escuela::Escuela(){
    string Nombre,Apellido,Id,Carrera,Promedio = " ";
    int Semestre = 0;
    char Grupo = ' ';
    Menu();
    
}
Escuela::Escuela(string Nombre, string Apellido, string Carrera, int Semestre, char Grupo){
    Menu();
}
Escuela::~Escuela(){
}





void Escuela::Menu(){
    int opcion,contador1=0,ordenar,ordenar1;
    string encontrar="";
    struct Alumno alumno;
    alumno.Nombre=new string[1000];
    alumno.Apellido=new string[1000];
    alumno.Id=new string[1000];
    alumno.Carrera=new string[1000];
    alumno.Semestre=new int[1000];
    alumno.Grupo=new char[1000];
    struct Calificaciones calificaciones;
    calificaciones.Parcial1_M=new float[1000];
    calificaciones.Parcial1_E=new float[1000];
    calificaciones.Parcial1_P=new float[1000];
    calificaciones.Parcial2_M=new float[1000];
    calificaciones.Parcial2_E=new float[1000];
    calificaciones.Parcial2_P=new float[1000];
    calificaciones.Parcial3_M=new float[1000];
    calificaciones.Parcial3_E=new float[1000];
    calificaciones.Parcial3_P=new float[1000];
    struct Promedio promedio;
    promedio.Promedio=new float[3];
    do{
        cout<<"\nMENU" << endl;
        cout<<"1. Capturar Datos del Alumno"<<endl;
        cout<<"2. Mostrar Datos del Alumno"<<endl;
        cout<<"3. Promedio por Alumno"<<endl;
        cout<<"4. Buscar x ID"<<endl;
        cout<<"5. Ordenar calificaciones finales"<<endl;
        cout<<"6. Guardar Datos (Archivo y Copia)"<<endl;
        cout<<"7. Salir"<<endl;
        cout<<"Selecciona una Opcion = ";
        cin>>opcion;
        switch(opcion){
            case 1:
                Captura_alumno(alumno,contador1);
                Captura_calificaciones(calificaciones,contador1);
                contador1++;
                cout<<"\n\n";
                break;
            case 2:
                Mostrar(alumno,calificaciones,contador1);
                cout<<"\n\n";
                break;
            case 3:
                Promedio(alumno,calificaciones,promedio,contador1);
                cout<<"\n\n";
                break;
            case 4:
                cout<<"\n¿ID a buscar? = ";
                cin>>encontrar;
                Busqueda(alumno,contador1,encontrar);
                cout<<"\n\n";
                break;
            case 5:
                if(contador1==0){
                    cout<<endl;
                    cout<<"\nNO tienes alumnos registrados";
                }else{
                    cout<<"\nTienes "<<contador1<<" alumn@s registrados"<<endl;
                    for(int i=0;i<contador1;i++){
                        cout<<"Alumn@ "<<i+1<<" = "<<alumno.Nombre[i]<<" "<<alumno.Apellido[i]<<endl;
                    }
                    cout<<"Numero de alumno que sea acomodar sus calificaciones = ";
                    cin>>ordenar;
                    if(ordenar<=contador1){
                        cout<<"Manera de ordenacion ="<<endl;
                        cout<<" 1. Menor a mayor"<<endl;
                        cout<<" 2. Mayor a menor"<<endl;
                        cout<<"¿Opcion? = ";
                        cin>>ordenar1;
                        Ordenar(alumno,calificaciones,promedio,contador1,ordenar,ordenar1);
                    }else{
                        cout<<"OPCION NO VALIDA";
                    }
                }
                cout<<"\n\n";
                break;
                
            case 6:
                Guardar(alumno,calificaciones,promedio,contador1);
                cout<<"\n\n";
                break;
        }
    } while (opcion!=7);
    cout<<"VUELVA PRONTO"<<endl;
    return;

}

void Escuela::Captura_alumno(struct Alumno&alumno,int contador1){
    cout<<"\nDATOS DEL ALUMNO"<<endl;
    cout<<"Nombre = ";
    cin>>alumno.Nombre[contador1];
    cout<<"Apellido = ";
    cin>>alumno.Apellido[contador1];
    cout<<"Id = ";
    cin>>alumno.Id[contador1];
    cout<<"Carrera = ";
    cin>>alumno.Carrera[contador1];
    cout<<"Semestre = ";
    cin>>alumno.Semestre[contador1];
    cout<<"Grupo = ";
    cin>>alumno.Grupo[contador1];
}

void Escuela::Captura_calificaciones(struct Calificaciones&calificaciones,int contador1){
    cout<<"\nCALIFICACIONES"<<endl;
    cout<<"** Parcial 1 "<<endl;
    cout<<"Matematicas = ";
    cin>>calificaciones.Parcial1_M[contador1];
    cout<<"Estructurs = ";
    cin>>calificaciones.Parcial1_E[contador1];
    cout<<"Programacion = ";
    cin>>calificaciones.Parcial1_P[contador1];
    cout<<"** Parcial 2 "<<endl;
    cout<<"Matematicas = ";
    cin>>calificaciones.Parcial2_M[contador1];
    cout<<"Estructurs = ";
    cin>>calificaciones.Parcial2_E[contador1];
    cout<<"Programacion = ";
    cin>>calificaciones.Parcial2_P[contador1];
    cout<<"** Parcial 3 "<<endl;
    cout<<"Matematicas = ";
    cin>>calificaciones.Parcial3_M[contador1];
    cout<<"Estructurs = ";
    cin>>calificaciones.Parcial3_E[contador1];
    cout<<"Programacion = ";
    cin>>calificaciones.Parcial3_P[contador1];
}

void Escuela::Mostrar(struct Alumno&alumno,struct Calificaciones&calificaciones,int contador1){
    for(int i=0;i<contador1;i++){
        cout << "\n\n\nDATOS DEL ALUMNO "<<i+1<<endl;
        cout << "Nombre del Alumno = " <<alumno.Nombre[i]<<" " <<alumno.Apellido[i]<<endl;
        cout<<"Id = "<<alumno.Id[i]<<endl;
        cout << "Carrera = " <<alumno.Carrera[i] << endl;
        cout << "Semestre = " <<alumno.Semestre[i]<< endl;
        cout << "Grupo = " << alumno.Grupo[i]<< endl;
        cout << "\nCALIFICACIONES PARCIALES" << endl;
        cout<<"** PARCIAL 1 "<<endl;
        cout<<"Matematicas = "<<calificaciones.Parcial1_M[i]<<endl;
        cout<<"Estructuras = "<<calificaciones.Parcial1_E[i]<<endl;
        cout<<"Programacion = "<<calificaciones.Parcial1_P[i]<<endl;
        cout<<"** PARCIAL 2 "<<endl;
        cout<<"Matematicas = "<<calificaciones.Parcial2_M[i]<<endl;
        cout<<"Estructuras = "<<calificaciones.Parcial2_E[i]<<endl;
        cout<<"Programacion = "<<calificaciones.Parcial2_P[i]<<endl;
        cout<<"** PARCIAL 3 "<<endl;
        cout<<"Matematicas = "<<calificaciones.Parcial3_M[i]<<endl;
        cout<<"Estructuras = "<<calificaciones.Parcial3_E[i]<<endl;
        cout<<"Programacion = "<<calificaciones.Parcial3_P[i]<<endl;
    }
}

void Escuela::Guardar(struct Alumno&alumno,struct Calificaciones&calificaciones,struct Promedio&promedio,int contador1){
    fstream Arch;
    //.txt
    Arch.open("Datos Alumno.txt", ios::out|ios::trunc);
    for(int i=0;i<contador1;i++){
        promedio.Promedio[0]=(calificaciones.Parcial1_M[i]+calificaciones.Parcial2_M[i]+calificaciones.Parcial3_M[i])/3;
        promedio.Promedio[1]=(calificaciones.Parcial1_E[i]+calificaciones.Parcial2_E[i]+calificaciones.Parcial3_E[i])/3;
        promedio.Promedio[2]=(calificaciones.Parcial1_P[i]+calificaciones.Parcial2_P[i]+calificaciones.Parcial3_P[i])/3;
        Arch << "Nombre del Alumno = "<<alumno.Nombre[i]<<" "<<alumno.Apellido[i]<<endl;
        Arch<<"ID = "<<alumno.Id[i]<<endl;
        Arch << "Carrera =  " <<alumno.Carrera[i]<<endl;
        Arch << "Semestre = " <<alumno.Semestre[i]<<endl;
        Arch << "Grupo =  " <<alumno.Grupo[i] << endl;
        Arch << "\nCALIFICACIONES PARCIALES" << endl;
        Arch << "* PARCIAL 1"<<endl;
        Arch << "Matematicas = " <<calificaciones.Parcial1_M[i] << endl;
        Arch << "Programacion = " <<calificaciones.Parcial1_E[i]<< endl;
        Arch << "Estructuras = " <<calificaciones.Parcial1_P[i]<< endl;
        Arch << "* PARCIAL 2"<<endl;
        Arch << "Matematicas = " <<calificaciones.Parcial2_M[i] << endl;
        Arch << "Programacion = " <<calificaciones.Parcial2_E[i]<< endl;
        Arch << "Estructuras = " <<calificaciones.Parcial2_P[i]<< endl;
        Arch << "* PARCIAL 3"<<endl;
        Arch << "Matematicas = " <<calificaciones.Parcial2_M[i] << endl;
        Arch << "Programacion = " <<calificaciones.Parcial2_E[i]<< endl;
        Arch << "Estructuras = " <<calificaciones.Parcial2_P[i]<< endl;
        Arch<<"*CALIFICACIONES FINALES"<<endl;
        Arch<<"Matematicas = "<<promedio.Promedio[0]<<endl;
        Arch<<"Estructuras = "<<promedio.Promedio[1]<<endl;
        Arch<<"Programacion = "<<promedio.Promedio[2]<<endl;
        
        
    }
    cout << "\nDATOS GUARDADOS EN ARCHIVO DE TEXTO - " << endl;
    Arch.close();
    //.dat
    Arch.open("Datos Alumno (Copia).dat", ios::out|ios::trunc);
    for(int i=0;i<contador1;i++){
        promedio.Promedio[0]=(calificaciones.Parcial1_M[i]+calificaciones.Parcial2_M[i]+calificaciones.Parcial3_M[i])/3;
        promedio.Promedio[1]=(calificaciones.Parcial1_E[i]+calificaciones.Parcial2_E[i]+calificaciones.Parcial3_E[i])/3;
        promedio.Promedio[2]=(calificaciones.Parcial1_P[i]+calificaciones.Parcial2_P[i]+calificaciones.Parcial3_P[i])/3;
        Arch<<"Alumno "<<i+1<<endl;
        Arch<<"Nombre del Alumno: "<<alumno.Nombre[i]<<" "<<alumno.Apellido[i]<<endl;
        Arch<<"Id = "<<alumno.Id[i]<<endl;
        Arch<<"Carrera = "<<alumno.Carrera[i]<<endl;
        Arch<<"Semestre = "<<alumno.Semestre[i]<<endl;
        Arch<<"Grupo = "<<alumno.Grupo[i] << endl;
        Arch<<"\nCALIFICACIONES PARCIALES" << endl;
        Arch<<"* PARCIAL 1"<<endl;
        Arch<<"Matematicas = "<<calificaciones.Parcial1_M[i] << endl;
        Arch<<"Programacion = "<<calificaciones.Parcial1_E[i]<< endl;
        Arch<<"Estructuras = "<<calificaciones.Parcial1_P[i]<< endl;
        Arch<<"* PARCIAL 2"<<endl;
        Arch<<"Matematicas = "<<calificaciones.Parcial2_M[i] << endl;
        Arch<<"Programacion = "<<calificaciones.Parcial2_E[i]<< endl;
        Arch<<"Estructuras = "<<calificaciones.Parcial2_P[i]<< endl;
        Arch<<"* PARCIAL 3"<<endl;
        Arch<<"Matematicas = "<<calificaciones.Parcial2_M[i] << endl;
        Arch<<"Programacion = "<<calificaciones.Parcial2_E[i]<< endl;
        Arch<< "Estructuras = "<<calificaciones.Parcial2_P[i]<< endl;
        Arch<<"*CALIFICACIONES FINALES"<<endl;
        Arch<<"Matematicas = "<<promedio.Promedio[0]<<endl;
        Arch<<"Estructuras = "<<promedio.Promedio[1]<<endl;
        Arch<<"Programacion = "<<promedio.Promedio[2]<<endl;
    }
    cout<<"DATOS GUARDADOS EN ARCHIVO BINARIO - " << endl;
    Arch.close();
    cout<<"\n";
}

void Escuela::Promedio(struct Alumno&alumno,struct Calificaciones&calificaciones,struct Promedio&promedio,int contador1){
    for(int i=0;i<contador1;i++){
        promedio.Promedio[0]=(calificaciones.Parcial1_M[i]+calificaciones.Parcial2_M[i]+calificaciones.Parcial3_M[i])/3;
        promedio.Promedio[1]=(calificaciones.Parcial1_E[i]+calificaciones.Parcial2_E[i]+calificaciones.Parcial3_E[i])/3;
        promedio.Promedio[2]=(calificaciones.Parcial1_P[i]+calificaciones.Parcial2_P[i]+calificaciones.Parcial3_P[i])/3;
        cout<<"\nALUMNO "<<i+1<<endl;
        cout<<"Alumno = "<<alumno.Nombre[i]<<" "<<alumno.Apellido[i]<<endl;
        cout<<"Calificación final Matematicas = "<<promedio.Promedio[0]<<endl;
        cout<<"Calificación final Estructuras = "<<promedio.Promedio[1]<<endl;
        cout<<"Calificación final Programación = "<<promedio.Promedio[2]<<endl;
    }
}
//SECUENCIAL ORDENADO
void Escuela::Busqueda(struct Alumno&alumno,int contador1,string encontrar){
    int i=0;
    while(i<=contador1&&encontrar>alumno.Id[i]){
        i=i+1;
    }
    if(i>contador1||encontrar<alumno.Id[i]){
        cout<<"LA INFORMACION NO ESTA EN EL ARREGLO\n"<<endl;
    }
    else{
        cout<<"LA INFORMACION CON ESE ID ES = "<<endl;
        cout<<"Nombre del Alumno: "<<alumno.Nombre[i]<<" "<<alumno.Apellido[i]<<endl;
        cout<<"Id = "<<alumno.Id[i]<<endl;
        cout<<"Carrera = "<<alumno.Carrera[i]<<endl;
        cout<<"Semestre = "<<alumno.Semestre[i]<<endl;
        cout<<"Grupo = "<<alumno.Grupo[i];
    }
}
//INTERCAMBIO SEÑAL
void Escuela::Ordenar(struct Alumno&alumno,struct Calificaciones&calificaciones,struct Promedio&promedio,int contador1,int ordenar,int ordenar1){
    float posicion1M,posicion2E,posicion3P,mayor,menor,medio;
    promedio.Promedio[0]=(calificaciones.Parcial1_M[ordenar-1]+calificaciones.Parcial2_M[ordenar-1]+calificaciones.Parcial3_M[ordenar-1])/3;
    promedio.Promedio[1]=(calificaciones.Parcial1_E[ordenar-1]+calificaciones.Parcial2_E[ordenar-1]+calificaciones.Parcial3_E[ordenar-1])/3;
    promedio.Promedio[2]=(calificaciones.Parcial1_P[ordenar-1]+calificaciones.Parcial2_P[ordenar-1]+calificaciones.Parcial3_P[ordenar-1])/3;
    posicion1M=promedio.Promedio[0];
    posicion2E=promedio.Promedio[1];
    posicion3P=promedio.Promedio[2];
    int AUX=0;
    int i=0;
    bool BAND=false;
    while((i<=3-1)&&(BAND==false)){
        BAND=true;
        for(int j=0;j<3-1;j++){
            if(promedio.Promedio[j]>promedio.Promedio[j+1]){
                AUX=promedio.Promedio[j];
                promedio.Promedio[j]=promedio.Promedio[j+1];
                promedio.Promedio[j+1]=AUX;
                BAND=false;
            }
        }
    }
    if(ordenar1==1){
        cout<<"VECTOR MENOR A MEYOR = ";
        for(int i=0;i<3;i++){
            cout<<promedio.Promedio[i]<<"\t";
        }
        if(posicion1M>posicion2E && posicion2E>posicion3P){
            mayor = posicion1M;
            medio = posicion2E;
            menor = posicion3P;
            cout<<"\nProgramación = "<<posicion3P<<endl;
            cout<<"Estructura = "<<posicion2E<<endl;
            cout<<"Matematicas = "<<posicion1M<<endl;
        }
        if(posicion1M>posicion3P&&posicion3P>posicion2E){
            mayor = posicion1M;
            medio = posicion3P;
            menor = posicion2E;
            cout<<"\nEstructura = "<<posicion2E<<endl;
            cout<<"Programación = "<<posicion3P<<endl;
            cout<<"Matematics = "<<posicion1M<<endl;
        }
        if(posicion2E>posicion3P && posicion3P>posicion1M){
            mayor = posicion2E;
            medio=posicion3P;
            menor = posicion1M;
            cout<<"\nMatematicas = "<<posicion1M<<endl;
            cout<<"Programación = "<<posicion3P<<endl;
            cout<<"Estructura = "<<posicion2E<<endl;

        }
        if(posicion2E>posicion1M && posicion1M>posicion3P){
            mayor = posicion2E;
            medio=posicion1M;
            menor = posicion3P;
            cout<<"\nProgramación = "<<posicion3P<<endl;
            cout<<"Matematicas = "<<posicion1M<<endl;
            cout<<"Estructura = "<<posicion2E<<endl;
        }
        if(posicion3P>posicion2E && posicion2E>posicion1M){
            mayor = posicion3P;
            medio = posicion2E;
            menor = posicion1M;
            cout<<"\nMatematicas = "<<posicion1M<<endl;
            cout<<"Estructura = "<<posicion2E<<endl;
            cout<<"Programación = "<<posicion3P<<endl;
        }
        if(posicion3P>posicion1M && posicion1M>posicion2E){
            mayor=posicion3P;
            medio=posicion1M;
            menor = posicion2E;
            cout<<"\Estructura = "<<posicion2E<<endl;
            cout<<"Matematicas = "<<posicion1M<<endl;
            cout<<"Programación = "<<posicion3P<<endl;
        }
    }
   
    if(ordenar1==2){
        cout<<"VECTOR MAYOR A MENOR = ";
        for(int i=2;i>=0;i--){
            cout<<promedio.Promedio[i]<<"\t";
        }
        if(posicion1M>posicion2E && posicion2E>posicion3P){
            mayor = posicion1M;
            medio = posicion2E;
            menor = posicion3P;
            cout<<"\nMatematicas = "<<posicion1M<<endl;
            cout<<"Estructura = "<<posicion2E<<endl;
            cout<<"Programación = "<<posicion3P<<endl;
        }
        if(posicion1M>posicion3P&&posicion3P>posicion2E){
            mayor = posicion1M;
            medio = posicion3P;
            menor = posicion2E;
            cout<<"\nMatematics = "<<posicion1M<<endl;
            cout<<"Programación = "<<posicion3P<<endl;
            cout<<"Estructura = "<<posicion2E<<endl;
        }
        if(posicion2E>posicion3P && posicion3P>posicion1M){
            mayor = posicion2E;
            medio=posicion3P;
            menor = posicion1M;
            cout<<"\nEstructura = "<<posicion2E<<endl;
            cout<<"Programación = "<<posicion3P<<endl;
            cout<<"Matematicas = "<<posicion1M<<endl;
        }
        if(posicion2E>posicion1M && posicion1M>posicion3P){
            mayor = posicion2E;
            medio=posicion1M;
            menor = posicion3P;
            cout<<"\nEstructura = "<<posicion2E<<endl;
            cout<<"Matematicas = "<<posicion1M<<endl;
            cout<<"Programación = "<<posicion3P<<endl;
        }
        if(posicion3P>posicion2E && posicion2E>posicion1M){
            mayor = posicion3P;
            medio = posicion2E;
            menor = posicion1M;
            cout<<"\nProgramación = "<<posicion3P<<endl;
            cout<<"Estructura = "<<posicion2E<<endl;
            cout<<"Matematicas = "<<posicion1M<<endl;
        }
        if(posicion3P>posicion1M && posicion1M>posicion2E){
            mayor=posicion3P;
            medio=posicion1M;
            menor = posicion2E;
            cout<<"\nProgramación = "<<posicion3P<<endl;
            cout<<"Matematicas = "<<posicion1M<<endl;
            cout<<"Estructura = "<<posicion2E<<endl;
        }
    }
}


int main(){
    Escuela P0;
    Escuela P1;
}
