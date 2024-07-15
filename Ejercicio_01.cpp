/*1. Producto de Dos Matrices: Implemente un programa que multiplique dos matrices de 3x3 y muestre el resultado,
y muestre las dos matrices y su resultado en horizontal.
Ejemplo de Salida:
Matriz A:	Matriz B:	Resultado:
1 2 3	9 8 7 	30 24 18
4 5 6	6 5 4 	84 69 54
7 8 9	3 2 1 	138 114 90
*/
#include <iostream>
using namespace std;

void multiplicarMatrices(int A[][3], int B[][3], int C[][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < 3; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void mostrarMatrices(int A[][3], int B[][3], int C[][3]) {
    cout << "Matriz A:\tMatriz B:\tResultado:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << A[i][j] << "  ";
        }
        cout << "\t";
        for (int j = 0; j < 3; ++j) {
            cout << B[i][j] << "  ";
        }
        cout << "\t";
        for (int j = 0; j < 3; ++j) {
            cout << C[i][j] << "  ";
        }
        cout << endl;
    }
}

int main() {
    int matrizA[3][3] = {
        {2, 3, 4},
        {8, 10, 8},
        {14, 16, 18}
    };

    int matrizB[3][3] = {
        {18, 16, 14},
        {12, 10, 8}, 
        {6, 4, 2}
    };
    
    int resultado[3][3];
    multiplicarMatrices(matrizA, matrizB, resultado);

    mostrarMatrices(matrizA, matrizB, resultado);

    return 0;
}