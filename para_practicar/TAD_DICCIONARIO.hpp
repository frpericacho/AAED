#include "LISTA_ENLA.hpp"
#include <string.h>

using namespace std;


class traduccion{
    public:
        traduccion():
        l_esp()
        {};

        void insertar(string& esp){
            if(l_esp.buscar(esp) == l_esp.fin()){
                l_esp.insertar(esp,l_esp.fin());
            }
        }

        void eleminar(string& esp){
            l_esp.eliminar(l_esp.buscar(esp));
        }

        string consultar(){
            string cad;
            Lista<string>::posicion p;
            for(p = l_esp.primera();p != l_esp.fin(); p = l_esp.siguiente(p)){
                cad += l_esp.elemento(p) + "\n";
            }
        }
        
    private:
        Lista<string> l_esp;
};

class diccionario{
    public:
        diccionario():
        l_ing()
        {};

        void nuevo_esp(string& esp,string& ing){
            Lista<traduccion>::posicion p;
            assert(l_ing.fin()==l_ing.primera());
            p = l_ing.buscar(ing);
            l_ing.elemento(p).insertar(esp);
        }

        void eliminar_esp(string& esp,string& ing){
            Lista<traduccion>::posicion p;
            assert(!l_ing.fin()==l_ing.primera());
            p = l_ing.buscar(ing);
            l_ing.eliminar(p).eliminar(esp);
        }

        void consultar_ing(string& ing){
            Lista<traduccion>::posicion p;
            assert(!l_ing.fin()==l_ing.primera());
            p = l_ing.buscar(ing);
            cout << ing << endl;
            cout << l_ing.elemento(p).consultar() << endl;
        }

        ~diccionario();

    private:
        Lista<traduccion> l_ing;
};
