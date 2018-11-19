#include <iostream>
#include "cronometro.h"

using namespace std;
void int_directo(int []);
void sel_directo(int []);
void ins_directo(int []);

int main()
{
    int a[10]={10,9,8,7,6,5,4,3,2,1};
    cronometro c;
    //y luego lo de activar y eso
    int_directo(a);
    sel_directo(a);
    ins_directo(a);

    return 0;
}

void int_directo(int a[]){
    int aux = 0,j = 0;
    for(int i = 0;i < 10; ++i){
        if(a[j]>a[j+1]){
            aux = a[j];
            a[j] = a[j+1];
            a[j+1] = aux;
        }
    }
}

void sel_directo(int a[]){
    int aux = a[0],i = 0,j = 0,k = 0;
    for(i = 0;i < 9; ++i){
        k = i;
        aux = a[i];
        for(j = i+1;j < 10; ++j){
            if(a[j] < aux){
                aux = a[j];
                k = j;
            }
        }
        a[k] = a[i];
        a[i] = aux;
    }
}

void ins_directo(int a[]){
    int i, j, index;
    for (i=1; i < 10; i++) {
        index = a[i];
        j = i-1;
        while (j >= 0 && a[j] > index) {
        a[j + 1] = a[j];
        j--;
        }
        a[j+1] = index;
    }
}