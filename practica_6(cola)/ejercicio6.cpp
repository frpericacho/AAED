#include <iostream>
#include <algorithm>
#include "ejercicio6.hpp"
#include "COLA_CIR.h"
using namespace std;

typedef Cola<tCarta> tMonton;
bool solitario(tCarta [], tFig , tMonton );

int main(int argc, char const *argv[])
{
    tCarta baraja[40];
    tMonton reyes(5);

    for(int i = 0, p = OROS; p <= BASTOS; p++){
        for(int f = AS; f <= REY; f++, i++){
            baraja[i] = tCarta(tPalo(p), tFig(f));
        }
    }
    srand(time(0));
    bool victoria = false;
    
    do{
        tFig montonI = tFig(rand() % 10);
        random_shuffle(baraja, baraja+40);
        victoria = solitario(baraja, montonI, reyes);
        while(!reyes.vacia()){
            reyes.pop();
        }
    }while(!victoria);
    
    return 0;
}

bool solitario(tCarta baraja, tFig montonI, tMonton reyes){
    
}