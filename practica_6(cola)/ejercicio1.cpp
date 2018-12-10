#include <iostream>
#include "COLA_CIR.h"
#include "PILA_ENLA.h"
using namespace std;

void rellenaP(Pila<int> &);
void rellenaC(Cola<int> &);
//void imprimeC(Cola<int> &);
//
void imprimeP(Pila<int> );
void fun(Pila<int> ,Cola<int> &);

int main(int argc, char const *argv[])
{
    Pila<int> p;
    Cola<int> c(100); 

    rellenaP(p);
    rellenaC(c);

    //imprimeP(p);
    //imprimeC(c);

    fun(p ,c);

    return 0;
}

/*void imprimeC(Cola<int> &c){
    while(!c.vacia()){
        cout << c.frente() << endl;
        c.pop();
    }
}

void imprimeP(Pila<int> p){
    while(!p.vacia()){
        cout << p.tope() << endl;
        p.pop();
    }
}*/

void fun(Pila<int> p,Cola<int> &c){
    int auxp = 0,auxc = 0,i = 1,cont = 0;
    while(!p.vacia() || !c.vacia()){
        if(i%3 == 0){
            if(auxc!=auxp){
                cout << cont << endl;
                cout << "no son iguales " << endl;
                exit(0);
            }
        }
        if(i%2 == 0){
            auxp = p.tope();
            p.pop();
            c.pop();
            i++;
            cont++;
        }else{
            auxc = c.frente();
            c.pop();
            p.pop();
            i++;
            cont++;
        }
    }
    cout << "son isomorficas" << endl;
}

void rellenaP(Pila<int> &p){
    int aux = 0;
    cout << "introduzcalos numeros de la pila('-1' para salir)" << endl;
    cout << "ten encuenta que debes meterlos desde el final al principio" << endl;
    while(aux!= -1){
        cin >> aux;
        if(aux!=-1)
            p.push(aux);
    }
}

void rellenaC(Cola<int> &c){
    int aux = 0;
    cout << "introduzcalos numeros de la cola('-1' para salir)" << endl;
    while(aux!= -1){
        cin >> aux;
        if(aux!=-1)
            c.push(aux);
    }
}
