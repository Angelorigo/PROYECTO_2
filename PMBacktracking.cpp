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
    double relacionValorPeso;
};

// Ordenar objetos por relación valor/peso descendente
bool comparar(Objeto a, Objeto b) {
    return a.relacionValorPeso > b.relacionValorPeso;
}

int main() {
    int n;
    double capacidad;
    cout << "Número de objetos: ";
    cin >> n;

    vector<Objeto> objetos(n);

    for (int i = 0; i < n; i++) {
        cout << "Peso del objeto " << i + 1 << ": ";
        cin >> objetos[i].peso;
        cout << "Valor del objeto " << i + 1 << ": ";
        cin >> objetos[i].valor;
        objetos[i].id = i + 1;
        objetos[i].relacionValorPeso = objetos[i].valor / objetos[i].peso;
    }

    cout << "Peso máximo de la mochila: ";
    cin >> capacidad;

    sort(objetos.begin(), objetos.end(), comparar);

    double pesoActual = 0.0;
    double valorTotal = 0.0;

    cout << "\nObjetos seleccionados:\n";

    for (int i = 0; i < n && pesoActual < capacidad; i++) {
        if (pesoActual + objetos[i].peso <= capacidad) {
            // Se mete el objeto completo
            pesoActual += objetos[i].peso;
            valorTotal += objetos[i].valor;
            cout << " - Objeto " << objetos[i].id << " (completo)" << endl;
        } else {
            // Se mete fracción del objeto
            double fraccion = (capacidad - pesoActual) / objetos[i].peso;
            pesoActual += objetos[i].peso * fraccion;
            valorTotal += objetos[i].valor * fraccion;
            cout << " - Objeto " << objetos[i].id << " (" << fraccion * 100 << "% del objeto)" << endl;
        }
    }

    cout << "\nValor máximo que se puede obtener: " << valorTotal << endl;

    return 0;
}

