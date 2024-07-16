/*Buscar el Máximo y Mínimo: Escriba un programa que encuentre el valor máximo y el valor mínimo en una matriz de 4x4, indicando sus posiciones.*/
#include <iostream>
using namespace std;

void encontrarMaximoMinimo(const int matriz[][4], int& maximo, int& minimo, int& filaMaximo, int& columnaMaximo, int& filaMinimo, int& columnaMinimo){
    maximo = matriz[0][0];
    minimo = matriz[0][0];

    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            if (matriz[i][j] > maximo){
                maximo = matriz[i][j];
                filaMaximo = i;
                columnaMaximo = j;
            }
            if (matriz[i][j] < minimo){
                minimo = matriz[i][j];
                filaMinimo = i;
                columnaMinimo = j;
            }
        }
    }
}

void mostrarMatriz(const int matriz[][4]) {
    cout << "Matriz A:" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    const int n = 4;
    int matriz[n][n] ={
        {10, 20, 5, 1},
        {7, 30, 4, 11},
        {5, 0, 1, 12},
        {4, 2, 7, 13}
    };
	
	mostrarMatriz(matriz);
	
    int maximo, minimo, filaMaximo, columnaMaximo, filaMinimo, columnaMinimo;
    encontrarMaximoMinimo(matriz, maximo, minimo, filaMaximo, columnaMaximo, filaMinimo, columnaMinimo);

    cout << "El valor maximo encontrado es " << maximo << " en la posicion (" << filaMaximo << ", " << columnaMaximo << ")." << endl;
    cout << "El valor minimo encontrado es " << minimo << " en la posicion (" << filaMinimo << ", " << columnaMinimo << ")." << endl;

    return 0;
}