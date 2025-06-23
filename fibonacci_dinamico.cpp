//================================
//  Álvarez Servín Ángel Rodrigo
//    IPN ESFM   Junio 2025
//    PROGRAMACIÓN DINÁMICA
//    ANÁLISIS DE ALGORITMOS
//================================

#include <iostream>
using namespace std;

const int MAX = 100;	//  1 OE
int Tabla[MAX]; 

int FibonacciDinamico(int n) {	
    if (n == 0 || n == 1)	//  2 OE
        return 1;	//  1 OE
    if (Tabla[n] == 0)	//  2 OE
        Tabla[n] = FibonacciDinamico(n - 1) + FibonacciDinamico(n - 2);	//  6 OE
    return Tabla[n];}	// 2 OE

int main() {
    int n;
    cout << "Hola, vamos a calcular la funcion de fibonacci con programacion dinamica." << endl;	//  1 OE
    cout << "Por favor, introduce el valor de n: ";	//  1 OE
    cin >> n;	//  1 OE

    for (int i = 0; i <= n; ++i)	//  5 OE
        Tabla[i] = 0;	//  2 OE

    int resultado = FibonacciDinamico(n);	// 2 OE
    cout << "El Fibonacci dinamico de " << n << " es: " << resultado << endl;	//  4 OE

    return 0;}	//  1 OE
