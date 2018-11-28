#include <iostream>
#include "COLA_CIR.h"
#include "PILA_ENLA.h"
using namespace std;

void rellena(Cola<int> );
void fun(Cola<int> );

int main(int argc, char const *argv[])
{
    Cola<int> c(50);

    rellena(c);

    fun(c);

    return 0;
}

void fun(Cola<int> c){
    Pila<int> p;
    Cola<int> res(50);

    int a = 0,b = 0;
    cout << "introduzca el primer elemento" << endl;
    cin >> a;
    cout << "introduzca el segundo elemento" << endl;
    cin >> b;

    while(c.frente() != b){
        res.push(c.frente());
        c.pop();
    }
    while(c.frente() != a){
        p.push(c.frente());
        c.pop();
    }
    p.push(c.frente());
    c.pop();
    while(!p.vacia()){
        res.push(p.tope());
        p.pop();
    }
    while(!c.vacia()){
        res.push(c.frente());
        c.pop();
    }

    while(!res.vacia()){
        cout << res.frente() << endl;
        res.pop();
    }
}

void rellena(Cola<int> c){
    int aux = 0;
    cout << "introduzca los elementos de la cola" << endl;
    while(aux != -1){
        cin >> aux;
        if(aux!=-1)
            c.push(aux);
    }
}
