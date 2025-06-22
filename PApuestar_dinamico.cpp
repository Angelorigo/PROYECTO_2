//================================
//  Álvarez Servín Ángel Rodrigo
//    IPN ESFM   Junio 2025
//    PROGRAMACIÓN DINÁMICA
//   ANÁLISIS DE ALGORITMOS
//================================

#include <iostream>
#include <iomanip>
using namespace std;

const int N = 5; // Supongamos que se juegan hasta 4 partidos por equipo (índice de 0 a 4)
float P[N][N];   // Matriz de probabilidades

float Prob(int i, int j) {
    // Caso base: A gana todos antes de B
    if (i == 0 && j > 0) return 1.0;
    // Caso base: B gana todos antes de A
    if (i > 0 && j == 0) return 0.0;
    // Si ya está calculado, solo lo regresamos
    if (P[i][j] != -1.0)
        return P[i][j];

    // Aplicamos la fórmula: probabilidad promedio de que gane A o B
    P[i][j] = 0.5 * Prob(i - 1, j) + 0.5 * Prob(i, j - 1);
    return P[i][j];
}

int main() {
    // Inicializamos toda la matriz con -1 para identificar no calculado
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            P[i][j] = -1.0;

    int victoriasA, victoriasB;
    cout << "Ingrese el número de juegos restantes para A: ";
    cin >> victoriasA;
    cout << "Ingrese el número de juegos restantes para B: ";
    cin >> victoriasB;

    if (victoriasA >= N || victoriasB >= N || victoriasA < 0 || victoriasB < 0) {
        cout << "Número inválido de juegos (máximo " << N - 1 << ")." << endl;
        return 1;
    }

    float resultado = Prob(victoriasA, victoriasB);
    cout << fixed << setprecision(4);
    cout << "Probabilidad de que el equipo A gane la serie: " << resultado << endl;

    return 0;
}

