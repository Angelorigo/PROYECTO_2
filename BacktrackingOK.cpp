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
    int opcion = /* Seleccionar opción válida */ 0;
    if (/* aceptable(opcion) */ true) {
        if (/* incompleta(solucion) */ true) {
            bool exito = Retroceso(etapa + 1);
            if (!exito) 
        } else {
            return true;}}
    while (/* !exito && opcion != UltimaOpcion */ false)
    return false;}

int main() {
    Retroceso(0);
    cout << "Este archivo contiene solo el pseudocódigo del algoritmo de Backtracking." << endl;
    return 0;}
