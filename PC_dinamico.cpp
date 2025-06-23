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

const int NumDen = 3;	//  1 OE
const int MontoMax = 100; // Límite para el monto, por temas de procesamiento, 1 OE
int denominaciones[NumDen] = {1, 5, 9};	//  1 OE

int CambioPorDinamica(int monto, vector<int> & monedasUsadas) {
    int C[NumDen][MontoMax + 1];
    int decision[NumDen][MontoMax + 1];
   
    for (int j = 0; j <= monto; j++) {	//  6 OE
        C[0][j] = j;	//  2 OE
        decision[0][j] = 1;}  // Solo monedas de 1, 2 OE

    for (int i = 1; i < NumDen; i++) {	//  6 OE
        for (int j = 0; j <= monto; j++) {	//  5 OE
            if (j < denominaciones[i]) {	//  2  OE
                C[i][j] = C[i - 1][j];	//  3 OE
                decision[i][j] = 0; // no se usó la moneda i, 3 OE
            } else {
                int sinUsar = C[i - 1][j];	//  2 OE
                int usar = 1 + C[i][j - denominaciones[i]];	//  4 OE

                if (usar < sinUsar) {	//  1 OE
                    C[i][j] = usar;	//  2 OE
                    decision[i][j] = 1; // se usó moneda i, 2 OE
                } else {
                    C[i][j] = sinUsar;	//  2 OE
                    decision[i][j] = 0; // no se usó moneda i, 2 OE
                }}}}

    // Recuperar qué monedas se usaron
    int i = NumDen - 1;	//  2 OE
    int j = monto;	//  1 OE
    while (j > 0) {	//  1 OE
        if (decision[i][j] == 1) {	//  2 OE
            monedasUsadas.push_back(denominaciones[i]);	//  1 OE
            j -= denominaciones[i];	//  3 OE
        } else {
            i--;}}	//  2 OE

    return C[NumDen - 1][monto];}	//  3 OE

int main() {
    int monto;
    cout << "+ Wenas joven, cuanto le vamos a cambiar? " << endl;	//  1 OE
    cout << "- Buenos días, quisiera que me cambie $";	//  1 OE
    cin >> monto;	//  1 OE

    if (monto < 0 || monto > MontoMax) {	//  2 OE
        cout << "Como asi joven? solo le puedo cambiar entre $0 y $" << MontoMax << endl;	//  2 OE
        return 1;}	//  1 OE

    vector<int> monedasUsadas;
    int resultado = CambioPorDinamica(monto, monedasUsadas);	//  2 OE
    cout << "El mínimo número de monedas para juntarle sus $" << monto << ", es: " << resultado << endl;	//  4 OE

    cout << "Aqui tiene, son: ";	//  1 OE
    for (int moneda : monedasUsadas) {	//  1 OE
        cout << "$" << moneda << " "; }	//  3 OE
    cout << endl;	//  1 OE

    return 0;}	//  1 OE
