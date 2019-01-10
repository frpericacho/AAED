#include <iostream>
#include "LISTA_ENLA.hpp"
using namespace std;

void rellena(Lista<int> &);
void fun(Lista<int> &,int );

int main(int argc, char const *argv[])
{
    Lista<int> l;
    int x = 5;

    rellena(l);
    fun(l,x);

    return 0;
}

void rellena(Lista<int> &l){
    Lista<int>::posicion p = l.primera();
    int i = 0;

    while(i < 10){
        l.insertar(i,p);
        p  =l.siguiente(p);
        i++;
    }
}

void fun(Lista<int> &l,int x){
    Lista<int>::posicion p = l.primera();

    while(x > 0){
        p = l.siguiente(p);
    }

    while(p > l.primera()){
        cout << l.elemento(p) << endl;
        p = l.anterior(p);
    }
}