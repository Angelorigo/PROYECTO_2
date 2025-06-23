//================================
//  Álvarez Servín Ángel Rodrigo
//     ESFM IPN    Junio 2025
//     ANÁLISIS DE ALGORITMOS
//         BACKTRACKING
//================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Objeto {
    int id;
    double peso;
    double valor;
    double relacionValorPeso;};

bool comparar(Objeto a, Objeto b) {
    return a.relacionValorPeso > b.relacionValorPeso;}	//  4 OE
int main() {	
    int n;
    double capacidad;
    cout << "Hola, cuantos objetos quisieras meter en tu mochila?: ";	// 1 OE
    cin >> n;	// 1 OE
    vector<Objeto> objetos(n);
    for (int i = 0; i < n; i++) {	//  4 OE
        cout << "\nCuanto pesa el objeto " << i + 1 << "?" << endl;	//  4 OE
        cin >> objetos[i].peso;	//  2 OE
        cout << "Cual es el valor del objeto " << i + 1 << "?" << endl;	//  4 OE
        cin >> objetos[i].valor;	//  2 OE
        objetos[i].id = i + 1;	//  4 OE
        objetos[i].relacionValorPeso = objetos[i].valor / objetos[i].peso;}	//  5 OE

    cout << "Cual es el peso máximo de tu mochila?" << endl;	//  1 OE
    cin >> capacidad;	// 1 OE

    sort(objetos.begin(), objetos.end(), comparar);	//  1 OE

    double pesoActual = 0.0;	//  1 OE
    double valorTotal = 0.0;	//  1 OE

    cout << "\nLos objetos que pondremos en la mochila son:\n";	//  1 OE

    for (int i = 0; i < n && pesoActual < capacidad; i++) {	//  6 OE
        if (pesoActual + objetos[i].peso <= capacidad) {	//  3 OE
            pesoActual += objetos[i].peso;	//  3 OE
            valorTotal += objetos[i].valor;	//  3 OE
            cout << " - Objeto " << objetos[i].id << " (completo)" << endl;	//  4 OE
        } else {
            double fraccion = (capacidad - pesoActual) / objetos[i].peso;	//  4 OE
            pesoActual += objetos[i].peso * fraccion;	//  4 OE
            valorTotal += objetos[i].valor * fraccion;	//  4 OE
            cout << " - Objeto " << objetos[i].id << " (" << fraccion * 100 << "/100 del objeto)" << endl;}}	//  7 OE
    cout << "\nEl valor total de lo que cupo en tu mochila es: " << valorTotal << endl;	//  2 OE
    return 0;}	//  1 OE
