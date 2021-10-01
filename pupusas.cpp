#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct nodo
{
    int nPupusas;
    string Ingrediente, tipoMasa, Bebida;
    nodo *sig;
};

class Pedido
{
    private:
        nodo *pInicio;

    public: 
        Pedido(); 
        void orden(void);
        void mostrar_orden(void);
};

Pedido::Pedido(void)
{
    pInicio = NULL;
}

//----------------------------------------------INSERTAR EN PEDIDO--------------------------------------------

void Pedido::orden(void)
{
    nodo *nuevo;
    nuevo = new nodo;
    int opMasa, opCoca;

    system("cls");

cout << "Ingrese la cantidad de pupusas y su ingrediente: ";
    cin >> nuevo->nPupusas;
    cin.clear();
    cin.ignore(1000,'\n');
    getline(cin,nuevo->Ingrediente);
    

    system("cls");

    cout << "1- Maiz" << endl;
    cout << "2- Arroz" << endl;
    cout << "Seleccione el tipo de masa: "; cin >> opMasa;

    if (opMasa == 1)
        nuevo->tipoMasa = "Maiz";
    if  (opMasa == 2)
        nuevo->tipoMasa = "Arroz";

    system("cls");

    cout << "Desea anadir una Coca-Cola a su pedido?" << endl;
    cout << "1- Si." << endl;
    cout << "2- No." << endl << endl;

    cout << "Opcion: "; cin >> opCoca;

    if (opCoca == 1)
    {
        nuevo->Bebida = "Con Coca-Cola";
    }
    if (opCoca == 2)
    {
        nuevo ->Bebida = "Sin Coca-Cola";
    }

    if (!pInicio)
    {
        pInicio = nuevo;
    }
    else
    {
        nodo *aux = pInicio;

        while (aux->sig !=NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

//---------------------------------------------------MOSTRAR ORDEN------------------------------------------------

void Pedido::mostrar_orden(void)
{
    nodo *r = pInicio;

    if (!r)
    {
        cout << "No se encontraron pedidos." << endl;
        cout << endl;
        cout << "Presiona Enter para continuar...";
        getch();
        system("cls"); 
        return;
    }
    else
    {
        cout << "Cantidad de Pupusas: " << r->nPupusas << endl;
        cout << "Ingredientes: " << r->Ingrediente << endl;
        cout << "Tipo de masa: " << r->tipoMasa << endl;
        cout << "Bebida: " << r->Bebida << endl;

        cout << endl;
        cout << "Presiona Enter para continuar...";
        getch();
        system("cls");
    }
}

//---------------------------------------------------MAIN---------------------------------------------------------

int main(void)
{
    Pedido Pedido;

    int op;

    do
    {
        system("cls");

        cout << endl << "PUPUSERIA EL INGENIERO" << endl;
        cout << "MENU DE PEDIDOS" << endl << endl;
        cout << "1- Realizar un pedido" << endl;
        cout << "2- Mostrar el pedido" << endl;
        cout << "3- Salir" << endl << endl;

        cout << "Ingrese una opcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
            Pedido.orden();
            break;

        case 2:
            system("cls");
            Pedido.mostrar_orden();
            break;

        case 3:
            system("cls");
            cout << "Gracias por preferirnos!" << endl << endl;
            cout << "Estudiante: Jose Raul Moran Henriquez \nCarnet: 00135321" << endl << endl;
            break;
    
        default:

            cout << endl;
            system("cls");

            cout << "Opcion invalida";

            cout << endl;
            cout << "Presiona Enter para continuar...";
            getch();
            system("cls");

            break;
        }   
    } while (op != 3);
    
    return 0;
}
