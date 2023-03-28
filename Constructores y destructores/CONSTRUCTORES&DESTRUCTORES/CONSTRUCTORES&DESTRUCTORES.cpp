#include<iostream>
using namespace std;

class grupo{
    
    private:
        int alumnos;
        int parciales;
        float*promedio;
        float**calificacion;
    
    public:
        grupo();
        grupo(const grupo &);
        grupo(int, int);
        ~grupo();
};

int main(){//INICIO INT MAIN
    grupo a;
    grupo b(5,3);
    grupo c(ios);
    return 0;
}//FIN INT MAIN

grupo::grupo(){//INICIO GRUPO::GRUPO
    int alumnos=0;
    int parciales=0;
    float **calificacion;
    float *promedio=NULL;
}//FIN GRUPO::GRUPO

grupo::grupo(int alumnos,int parciales){//INICIO GRUPO::GRUPO
    calificacion=new float*[alumnos];
    promedio=new float[alumnos];
}//FIN GRUPO::GRUPO

grupo::grupo(const grupo&dos){//INICIO GRUPO::GRUPO
    alumnos=dos.alumnos;
    parciales=dos.parciales;
    calificacion=new float*[dos.alumnos];
    promedio=new float[dos.alumnos];
}//FIN GRUPO::GRUPO

grupo::~grupo(){//INICIO GRUPO::~GRUPO
    delete[]calificacion;
    delete[]promedio;
}//FIN GRUPO::~GRUPO
