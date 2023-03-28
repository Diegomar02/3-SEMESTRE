
#include<iostream>
#include <math.h>

using namespace std;

class Calculadora{
    private:
        double *datos;
        double resultado;
        int cantidad;
    public:
        Calculadora(); // constructor
        Calculadora(int);
        Calculadora(int,int *);
        Calculadora( const Calculadora &);  // constructor de copia
        ~Calculadora();
     
        void Capturar_datos();
        void Suma();
        void Resta();
        void Multiplacacion();
        void Division(); // *
        void Raiz();
        void Potencia();
        void Menu();     // *
};

int main(){

    Calculadora X;
    Calculadora Y(8);
    int vector[4] = {2,3,4,5};
    Calculadora Z(4,vector);
    Calculadora W(Z);
    W.Suma();
    //X.Menu();

    return 0;
}

 Calculadora::Calculadora(){
     cout << "Generando clase e iniciando valores .....(por default)" << endl;
     resultado=0;
     cantidad=0;
     datos= NULL;
 }

 Calculadora::Calculadora(int n){
     cout << "Generando clase e iniciando valores .....(con cantidad de datos definida)" << endl;
     resultado=0;
     cantidad = n;
     datos=new double[n];
 }
 
  Calculadora::Calculadora(int n, int *Vector){
     cout << "Generando clase e iniciando valores .....(con datos definidos)" << endl;
     resultado=0;
     cantidad = n;
     datos=new double[n];
     for(int i=0; i<n ; i++)
            datos[i]=Vector[i];
 }

 Calculadora::Calculadora( const Calculadora & x){
     cout << "Generando clase e iniciando valores .....(copia)" << endl;
     resultado= x.resultado;
     cantidad = x.cantidad;
     datos = new double[ x.cantidad ];
     for(int i=0; i<cantidad ; i++)
            datos[i] = x.datos[i];
 }

 Calculadora::~Calculadora(){
     delete [] datos;
 }

void Calculadora::Capturar_datos(){
     cout<<"Numero de Datos :";
     cin>>cantidad;
     datos=new double[cantidad];
     cout<<"\n";

     for(int i=0;i<cantidad;i++){
         cout<<"Dato " << i+1 <<" : ";
         cin>>datos[i];
     }
     cout<<"\n";
}

void Calculadora::Suma(){
     cout << endl << "sumando ..." << endl ;
     resultado = 0;
     for(int i=0;i<cantidad;i++){
        resultado += datos[i];
     }
     cout<<" Resultado:  "<< resultado <<"\n" ;
}

void Calculadora::Resta(){
     cout << endl << "restando ..." << endl ;
     resultado = datos[0];
     for(int i=1;i<cantidad;i++){
        resultado -= datos[i];
     }
     cout<<" Resultado:  "<< resultado <<"\n" ;
}

void Calculadora::Multiplacacion(){
     cout << endl << "multiplacando ..." << endl ;
     resultado = 1;
     for(int i=0;i<cantidad;i++){
        resultado *= datos[i];
     }
     cout<<" Resultado:  "<< resultado <<"\n" ;
}

void Calculadora::Division(){
     cout << endl << "division ..." << endl ;
     resultado = datos[0];
     for(int i=1;i<cantidad;i++){
        resultado /= datos[i];
     }
     cout<<" Resultado:  "<< resultado <<"\n" ;
}

void Calculadora::Raiz(){
     cout << endl << "calculando ..." << endl ;
     resultado = 0;
     for(int i=0;i<cantidad;i++){
        cout<<" Resultado:  "<< sqrt(datos[i]) <<"\n" ;
     }
}

void Calculadora::Potencia(){
     resultado = 0;
     int n_potencia;
     cout << "¿A que pontencia ? ";
     cin >> n_potencia;
     cout << endl << "calculando ..." << endl ;

     for(int i=0;i<cantidad;i++){
        resultado = pow(datos[i], n_potencia);
        cout<<" Resultado:  "<< resultado<<"\n" ;
     }
}

void Calculadora::Menu(){

     Capturar_datos();
     Division();

}
