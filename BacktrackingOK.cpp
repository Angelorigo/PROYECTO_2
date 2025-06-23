//================================
//  Álvarez Servín Ángel Rodrigo
//     ESFM IPN   Junio 2025
//    ANÁLISIS DE ALGORITMOS
//         BACKTRACKING
//================================

#include <iostream>
using namespace std;
bool Retroceso(int etapa);
bool Retroceso(int etapa) {
    int opcion = /* Seleccionar opción válida */ 0;	//  1 OE
    if (/* aceptable(opcion) */ true) {	//  1 OE
        if (/* incompleta(solucion) */ true) {	//  1 OE
            bool exito = Retroceso(etapa + 1);	//  3 OE
            if (!exito) 	//  1 OE
        } else {
            return true;}}	//  1 OE
    while (/* !exito && opcion != UltimaOpcion */ false)	//  5 OE
    return false;}	//  1 OE

int main() {
    Retroceso(0);
    cout << "Este archivo contiene solo el pseudocódigo del algoritmo de Backtracking." << endl;	//  1 OE
    return 0;}	//  1 OE
