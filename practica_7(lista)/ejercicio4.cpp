#include <iostream>
#include "LISTA_ENLA.hpp"
using namespace std;

void rellena1(Lista<int> &);

void rellena2(Lista<int> &);

void fun(Lista<int> &,Lista<int> &);

int main(int argc, char const *argv[])
{
    Lista<int> a,b;
    rellena1(a);
    cout << "-----------------" << endl;
    rellena2(b);
    cout << "-----------------" << endl;
    fun(a,b);

    return 0;
}

//AQUI ES DONDE DA EL FALLO
void rellena1(Lista<int> &l){
    Lista<int>::posicion q = l.primera();
    int i = 0;
    l.insertar(1,q);
    q = l.primera();

    while(i < 10){
        l.insertar(1,q);
        q = l.siguiente(q);
        i++;
    }
    
    /*for(q = l.primera(); q < l.fin(); q = l.siguiente(q)){
        l.insertar(1,q);
    }
    */
    
    for(Lista<int>::posicion p = l.primera(); p < l.fin(); p = l.siguiente(p)){
        cout << l.elemento(p) << endl;
    }
}

void rellena2(Lista<int> &l){
    Lista<int>::posicion q = l.primera();
    int i = 0;
    l.insertar(2,q);
    q = l.siguiente(q);

    while(i < 10){
        l.insertar(2,q);
        q = l.siguiente(q);
        i++;
    }

    /*for(Lista<int>::posicion p = l.primera(); p < l.fin(); p = l.siguiente(p)){
        l.insertar(2,p);
    }*/

    for(Lista<int>::posicion p = l.primera(); p < l.fin(); p = l.siguiente(p)){
        cout << l.elemento(p) << endl;
    }
}

void fun(Lista<int> &a, Lista<int> &b){
    Lista<int> c;
    Lista<int>::posicion p = a.primera();
    Lista<int>::posicion q = b.primera();
    Lista<int>::posicion t = c.primera();
    
    while(p < a.fin() || q < b.fin()){
        c.insertar(a.elemento(p),t);
        t = c.siguiente(t);
        c.insertar(b.elemento(q),t);
        t = c.siguiente(t);

        p = a.siguiente(p);
        q = b.siguiente(q);
    }

    t = c.primera();
    while(t < c.fin()){
        cout << c.elemento(t) << endl;
        t = c.siguiente(t);
    }


    /*for(p = c.primera() && q = c.primera(); p < a.fin() || q < b.fin(); p = a.siguiente(p) && q = b.siguiente(p)){

    }*/
}