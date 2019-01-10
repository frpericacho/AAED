#include "PILA_ENLA.h"

class Tren
{
    public:

        Tren():
        p1(),
        p2()
        {};        
        
        void desp_izq()
        {
            assert(!p2.vacio());
            p2.push(p1.tope());
            p1.pop();
        }
        
        void desp_der()
        {
            assert(!p1.vacio());
            p1.push(p2.tope());
            p2.pop();
        }
        
        void elim_activo()
        {
            assert(!p2.vacio());
            p2.pop();
        }

        void inserta_activo(vagon v)
        {
            p2.push(v);
        }

        vagon observa_activo() const
        {
            assert(!p2.vacio());
            return p2.tope();
        }

        bool esta_vacio() const
        {
            return p2.vacio();
        }

        private:
            Pila<vagon> p1;
            Pila<vagon> p2;
};
