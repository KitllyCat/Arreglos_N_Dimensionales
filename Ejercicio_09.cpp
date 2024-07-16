/*Programa que imprime un cuadrado latino de orden N. Un cuadrado latino de orden N es una matriz cuadrada en la que la primera fila contiene
los N primeros números naturales y cada una de las siguientes N-1 filas contiene la rotación de la fila anterior un lugar a la derecha.*/
#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Introduzca el valor de N: ";
    cin >> N;

    int matriz[N][N];
    for (int i = 0; i < N; ++i) {
        matriz[0][i] = i + 1;
    }

    for (int fila = 1; fila < N; ++fila) {
        for (int col = 0; col < N; ++col) {
            matriz[fila][col] = matriz[fila - 1][(col + 1) % N];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}