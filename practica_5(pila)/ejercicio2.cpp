#include <iostream>
#include <stdlib.h>
#include "PILA_ENLA.h"
using namespace std;

bool fun1(string );
void fun2(string );

int main(){
    string cad,cad2;
    /*cout << "introduzca la cadena" << endl;
    cin >> cad;
    fun1(cad);*/

    cout << "introduzca la cadena para el ejercicio 2" << endl;
    cin >> cad2;
    fun2(cad2);

    return 0;
}

void fun2(string cad){
    int i = 0,p = 0;
    string aux;
    Pila<char> a;

    while(cad[i]!='\0'){
        if(cad[i]!='#'){
            aux[i]=cad[i];
        }else{
            if(!fun1(aux)){
                exit(0);
            }else{

            }
        }
        i++;
    }
    cout << "son iguales" << endl;
}

bool fun1(string cad){
    int i = 0;

    Pila<char> p;
    Pila<char> q;
    Pila<char> r;

    while(cad[i]!='&'){
        p.push(cad[i]);
        i++;
    }

    i++;

    while(cad[i]!='\0'){
        q.push(cad[i]);
        i++;
    }

    while(!q.vacia()){
        r.push(q.tope());
        q.pop();
    }

    while(!p.vacia()){
        if(p.tope()!=r.tope()){
            cout << "No son iguales" << endl;
            return false;
        }
        p.pop();
        r.pop();
    }
}