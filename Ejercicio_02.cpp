/*Buscar un Valor en una Matriz: Escriba un programa que busque un valor específico en una matriz de 3x3 y devuelva todas las posiciones donde se encuentra, indicando la fila y la columna de cada ocurrencia.
Ejemplo de entrada
Matriz:
1 2 3
4 2 6
7 2 9
Valor a buscar: 2
Ejemplo Salida
El valor 2 se encuentra en:
Fila 0, Columna 1
Fila 1, Columna 1
Fila 2, Columna 1*/
#include <iostream>
using namespace std;

void mostrarMatriz(int matriz[][3]) {
    cout << "Matriz:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void buscarValor(int matriz[][3], int valor) {
    bool encontrado = false;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (matriz[i][j] == valor) {
                cout << "El valor " << valor << " se encuentra en: Fila " << i << ", Columna " << j << endl;
                encontrado = true;
            }
        }
    }
    if (!encontrado) {
        cout << "El valor " << valor << " no se encuentra en la matriz." << endl;
    }
}

int main() {
    int matriz[3][3] = {
        {8, 4, 5},
        {4, 6, 8},
        {2, 1, 3}
    };

    mostrarMatriz(matriz);

    int valorABuscar;
    cout << "Ingrese el valor que desea buscar en la matriz: ";
    cin >> valorABuscar;

    buscarValor(matriz, valorABuscar);

    return 0;
}