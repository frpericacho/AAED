#include <iostream>
using namespace std;
int main()
{
    char cadena[10];
    int n = 0;
    cout << "introduzca la cadena" << endl;
    cin >> cadena;
    cout << "introduzca el numero de ciframiento" << endl;
    cin >> n;
    for(int i = 0;i < 10; ++i){
        cadena[i] = (char)(cadena[i]-(n%26));
    }
    cout << cadena << endl;
    return 0;
}
