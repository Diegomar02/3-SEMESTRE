//DIEGO MARQUEZ GOMEZ
//EJERICIO 1
//

#include <iostream>

using namespace std;
float vector[10];

int main() {
    srand(time(NULL));
    float vector[10];
    cout<<"\nVECTOR"<<endl;
    for(int i=0;i<10;i++){
        vector[i]=rand()%101;
        cout<<vector[i]<<"\t";
    }
    cout<<"\n\nVECTOR INVERTIDA"<<endl;
    for(int a=8;a>-1;a-=2){
        cout<<vector[a]<<"\t";
    }
    cout<<"\n";
}
