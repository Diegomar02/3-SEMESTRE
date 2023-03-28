//diego marquexz gomez 

#include <stdlib.h>
#include <iostream>
using namespace std;

struct cine{
    int cuenta;
    char nombrePelicula[100];
    float precioBoleto;
};

void crear(){
    FILE*arch;
    arch=fopen("cine.dat","wb");
    if(arch==NULL)
        exit(1);
    fclose(arch);
}
void agregar(){
    FILE*arch;
    arch=fopen("cine.dat","ab");
    if(arch==NULL)
        exit(1);
    cine cartelera;
    cout<<"Nombre de la pelicula";
    cin>>cartelera.nombrePelicula;
    cout<<"Precio de la funcion";
    cin>>cartelera.precioBoleto;
    fwrite(&cartelera, sizeof(cine),1, arch);
    fclose(arch);
}
void mostrar(){
    FILE *arch;
    arch=fopen("cine.dat","ab");
    if(arch==NULL)
        exit(1);
    cine cartelera;
    fread(&cartelera, size(cine), 1, arch);
    while(!feof(arch)){
        cout<<"Nombre"<<cartelera.nombrePelicula<<"Precio"<<cartelera.precioBoleto;
        fread(&cartelera, size(cine), 1, arch);
    }
    fclose (arch);
}

int main(){
    int opcion;
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
        switch(opcion){
            case 1:
                crear();
                break;
            case 2:
                
                break;
            case 3:
                agregar();
                break;
            case 4:
            
                break;
            case 5:
           
                break;
            case 6:
            
                break;
            case 7:
            
                break;
            case 8:
            
                break;
            case 9:
            
                break;
            case 10:
                
                break;
        }
    return 0;
}

