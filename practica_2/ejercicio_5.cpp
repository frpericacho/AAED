#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string.h>
using namespace std;


int main(){
    int comp=0;
    int a[]={0,1,2,3,4,5};
    int b[]={0,1,2,3,4,5};
    const size_t n = sizeof a / sizeof *a;
    for(int i=0;i<10000000;++i){
        random_shuffle(a,a+n);
        if(memcmp(a,b,sizeof b)==0) ++comp;
    }
    cout << "el numero de veces que se han ordenado son: " << comp << endl;
    return 0;
}