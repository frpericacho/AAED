#include <iostream>
#include "cronometro.hpp"

int main(int argc, char const *argv[])
{
    cronometro c;
    c.activar();
    for(int i = 0; i < 1000000000; ++i);
    c.parar();
    std::cout << c.tiempo() << std::endl;
    return 0;
}
