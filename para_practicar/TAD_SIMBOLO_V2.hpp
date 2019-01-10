#include "LISTA_ENLA.hpp"

class Simbolo2{
    public:
        simbolo2():
        l()
        {};

        void poner_alfinal(char a){
            Lista<char>::posicion p = l.fin();
            l.insertar(a,p);
        }

        void deshacer(int n){
            Lista<char>::posicion p = l.fin();
            while(n!=0){
                l.eliminar(p);
                n--;
            }
        }

        Lista<char> eje_x(Lista<char> l){
            Lista<char> l2;
            Lista<char>::posicion p = l.primera();
            Lista<char>::posicion q = l.primera();
            while(l.fin()!=l.primera()){
                if(l.elemento(q)=='S'){
                    l2.insertar('B',p);
                }else{
                    if(l.elemento(q)=='B'){
                        l2.insertar('S',p);
                    }else{
                        l2.insertar(l.elemento(p),p);
                    }
                }
                p = l2.siguiente(p);
                q = l.siguiente(q);
            }
            return l2;
        }

        Lista<char> eje_y(Lista<char> l){
            Lista<char> l2;
            Lista<char>::posicion p = l.primera();
            Lista<char>::posicion q = l.primera();
            while(l.fin()!=l.primera()){
                if(l.elemento(q)=='I'){
                    l2.insertar('D',p);
                }else{
                    if(l.elemento(q)=='D'){
                        l2.insertar('I',p);
                    }else{
                        l2.insertar(l.elemento(p),p);
                    }
                }
                p = l2.siguiente(p);
                q = l.siguiente(q);
            }
            return l2;
        }

        Lista<char> eje_xy(Lista<char> l){
            Lista<char> l2;
            Lista<char>::posicion p = l.primera();
            Lista<char>::posicion q = l.primera();
            while(l.fin()!=l.primera()){
                if(l.elemento(q)=='S'){
                    l2.insertar('B',p);
                }else{
                    if(l.elemento(q)=='B'){
                        l2.insertar('S',p);
                    }else{
                        if(l.elemento(q)=='I'){
                            l2.insertar('D',p);
                        }else{
                            if(l.elemento(q)=='D'){
                                l2.insertar('I',p);
                            }
                        }
                    }
                }
                p = l2.siguiente(p);
                q = l.siguiente(q);
            }
            return l2;
        }

    private:
        Lista<char> l;
}