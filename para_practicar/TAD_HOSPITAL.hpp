#include "LISTA_VECT.hpp"

class hospital{
    public:
        hospital()

        void ingreso(paciente& p){
            if(p.grado >= 6 && !planta.llena())
                planta.insertar();
            else{
                if(p.grado <= 5 && p.grado != 0 && !uci.llena())
                    uci.insertar();
                    else
                        morgue.insertar();
            }
        }

        bool operator ==(paciente& p, paciente& q){
            return p.id_ == q.id_;
        }

        void alta(paciente& p){
            planta.buscar(p);
        }

        void muerte(paciente& p){
            assert(!morgue.vacia());
            morgue.insertar(uci.buscar(p),morgue.fin());
            uci.eliminar(p);
        }

        int pac_UCI(){
            assert(!uci.vacia());
            int cont = 0;
            Lista<paciente>::posicion p = uci.primera();
            while(p != uci.fin()){
                cont++;
                p = uci.siguiente(p);
            }
            return cont;
        }

        int pac_PLANTA(){
            assert(!planta.vacia());
            int cont = 0;
            Lista<paciente>::posicion p = planta.primera();
            while(p != planta.fin()){
                cont++;
                p = planta.siguiente(p);
            }
            return cont;
        }

        int pac_GRAVEDAD(int gr){
            assert(!planta.vacia() && !uci.vacia());
            if(gr >= 6){
                planta.
            }else{
                uci.
            }
        }

        ~hospital();

    private:
        Lista<paciente> uci(50),planta(50),morgue(50);
}

class paciente{
    public:
        paciente(int id=0,int grado=6):
        id_(id),
        grado_(grado)
        {}
    private:
        int id_,grado_;
}