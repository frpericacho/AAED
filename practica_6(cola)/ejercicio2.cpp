#include <iostream>
#include "COLA_CIR.h"
#include "PILA_ENLA.h"
using namespace std;

void rellena(Cola<int> &);
void fun(Cola<int> &);
void escribe(Cola<int> &);

int main(int argc, char const *argv[])
{
    Cola<int> c(50);

    rellena(c);
    
    fun(c);

    escribe(c);

    return 0;
}

void escribe(Cola<int> &c){
    while(!c.vacia()){
        cout << c.frente() << endl;
        c.pop();
    }
}

void fun(Cola<int> &c){
    Pila<int> p;
    Cola<int> res(50);
    bool d = true;
    int a = 0,b = 0;
    cout << "introduzca el primer elemento" << endl;
    cin >> a;
    cout << "introduzca el segundo elemento" << endl;
    cin >> b;

    /*while(c.frente() != b){
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
    }*/

    while(!c.vacia()){
        if(c.frente() == a && d){
            while(!c.vacia() && c.frente() != b){
                p.push(c.frente());
                c.pop();
            }
            if(!c.vacia()){
                p.push(c.frente());
                c.pop();
            }
            while(!p.vacia()){
                res.push(p.tope());
                p.pop();
            }
            d = false;
        }
        res.push(c.frente());
        c.pop();
    }
    c = res;
}

void rellena(Cola<int> &c){  //Da error porque no se guarda en la cola :(
    int aux = 0;
    cout << "introduzca los elementos de la cola('-1' para salir)" << endl;
    while(aux != -1){
        cin >> aux;
        if(aux!=-1)
            c.push(aux);
    }
}
