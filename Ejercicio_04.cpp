/*Intercambio de Filas: Desarrolle un programa que intercambie dos filas específicas de una matriz de 4x4 y muestre la matriz resultante.
Ejemplo de Entrada
Matriz:			Matriz resultante:
1 2 3 4			9 10 11 12
5 6 7 8			5 6 7 8
9 10 11 12		1 2 3 4
13 14 15 16		1 2 3 4
Filas a intercambiar:
0
2*/
#include <iostream>
using namespace std;

void intercambiarFilas(int matriz[4][4], int fila1, int fila2) {
    for (int j = 0; j < 4; ++j) {
        int temp = matriz[fila1][j];
        matriz[fila1][j] = matriz[fila2][j];
        matriz[fila2][j] = temp;
    }
}

void mostrarMatriz(const int matriz[4][4]) {
    cout << "Matriz actual:" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matriz[4][4] = {
        {10, 20, 30, 40},
        {50, 60, 70, 80},
        {90, 100, 110, 120},
        {130, 140, 150, 160}
    };
    
    mostrarMatriz(matriz);
    
    int fila1, fila2;
    cout << "Ingrese el numero de la primera fila para intercambiar (0-3): ";
    cin >> fila1;
    cout << "Ingrese el numero de la segunda fila para intercambiar (0-3): ";
    cin >> fila2;

    if (fila1 < 0 || fila1 > 3 || fila2 < 0 || fila2 > 3) {
        cout << "Numero de fila incorrecto. Ingrese valores entre 0 y 3." << endl;
        return 1;
    }
    
    intercambiarFilas(matriz, fila1, fila2);
    mostrarMatriz(matriz);

    return 0;
}