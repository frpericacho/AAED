#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int a=0,uno=0,dos=0,tres=0,cuatro=0,cinco=0,seis=0;
    for(int i=0; i < 10000000; ++i){
        a = rand() %(6 + 1);
        if(a==1) ++uno;
        if(a==2) ++dos;
        if(a==3) ++tres;
        if(a==4) ++cuatro;
        if(a==5) ++cinco;
        if(a==6) ++seis;
    }

    cout << "la frecuencia de uno es: " <<(float) uno/10000000 << endl;
    cout << "la frecuencia de dos es: " <<(float) dos/10000000 << endl;
    cout << "la frecuencia de tres es: " <<(float) tres/10000000 << endl;
    cout << "la frecuencia de cuatro es: " <<(float) cuatro/10000000 << endl;
    cout << "la frecuencia de cinco es: " <<(float) cinco/10000000 << endl;
    cout << "la frecuencia de seis es: " <<(float) seis/10000000 << endl;
    
    return 0;
}