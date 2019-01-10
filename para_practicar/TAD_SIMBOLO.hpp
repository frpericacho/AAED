#include "COLA_CIR.h"

/*

            COMPROBAR QUE ESTA BIEN HECHO

*/


class Simbolo{
    public:
        Simbolo():
        c1(),
        c2()
        {};

        void poner_al_final(char a){
            c1.push(a);
        }

        void deshacer(int n){
            assert(!c1.vacia());
            while(n!=0){
                c1.pop();
                n--;
            }
        }

        Cola eje_x(){
            assert(!c1.vacia());
            while(!c1.vacia()){
                if(c1.frente()=='S'){
                    c2.push('B');
                    c1.pop();
                }
                if(c1.frente()=='B'){
                    c2.push('S');
                    c1.pop();
                }
                else{
                    c2.push(c1.frente());
                    c1.pop();
                }
            }

            return c2;
        }

        Cola eje_y(){
            assert(!c1.vacia());
            while(!c1.vacia()){
                if(c1.frente()=='I'){
                    c2.push('D');
                    c1.pop();
                }
                if(c1.frente()=='D'){
                    c2.push('I');
                    c1.pop();
                }
                else{
                    c2.push(c1.frente());
                    c1.pop();
                }
            }

            return c2;
        }

        Cola eje_xy(){
            assert(!c1.vacia());
            while(!c1.vacia()){
                if(c1.frente()=='I'){
                    c2.push('D');
                    c1.pop();
                }
                if(c1.frente()=='D'){
                    c2.push('I');
                    c1.pop();
                }
                if(c1.frente()=='S'){
                    c2.push('B');
                    c1.pop();
                }
                if(c1.frente()=='B'){
                    c2.push('S');
                    c1.pop();
                }
                else{
                    c2.push(c1.frente());
                    c1.pop();
                }
            }

            return c2;
        }

    private:
        Cola<char> c1,c2;
}