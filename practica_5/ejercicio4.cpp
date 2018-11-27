#include <iostream>
#include <fstream>
#include "PILA_ENLA.h"
using namespace std;

void suma(Pila<int> ,Pila<int> ,Pila<int> );

int main(int argc, char const *argv[])
{
    string nombre;

    cout << "introduzca el nombre del fichero de datos" << endl;
    cin >> nombre;

    fstream f(nombre);
    Pila<int> p,q,r;
    f >> p >> q;

    suma(p,q,r);

    f << r;

    f.close();
    return 0;
}

void suma(Pila<int> p ,Pila<int> q, Pila<int> r){
    int res = 0;
    while(!p.vacia() && !q.vacia()){
        if(p.tope()+q.tope()+res >9){
            r.push(p.tope()+q.tope()+res-10);
            res=1;
        }else{
            r.push(p.tope()+q.tope()+res);
            res=0;
        }
        p.pop();
        q.pop();
    }
}

fstream& operator >>(fstream& fe, Pila<int>& P){
    char cifra;
    while(fe.get(cifra) && cifra != '\n'){
        P.push(cifra -= '0');
    }
    return fe;
}

fstream& operator <<(fstream& fs, Pila<int> P){
    while(!P.vacia()){
        fs << P.tope();
        P.pop();
    }
    fs << endl;
    return fs;
}