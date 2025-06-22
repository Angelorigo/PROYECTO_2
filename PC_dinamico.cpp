//================================
//  Álvarez Servín Ángel Rodrigo
//    ESFM IPN   Junio 2025
//    PROGRAMACIÓN DINÁMICA
//   ANÁLISIS DE ALGORITMOS
//================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int NumDen = 3;
const int MontoMax = 100; // Límite para el monto, por temas de procesamiento.
int denominaciones[NumDen] = {1, 5, 9};

int CambioPorDinamica(int monto, vector<int>& monedasUsadas) {
    int C[NumDen][MontoMax + 1];
    int decision[NumDen][MontoMax + 1];
   
    for (int j = 0; j <= monto; j++) {
        C[0][j] = j;
        decision[0][j] = 1; // Solo monedas de 1
 }

    for (int i = 1; i < NumDen; i++) {
        for (int j = 0; j <= monto; j++) {
            if (j < denominaciones[i]) {
                C[i][j] = C[i - 1][j];
                decision[i][j] = 0; // no se usó la moneda i
            } else {
                int sinUsar = C[i - 1][j];
                int usar = 1 + C[i][j - denominaciones[i]];

                if (usar < sinUsar) {
                    C[i][j] = usar;
                    decision[i][j] = 1; // se usó moneda i
                } else {
                    C[i][j] = sinUsar;
                    decision[i][j] = 0; // no se usó moneda i
                }}}}

    // Recuperar qué monedas se usaron
    int i = NumDen - 1;
    int j = monto;
    while (j > 0) {
        if (decision[i][j] == 1) {
            monedasUsadas.push_back(denominaciones[i]);
            j -= denominaciones[i];
        } else {
            i--;}}

    return C[NumDen - 1][monto];}

int main() {
    int monto;
    cout << "+ Wenas joven, cuanto le vamos a cambiar? " << endl;
    cout << "- Buenos días, quisiera que me cambie $";
    cin >> monto;

    if (monto < 0 || monto > MontoMax) {
        cout << "Como asi joven? solo le puedo cambiar entre $0 y $" << MontoMax << endl;
        return 1;}

    vector<int> monedasUsadas;
    int resultado = CambioPorDinamica(monto, monedasUsadas);
    cout << "El mínimo número de monedas para juntarle sus $" << monto << ", es: " << resultado << endl;

    cout << "Aqui tiene, son: ";
    for (int moneda : monedasUsadas) {
        cout << "$" << moneda << " "; }
    cout << endl;

    return 0;}
