//================================
//  Álvarez Servín Ángel Rodrigo
//    IPN ESFM   Junio 2025
//    PROGRAMACIÓN DINÁMICA
//   ANÁLISIS DE ALGORITMOS
//================================

#include <iostream>
#include <iomanip>
using namespace std;

const int N = 5; // Supongamos que se juegan hasta 4 partidos por equipo (índice de 0 a 4),  1 OE
float P[N][N];   // Matriz de probabilidades

float Prob(int i, int j) {
    if (i == 0 && j > 0) return 1.0;	//  4 OE
    if (i > 0 && j == 0) return 0.0;	//  4 OE
    if (P[i][j] != -1.0)	//  3 OE
        return P[i][j];	//  2 OE

    P[i][j] = 0.5 * Prob(i - 1, j) + 0.5 * Prob(i, j - 1);	//  7 OE
    return P[i][j];}	//  2 OE

int main() {
    for (int i = 0; i < N; i++)	//  4 OE
        for (int j = 0; j < N; j++)	//  4 OE
            P[i][j] = -1.0;	//  3 OE

    int victoriasA, victoriasB;
    cout << "Hola, calculemos la probabilidad de que gane el equipo A en base a los partidos faltantes. Son 4 partidos." << endl;	//  2 OE
    cout << "Ingrese el número de partidos faltantes del equipo A: ";	//  1 OE
    cin >> victoriasA;	//  1 OE
    cout << "Ingrese el número de partidos faltantes del equipo B: ";	//  1 OE
    cin >> victoriasB;	//  1 OE

    if (victoriasA >= N || victoriasB >= N || victoriasA < 0 || victoriasB < 0) {	//  9 OE
        cout << "Ese numero de juegos es incorrecto, el maximo es (" << N - 1 << ")." << endl;	//  4 OE
        return 1;}	//  1 OE

    float resultado = Prob(victoriasA, victoriasB);	//  2 OE
    cout << fixed << setprecision(4);	//  3 OE
    cout << "La probabilidad de que el equipo A gane la serie es de: " << resultado << endl;	//  2 OE
    return 0;}	//  1 OE
