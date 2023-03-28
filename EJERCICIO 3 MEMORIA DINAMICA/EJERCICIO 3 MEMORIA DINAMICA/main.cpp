//Caso 1 :
//Preguntar cuantas letras tiene la palabras , generar un vector dinámico, capturarlo y mostrarlo la palabra de forma inversa usando punteros
//Caso 2 :
//Preguntar cuantos salones son y generar un vector dinámico donde guardes dentro el promedio de cada salón , después preguntar cuantos alumnos son en cada salón (capturar en un vector dinámico)para obtener el promedio del grupo , mostrar al final los promedios de cada salón
//Caso 3 :
//Salir


// DIEGO MARQUEZ GOMEZ
// ID 245119

#include <iostream>
using namespace std;

void menu();
void caso1(char* &vector1);
void caso2(int* &vector2, int* &vector3);

int main(){
    menu();
}

void menu(){//INICIO VOID MENU
    int opcion;
    char* vector1;
    int* vector2;
    int* vector3;
    do{//INICIO DO
        cout<<"\nMENU" << endl;
        cout<<"1. CASO 1 (PALABRAS)\n";
        cout<<"2. CASO 2 (SALONES)\n";
        cout<<"3. SALIR\n" << endl;
        cout<<"¿CUAL OPCION DESEA? = ";
        cin>>opcion;
        switch(opcion){//INICIO SWITCH
            case 1: caso1(vector1);
                break;
            case 2: caso2(vector2,vector3);
                break;
        }//FIN SWITCH
    }while((opcion!=3)); //FIN DO
    cout<<"\nGRACIAS!! VUELVA PRONTO...\n"<<endl;
}//FIN VOID MENU

void caso1(char* &vector1){//INICIO VOID CASO1
    int cantidadLetras;
    cout<<"\n¿CUANTAS PALABRAS TIENE LA LETRA? = ";
    cin>>cantidadLetras;
    vector1=new char[cantidadLetras];
    cout<<"\n";
    for (int i=0;i<cantidadLetras;i++){//INICIO FOR
        cout<<"LETRA "<<i+1<<" = ";
        cin>>vector1[i];
    }//FIN FOR
    cout<<"\n";
    for (int i=cantidadLetras;i>=0;i--){//INICIO FOR
        cout<<vector1[i];
    }//FIN FOR
    delete vector1;
    cout<<"\n";
}//FIN VOID CASO1

void caso2(int* &vector2,int* &vector3){//INICIO VOID CASO2
    cout<<"\n";
    int numeroSalones;
    int numeroAlumnos;
    int suma=0;
    int promedio;
    cout<<"¿NUMERO DE SALONES? = ";
    cin>>numeroSalones;
    vector2=new int[numeroSalones];
    for (int i=0;i<numeroSalones;i++){//INICIO FOR
        cout<<"¿NUMERO DE ALUMNOS DEL SALON "<<i+1<<"? = ";
        cin>>numeroAlumnos;
        vector3=new int[numeroAlumnos];
        for (int j=0;j<numeroAlumnos;j++){//INICIO FOR
            cout << "¿CALIFICACION "<<j+1<<"? = ";
            cin>>vector3[j];
            suma=suma+vector3[j];
        }//FIN FOR
        promedio=suma/numeroAlumnos;
        vector2[i]=promedio;
        cout<<"PROMEDIO DEL SALON " << i+1 << " ES DE = "<<vector2[i]<<endl;
    }//FIN FOR
    delete vector2;
    delete vector3;
}//FIN VOID CASO2

