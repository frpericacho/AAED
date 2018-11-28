#include <iostream>
#include "COLA_CIR.h"
#include "PILA_ENLA.h"
using namespace std;

void rellenaC(Pila<int> );
void rellenaP(Cola<int> );
void fun(Pila<int> ,Cola<int> );

int main(int argc, char const *argv[])
{
    Pila<int> p;
    Cola<int> c(100); 

    rellenaP(p);
    rellenaC(c);

    fun(p ,c);

    return 0;
}

void fun(Pila<int> p,Cola<int> c){
    int auxp = 0,auxc = 0,i = 1;
    while(!p.vacia() || !c.vacia()){
        if(i%3 == 0){
            if(auxc!=auxp)
                exit(0);
        }
        if(i%2 == 0){
            auxp = p.tope();
            p.pop();
            i++;
        }else{
            auxc = c.frente();
            c.pop();
            i++;
        }
    }
    cout << "son isomorficas" << endl;
}

void rellenaP(Pila<int> p){
    int aux = 0;
    cout << "introduzcalos numeros de la pila('-1' para salir)" << endl;
    while(aux!= -1){
        cin >> aux;
        p.push(aux);
    }
}

void rellenaC(Cola<int> c){
    int aux = 0;
    cout << "introduzcalos numeros de la cola('-1' para salir)" << endl;
    while(aux!= -1){
        cin >> aux;
        c.push(aux);
    }
}
