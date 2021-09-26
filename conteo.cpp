#include <iostream>
using namespace std;

void conteo(int, int);

int main(){
    int num;

    cout << "PROGRAMA DE CONTEO" << endl << endl;
    cout << "Ingrese un numero: "; 
    cin >> num;

    conteo(1, num);
    
    return 0;
}

void conteo(int aux, int num)
{
    if(aux <= num)
    {
        cout << aux << endl;
        aux++;

        conteo(aux, num);
    }  
    else if(num >= 1)
    {
        num--;
        cout << num << endl;

        if(num != 1)
        {
            conteo(aux, num);
        }
    }
}