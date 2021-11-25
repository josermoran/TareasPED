#include <iostream>

using namespace std;

struct nodo {
    int dato;
    nodo *subLeft;
    nodo *subRight;
};

class BinarySearchTree{
    private:
        nodo *pBinarySearchTree;
    public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insertar(void);
    void insertarBST(nodo **, int);
    void showPreorder(nodo *);
    void showInorder(void);
    void showIn(nodo *);
    void showPost(nodo *);
    void showPostOrder(void);
    void showPreorder(void);
    void showPre(nodo *);
    void search(int);
    void searchNode(nodo *, int);
    void deleteN(int);
    void deleteNode(nodo **, int);
    bool empty(void);
};

BinarySearchTree::BinarySearchTree(void)
{
    pBinarySearchTree = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    cout << "Program Execution" << endl;
}

void BinarySearchTree::insertar(void)
{
    int dato;
    char resp;

    do{
        cout << "Escriba y para continuar" << endl;
        cout << "Desea digitar un dato?";
        cin >> resp;
        if(resp == 'y'){
            cout << "Elemento que desea ingresar: ";
            cin >> dato;
            insertarBST(&pBinarySearchTree, dato);
        }

    }while(resp == 'y');
}

void BinarySearchTree::insertarBST(nodo **p, int dato)
{
    if(!(*p)){
        *p = new nodo;
        (*p)->dato = dato;
        (*p)->subLeft = NULL;
        (*p)->subRight = NULL; 
    }
    else{
        if(dato < (*p)->dato)
            insertarBST(&((*p)->subLeft), dato);
        else
            if(dato > (*p)->dato)
                insertarBST(&((*p)->subRight), dato);
            else
                cout << "El dato ya esta ingresado" << endl << endl;
    }
}

void BinarySearchTree::showInorder(void)
{
    showIn(pBinarySearchTree);
}

void BinarySearchTree::showIn(nodo *p)
{
    if(p){
        showIn(p->subLeft);
        cout << p->dato << " ";
        showIn(p->subRight);
    }
    cout << endl;
}

void BinarySearchTree::showPreorder(void)
{
    showPre(pBinarySearchTree);
}

void BinarySearchTree::showPre(nodo *p)
{
    if(p){
        cout << p->dato << " ";
        showPre(p->subLeft);
        showPre(p->subRight);
    }
    cout << endl;
}

void BinarySearchTree::showPostOrder(void)
{
    showPost(pBinarySearchTree);
}

void BinarySearchTree::showPost(nodo *p)
{
    if(p)
    {
        showPost(p->subLeft);
        showPost(p->subRight);
        cout << p->dato << " ";
    }
    cout << endl;
}

void BinarySearchTree::search(int dato)
{
    searchNode(pBinarySearchTree, dato);
}

void BinarySearchTree::searchNode(nodo *p, int dato)
{
    if(!p)
        cout << "El dato no está en el árbol" << endl << endl;
    else
        if(dato < p->dato)
            searchNode(p->subLeft, dato);
        else
            if(dato > p->dato)
                searchNode(p->subRight, dato);
            else
                cout << "Ya llegué al dato" << endl << endl;
}

void BinarySearchTree::deleteN(int dato)
{
    deleteNode(&pBinarySearchTree, dato);
}


void BinarySearchTree::deleteNode(nodo **r, int dato)
{
    nodo *p;

    if(!(*r))
        cout << "El dato NO está en el árbol" << endl << endl;
    else
        if(dato < (*r)->dato)
            deleteNode(&((*r)->subLeft), dato);
        else
            if(dato > (*r)->dato)
                deleteNode(&((*r)->subRight), dato);
            else{
                if(!((*r)->subLeft) && !((*r)->subRight)){
                    p = *r;
                    *r = NULL;
                }
                else
                    if(!((*r)->subLeft) && (*r)->subRight){
                        p = *r;
                        *r = (*r)->subRight;
                    }
                    else
                        if((*r)->subLeft && !((*r)->subRight)){ 
                            p = *r; 
                            *r = (*r)->subLeft; 
                        }
                        else
                            if((*r)->subLeft && (*r)->subRight){ 
                                p = (*r)->subLeft;
                                if(!p->subRight){
                                    (*r)->dato = p ->dato;
                                    (*r)->subLeft = p->subLeft;
                                }
                                else{
                                    nodo *q;
                                    while(p->subRight){
                                        q = p;
                                        p = p->subRight;
                                    }
                                    (*r)->dato = p->dato;
                                    q->subRight = p->subLeft;
                                }
                            }
                delete p;
            }
}

bool BinarySearchTree::empty(void)
{
    return pBinarySearchTree == NULL;
}

int main(void)
{
    BinarySearchTree objBinarySearchTree;
    bool continuar = true;

    int opcion_menu=0;
	do
	{
		cout << "\n|-------------------------------------|";
		cout << "\n|                 MENU                |";
		cout << "\n|------------------|------------------|";
		cout << "\n| 1. Insertar      | 5. Buscar Nodo   |";
		cout << "\n| 2. Pre-orden     | 6. Eliminar      |";
		cout << "\n| 3. In-orden      | 7. Salir         |";
		cout << "\n| 4. Post-orden    |                  |";
		cout << "\n|------------------|------------------|";
		cout << "\n\n Escoja una Opcion: ";
		cin >> opcion_menu;

        switch(opcion_menu){
		case 1:
			cout << "\n\n MENU DE INSERCION \n\n";
			cout << "Insertar datos en el arbol:" <<  endl;
            objBinarySearchTree.insertar();
			break;
		case 2:
			cout << "\n\n PRE-ORDEN \n\n";
			cout << "Mostrar Pre-orden: " << endl;
            objBinarySearchTree.showPreorder();
            cout << endl;
			break;
        case 3:
			cout << "\n\n IN-ORDEN \n\n";
			cout << "Mostrar In-Orden: " << endl;
            objBinarySearchTree.showInorder();
            cout << endl;
			break;
        case 4:
			cout << "\n\n MENU DE INSERCION \n\n";
			cout << "Mostrar Post-Orden: " << endl;
            objBinarySearchTree.showPostOrder();
            cout << endl;
			break;
        case 5:
            cout << "\n\n MENU DE BUSQUEDA \n\n";
            int data;

            cout << "Busquemos un dato:" << endl;
            cout << "Digite el dato a buscar: ";
            cin >> data;
            objBinarySearchTree.search(data);
			break;
        case 6:
			cout << "\n\n ELIMINACION \n\n";
			cout << "Borremos un dato:" << endl;
            cout << "Digite el dato a borrar: ";
            cin >> data;
            objBinarySearchTree.deleteN(data);
			break;
		case 7:
            continuar = false;
            system ("cls");
            cout << "Gracias por preferirnos!" << endl << endl;
            cout << "Estudiante: Jose Raul Moran Henriquez \nCarnet: 00135321" << endl << endl;
			cout << "\n\n Programa finalizado...";
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (opcion_menu != 7);

    return 0;
}