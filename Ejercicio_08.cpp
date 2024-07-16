/*Espiral de Matriz: Escribe un programa que recorra los elementos de una matriz cuadrada de 5x5 en orden espiral.
El recorrido debe comenzar en la esquina superior izquierda de la matriz y avanzar en sentido horario, imprimiendo
los elementos en el orden en que se encuentran siguiendo un camino espiral.*/
#include <iostream>
using namespace std;

const int N = 5;

void recorridoEspiral(int matriz[5][5]) {
    int inicioFila = 0, finFila = N - 1;
    int inicioColumna = 0, finColumna = N - 1;

    while (inicioFila <= finFila && inicioColumna <= finColumna) {
        for (int i = inicioColumna; i <= finColumna; ++i)
            cout << matriz[inicioFila][i] << " ";
        ++inicioFila;

        for (int i = inicioFila; i <= finFila; ++i)
            cout << matriz[i][finColumna] << " ";
        --finColumna;

        if (inicioFila <= finFila) {
            for (int i = finColumna; i >= inicioColumna; --i)
                cout << matriz[finFila][i] << " ";
            --finFila;
        }

        if (inicioColumna <= finColumna) {
            for (int i = finFila; i >= inicioFila; --i)
                cout << matriz[i][inicioColumna] << " ";
            ++inicioColumna;
        }
    }
}

void mostrarMatriz(int matriz[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matriz[5][5] = {
	{1, 9, 3, 7, 5},
	{6, 2, 8, 4, 10},
	{11, 18, 13, 16, 15},
	{21, 12, 14, 19, 20},
	{22, 23, 24, 25, 17}
    };
    cout<<"Matriz(A):"<<endl;
    mostrarMatriz(matriz);
	cout<<endl;
	cout<<"La matriz en forma de espiral es:"<<endl;
    recorridoEspiral(matriz);

    return 0;
}