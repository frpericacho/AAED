#include <iostream>
#include "operaciones.hpp"
#include "polinom.h"


Polinomio operator +(Polinomio a, Polinomio b){
    int maxA=0,maxB=0;
    maxA=a.grado();
    maxB=b.grado();
    
    if(maxA > maxB){
        Polinomio res(maxA);
        while(maxA >= 0){
            res.coeficiente(maxA,(a.coeficiente(maxA))+(b.coeficiente(maxA)));
            --maxA;
        }
    }else{
        Polinomio res(maxB);
        while(maxB >= 0){
            res.coeficiente(maxB,(a.coeficiente(maxB))+(b.coeficiente(maxB)));
            --maxB;
        }
    }
    return res;
}

Polinomio operator -(Polinomio a, Polinomio b){
    int maxA=0,maxB=0;
    maxA=a.grado();
    maxB=b.grado();
    
    if(maxA > maxB){
        Polinomio res(maxA);
        while(maxA >= 0){
            res.coeficiente(maxA,(a.coeficiente(maxA))-(b.coeficiente(maxA)));
            --maxA;
        }
    }else{
        Polinomio res(maxB);
        while(maxB >= 0){
            res.coeficiente(maxB,(a.coeficiente(maxB))-(b.coeficiente(maxB)));
            --maxB;
        }
    }
    return res;
}

Polinomio operator *(Polinomio a, Polinomio b){
    int maxA=0,maxB=0;
    maxA=a.grado();
    maxB=b.grado();
    
    if(maxA > maxB){
        Polinomio res(maxA);
        while(maxA >= 0){
            res.coeficiente(maxA,(a.coeficiente(maxA))*(b.coeficiente(maxA)));
            --maxA;
        }
    }else{
        Polinomio res(maxB);
        while(maxB >= 0){
            res.coeficiente(maxB,(a.coeficiente(maxB))*(b.coeficiente(maxB)));
            --maxB;
        }
    }
    return res;
}

Polinomio derivada(Polinomio a){
    int max=0;
    max=a.grado();
    Polinomio res(max);
    while(max >= 0){
        res.coeficiente(max,max*a.coeficiente(max));
        --max;
    }
    return res;
}