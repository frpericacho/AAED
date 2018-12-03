#include <iostream>
#include "ejercicio3.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    Bicola<int> B;

    B.pushdr(5);
    B.pushiz(7);
    cout << B.frente() << endl;
    cout << B.fiin() << endl;
    B.popdr();
    B.popiz();
    cout << B.frente() << endl;

    return 0;
}
