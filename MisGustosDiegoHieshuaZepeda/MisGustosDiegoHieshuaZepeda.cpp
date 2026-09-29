#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 3. Función matriz: Transfiere el arreglo a una estructura 2x3
void crearMatriz(const string arr[6], string matriz[2][3]) {
    int index = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = arr[index++];
        }
    }
    cout << "-> Valores transferidos a la matriz 2x3 correctamente.\n";
}

// 4. Función pila: Guarda los 6 valores iniciales y agrega 2 adicionales
void simularPila(const string arr[6], vector<string>& pila) {
    pila.clear(); // Limpiamos el vector por si se llama múltiples veces

    // Apilamos los 6 elementos del arreglo estático
    for (int i = 0; i < 6; i++) {
        pila.push_back(arr[i]);
    }

    // Apilamos 2 elementos adicionales
    pila.push_back("Computación Cuántica");
    pila.push_back("Realidad Aumentada");

    cout << "-> Pila generada exitosamente con 8 elementos en total.\n";
}

// 5. Función de impresión
void imprimirResultados(const string matriz[2][3], const vector<string>& pila) {
    cout << "\n--- MATRIZ (2x3) ---\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "[" << matriz[i][j] << "]\t";
        }
        cout << "\n";
    }

    cout << "\n--- PILA (Orden LIFO: Ultimo en entrar, primero en salir) ---\n";
    if (pila.empty()) {
        cout << "La pila está vacía.\n";
    }
    else {
        // Recorremos el vector en reversa para simular el comportamiento de una pila
        for (int i = pila.size() - 1; i >= 0; i--) {
            cout << " | " << pila[i] << " |\n";
        }
        cout << "  ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
    }
}

int main() {
    // 1. Arreglo estático de 6 cadenas
    string tecnologias[6] = {
        "Inteligencia Artificial", "Ciberseguridad", "Blockchain",
        "Internet de las Cosas", "Big Data", "Cloud Computing"
    };

    string matriz[2][3];
    vector<string> pila;

    bool matrizLista = false, pilaLista = false;
    int opcion = 0;

    // 2. Menú interactivo con ciclo 'while'
    while (opcion != 4) {
        cout << "\n===== MENU DE TECNOLOGIAS =====\n";
        cout << "1. Cargar datos en la Matriz 2x3\n";
        cout << "2. Cargar datos en la Pila (Vector)\n";
        cout << "3. Imprimir resultados\n";
        cout << "4. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            crearMatriz(tecnologias, matriz);
            matrizLista = true;
            break;
        case 2:
            simularPila(tecnologias, pila);
            pilaLista = true;
            break;
        case 3:
            if (!matrizLista || !pilaLista) {
                cout << "[!] Advertencia: Por favor, llena primero la matriz y la pila (Opciones 1 y 2).\n";
            }
            else {
                imprimirResultados(matriz, pila);
            }
            break;
        case 4:
            cout << "Cerrando el programa...\n";
            break;
        default:
            cout << "[!] Opcion no valida. Intentalo de nuevo.\n";
        }
    }

    return 0;
}