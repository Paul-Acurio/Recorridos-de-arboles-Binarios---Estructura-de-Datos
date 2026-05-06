#include <iostream>
#include <queue>
#include <string>
#include <sstream>
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

bool buscar(Nodo* raiz, int valor) {
    if (raiz == nullptr) return false;
    if (raiz->dato == valor) return true;
    if (valor < raiz->dato) return buscar(raiz->izquierda, valor);
    return buscar(raiz->derecha, valor);
}

Nodo* insertar(Nodo* nodo, int valor) {
    if (nodo == nullptr) return new Nodo(valor);
    if (valor < nodo->dato) {
        nodo->izquierda = insertar(nodo->izquierda, valor);
    } else if (valor > nodo->dato) {
        nodo->derecha = insertar(nodo->derecha, valor);
    }
    return nodo;
}

void imprimirArbol(Nodo* raiz, int espacio = 0) {
    if (raiz == nullptr) return;
    int incremento = 5;
    espacio += incremento;
    imprimirArbol(raiz->derecha, espacio);
    cout << endl;
    for (int i = incremento; i < espacio; i++) cout << " ";
    cout << raiz->dato << "\n";
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

void obtenerPreorden(Nodo* raiz, string& res) {
    if (raiz == nullptr) return;
    res += to_string(raiz->dato) + " ";
    obtenerPreorden(raiz->izquierda, res);
    obtenerPreorden(raiz->derecha, res);
}

void obtenerInorden(Nodo* raiz, string& res) {
    if (raiz == nullptr) return;
    obtenerInorden(raiz->izquierda, res);
    res += to_string(raiz->dato) + " ";
    obtenerInorden(raiz->derecha, res);
}

void obtenerPostorden(Nodo* raiz, string& res) {
    if (raiz == nullptr) return;
    obtenerPostorden(raiz->izquierda, res);
    obtenerPostorden(raiz->derecha, res);
    res += to_string(raiz->dato) + " ";
}

void obtenerBfs(Nodo* raiz, string& res) {
    if (raiz == nullptr) return;
    queue<Nodo*> cola;
    cola.push(raiz);
    while (!cola.empty()) {
        Nodo* actual = cola.front();
        cola.pop();
        res += to_string(actual->dato) + " ";
        if (actual->izquierda != nullptr) cola.push(actual->izquierda);
        if (actual->derecha != nullptr) cola.push(actual->derecha);
    }
}

string limpiarEspacios(const string& str) {
    stringstream ss(str);
    string item, resultado = "";
    while (ss >> item) resultado += item + " ";
    return resultado;
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
        cout << "7. Evaluar recorridos manualmente (Quiz)" << endl; 
        cout << "8. Proyecto Final Web" << endl; 
        cout << "9. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        cout << "\n----------------------------------------" << endl;
        switch (opcion) {
            case 1:
                cout << "Estructura del Arbol:\n"; imprimirArbol(raiz);
                cout << "\n\nRecorrido Preorden: \n"; preorden(raiz); cout << endl;
                break;
            case 2:
                cout << "Estructura del Arbol:\n"; imprimirArbol(raiz);
                cout << "\n\nRecorrido Inorden: \n"; inorden(raiz); cout << endl;
                break;
            case 3:
                cout << "Estructura del Arbol:\n"; imprimirArbol(raiz);
                cout << "\n\nRecorrido Postorden: \n"; postorden(raiz); cout << endl;
                break;
            case 4:
                cout << "Estructura del Arbol:\n"; imprimirArbol(raiz);
                cout << "\n\nRecorrido BFS (Niveles): \n"; bfs(raiz); cout << endl;
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
                    if (buscar(raiz, valor)) {
                        cout << "-> ERROR: El valor " << valor << " ya existe en el arbol. Intente con otro.\n";
                    } else {
                        insertar(raiz, valor);
                        ingresados++;
                    }
                }
                cout << "Nodos agregados correctamente." << endl;
                break;
            }
            case 7: {
                cin.ignore(); 
                string respuestaUsuario, respuestaCorrecta;
                cout << "=== MODO EVALUACION ===" << endl;
                cout << "Nota: Ingrese los valores separados por un espacio.\n\n";
                
                // IMPRIMIR EL ÁRBOL PARA GUÍA DEL USUARIO
                cout << "Estructura actual del Arbol:\n";
                imprimirArbol(raiz);
                cout << "\n\n";

                respuestaCorrecta = ""; obtenerPreorden(raiz, respuestaCorrecta);
                cout << "1. Escriba el recorrido PREORDEN:\n> ";
                getline(cin, respuestaUsuario);
                if (limpiarEspacios(respuestaUsuario) == respuestaCorrecta) {
                    cout << "   [CORRECTO]\n";
                } else {
                    cout << "   [INCORRECTO] Has fallado.\n   Respuesta esperada: " << respuestaCorrecta << "\n";
                }

                cout << "\n2. Escriba el recorrido INORDEN:\n> ";
                respuestaCorrecta = ""; obtenerInorden(raiz, respuestaCorrecta);
                getline(cin, respuestaUsuario);
                if (limpiarEspacios(respuestaUsuario) == respuestaCorrecta) {
                    cout << "   [CORRECTO]\n";
                } else {
                    cout << "   [INCORRECTO] Has fallado.\n   Respuesta esperada: " << respuestaCorrecta << "\n";
                }

                cout << "\n3. Escriba el recorrido POSTORDEN:\n> ";
                respuestaCorrecta = ""; obtenerPostorden(raiz, respuestaCorrecta);
                getline(cin, respuestaUsuario);
                if (limpiarEspacios(respuestaUsuario) == respuestaCorrecta) {
                    cout << "   [CORRECTO]\n";
                } else {
                    cout << "   [INCORRECTO] Has fallado.\n   Respuesta esperada: " << respuestaCorrecta << "\n";
                }

                cout << "\n4. Escriba el recorrido BFS:\n> ";
                respuestaCorrecta = ""; obtenerBfs(raiz, respuestaCorrecta);
                getline(cin, respuestaUsuario);
                if (limpiarEspacios(respuestaUsuario) == respuestaCorrecta) {
                    cout << "   [CORRECTO]\n";
                } else {
                    cout << "   [INCORRECTO] Has fallado.\n   Respuesta esperada: " << respuestaCorrecta << "\n";
                }
                break;
            }
            case 8:
                cout << "=== Aplicado al proyecto final ===" << endl;
                cout << "Represente los modulos de un sistema web como un arbol binario:\n\n";
                cout << "            Sistema Web" << endl;
                cout << "           /           \\" << endl;
                cout << "     Usuarios        Inventario" << endl;
                cout << "      /    \\          /      \\" << endl;
                cout << " Registrar Buscar  Productos Reportes\n\n";
                
                cout << "1. Mostrar el menu principal:" << endl;
                cout << "   Respuesta: Recorrido PREORDEN (Raiz -> Izquierda -> Derecha)." << endl;
                cout << "   Justificacion: Permite mostrar primero el titulo/modulo principal (Sistema Web) antes de desplegar sus submenus o hijos." << endl;
                
                cout << "\n2. Procesar primero los modulos internos:" << endl;
                cout << "   Respuesta: Recorrido POSTORDEN (Izquierda -> Derecha -> Raiz)." << endl;
                cout << "   Justificacion: Visita primero las hojas (Registrar, Buscar, Productos), asegurando que los procesos mas profundos o internos terminen antes de volver a la raiz." << endl;
                
                cout << "\n3. Mostrar modulos nivel por nivel:" << endl;
                cout << "   Respuesta: Recorrido BFS (Busqueda en Anchura)." << endl;
                cout << "   Justificacion: Permite visualizar las jerarquias nivel por nivel. Primero el Sistema general, luego las grandes categorias (Usuarios, Inventario) y finalmente los detalles." << endl;
                break;
            case 9:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
        cout << "----------------------------------------" << endl;
    } while (opcion != 9);

    return 0;
}