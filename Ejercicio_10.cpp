/*Generador de Tablero de Buscaminas: Desarrolla un programa que genere un tablero inicial para el juego de Buscaminas en una cuadrícula de 10x10.
El programa debe:
a) Crear aleatoriamente un tablero donde cada celda puede contener una mina (1) o estar vacía (0).
b) Para cada celda, calcular y mostrar el número de minas en las ocho celdas adyacentes (no se cuenta la celda misma).
c) Mostrar el tablero original con las minas y el tablero con los números lado a lado.
Nota: Recuerda que en Buscaminas, el número en una celda indica cuántas minas hay alrededor, no incluyendo la propia celda.*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int filas = 10;
const int columnas = 10;
const int numMinas = 20;
int tablero[filas][columnas];
int tableroConMinas[filas][columnas];
int direcciones[8][2] ={
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},          {0, 1},
    {1, -1}, {1, 0}, {1, 1}
};

void inicializarTablero(){
    for (int i = 0; i < filas; ++i){
        for (int j = 0; j < columnas; ++j){
            tablero[i][j] = 0;
            tableroConMinas[i][j] = 0;
        }
    }
}

void colocarMinas(){
    int minasColocadas = 0;
    while (minasColocadas < numMinas){
        int fila = rand() % filas;
        int columna = rand() % columnas;
        if (tableroConMinas[fila][columna] == 0){
            tableroConMinas[fila][columna] = 1;
            minasColocadas++;
        }
    }
}

void calcularNumeros(){
    for (int i = 0; i < filas; ++i){
        for (int j = 0; j < columnas; ++j){
            if (tableroConMinas[i][j] == 1) continue;
            int minasAdyacentes = 0;
            for (int d = 0; d < 8; ++d){
                int nuevaFila = i + direcciones[d][0];
                int nuevaColumna = j + direcciones[d][1];
                if (nuevaFila >= 0 && nuevaFila < filas && nuevaColumna >= 0 && nuevaColumna < columnas && tableroConMinas[nuevaFila][nuevaColumna] == 1) {
                    minasAdyacentes++;
                }
            }
            tablero[i][j] = minasAdyacentes;
        }
    }
}

void mostrarTablero(int tablero[][columnas]){
    for (int i = 0; i < filas; ++i){
        for (int j = 0; j < columnas; ++j){
            cout << (tablero[i][j] == 1 ? "*" : to_string(tablero[i][j])) << " ";
        }
        cout << endl;
    }
}

void mostrarTablerosLadoALado(){
    for (int i = 0; i < filas; ++i){
        for (int j = 0; j < columnas; ++j){
            cout << (tableroConMinas[i][j] == 1 ? "1" : "0") << " ";
        }
        cout << "\t";
        for (int j = 0; j < columnas; ++j){
            cout << (tableroConMinas[i][j] == 1 ? "0" : to_string(tablero[i][j])) << " ";
        }
        cout << endl;
    }
}

int main(){
    srand(time(nullptr));

    inicializarTablero();
    colocarMinas();
    calcularNumeros();

    cout << "Campo de minas:" << endl;
    mostrarTablerosLadoALado();

    return 0;
}

