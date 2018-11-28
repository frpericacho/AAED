#include <iostream>
#include "COLA_CIR.h"
using namespace std;

void rellenar(Cola<int> );
void izquierda(Cola<int> );
void derecha(Cola<int> );

int main(int argc, char const *argv[])
{
    Cola<int> c(100);
    int a = 0;

    do{
        do{
            cout << "introduzca la opcion" << endl;
            cout << "///////////////////////" << endl;
            cout << "1.- rellenar cola" << endl;
            cout << "2.- insertar por la izquierda" << endl;
            cout << "3.- insertar por la derecha" << endl;
            cout << "4.- salir" << endl;
            cin >> a;
        }while(a!=-1);
            switch(a){
                case 1: rellenar(c);
                case 2: izquierda(c);
                case 3: derecha(c);
                case 4: exit(0);
            }
            cout << "Continuar?(5 continuar)" << endl;
    }while(a == 5);

    return 0;
}

void rellenar(Cola<int> c){
    int aux = 0;
    cout << "introduzca los elementos de la cola" << endl;
    while(aux != -1){
        if(aux == -1)
            exit(0);
        cin >> aux;
        c.push(aux);
    }
}

void izquierda(Cola<int> c){
    int aux = 0;
    cout << "introduzca el elemento a introducir" << endl;
    cin >> aux;
    c.push(aux);
}

void derecha(Cola<int> c){
    Cola<int> c2(100);
    int aux = 0;
    cout << "introduzca el elemento a introducir" << endl;
    cin >> aux;
    c2.push(aux);
    while(!c.vacia()){
        c2.push(c.frente());
        c.pop();
    }
    while(!c2.vacia()){
        c.push(c2.frente());
        c2.pop();
    }
}