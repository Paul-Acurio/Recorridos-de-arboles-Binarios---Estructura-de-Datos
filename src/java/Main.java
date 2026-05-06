import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Nodo {
    int dato;
    Nodo izquierda;
    Nodo derecha;

    public Nodo(int dato) {
        this.dato = dato;
        this.izquierda = null;
        this.derecha = null;
    }
}

public class Main {

    public static boolean buscar(Nodo raiz, int valor) {
        if (raiz == null) return false;
        if (raiz.dato == valor) return true;
        if (valor < raiz.dato) return buscar(raiz.izquierda, valor);
        return buscar(raiz.derecha, valor);
    }

    public static Nodo insertar(Nodo nodo, int valor) {
        if (nodo == null) return new Nodo(valor);
        if (valor < nodo.dato) {
            nodo.izquierda = insertar(nodo.izquierda, valor);
        } else if (valor > nodo.dato) {
            nodo.derecha = insertar(nodo.derecha, valor);
        }
        return nodo;
    }

    public static void imprimirArbol(Nodo raiz, int espacio) {
        if (raiz == null) return;
        int incremento = 5;
        espacio += incremento;
        imprimirArbol(raiz.derecha, espacio);
        System.out.println();
        for (int i = incremento; i < espacio; i++) System.out.print(" ");
        System.out.println(raiz.dato);
        imprimirArbol(raiz.izquierda, espacio);
    }

    public static void preorden(Nodo raiz) {
        if (raiz == null) return;
        System.out.print(raiz.dato + " ");
        preorden(raiz.izquierda);
        preorden(raiz.derecha);
    }

    public static void inorden(Nodo raiz) {
        if (raiz == null) return;
        inorden(raiz.izquierda);
        System.out.print(raiz.dato + " ");
        inorden(raiz.derecha);
    }

    public static void postorden(Nodo raiz) {
        if (raiz == null) return;
        postorden(raiz.izquierda);
        postorden(raiz.derecha);
        System.out.print(raiz.dato + " ");
    }

    public static void bfs(Nodo raiz) {
        if (raiz == null) return;
        Queue<Nodo> cola = new LinkedList<>();
        cola.add(raiz);
        while (!cola.isEmpty()) {
            Nodo actual = cola.poll();
            System.out.print(actual.dato + " ");
            if (actual.izquierda != null) cola.add(actual.izquierda);
            if (actual.derecha != null) cola.add(actual.derecha);
        }
    }

    public static void obtenerPreorden(Nodo raiz, StringBuilder res) {
        if (raiz == null) return;
        res.append(raiz.dato).append(" ");
        obtenerPreorden(raiz.izquierda, res);
        obtenerPreorden(raiz.derecha, res);
    }

    public static void obtenerInorden(Nodo raiz, StringBuilder res) {
        if (raiz == null) return;
        obtenerInorden(raiz.izquierda, res);
        res.append(raiz.dato).append(" ");
        obtenerInorden(raiz.derecha, res);
    }

    public static void obtenerPostorden(Nodo raiz, StringBuilder res) {
        if (raiz == null) return;
        obtenerPostorden(raiz.izquierda, res);
        obtenerPostorden(raiz.derecha, res);
        res.append(raiz.dato).append(" ");
    }

    public static void obtenerBfs(Nodo raiz, StringBuilder res) {
        if (raiz == null) return;
        Queue<Nodo> cola = new LinkedList<>();
        cola.add(raiz);
        while (!cola.isEmpty()) {
            Nodo actual = cola.poll();
            res.append(actual.dato).append(" ");
            if (actual.izquierda != null) cola.add(actual.izquierda);
            if (actual.derecha != null) cola.add(actual.derecha);
        }
    }

    public static String limpiarEspacios(String str) {
        return str.trim().replaceAll("\\s+", " ") + " ";
    }

    public static int contarNodos(Nodo raiz) {
        if (raiz == null) return 0;
        return 1 + contarNodos(raiz.izquierda) + contarNodos(raiz.derecha);
    }

    public static int contarHojas(Nodo raiz) {
        if (raiz == null) return 0;
        if (raiz.izquierda == null && raiz.derecha == null) return 1;
        return contarHojas(raiz.izquierda) + contarHojas(raiz.derecha);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Nodo raiz = new Nodo(10);
        raiz.izquierda = new Nodo(5);
        raiz.derecha = new Nodo(15);
        raiz.izquierda.izquierda = new Nodo(2);
        raiz.izquierda.derecha = new Nodo(7);
        raiz.derecha.izquierda = new Nodo(12);
        raiz.derecha.derecha = new Nodo(20);

        int opcion = 0;
        do {
            System.out.println("\n=== MENU PRINCIPAL - ARBOLES BINARIOS (UTA) ===");
            System.out.println("1. Mostrar recorrido Preorden");
            System.out.println("2. Mostrar recorrido Inorden");
            System.out.println("3. Mostrar recorrido Postorden");
            System.out.println("4. Mostrar recorrido BFS (Niveles)");
            System.out.println("5. Ver metricas (Total nodos y hojas)");
            System.out.println("6. Agregar nodos adicionales");
            System.out.println("7. Evaluar recorridos manualmente (Quiz)");
            System.out.println("8. Proyecto Final Web");
            System.out.println("9. Salir");
            System.out.print("Seleccione una opcion: ");

            try {
                opcion = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                opcion = 0;
            }

            System.out.println("\n----------------------------------------");
            switch (opcion) {
                case 1:
                    System.out.println("Estructura del Arbol:"); imprimirArbol(raiz, 0);
                    System.out.println("\n\nRecorrido Preorden:"); preorden(raiz); System.out.println();
                    break;
                case 2:
                    System.out.println("Estructura del Arbol:"); imprimirArbol(raiz, 0);
                    System.out.println("\n\nRecorrido Inorden:"); inorden(raiz); System.out.println();
                    break;
                case 3:
                    System.out.println("Estructura del Arbol:"); imprimirArbol(raiz, 0);
                    System.out.println("\n\nRecorrido Postorden:"); postorden(raiz); System.out.println();
                    break;
                case 4:
                    System.out.println("Estructura del Arbol:"); imprimirArbol(raiz, 0);
                    System.out.println("\n\nRecorrido BFS (Niveles):"); bfs(raiz); System.out.println();
                    break;
                case 5:
                    System.out.println("Metricas:");
                    System.out.println("- Total de nodos: " + contarNodos(raiz));
                    System.out.println("- Total de hojas: " + contarHojas(raiz));
                    break;
                case 6:
                    System.out.print("Cuantos nodos desea ingresar? ");
                    try {
                        int numNodos = Integer.parseInt(scanner.nextLine());
                        int ingresados = 0;
                        while (ingresados < numNodos) {
                            System.out.print("Ingrese el valor del nodo " + (ingresados + 1) + ": ");
                            int valor = Integer.parseInt(scanner.nextLine());
                            if (buscar(raiz, valor)) {
                                System.out.println("-> ERROR: El valor " + valor + " ya existe en el arbol. Intente con otro.");
                            } else {
                                insertar(raiz, valor);
                                ingresados++;
                            }
                        }
                        System.out.println("Nodos agregados correctamente.");
                    } catch (NumberFormatException e) {
                        System.out.println("Entrada invalida. Volviendo al menu.");
                    }
                    break;
                case 7:
                    StringBuilder correct;
                    String user;
                    System.out.println("=== MODO EVALUACION ===");
                    System.out.println("Nota: Ingrese los valores separados por un espacio.\n");

                    // IMPRIMIR EL ÁRBOL PARA GUÍA DEL USUARIO
                    System.out.println("Estructura actual del Arbol:");
                    imprimirArbol(raiz, 0);
                    System.out.println("\n");

                    // Preorden
                    correct = new StringBuilder(); obtenerPreorden(raiz, correct);
                    System.out.print("1. Escriba el recorrido PREORDEN:\n> ");
                    user = scanner.nextLine();
                    if (limpiarEspacios(user).equals(correct.toString())) {
                        System.out.println("   [CORRECTO]");
                    } else {
                        System.out.println("   [INCORRECTO] Has fallado.\n   Respuesta esperada: " + correct.toString());
                    }

                    // Inorden
                    correct = new StringBuilder(); obtenerInorden(raiz, correct);
                    System.out.print("\n2. Escriba el recorrido INORDEN:\n> ");
                    user = scanner.nextLine();
                    if (limpiarEspacios(user).equals(correct.toString())) {
                        System.out.println("   [CORRECTO]");
                    } else {
                        System.out.println("   [INCORRECTO] Has fallado.\n   Respuesta esperada: " + correct.toString());
                    }

                    // Postorden
                    correct = new StringBuilder(); obtenerPostorden(raiz, correct);
                    System.out.print("\n3. Escriba el recorrido POSTORDEN:\n> ");
                    user = scanner.nextLine();
                    if (limpiarEspacios(user).equals(correct.toString())) {
                        System.out.println("   [CORRECTO]");
                    } else {
                        System.out.println("   [INCORRECTO] Has fallado.\n   Respuesta esperada: " + correct.toString());
                    }

                    // BFS
                    correct = new StringBuilder(); obtenerBfs(raiz, correct);
                    System.out.print("\n4. Escriba el recorrido BFS:\n> ");
                    user = scanner.nextLine();
                    if (limpiarEspacios(user).equals(correct.toString())) {
                        System.out.println("   [CORRECTO]");
                    } else {
                        System.out.println("   [INCORRECTO] Has fallado.\n   Respuesta esperada: " + correct.toString());
                    }
                    break;
                case 8:
                    System.out.println("=== Aplicado al proyecto final ===");
                    System.out.println("Represente los modulos de un sistema web como un arbol binario:\n");
                    System.out.println("            Sistema Web");
                    System.out.println("           /           \\");
                    System.out.println("     Usuarios        Inventario");
                    System.out.println("      /    \\          /      \\");
                    System.out.println(" Registrar Buscar  Productos Reportes\n");

                    System.out.println("1. Mostrar el menu principal:");
                    System.out.println("   Respuesta: Recorrido PREORDEN (Raiz -> Izquierda -> Derecha).");
                    System.out.println("   Justificacion: Permite mostrar primero el titulo/modulo principal (Sistema Web) antes de desplegar sus submenus o hijos.");

                    System.out.println("\n2. Procesar primero los modulos internos:");
                    System.out.println("   Respuesta: Recorrido POSTORDEN (Izquierda -> Derecha -> Raiz).");
                    System.out.println("   Justificacion: Visita primero las hojas (Registrar, Buscar, Productos), asegurando que los procesos mas profundos o internos terminen antes de volver a la raiz.");

                    System.out.println("\n3. Mostrar modulos nivel por nivel:");
                    System.out.println("   Respuesta: Recorrido BFS (Busqueda en Anchura).");
                    System.out.println("   Justificacion: Permite visualizar las jerarquias nivel por nivel. Primero el Sistema general, luego las grandes categorias (Usuarios, Inventario) y finalmente los detalles.");
                    break;
                case 9:
                    System.out.println("Saliendo...");
                    break;
                default:
                    System.out.println("Opcion invalida.");
            }
            System.out.println("----------------------------------------");

        } while (opcion != 9);

        scanner.close();
    }
}
