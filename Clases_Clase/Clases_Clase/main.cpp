
// DIEGO MARQUEZ GOMEZ
// 245119
// 30 DE SEPTIEMBRE


#include <iostream>
#include <math.h>

using namespace std;

class tienda{
    private:
    int opcionMenu;
    int v;//ventas
    int d;
    int i;
    int cantidad;//ventas
    int cantidad1;
    int regresar;//devolucion
    int opcion;//ventas
    int continuar;//ventas
    int total;
    int playera,blazer,camiseta,pantalon,zapatos;
    int invPlayera,invBlazer,invCamiseta,invPantalon,invZapatos;

public:
        tienda();//CONSTRUCTOR
        void ventas();
        void devolucion();
        void descuentos();
        void productoFuturo();
        void inventario();
        void Menu();
};

int main(){
    tienda x;
    return 0;
}

tienda::tienda(){
    opcionMenu=0;
    v=0;                //ventas
    d=0;                //devolucion
    cantidad=0;         //ventas
    cantidad1=0;        //ventas
    regresar=0;         //devolucion
    opcion=0;           //ventas
    total=0;            //ventas
    continuar=0;        //ventas
    Menu();
    i=0;
    
    
    playera=250;
    blazer=700;
    camiseta=500;
    pantalon=300;
    zapatos=1500;
    
    invPlayera=100;
    invBlazer=100;
    invCamiseta=100;
    invPantalon=100;
    invZapatos=100;
    
}

void tienda::ventas(){
    cout<<"PRODUCTOS"<<endl;
    cout<<"1. Playera ($250)"<<endl;
    cout<<"2. Blazer - Saco ($700)"<<endl;
    cout<<"3. Camiseta ($500)"<<endl;
    cout<<"4. Pantalon ($300)"<<endl;
    cout<<"5. Zapatos formales - negros ($1,500)"<<endl;
    cout<<"¿Cuantos productos desea comprar? = ";
    cin>>cantidad;
    for(i=0;i<cantidad;i++){
        cout<<"Producto "<<cantidad<<endl;
        cout<<"¿Cual seria? = ";
        cin>>opcion;
        if(opcion==1){
            total=total+playera;
            invPlayera=invPlayera-1;
            Menu();
        }
        if(opcion==2){
            total=total+blazer;
            invBlazer=invBlazer-1;
            Menu();
        }
        if(opcion==3){
            total=total+camiseta;
            invCamiseta=invCamiseta-1;
            Menu();
        }
        if(opcion==4){
            total=total+pantalon;
            invPantalon=invPantalon-1;
            Menu();
        }
        if(opcion==5){
            total=total+zapatos;
            invZapatos=invZapatos-1;
            Menu();
        }
    }
}

void tienda::devolucion(){
    cout<<"1. Playera"<<endl;
    cout<<"2. Blazer - Saco"<<endl;
    cout<<"3. Camiseta"<<endl;
    cout<<"4. Pantalon"<<endl;
    cout<<"5. Zapatos"<<endl;
    cout<<"¿Que se va a regresar? = ";
    cin>>regresar;
    switch (regresar) {
        case 1:
            cout<<"Se le ha regresado al cliente $"<<playera<<" Pesos";
            invPlayera=invPlayera+1;
            Menu();
        case 2:
            cout<<"Se le ha regresado al cliente $"<<blazer<<" Pesos";
            invBlazer=invBlazer+1;
            Menu();
        case 3:
            cout<<"Se le ha regresado al cliente $"<<camiseta<<" Pesos";
            invCamiseta=invCamiseta+1;
            Menu();
        case 4:
            cout<<"Se le ha regresado al cliente $"<<pantalon<<" Pesos";
            invPantalon=invPantalon+1;
            Menu();
        case 5:
            cout<<"Se le ha regresado al cliente $"<<zapatos<<" Pesos";
            invZapatos=invZapatos+1;
            Menu();
    }
}

void tienda::descuentos(){
    cout<<"Seleccione el tipo de descuento"<<endl;
    cout<<"UN PRODUCTO POR MES\n"<<endl;
    cout<<"Emplead@ = 30%"<<endl;
    cout<<"Conocido = 20%\n"<<endl;
    cout<<"1. Playera ($250)"<<endl;
    cout<<"2. Blazer - Saco ($700)"<<endl;
    cout<<"3. Camiseta ($500)"<<endl;
    cout<<"4. Pantalon ($300)"<<endl;
    cout<<"5. Zapatos formales - negros ($1,500)"<<endl;
    cout<<"¿Que desea comprar? = ";
    cin>>opcion;
    cout<<"Tipo de descuento : 1. Emplead@ o 2. Conocido = ";
    cin>>d;
    switch (opcion) {
        case 1:
            if(d==1){
                playera=playera*.70;
                cout<<"El precio final de la playera es de "<<playera<<endl;
                invPlayera=invPlayera-1;
                Menu();
            }
            if(d==2){
                playera=playera*.80;
                cout<<"El precio final de la playera es de "<<playera<<endl;
                invPlayera=invPlayera-1;
                Menu();
            }
        case 2:
            if(d==1){
                blazer=blazer*.70;
                cout<<"El precio final del blazer es de "<<blazer<<endl;
                invBlazer=invBlazer-1;
                Menu();
            }
            if(d==2){
                blazer=blazer*.80;
                cout<<"El precio final del blazer es de "<<blazer<<endl;
                invBlazer=invBlazer-1;
                Menu();
            }
        case 3:
            if(d==1){
                camiseta=camiseta*.70;
                cout<<"El precio final de la camiseta es de "<<camiseta<<endl;
                invCamiseta=invCamiseta-1;
                Menu();
            }
            if(d==2){
                camiseta=camiseta*.80;
                cout<<"El precio final de la camiseta es de "<<camiseta<<endl;
                invCamiseta=invCamiseta-1;
                Menu();
            }
        case 4:
            if(d==1){
                pantalon=pantalon*.70;
                cout<<"El precio final del pantalon es de "<<pantalon<<endl;
                invPantalon=invPantalon-1;
                Menu();
            }
            if(d==2){
                pantalon=pantalon*.80;
                cout<<"El precio final del pantalon es de "<<pantalon<<endl;
                invPantalon=invPantalon-1;
                Menu();
            }
        case 5:
            if(d==1){
                zapatos=zapatos*.70;
                cout<<"El precio final del zapato es de "<<zapatos<<endl;
                invZapatos=invZapatos-1;
                Menu();
            }
            if(d==2){
                zapatos=zapatos*.80;
                cout<<"El precio final del zapato es de "<<zapatos<<endl;
                invZapatos=invZapatos-1;
                Menu();
            }
    }
}

void tienda::productoFuturo(){
    cout<<"PRODUCTOS EN UN FUTURO"<<endl;
    cout<<"1. Tenis"<<endl;
    cout<<"2. Chamarra"<<endl;
    cout<<"3. Guantes"<<endl;
    cout<<"4. Gorras"<<endl;
    cout<<"5. Bolsas"<<endl;
    Menu();
}

void tienda::inventario(){
    cout<<"VER INVENTARIO"<<endl;
    cout<<"1. Playera = "<<invPlayera<<endl;
    cout<<"2. Blazer = "<<invBlazer<<endl;
    cout<<"3. Camiseta = "<<invCamiseta<<endl;
    cout<<"4. Pantalon = "<<invPantalon<<endl;
    cout<<"5. Zapaton = "<<invZapatos<<endl;
    Menu();
}

void tienda::Menu(){
    cout<<"MENU"<<endl;
    cout<<"1. Comprar"<<endl;
    cout<<"2. Devoluciones"<<endl;
    cout<<"3. Descuentos"<<endl;
    cout<<"4. Productos Proximamente"<<endl;
    cout<<"5. Inventario"<<endl;
    cout<<"¿OPCION? = ";
    cin>>opcionMenu;
    switch (opcionMenu) {
        case 1:
            ventas();
        case 2:
            devolucion();
        case 3:
            descuentos();
        case 4:
            productoFuturo();
        case 5:
            inventario();
    }
    
}
