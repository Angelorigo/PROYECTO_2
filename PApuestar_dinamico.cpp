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
    if (i == 0 && j > 0) return 1.0;
    if (i > 0 && j == 0) return 0.0;
    if (P[i][j] != -1.0)
        return P[i][j];

    P[i][j] = 0.5 * Prob(i - 1, j) + 0.5 * Prob(i, j - 1);
    return P[i][j];}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            P[i][j] = -1.0;

    int victoriasA, victoriasB;
    cout << "Hola, calculemos la probabilidad de que gane el equipo A en base a los partidos faltantes. Son 4 partidos." << endl;
    cout << "Ingrese el número de partidos faltantes del equipo A: ";
    cin >> victoriasA;
    cout << "Ingrese el número de partidos faltantes del equipo B: ";
    cin >> victoriasB;

    if (victoriasA >= N || victoriasB >= N || victoriasA < 0 || victoriasB < 0) {
        cout << "Ese numero de juegos es incorrecto, el maximo es (" << N - 1 << ")." << endl;
        return 1;}

    float resultado = Prob(victoriasA, victoriasB);
    cout << fixed << setprecision(4);
    cout << "La probabilidad de que el equipo A gane la serie es de: " << resultado << endl;
    return 0;}
