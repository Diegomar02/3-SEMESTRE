//DIEGO MARQUEZ
//22/11/2021

#include <iostream>
using namespace std;

class materia{
public:
    string nombreMateria;//
    int semestre;//
    
};

class examen:virtual public materia{
public:
    float parcial[3];
    string tipo;
    float calificacionFinal;
};

class proyecto:virtual public materia{
public:
    string fecha;
    string tema;
    float calificacionFinal;
};

class alumno:public examen,public proyecto{
public:
    string carrera;//
    string nombreAlumno;//
    using proyecto::calificacionFinal;//
    
};

int main(){
    alumno diego;
    diego.nombreMateria="PROGRAMACIÓN";
    diego.semestre=3;
    diego.nombreAlumno="DIEGO";
    diego.carrera="INGENIERIA EN SISTEMAS COMPUTACIONALES";
    diego.calificacionFinal=9;
    
    diego.tipo="PRACTICO";
    diego.parcial[0]=10;
    diego.parcial[1]=9;
    diego.parcial[2]=10;
    diego.examen::calificacionFinal=(diego.parcial[0]+diego.parcial[1]+diego.parcial[2])/3;
    
    diego.tema="HERENCIAS";
    diego.fecha="22/11/2021";
    diego.proyecto::calificacionFinal=9;
    
    //MATERIA - ALUMNO
    cout<<"MATERIA = "<<diego.nombreMateria<<"\nSEMESTRE = "<<diego.semestre<<"\nNOMBRE DEL ALUMNO = "<<diego.nombreAlumno<<"\nCARRERA = "<<diego.carrera<<"\nCALIFICACIÓN FINAL= "<<diego.calificacionFinal<<"\n\n"<<"TIPO = "<<diego.tipo<<"\nPARCIAL 1 = "<<diego.parcial[0]<<"\nPARCIAL 2 = "<<diego.parcial[1]<<"\nPARCIAL 3 = "<<diego.parcial[2]<<"\nCALIFICACIÓN FINAL = "<<diego.examen::calificacionFinal<<"\n\n"<<"TEMA = "<<diego.tema<<"\nFECHA = "<<diego.fecha<<"\nCALIFICACIÓN FINAL"<<diego.proyecto::calificacionFinal<<"\n\n";
    
}
