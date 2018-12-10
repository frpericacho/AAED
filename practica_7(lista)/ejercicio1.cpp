#include <iostream>
#include "LISTA_ENLA.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    Lista<int> L;

    L.insertar(5);
    cout << L.primera() << endl;

    return 0;
}
