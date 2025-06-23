//================================
//  Álvarez Servín Ángel Rodrigo
//    IPN ESFM   Junio 2025
//    PROGRAMACIÓN DINÁMICA
//   ANÁLISIS DE ALGORITMOS
//================================

#include <iostream>
using namespace std;

const int MAX = 100;
int TP[MAX][MAX]; 

int CoefBin(int n, int r) {
    if (r < 0 || r > n)	//  3 OE
        return 0;	//  1 OE
    if (r == 0 || r == n)	//  3 OE
        return 1;	//  1 OE
    if (TP[n][r] != -1)	//  3 OE
        return TP[n][r];	//  2 OE

    TP[n][r] = CoefBin(n - 1, r - 1) + CoefBin(n - 1, r);	//  9 OE
    return TP[n][r];}	//  2 OE

int main() {
        for (int i = 0; i < MAX; i++)	//  4 OE
        for (int j = 0; j < MAX; j++)	//  4 OE
            TP[i][j] = -1;	//  3 OE

    int n, r;
    cout << "Calculemos el coeficiente binomial de (n, r), con n y r menores a 100:"<< endl;	//  1 OE
    cout << "Ingresa n: ";	//  1 OE
    cin >> n;	//  1 OE
    cout << "Ingresa r: ";	//  1 OE
    cin >> r;	//  1 OE

    int resultado = CoefBin(n, r);	//  2 OE
    cout << "El coeficiente binomial C(" << n << ", " << r << ") es: " << resultado << endl;	//  6 OE

    return 0;}	//  1 OE
