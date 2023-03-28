#include <iostream>
using namespace std;
class Cuadrado{
 public:
 float lado;
 Cuadrado(float l){ lado=l; }
 Cuadrado(){lado=0;}
 float calcularArea(){ return lado*lado; }
 Cuadrado captura(){ Cuadrado temp; cout << "lado:"; cin >> temp.lado; return temp;}
};
 
class Rectangulo{
 public:
 float base, altura;
 Rectangulo(){base=altura=0;}
 Rectangulo(float b,float a){ base=b; altura=a; }
 float calcularArea(){ return base*altura; }
 //void captura(){ cout << "base:"; cin >> base; cout << "altura:"; cin >> altura;}
};
 
template <class R>
 R capturarDatos(R f) {
 cout << "vamos a iniciar el proceso de captura "<< endl;
 return f.captura();
 }
 
template <class G>
 void imprimir(string nombre,G f) {
 cout<<nombre<<" area:"<<f.calcularArea()<<endl;
 }
 
int main(){
 Cuadrado c;
 Rectangulo r;
 c = capturarDatos(c);
 //capturarDatos(r);
 cout << "Datos lado :" << c.lado << endl;
 
 imprimir("Cuadrado",c);
 //imprimir("Rectangulo",r);
}
