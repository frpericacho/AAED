#include <iostream>
#include <cstdlib>

using namespace std;
 
int main()
{
    int a,b;
    cout << "introduzca el numero a: " << endl;
    cin >> a;
    cout << "introduzca el numero b: " << endl;
    cin >> b;

    cout << "el numero aleatorio es: " << rand() %(b-a+1)+a << endl;

    return 0;  
}
