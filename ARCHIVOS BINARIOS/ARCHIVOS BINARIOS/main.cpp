#include <fstream>
#include <iostream>

using namespace std;

void agregar_Pelicula();
void respaldo();

struct cine{//INCIO STRUCT CLIENTE
    int cuenta;
    char nombrePelicula[100];
    float precioBoleto;
};

void crear_Documento(){
    FILE*arch;
    arch=fopen("cine.dat","ab");
    if(arch==NULL)
        exit(1);
        fclose(arch);
        cout<<"CREADO";
}

void respaldo(){
    ifstream original("cine.dat");
    ofstream copia("cine_copia.dat");
    string a;
    while(getline(original,a))
        copia<<a<<endl;
    original.close();
    copia.close();
    cout<<"SE GENERO EL ARCHIVO"<<endl;
}


int main() {//INICIO INT MAIN
    int opcion;
    cout<<"SE HA CREADO EL ARCHIVO!!!\n";
    cout<<"\nMENU"<<endl;
    cout<<"1. CREAR DOCUMENTO"<<endl;
    cout<<"2. MOSTRAR PELICULAS"<<endl;
    cout<<"3. AGREGAR PELICULAS"<<endl;
    cout<<"4. EDITAR PELICULAS"<<endl;
    cout<<"5. VENDER BOLETOS"<<endl;
    cout<<"6. BORRAR ULTIMO BOLETO VENDIDO"<<endl;
    cout<<"7. OBTENER TOTAL DE BOLETOS VENDIDOS Y MONTO"<<endl;
    cout<<"8. MOSTRAR TODOS LOS BOLETOS VENDIDOS"<<endl;
    cout<<"9. BUSCAR BOLETOS VENDIDOS (POR PELICULA O POR DIA)"<<endl;
    cout<<"10. GENERAR COPIA"<<endl;
    cout<<"¿CUAL OPCION DESEA? = ";
    cin>>opcion;
    switch(opcion){//INICIO SWITCH
        case 1:
            cout<<"CREAR DOCUMENTO";
            crear_Documento();
        case 2:
            cout<<"MOSTRAR PELICULAS";
            
        case 3:
            cout<<"AGREGAR PELICULAS";
            
        case 4:
            cout<<"EDITAR PELICULAS";
            
        case 5:
            cout<<"VENDER BOLETOS";
            
        case 6:
            cout<<"BORRAR ULTIMO BOLETO VENDIDO";
            
        case 7:
            cout<<"OBTENER TOTAL DE BOLETOS VENDIDOS Y MONTO";
            
        case 8:
            cout<<"MOSTRAR TODOS LOS BOLETOS VENDIDOS";
            
        case 9:
            cout<<"BUSCAR BOLETOS VENDIDOS (POR PELICULA O POR DIA";
            
        case 10:
            cout<<"GENERAR COPIA DEL DOCUMENTO";
            respaldo();
            cout<<"¿DESEA REGRESAR AL MENU?";
    }//FIN SWITCH
}//FIN PROGRAMA

