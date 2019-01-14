#ifndef EJERCICIO8_HPP
#define EJERCICIO8_HPP
#include "LISTA_ENLA.hpp"
#include <cassert>
#include <iostream>
#include <string>

template <typename T> class Binario{
    public:
        Binario(string);
        Binario operator & (Binario& a);//el and
        Binario operator | (Binario& o); // el or
        Binario operator ^ (Binario& x); // el xor
        Binario operator ~ (Binario& n); // el not
        Binario operator << (Binario& izq); // para izquierda
        Binario operator >> (Binario& der); // para derecha
    private:
        Lista<int> l;
        unsigned tam;
};

Binario::Binario(string cad):tam(cad.size()){
    for(char& c: cad){
        assert(c-48 == 0 || c-48 == 1);
        l.insertar(c-48,l.fin());
    }
}

#endif