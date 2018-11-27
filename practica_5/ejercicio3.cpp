#include <iostream>
#include "cronometro.h"
#include "PILA_ENLA.h"
using namespace std;

void fun(string ,int ,int );

int main(int argc, char const *argv[])
{
    char a,b;
    string cad;
    cout << "introduzca la cadena de numeros" << endl;
    cin >> cad;
    cout << "introduzca el primer elemento" << endl;
    cin >> a;
    cout << "introduzca el segundo elemento" << endl;
    cin >> b;

    cout << cad << endl;

    return 0;
}

void fun(string cad,int a,int b){
    int i = 0;
    string aux;
    Pila<char> p;
    Pila<char> q;

    while(cad[i]!='\0'){
        p.push(cad[i]);
        i++;
    }

    i=0;
    while(p.tope()!='b'){
        q.push(p.tope());
        p.pop();
    }

    while(p.tope()!='a'){
        aux[i]=p.tope();
        p.pop();
        i++;
    }
    aux[i]=p.tope();
    p.pop();

    i=0;
    while(aux[i]!='\0'){
        q.push(aux[i]);
    }

    while(!p.vacia()){
        q.push(p.tope());
        p.pop();
    }

    while(!q.vacia()){
        cout << q.tope() << endl;
        q.pop();
    }
}