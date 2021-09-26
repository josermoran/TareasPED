#include <iostream>
using namespace std;

int mcd (int, int);

int main(void)
{
    int minor = 0, major = 0;

    cout << "CALCULADORA DE MCD POR EUCLIDES" << endl << endl;

    cout << "Ingrese el numero mayor y menor respectivamente" << endl;
    cin >> major >>minor;

    cout << endl;

    cout << "El resultado del MCD es: " << mcd(major,minor) << endl;
}

int mcd (int major, int minor)
{
    if (major%minor == 0)
    {
        return minor;
    }
    if(major%minor != 0)
    {   
        int aux;
        aux = major;
        major = minor%major;
        minor = aux;

        mcd(major,minor);
    }
}