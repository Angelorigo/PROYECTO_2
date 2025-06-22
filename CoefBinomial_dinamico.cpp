//================================
//  Álvarez Servín Ángel Rodrigo
//    IPN ESFM   Junio 2025
//    PROGRAMACIÓN DINÁMICA
//   ANÁLISIS DE ALGORITMOS
//================================

#include <iostream>
using namespace std;

const int MAX = 100;
int TP[MAX][MAX]; // Triángulo de Pascal para memoización

int CoefBin(int n, int r) {
    if (r < 0 || r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    if (TP[n][r] != -1)
        return TP[n][r];

    TP[n][r] = CoefBin(n - 1, r - 1) + CoefBin(n - 1, r);
    return TP[n][r];
}

int main() {
    // Inicializamos la matriz con -1
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            TP[i][j] = -1;

    int n, r;
    cout << "Calculemos el coeficiente binomial de (n, r), con n y r menores a 100:"<< endl;
    cout << "Ingresa n: ";
    cin >> n;
    cout << "Ingresa r: ";
    cin >> r;

    int resultado = CoefBin(n, r);
    cout << "El coeficiente binomial C(" << n << ", " << r << ") es: " << resultado << endl;

    return 0;
}

