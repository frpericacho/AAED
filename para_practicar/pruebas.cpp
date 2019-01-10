#include <iostream>
#include "TAD_DICCIONARIO.hpp"

int main(int argc, char const *argv[])
{
    diccionario d;
    d.nuevo_esp("hola","hi");
    d.nuevo_esp("adios","bye");
    d.nuevo_esp("chao","bye");
    d.consultar_ing("bye");
    return 0;
}
