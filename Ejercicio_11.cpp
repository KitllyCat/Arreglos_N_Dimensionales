/*Simulación de Propagación de Fuego: Cree un programa que simule la propagación de un incendio en un bosque representado por una matriz de 10x10, donde los árboles pueden estar en diferentes estados: vivos (0), quemándose (1), quemados (2). El programa debe actualizar el estado del bosque en función de las siguientes reglas y mostrar el bosque en su estado inicial y después de la propagación del fuego:
• Un árbol vivo (0) se convierte en quemándose (1) si al menos uno de sus vecinos está quemándose.
• Un árbol quemándose (1) se convierte en quemado (2) en la siguiente iteración.
• Un árbol quemado (2) permanece quemado.*/
#include <iostream>
using namespace std;

const int N = 10;

void mostrarBosque(int bosque[N][N]){
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cout << bosque[i][j] << " ";
        }
        cout << endl;
    }
}

void actualizarBosque(int bosque[N][N]){
    int nuevoBosque[N][N];

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            nuevoBosque[i][j] = bosque[i][j];
        }
    }

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            if (bosque[i][j] == 0){
                bool arbolVecinoQuemando = false;
                for (int di = -1; di <= 1; ++di){
                    for (int dj = -1; dj <= 1; ++dj){
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni >= 0 && ni < N && nj >= 0 && nj < N){
                            if (bosque[ni][nj] == 1){
                                arbolVecinoQuemando = true;
                                break;
                            }
                        }
                    }
                    if (arbolVecinoQuemando) break;
                }
                if (arbolVecinoQuemando){
                    nuevoBosque[i][j] = 1;
                }
            } else if (bosque[i][j] == 1){
                nuevoBosque[i][j] = 2;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            bosque[i][j] = nuevoBosque[i][j];
        }
    }
}

bool arbolesTodosQuemados(int bosque[N][N]){
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            if (bosque[i][j] != 2){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int bosque[N][N] = { {0} }; 

    bosque[4][4] = 1;
    cout << "---Bienvenido a una simulacion de un bosque quemandose~!---" << endl;
    cout << "Bosque en un principio:" << endl;
    mostrarBosque(bosque);

    while (true){
        cout << "Presiona enter para actualizar la propagacion del fuego...";
        cin.ignore();

        actualizarBosque(bosque);

        cout << "Bosque después de la propagación del fuego:" << endl;
        mostrarBosque(bosque);

        if (arbolesTodosQuemados(bosque)){
            cout << "El bosque esta quemado por completo. Fin de la simulacion" << endl;
            break;
        }
    }

    return 0;
}
