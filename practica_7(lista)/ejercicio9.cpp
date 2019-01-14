#include <iostream>
#include "LISTA_CIR.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    int i;
    Lista<int> l;
    Lista<int>::posicion p;
    p = l.initpos();

    while(i != 0){
        cout << "introduzca un valor" << endl;
        cin >> i;
        l.insertar(i,p);
        p = l.siguiente(p);
    }

    return 0;
}
