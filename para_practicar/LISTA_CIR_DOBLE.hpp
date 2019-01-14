#ifndef LISTA_CIR_DOBLE_HPP
#define LISTA_CIR_DOBLE_HPP
#include <iostream>
#include <string>
#include <cassert>

template <typename T>class Lista{
        private:
        std::string mostrar() const;
        struct nodo{
            T elto;
            nodo *sig;
            nodo *ant;
            nodo(const T&e, nodo* s = nullptr, nodo * a = nullptr) : elto(e),sig(s),ant(a){}
        };
        nodo* head;
        void copiar(const Lista<T>& l);
        public:
        typedef nodo* posicion;
        Lista() : head(nullptr){}
        Lista(const Lista<T>& l);
        Lista<T>& operator =(const Lista<T>& l);
        posicion initpos() const{
            return head;
        }
        posicion siguiente(posicion p) const{
            assert(head != nullptr);
            return p->sig;
        }
        posicion anterior(posicion p) const{
            assert(head != nullptr);
            return p->ant;
        }
        const T& elemento(posicion p) const{
            assert(head != nullptr);
            return p->elto;
        }
        T& elemento(posicion p) {
            assert(head != nullptr);
            return p->elto;
        }
        posicion buscar(const T& x) const;
        void insertar(const T& x, posicion p);
        void eliminar(posicion p);
        ~Lista();
        template <typename O>
        friend std::ostream& operator << (std::ostream&,const Lista<O>&);
    };

    template <typename T>
    inline void Lista<T>::copiar(const Lista<T>& l){
        head = nullptr;
        nodo* q = l.head->sig;
        nodo* r = new nodo(l.head->elto);
        r->sig = r->ant = r;
        head = r;
        while(q->sig != l.head->sig ){
            nodo* n = new nodo(q->elto,head);
            nodo* l = head->ant;
            head->ant = n;
            n->ant = l;
            l->sig = n;
            q = q->sig;
        }
        /*nodo* n = new nodo(q->elto,head);
        nodo* f = head->ant;
        head->ant = n;
        n->ant = f;
        f->sig = n;*/
    }

    template <typename T>
    inline Lista<T>::Lista(const Lista<T>& l){ copiar(l); }

    template <typename T>
    Lista<T>& Lista<T>::operator =(const Lista<T>& l){
        if (this != &l) {
            this->~Lista();
            copiar(l);
        }
        return *this;
    }

    template <typename T>
    inline typename Lista<T>::posicion Lista<T>::buscar(const T& e) const{
        if( head != nullptr ){
            nodo* tmp = head;
            do{
                if(tmp->elto == e)
                    return tmp;
                tmp = tmp->sig;
            } while(tmp != head );
        }
        return nullptr;
    }

    template <typename T>
    inline void Lista<T>::insertar(const T& e, posicion p){
        nodo* q = new nodo(e);
        nodo* l = head->ant;
        if( head != nullptr ){
            q->sig = head;
            head->ant = q;
            q->ant = l;
            l->sig = q;
        }
        else{
            q->sig = q->ant = q;
            head = q;
        }
    }

    template <typename T>
    inline void Lista<T>::eliminar(posicion q){
        nodo* l = head->ant;
        if ( q->sig == head && q->sig == l )
            head = nullptr;
        else if(q == head ){
            head =  head->sig;
            l->sig = head;
            head->ant = l;
        }
        else{
            q->ant->sig = q->sig;
            q->sig->ant = q->ant;
        }
        delete q;
    }

    template <typename T>
    std::string Lista<T>::mostrar() const{
        std::string n;
        if(head != nullptr){
            nodo* tmp = head;
            do{
                n += std::to_string(tmp->elto) + " ";
                tmp = tmp->sig;
            }while(tmp != head);
        }
        return n;
    }

    template <typename T>
    inline Lista<T>::~Lista(){
        if( head != nullptr ){
            nodo* tmp = head;
            while(tmp->sig != head ){
                nodo* q = tmp;
                tmp = tmp->sig;
                delete q;
            }
            head = nullptr;
        }
    }

    template <typename O>
    std::ostream& operator << (std::ostream& os ,const Lista<O>& list){
        return os << list.mostrar();
    }
}
#endif