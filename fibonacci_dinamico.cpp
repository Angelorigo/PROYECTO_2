//================================
//  Álvarez Servín Ángel Rodrigo
//    IPN ESFM   Junio 2025
//    PROGRAMACIÓN DINÁMICA
//    ANÁLISIS DE ALGORITMOS
//================================

#include <iostream>
using namespace std;

const int MAX = 100;
int Tabla[MAX]; 

int FibonacciDinamico(int n) {
    if (n == 0 || n == 1)
        return 1;
    if (Tabla[n] == 0) 
        Tabla[n] = FibonacciDinamico(n - 1) + FibonacciDinamico(n - 2);
    return Tabla[n];}

int main() {
    int n;
    cout << "Hola, vamos a calcular la funcion de fibonacci con programacion dinamica." << endl;
    cout << "Por favor, introduce el valor de n: ";
    cin >> n;

    for (int i = 0; i <= n; ++i)
        Tabla[i] = 0;

    int resultado = FibonacciDinamico(n);
    cout << "El Fibonacci dinamico de " << n << " es: " << resultado << endl;

    return 0;}
