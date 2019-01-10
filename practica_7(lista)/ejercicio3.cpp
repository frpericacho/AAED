/*
ERRORES:    1.- IMPRIME EN HEXADECIMAL
            2.- DA UN CORE DUMPED AL IMPRIMIR LA LISTA RESULTADO
*/
#include <iostream>
#include "LISTA_ENLA.hpp"
using namespace std;

void rellena(Lista<int> &);
void fun(Lista<int> &,int );

int main(int argc, char const *argv[])
{
    Lista<int> l;
    int a;

    rellena(l);

    cout << "introduce el numero que desea borrar de la lista" << endl;
    cin >> a;
    
    fun(l,a);
    
    return 0;
}

void rellena(Lista<int> &l){
    int i = 1;
    
    for(Lista<int>::posicion q = l.primera();q < l.fin(); q = l.siguiente(q)){
        l.insertar(i,q);
        i++;
    }

    for(Lista<int>::posicion q = l.primera();q < l.fin(); q = l.siguiente(q)){
        cout << l.elemento(q) << endl;
    }
}

void fun(Lista<int> &l,int x){
    Lista<int>::posicion p;
    p = l.primera();
    
    p = l.buscar(x);
    l.eliminar(p);

    for(Lista<int>::posicion q = l.primera();q < l.fin(); q = l.siguiente(q)){
        cout << l.elemento(q) << endl;
    }
}