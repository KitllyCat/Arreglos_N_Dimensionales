/*Rotación de una Imagen Representada por una Matriz: Escriba un programa que rote una matriz de 4x4, representando una imagen,
90 grados en sentido horario.*/
#include <iostream>
using namespace std;

void rotar90GradosMatriz(int a[][4]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = i; j < 3 - i; ++j) {
            int temp = a[i][j];
            a[i][j] = a[3 - j][i];
            a[3 - j][i] = a[3 - i][3 - j];
            a[3 - i][3 - j] = a[j][3 - i];
            a[j][3 - i] = temp;
        }
    }
}

void mostrarMatriz(int matriz[][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matriz[4][4] = {
	{1, 8, 3, 6},
	{5, 2, 7, 4},
	{9, 12, 11, 10},
	{13, 15, 16, 14}
    };

    cout << "La matriz original es:" << endl;
    mostrarMatriz(matriz);

    rotar90GradosMatriz(matriz);

    cout << "\nLa matriz al rotar 90 grados en sentido horario:" << endl;
    mostrarMatriz(matriz);

    return 0;
}