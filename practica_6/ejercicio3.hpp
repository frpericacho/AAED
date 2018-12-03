#ifndef EJERCICIO3_HPP
#define EJERCICIO3_HPP
#include <cassert>

template <typename T> 
class Bicola{
public:
    Bicola();
    bool vacia();
    void pushdr(const T &);
    void pushiz(const T &);
    void popdr();
    void popiz();
    const T & frente()const;
    const T & fiin()const;
    ~Bicola();
private:
    struct nodo{
        nodo(const T & elem,nodo* puntero=nullptr): elemento(elem),siguiente(puntero){}
        nodo* siguiente;
        T elemento;
    };
    nodo* inicio;
    nodo* fin;
    int size;
};

template <typename T> 
Bicola<T>::Bicola():inicio(nullptr),fin(nullptr),size(0){}

template <typename T>
bool Bicola<T>::vacia(){
    return size==0;
}

template <typename T>
void Bicola<T>::pushdr(const T& elem){
    if(inicio==nullptr){
        inicio=new nodo(elem);
        fin = inicio;
    }else{
        nodo* n = new nodo(elem);
        inicio->siguiente = n;
        inicio = n;
    }
    size++;
}

template <typename T>
void Bicola<T>::pushiz(const T& elem){
    if(fin == nullptr){
        fin=new nodo(elem);
        inicio = fin;
    }else{
        fin = new nodo(elem,fin);
    }
    size++;
}

template <typename T>
void Bicola<T>::popdr(){
    assert(size>0);
    if(inicio==fin){
        delete inicio;
        inicio = fin = nullptr;
    }else{
        nodo* iter=nullptr;
        for(iter = fin;iter->siguiente!=inicio;iter=iter->siguiente);
        delete inicio;
        inicio = iter;
    }
    size--;
}

template <typename T>
void Bicola<T>::popiz(){
    assert(size>0);
    nodo* iter=nullptr;
    if(inicio==fin){
        delete inicio;
        inicio = fin = nullptr;
    }else{
        iter = fin->siguiente;
        delete fin;
        fin = iter;
    }
    size--;
}

template <typename T>
const T& Bicola<T>::frente()const{
    assert(size>0);
    return inicio->elemento;
}

template <typename T>
const T& Bicola<T>::fiin()const{
    assert(size>0);
    return fin->elemento;
}

template <typename T>
Bicola<T>:: ~Bicola(){
    if(inicio!=nullptr && fin != nullptr){
        nodo *iter= fin;
        while(iter->siguiente != nullptr){
            iter = iter->siguiente;
            delete fin;
            fin = iter;
        }
        delete fin;
    }
} 

#endif 