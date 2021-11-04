#include <iostream>
#include <string>
using namespace std;

//STRUCT REGISTRO (para las variables que utilizaremos)
struct registro
{
    int id, edadm;
    string duenio, raza;
    float peso; 
};

//------------------------------------------INGRESAR DATOS---------------------------------------------------
registro ingresar_datos(void)
{
    registro r;
    cout << "Ingrese su id: ";
    cin>> r.id;
    cin.ignore(1000,'\n');
    cout << "Ingrese su nombre: ";
    getline(cin,r.duenio);
    cout << "Ingrese la raza de su mascota: ";
    getline(cin,r.raza);
    cout << "Ingrese el peso de su mascota: ";
    cin >> r.peso;
    cout << "Ingrese la edad de su mascota: ";
    cin >> r.edadm;

    return r;
}

//-----------------------------------------MOSTRAR DATOS----------------------------------------------------------
void mostrar_datos(registro r)
{
    cout << endl;
    cout << "Mostrando datos..." << endl << endl;

    cout << "id: " << r.id << endl;
    cout << "Nombre: " << r.duenio << endl;
    cout << "Raza de mascota: " << r.raza << endl;
    cout << "Peso de mascota: " << r.peso << endl;
    cout << "Edad de mascota: " << r.edadm << endl;
}

//----------------------------------------------------------------------------------------------------------------

typedef registro R;
const R noValido = {0};

struct nodo
{
    R dato;
    nodo *sig;
} *primero, *ultimo;

class Veterinaria
{
    private:
        nodo *inicio;
    
    public:
        Veterinaria();
        void insertar(R);
        void mostrar(void);
        void eliminar(R);
        bool empty(void);
};

//CONSTRUCTOR
Veterinaria::Veterinaria(void)
{
    inicio = NULL;
}

//------------------------------------------------INSERTAR-------------------------------------------------------
void Veterinaria::insertar(R dato)
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;

    if (primero==NULL)
    {
        primero = nuevo;
        primero->sig = primero;
        ultimo = primero;
    }
    else
    {
        ultimo->sig = nuevo;
        nuevo->sig = primero;
        ultimo = nuevo;
    }
}

//--------------------------------------------------MOSTRAR------------------------------------------------------
void Veterinaria::mostrar(void)
{
    nodo *actual = new nodo;
    actual = primero;
    bool encontrado = false;
	int num = 0;

    if (primero != NULL)
    {
        cout << "\n Ingrese su id: ";
	    cin >> num;

        do
        {
            if(actual->dato.id == num)
            {
                cout << endl;
                mostrar_datos(actual->dato);
                encontrado = true;
            }
            actual = actual->sig;

        } while(actual!=primero && encontrado != true);

		if(!encontrado)
        {
			cout << "\n id no encontrado...\n\n";
		}
        
    }
    else
    {
        cout << endl << "No se han realizado registros..." << endl << endl;
    }
}

//---------------------------------------------ELIMINAR----------------------------------------------------
void Veterinaria::eliminar(R dato)
{
    nodo* actual = new nodo();
	actual = primero;
	nodo* anterior = new nodo();
	anterior = NULL;
	bool encontrado = false;
	int num = 0;
    
	if(primero!=NULL)
    {
        cout << "\n Ingrese su id: ";
	    cin >> num;
		do{
			
			if(actual->dato.id == num)
            {
				if (actual == primero)
				{   
					primero = primero->sig;
					ultimo->sig = primero;
                    delete(actual);	
				}
				else if(actual == ultimo)
				{
					anterior->sig = primero;
					ultimo = anterior;
                    delete(actual);
				}
				else
				{
					anterior->sig = actual->sig;
				}

				cout << endl << "Registro Eliminado..." << endl << endl;
				encontrado = true;   
			}
			
			anterior = actual;
			actual = actual->sig;
		}while(actual!=primero && encontrado != true);
		if(!encontrado){
			cout << "\n id no encontrado...\n\n";
		}
	}else{
		cout << "\n No se han realizado registros...    \n\n";
	}
}

//---------------------------------------------EMPTY-------------------------------------
bool Veterinaria::empty(void)
{
    return inicio == NULL;
}

//-------------------------------------------------MAIN---------------------------------------------------------
int main(void)
{
    Veterinaria data;
    registro r;
    bool continuar = true;

    int opcion_menu=0;
	do
	{
		cout << "\n|-------------------------------------|";
		cout << "\n|         MENU DE VETERINARIA         |";
		cout << "\n|------------------|------------------|";
		cout << "\n| 1. Insertar      | 3. Eliminar      |";
		cout << "\n| 2. Mostrar       | 4. Salir         |";
		cout << "\n|------------------|------------------|";
		cout << "\n\n Escoja una Opcion: ";
		cin >> opcion_menu;
		switch(opcion_menu){
		case 1:
			cout << "\n\n MENU DE REGISTRO \n\n";
            r = ingresar_datos();
			data.insertar(r);
            cout << "Registro exitoso..." << endl;
			break;
		case 2:
			cout << "\n\n MENU DE IMPRESION \n\n";
			data.mostrar();
			break;
		case 3:
            cout << "\n\n MENU DE ELIMINACION \n\n";
            data.eliminar(r);
			break;
		case 4:
            continuar = false;
            system ("cls");
            cout << "Gracias por preferirnos!" << endl << endl;
            cout << "Estudiante: Jose Raul Moran Henriquez \nCarnet: 00135321" << endl << endl;
			cout << "\n\n Programa finalizado...";
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (opcion_menu != 4);

    return 0;
}