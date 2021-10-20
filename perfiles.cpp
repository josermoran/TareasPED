#include<iostream>
#include<string>
using namespace std; 

//STRUCT
struct perfil //variables que utilizaremos.
{
    int id;
    string nombre, rol;
};

//------------------------------------------------INGRESAR DATOS--------------------------------------------------
perfil solicitar_datos(void) //Insercion de datos.
{
    perfil d;
    cout << "Ingrese su id: ";
    cin >> d.id;
    cin.ignore(1000,'\n');
    cout << "Ingrese su nombre: ";
    getline (cin, d.nombre);
    cout << "Ingrese su rol (administrador, cliente o trabajador): ";
    getline (cin, d.rol);   
    
    return d;
}

//------------------------------------------------MOSTRAR DATOS----------------------------------------
void mostrar_perfil(perfil d)
{
    cout << endl;
    cout << "id: " << d.id << endl;
    cout << "Nombre: " << d.nombre << endl;
    cout << "Rol: " << d.rol << endl;
}


typedef perfil D;
const D noValido = {0};

//STRUCT
struct nodo
{
    D dato;
    nodo *sig;
    nodo *ant;
};

class Datos
{
    private:
        nodo *inicio;

    public:
        Datos();
        ~Datos();
        void ingresar_adelante(D);
        void ingresar_atras(D);
        void imprimir(void);
        void imprimir_reversa(void);
        void borrar_adelante(D); //pendiente
        void borrar_atras(D); //pendiente
        bool empty(void);
};

//CONSTRUCTOR
Datos::Datos(void)
{
    inicio = NULL;
}

//DESTRUCTOR
Datos::~Datos()
{
    cout << "Destructor ejecutándose" << endl;
    nodo *p;
    while(inicio){
        p = inicio;
        inicio = inicio->sig;
        delete p;
    }
}

//---------------------------------------------INGRESAR ADELANTE-----------------------------------------------
void Datos::ingresar_adelante(D dato)
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = inicio;
    if(inicio != NULL)
        inicio->ant = nuevo;
    inicio = nuevo;
}

//-------------------------------------------INGRESAR AL FINAL----------------------------------------------------
void Datos::ingresar_atras(D dato)
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if(!inicio){
        inicio = nuevo;
        inicio->sig = inicio->ant = NULL;
    }
    else{
        nodo *saltarin = inicio;
        while(saltarin->sig != NULL)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}

//---------------------------------------IMPRIMIR NORMAL----------------------------------------------------
void Datos::imprimir(void)
{
    nodo *saltarin = inicio;
    while(saltarin != NULL)
    {
        mostrar_perfil(saltarin->dato);
        saltarin = saltarin->sig;
    }
}

///---------------------------------------------IMPRIMIR A LA INVERSA---------------------------------------
void Datos::imprimir_reversa(void)
{
    if(!inicio)
        return;
    nodo *p = inicio;
    nodo *q = NULL;
    while(p)
    {
        q = p;
        p = p->sig;
    }
    while(q)
    {
        mostrar_perfil(q->dato);
        q = q->ant;
    }
}

//-------------------------------------------BORRAR ADELANTE-----------------------------------------------
void Datos::borrar_adelante(D datoB)
{
    if(!inicio)
    { // Lista vacía.
        cout << "Actualmente no hay perfiles." << endl;
    }
    else
    { 
        nodo *aux = NULL;

        while(inicio->sig)
        {
            if(inicio->ant) cout << inicio->ant << endl;
            inicio = inicio->sig;
        }
        aux = inicio->ant;
        aux->sig = NULL;
        delete(inicio);
        inicio = aux;
        while(inicio->ant)
        {
            inicio = inicio->ant;
        }
        cout << "Perfil eliminado!" << endl;
    }
}

//----------------------------------------------BORRAR ATRAS----------------------------------------------------
void Datos::borrar_atras(D datoB)
{   
    if(!inicio)
    { // Lista vacía.
        cout << "Actualmente no hay perfiles." << endl;
    }
    else
    { 
        nodo *aux = inicio;

        if(aux->sig)
        {
            aux = inicio->sig;
            aux->ant = NULL;
            delete inicio;
            inicio = aux;
        }
        cout << "Perfil eliminado!" << endl;
    }
}

//---------------------------------------------EMPTY-------------------------------------
bool Datos::empty(void){
    return inicio == NULL;
}

//-----------------------------------------------MAIN-------------------------------------------
int main(void)
{
    Datos data;

    int op = 0;
    bool continuar = true;
    perfil d;

    do
    {
        cout << endl << "MENU DE DATOS" << endl << endl;
        cout << "1.Ingresar datos al inicio" << endl;
        cout << "2.Ingresar datos al final" << endl;
        cout << "3.Mostrar datos en orden" << endl;
        cout << "4.Mostrar datos en reversa" << endl;
        cout << "5.Borrar al inicio" << endl;
        cout << "6.Borrar al final" << endl;
        cout << "7.Salir" << endl << endl;

        cout << "Opcion: ";
        cin >> op;

        switch (op)
        {
            case 1: //Insercion de datos al inicio.
                d = solicitar_datos();
                data.ingresar_adelante(d);
                cout << endl << "Datos almacenados exitosamente!" << endl << endl;
            break;

            case 2: // Insercion de datos al final.
                d = solicitar_datos();
                data.ingresar_atras(d);
                cout << endl << "Datos almacenados exitosamente!" << endl << endl;
            break;

            case 3: //Imprimir datos en orden.
                data.imprimir();
            break;

            case 4: //Imprimir datos en reversa.
                data.imprimir_reversa();
            break;

            case 5:
                if(data.empty())
                    cout << "Actualmente no hay perfiles" << endl;
                else{
                    data.borrar_atras(d);
                }
            break;

            case 6:
                if(data.empty())
                    cout << "Actualmente no hay perfiles" << endl;
                else{
                    data.borrar_adelante(d);
                }
            break;

            case 7: //Salir
                continuar = false;
                system ("cls");
                cout << "Gracias por preferirnos!" << endl << endl;
                cout << "Estudiante: Jose Raul Moran Henriquez \nCarnet: 00135321" << endl << endl;
            break;

            default: //El usuario se equivoco
                cout << "La opcion invalida, favor intente de nuevo." << endl;
            break;
        }
    }while (continuar);

return 0;
}