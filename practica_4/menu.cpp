#include <iostream>
#include "operaciones.cpp"
#include "polinom.cpp"
using namespace std;

int main(){
    int a=0,b=0;
    Polinomio a,b;
    a=datos();
    b=datos();

    do{
        do{
            cout << "elija una opcion" << endl;
            cout << "1.- Sumar" << endl;
            cout << "2.- Restar" << endl;
            cout << "3.- Multiplicar" << endl;
            cout << "4.- Derivar a" << endl;
            cout << "5.- Derivar b" << endl;
            cout << "---------------" << endl;
            cin >> a;
        }while(a<1 || a>4);
        switch(a){
            case 1: a+b; break;
            case 2: a-b; break;
            case 3: a*b; break;
            case 4: derivada(a); break;
            case 5: derivada(b); break;
            default: cout << "error" << endl; break;
        }
        cout << "desea hacer otra operacion?(0 para salir)" << endl;
        cin >> b;
    }while(b!=0);

    return 0;
}

Polinomio datos(){
    int sal=0,grad=0;
    Polinomio res;
    double coef=0;
    do{
        cout << "introduzca el coeficiente" << endl;
        cin >> coef;
        cout << "introduzca el grado del coeficiente" << endl;
        cin >> grad;
        res.coeficiente(grad,coef);
    }while(sal!=0);
    return res;
}
