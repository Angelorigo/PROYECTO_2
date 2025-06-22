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
    return a.relacionValorPeso > b.relacionValorPeso;}

int main() {
    int n;
    double capacidad;
    cout << "Hola, cuantos objetos quisieras meter en tu mochila?: ";
    cin >> n;

    vector<Objeto> objetos(n);

    for (int i = 0; i < n; i++) {
        cout << "\nCuanto pesa el objeto " << i + 1 << "?" << endl;
        cin >> objetos[i].peso;
        cout << "Cual es el valor del objeto " << i + 1 << "?" << endl;
        cin >> objetos[i].valor;
        objetos[i].id = i + 1;
        objetos[i].relacionValorPeso = objetos[i].valor / objetos[i].peso;}

    cout << "Cual es el peso máximo de tu mochila?" << endl;
    cin >> capacidad;

    sort(objetos.begin(), objetos.end(), comparar);

    double pesoActual = 0.0;
    double valorTotal = 0.0;

    cout << "\nLos objetos que pondremos en la mochila son:\n";

    for (int i = 0; i < n && pesoActual < capacidad; i++) {
        if (pesoActual + objetos[i].peso <= capacidad) {
            pesoActual += objetos[i].peso;
            valorTotal += objetos[i].valor;
            cout << " - Objeto " << objetos[i].id << " (completo)" << endl;
        } else {
            double fraccion = (capacidad - pesoActual) / objetos[i].peso;
            pesoActual += objetos[i].peso * fraccion;
            valorTotal += objetos[i].valor * fraccion;
            cout << " - Objeto " << objetos[i].id << " (" << fraccion * 100 << "/100 del objeto)" << endl;}}

    cout << "\nEl valor total de lo que cupo en tu mochila es: " << valorTotal << endl;
    return 0;}
