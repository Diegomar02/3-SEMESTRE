//Diego Márquez Gómez
//ID 245119

//NO SE GUARDAN DE MANERA CORRECTA LOS ARCHIVOS EN EL DOCUMENTO Y NO LOS MUESTRA... ES EL ERROR QUE TUVE AL HACERLO

#include <fstream>
#include <iostream>

using namespace std;

void agregar_Pelicula();
void respaldo();

struct cine{
    int cuenta;
    char nombrePelicula[100];
    float precioBoleto;
};

//VOID CREAR DOCUMENTO
void crear_Documento(){
    fstream archivo;
    archivo.open("cine.dat",ios::binary|ios::out|ios::trunc);
    if (!archivo) {
        cerr<<"No se pudo abrir el archivo"<<endl;
        return;
    }
    cine blank={0,"",0};
    for(int i=0;i<10;i++){
        archivo.write(reinterpret_cast<char*>(&blank),sizeof(cine));
    }
    archivo.close();
    cout<<"\nARCHIVO CREADO!!!\n";
    cin.get();
}

//VOID AGREGAR PELICULA
void agregar(){
    fstream archivo;
    archivo.open("cine.dat",ios::binary|ios::in|ios::out);
    if (!archivo) {
        cerr<<"No se pudo abrir el archivo "<<endl;
        return;
    }
    cine cartelera;
    cout<<"NOMBRE DE LA PELICULA = ";
    cin>>cartelera.nombrePelicula;
    cout<<"PRECIO DE LA FUNCIÓN = ";
    cin>>cartelera.precioBoleto;
    archivo.seekp((cartelera.cuenta-1) * sizeof(cine),ios::beg);
    archivo.write(reinterpret_cast<char*>(&cartelera),sizeof(cine));
    cout<< "Datos grabados...\n ingresa la cuenta: ";
    cin >> cartelera.cuenta;
    archivo.close();
    return;
}

void mostrar(){
    fstream archivo;
    archivo.open("cine.dat", ios::binary|ios::in);
    if ( !archivo ) {
        cerr << " No se pudo abrir el archivo " << endl;
        return;
    }
    cine cartelera;
    cout << "Datos del los cliente...\n";
    archivo.read((char *)&cartelera, sizeof(cine));
    while( !archivo.eof() ){
        if (cartelera.cuenta != 0) {
            cout << "NOMBRE " << cartelera.nombrePelicula << " PRECIO "<<cartelera.precioBoleto;
        }
        archivo.read((char *)&cartelera, sizeof(cine));
    }
    archivo.close();
    cin.get();
    return;
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
    int opcion,continuar;
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
            crear_Documento();
            cout<<"\n¿DESEA REGRESAR AL MENU? 1. Si y 2. No = ";
            cin>>continuar;
            if(continuar==1){
                main();
            }
            if(continuar==2){
                cout<<"GRACIAS!!! REGRESE PRONTO...";
                break;
            }
        case 2:
            cout<<"MOSTRAR PELICULAS";
            mostrar();
            cout<<"\n¿DESEA REGRESAR AL MENU? 1. Si y 2. No = ";
            cin>>continuar;
            if(continuar==1){
                main();
            }
            if(continuar==2){
                cout<<"GRACIAS!!! REGRESE PRONTO...";
                break;
            }
        case 3:
            cout<<"AGREGAR PELICULAS";
            agregar();
            cout<<"\n¿DESEA REGRESAR AL MENU? 1. Si y 2. No = ";
            cin>>continuar;
            if(continuar==1){
                main();
            }
            if(continuar==2){
                cout<<"GRACIAS!!! REGRESE PRONTO...";
                break;
            }
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

