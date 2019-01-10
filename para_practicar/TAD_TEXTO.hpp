#include "PILA_ENLA.h"

using namespace std;

class texto{
    public:
        texto():
        p()
        {};

        void imprimir(Pila<int> p){
            Pila<char> p2;
            while(!p.vacia()){
                if(p.tope()=='@'){
                    while(p.tope()=='@'){
                        p.pop();
                    }
                    p.pop();
                }else{
                    if(p.tope()=='#'){
                        while(p.tope()!='\n'){
                            p.pop();
                        }
                        p.pop();
                    }else{
                        p2.push(p.tope());
                        p.pop();
                    }
                }
            }
            while(!p2.vacia){
                cout << p2.tope() << endl;
                p2.pop();
            }
        }

    private:
        Pila<char> p;
}