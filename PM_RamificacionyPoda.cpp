//================================
//  Álvarez Servín Ángel Rodrigo
//    IPN ESFM   Junio 2025
//   ANÁLISIS DE ALGORITMOS
//    RAMIFICACIÓN Y PODA
//================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Objeto {
    int id;
    double peso;
    double valor;
    double relacion;};

bool comparar(Objeto a, Objeto b) {
    return a.relacion > b.relacion;}	// 4OE
	
double mejorValor = 0.0;	//  1OE
vector<int> seleccionMejor;
vector<int> seleccionActual;

double cotaSuperior(int nivel, double pesoActual, double valorActual, double capacidad, const vector<Objeto>& objetos) {
    double peso = pesoActual;	//  1OE
    double valor = valorActual;	//  1OE 
    int n = objetos.size();	//  1OE

    for (int i = nivel; i < n; i++) {	//  4OE
        if (peso + objetos[i].peso <= capacidad) {	//  4OE
            peso += objetos[i].peso;	//  3OE
            valor += objetos[i].valor;	//  3OE
        } else {
            double fraccion = (capacidad - peso) / objetos[i].peso;	//  4OE
            valor += objetos[i].valor * fraccion;	//  4OE
            break;}}
    return valor;}	//  1OE

void mochilaRP(int nivel, double pesoActual, double valorActual, double capacidad, const vector<Objeto>& objetos) {
    int n = objetos.size();	//  2OE

    if (nivel == n) {	//  1OE
        if (valorActual > mejorValor) {	//  1OE
            mejorValor = valorActual;	//  1OE
            seleccionMejor = seleccionActual;}	//  1OE
 	return;}	//  1OE
 
    if (pesoActual + objetos[nivel].peso <= capacidad) {	//  4OE
        seleccionActual.push_back(objetos[nivel].id);	//  2OE
        mochilaRP(nivel + 1, pesoActual + objetos[nivel].peso, valorActual + objetos[nivel].valor, capacidad, objetos);	//  5OE
        seleccionActual.pop_back();}	//  1OE

    double estimado = cotaSuperior(nivel + 1, pesoActual, valorActual, capacidad, objetos);	//  2OE
    if (estimado > mejorValor) {	//  1OE
        mochilaRP(nivel + 1, pesoActual, valorActual, capacidad, objetos);};}	//  2OE

int main() {
    int n;
    double capacidad;
    cout << "PROBLEMA DE LA MOCHILA POR RAMIFICACION Y PODA, NO SE PUEDEN PARTICIONAR OBJETOS" << endl;	//  1OE
    cout << "+ Holaaa, Cuantos objetos quisieras meter en la mochila???: " << endl;	//  1OE
    cout << "- Hola, serian ";	//  1OE
    cin >> n;	//  1OE

    vector<Objeto> objetos(n);	//  1OE

    for (int i = 0; i < n; i++) {	//  4OE
        cout << "\n+ ¿Cuánto pesa el objeto " << i + 1 << "?" << endl;	//  4OE
	cout << "- Pesa ";	//  1OE
        cin >> objetos[i].peso;	//  2OE
        cout << "+ ¿Cuál es el valor del objeto " << i + 1 << "?" << endl;	//  4OE
	cout << "- Vale ";	//  1OE
        cin >> objetos[i].valor;	//  2OE
        objetos[i].id = i + 1;	//  3OE
        objetos[i].relacion = objetos[i].valor / objetos[i].peso;}	//  5OE

    cout << "\n+ ¿Cuál es la capacidad máxima de tu mochila?" << endl;	//  1OE
    cout << "- ";	//  1OE
    cin >> capacidad;	//  1OE

    sort(objetos.begin(), objetos.end(), comparar);	//  1OE
    mochilaRP(0, 0.0, 0.0, capacidad, objetos);	//  1OE

    cout << "\n+ El valor maximo en objetos que puedes llevar es: " << mejorValor << endl;	//  2OE
    cout << "- Que objetos cupieron?" << endl; 	//  1OE
    cout << "+ Los objetos seleccionados son: ";	//  1OE
    for (int id : seleccionMejor)	
        cout << "Objeto " << id << "  ";	//  3OE
    cout << endl;	//  1OE
    cout << "- Gracias! Buen dia :)" << endl;	//  1OE
    return 0;}	//  1OE
