#include <iostream>
#include <queue>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int valor) {
        dato = valor;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

//Función para buscar si un valor ya existe en el árbol
bool buscar(Nodo* raiz, int valor) {
    if (raiz == nullptr) return false;
    if (raiz->dato == valor) return true;
    if (valor < raiz->dato) return buscar(raiz->izquierda, valor);
    return buscar(raiz->derecha, valor);
}

// Función para insertar un nodo en el árbol binario de búsqueda
Nodo* insertar(Nodo* nodo, int valor) {
    if (nodo == nullptr) return new Nodo(valor);
    
    if (valor < nodo->dato) {
        nodo->izquierda = insertar(nodo->izquierda, valor);
    } else if (valor > nodo->dato) {
        nodo->derecha = insertar(nodo->derecha, valor);
    }
    
    return nodo;
}

// Función para imprimir el árbol de forma gráfica en consola
void imprimirArbol(Nodo* raiz, int espacio = 0) {
    if (raiz == nullptr) return;
    
    int incremento = 5;
    espacio += incremento;

    // Procesar hijo derecho primero
    imprimirArbol(raiz->derecha, espacio);

    // Imprimir nodo actual
    cout << endl;
    for (int i = incremento; i < espacio; i++) {
        cout << " ";
    }
    cout << raiz->dato << "\n";

    // Procesar hijo izquierdo
    imprimirArbol(raiz->izquierda, espacio);
}

void preorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    cout << raiz->dato << " ";
    preorden(raiz->izquierda);
    preorden(raiz->derecha);
}

void inorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    inorden(raiz->izquierda);
    cout << raiz->dato << " ";
    inorden(raiz->derecha);
}

void postorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    postorden(raiz->izquierda);
    postorden(raiz->derecha);
    cout << raiz->dato << " ";
}

void bfs(Nodo* raiz) {
    if (raiz == nullptr) return;
    queue<Nodo*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        Nodo* actual = cola.front();
        cola.pop();
        cout << actual->dato << " ";

        if (actual->izquierda != nullptr) cola.push(actual->izquierda);
        if (actual->derecha != nullptr) cola.push(actual->derecha);
    }
}

int contarNodos(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    return 1 + contarNodos(raiz->izquierda) + contarNodos(raiz->derecha);
}

int contarHojas(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    if (raiz->izquierda == nullptr && raiz->derecha == nullptr) return 1;
    return contarHojas(raiz->izquierda) + contarHojas(raiz->derecha);
}

int main() {
    // Árbol base
    Nodo* raiz = new Nodo(10);
    raiz->izquierda = new Nodo(5);
    raiz->derecha = new Nodo(15);
    raiz->izquierda->izquierda = new Nodo(2);
    raiz->izquierda->derecha = new Nodo(7);
    raiz->derecha->izquierda = new Nodo(12);
    raiz->derecha->derecha = new Nodo(20);

    int opcion;
    do {
        cout << "\n=== MENU PRINCIPAL - ARBOLES BINARIOS (UTA) ===" << endl;
        cout << "1. Mostrar recorrido Preorden" << endl;
        cout << "2. Mostrar recorrido Inorden" << endl;
        cout << "3. Mostrar recorrido Postorden" << endl;
        cout << "4. Mostrar recorrido BFS (Niveles)" << endl;
        cout << "5. Ver metricas (Total nodos y hojas)" << endl;
        cout << "6. Agregar nodos adicionales" << endl; 
        cout << "7. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        cout << "\n----------------------------------------" << endl;
        switch (opcion) {
            case 1:
                cout << "Estructura del Arbol:\n";
                imprimirArbol(raiz);
                cout << "\n\nRecorrido Preorden: \n";
                preorden(raiz); cout << endl;
                break;
            case 2:
                cout << "Estructura del Arbol:\n";
                imprimirArbol(raiz);
                cout << "\n\nRecorrido Inorden: \n";
                inorden(raiz); cout << endl;
                break;
            case 3:
                cout << "Estructura del Arbol:\n";
                imprimirArbol(raiz);
                cout << "\n\nRecorrido Postorden: \n";
                postorden(raiz); cout << endl;
                break;
            case 4:
                cout << "Estructura del Arbol:\n";
                imprimirArbol(raiz);
                cout << "\n\nRecorrido BFS (Niveles): \n";
                bfs(raiz); cout << endl;
                break;
            case 5:
                cout << "Metricas:" << endl;
                cout << "- Total de nodos: " << contarNodos(raiz) << endl;
                cout << "- Total de hojas: " << contarHojas(raiz) << endl;
                break;
            case 6: {
                int numNodos, valor;
                cout << "Cuantos nodos desea ingresar? ";
                cin >> numNodos;
                
                int ingresados = 0;
                while (ingresados < numNodos) {
                    cout << "Ingrese el valor del nodo " << (ingresados + 1) << ": ";
                    cin >> valor;
                    
                    // Validación de duplicados
                    if (buscar(raiz, valor)) {
                        cout << "-> ERROR: El valor " << valor << " ya existe en el arbol. Intente con otro.\n";
                    } else {
                        insertar(raiz, valor);
                        ingresados++; // Solo avanzamos si el número fue aceptado
                    }
                }
                cout << "Nodos agregados correctamente al arbol." << endl;
                break;
            }
            case 7:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
        cout << "----------------------------------------" << endl;
    } while (opcion != 7);

    return 0;
}