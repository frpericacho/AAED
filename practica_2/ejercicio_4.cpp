#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

int main(){
    int a=0,b=1;
    double x=0,med=0;
    for(int i=0;i<10000000;++i){
        x=(double)rand()/RAND_MAX*(b-a+1)+a;
        med=4*(sqrt)(1-pow(x,2));
    }
    cout << "la media es: " << med/10000000 << endl;
    return 0;
}