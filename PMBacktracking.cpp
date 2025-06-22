//================================
//  Álvarez Servín Ángel Rodrigo
//     ESFM IPN    Junio 2025
//     ANÁLISIS DE ALGORITMOS
//         BACKTRACKING
//================================

#include <iostream>
#include <vector>
using namespace std;

// Variables globales
int pesoMaximo;
vector<int> pesos;
vector<int> valores;
int numObjetos;
int mejorValor = 0;

// Función Backtracking
void mochilaBT(int index, int pesoActual, int valorActual) {
    if (pesoActual > pesoMaximo) return;

    if (index == numObjetos) {
        if (valorActual > mejorValor)
            mejorValor = valorActual;
        return;
    }

    // Caso 1: incluir el objeto index
    mochilaBT(index + 1, pesoActual + pesos[index], valorActual + valores[index]);

    // Caso 2: no incluir el objeto index
    mochilaBT(index + 1, pesoActual, valorActual);
}

int main() {
    cout << "Ingrese el número de objetos: ";
    cin >> numObjetos;

    pesos.resize(numObjetos);
    valores.resize(numObjetos);

    for (int i = 0; i < numObjetos; i++) {
        cout << "Peso del objeto " << i + 1 << ": ";
        cin >> pesos[i];
        cout << "Valor del objeto " << i + 1 << ": ";
        cin >> valores[i];
    }

    cout << "Ingrese el peso máximo de la mochila: ";
    cin >> pesoMaximo;

    // Llamar a la función de backtracking
    mochilaBT(0, 0, 0);

    cout << "El valor máximo que se puede obtener es: " << mejorValor << endl;

    return 0;
}

