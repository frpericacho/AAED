#include <iostream>
#include "LISTA_CIR.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Lista<int> l;
    Lista<int>::posicion p = l.initpos();
    l.insertar(4,p);
    
    return 0;
}
