//================================
//  Álvarez Servín Ángel Rodrigo
//     ESFM IPN   Junio 2025
//    ANÁLISIS DE ALGORITMOS
//     RAMIFICACIÓN Y PODA
//================================

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int N = 4;	//  1OE
int costo[N][N] = {
    {29, 19, 17, 12},  // Trabajador A
    {32, 30, 26, 28},  // Trabajador B
    {3,  21, 7,  9 },  // Trabajador C
    {18, 13, 10, 15}   // Trabajador D
};

bool usado[N];
int minimo = INT_MAX;	//  1OE
int mejorAsignacion[N];
int asignacionActual[N];

void asignar(int trabajador, int costoParcial) {
    if (trabajador == N) {	//  1OE
        if (costoParcial < minimo) {	//  1OE
            minimo = costoParcial;	//  1OE
            for (int i = 0; i < N; i++)	//  4OE
                mejorAsignacion[i] = asignacionActual[i];}	//  3OE
        return;}	//  1OE

    for (int tarea = 0; tarea < N; tarea++) {	//  4OE
        if (!usado[tarea]) {	//  2OE
            int nuevoCosto = costoParcial + costo[trabajador][tarea];	//  4OE
            if (nuevoCosto < minimo) {	//  1OE
                usado[tarea] = true;	//  2OE
                asignacionActual[trabajador] = tarea;	//  2OE
                asignar(trabajador + 1, nuevoCosto);	//  2OE
                usado[tarea] = false;}}}}	//  2OE

int main() {
    for (int i = 0; i < N; i++)	//  4OE
	    usado[i] = false; 	//  2OE

    asignar(0, 0);

    cout << "PROBLEMA DE ASIGNACION TRABAJADOR/TAREA" << endl;	//  1OE
    cout << "Hola, con la tabla dada, el costo mínimo de asignacion de tareas es: " << minimo << endl;	//  2OE
    cout << "Asignación óptima:\n";	//  1OE

    for (int i = 0; i < N; i++) {	//  4OE
        char trabajador = 'A' + i;	//  3OE
        int tarea = mejorAsignacion[i] + 1;	//  3OE
        cout << " - Trabajador " << trabajador << " realiza la tarea " << tarea << " (Costo: " << costo[i][mejorAsignacion[i]] << ")\n";}	//  9OE

    return 0;}	//  1OE
