/*Reflejar una Imagen: Implemente un programa que refleje horizontalmente una imagen representada por una matriz de 6x6.
El programa debe intercambiar los elementos de cada fila para obtener la imagen reflejada.*/
#include <iostream>
using namespace std;

void reflejarMatriz(int matriz[][6]) {
    for (int fila = 0; fila < 6; ++fila) {
        for (int col = 0; col < 3; ++col) {
            int temp = matriz[fila][col];
            matriz[fila][col] = matriz[fila][5 - col];
            matriz[fila][5 - col] = temp;
        }
    }
}

void mostrarMatriz(int matriz[][6]) {
    for (int fila = 0; fila < 6; ++fila) {
        for (int col = 0; col < 6; ++col) {
            cout << matriz[fila][col] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matriz[6][6] = {
        {8, 12, 10, 15, 14, 11},
        {7, 9, 13, 16, 18, 17},
        {5, 3, 2, 4, 1, 6},
        {24, 20, 22, 19, 21, 23},
        {30, 25, 26, 27, 28, 29},
        {36, 31, 32, 33, 34, 35}
    };

    cout << "La matriz original es:" << endl;
    mostrarMatriz(matriz);

    reflejarMatriz(matriz);

    cout << "\nLa Matriz reflejada es:" << endl;
    mostrarMatriz(matriz);

    return 0;
}
