//DIEGO MARQUEZ GOMEZ
//245119

#include <iostream>
using namespace std;

class alumno{
    private:
        int calificaciones[3];
        int faltas[3];
    public:
        alumno();
        void Mostrar();
        friend class Profesor;
        
};

class Profesor{
    public:
        void Capturar(alumno&obj);
    
};

alumno::alumno(){
    for(int i=0;i<3;i++){
        calificaciones[i]=0;
    }
    for(int i=0;i<3;i++){
        faltas[i]=0;
    }
}

void Profesor::Capturar(alumno&obj){
    cout<<"\nCALIFICACIONES"<<endl;
    for(int i=0;i<3;i++){
        
        cout<<"CALIFICACIÓN "<<i+1<<" = ";
        cin>>obj.calificaciones[i];
        
    }
    cout<<"\nFALTAS"<<endl;
    for(int i=0;i<3;i++){
        cout<<"FALTAS "<<i+1<<" = ";
        cin>>obj.faltas[i];
    }
}

void alumno::Mostrar(){
    for(int i=0;i<3;i++){
        cout<<"CALIFICACION "<<i+1<<" = "<<calificaciones[i]<<endl;
        
    }
    
    for(int i=0;i<3;i++){
        
        cout<<"FALTAS "<<i+1<<" = "<<faltas[i]<<endl;
        
    }
    
}

int main(){
    alumno Diego;
    Profesor David;
    David.Capturar(Diego);
    cout<<"\nRESUMEN (COMPLETO)"<<endl;
    Diego.Mostrar();
    cout<<"\n\n";
}

