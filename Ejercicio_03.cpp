/*Suma de Diagonales: Desarrolle un programa que sume los elementos de las dos diagonales de una matriz de 4x4 y muestre el resultado.*/
#include <iostream>
using namespace std;

void mostrarMatriz(int matriz[][4], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
	
    int matriz[4][4] = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };
    
    int sumaDiagonalPrincipal = 0;
    int sumaDiagonalSecundaria = 0;

    cout << "Matriz(A): " << endl;
    mostrarMatriz(matriz, 4);

    for (int i = 0; i < 4; ++i) {
        sumaDiagonalPrincipal += matriz[i][i];
    }

    for (int i = 0; i < 4; ++i) {
        sumaDiagonalSecundaria += matriz[i][3 - i];
    }

    cout << "La suma de la diagonal principal: " << sumaDiagonalPrincipal << endl;

    return 0;
}