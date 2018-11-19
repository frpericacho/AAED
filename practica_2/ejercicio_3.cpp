#include <iostream>
#include <cstdlib>
using namespace std;
void flotante();
void doble();

int main()
{
    int opc;
    cout << "introduzca si quiere usar flotante(1) o double(2)" << endl;
    cin >> opc;
    switch(opc){
        case 1: flotante(); break;
        case 2: doble(); break;
        default: cout << "valor no valido" << endl; break;
    }
    return 0;
}

void flotante(){
    float a,b;
    cout << "introduzca el numero a: " << endl;
    cin >> a;
    cout << "introduzca el numero b: " << endl;
    cin >> b;
    cout << "el numero aleatorio es: " << ((float)rand()/RAND_MAX*(b-a+1)+a) << endl;
}

void doble(){
    double a,b;
    cout << "introduzca el numero a: " << endl;
    cin >> a;
    cout << "introduzca el numero b: " << endl;
    cin >> b;
    cout << "el numero aleatorio es: " << ((double)rand()/RAND_MAX*(b-a+1)+a) << endl;
}