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
    return a.relacion > b.relacion;}

double mejorValor = 0.0;
vector<int> seleccionMejor;
vector<int> seleccionActual;

double cotaSuperior(int nivel, double pesoActual, double valorActual, double capacidad, const vector<Objeto>& objetos) {
    double peso = pesoActual;
    double valor = valorActual;
    int n = objetos.size();

    for (int i = nivel; i < n; i++) {
        if (peso + objetos[i].peso <= capacidad) {
            peso += objetos[i].peso;
            valor += objetos[i].valor;
        } else {
            double fraccion = (capacidad - peso) / objetos[i].peso;
            valor += objetos[i].valor * fraccion;
            break;}}
    return valor;}

void mochilaRP(int nivel, double pesoActual, double valorActual, double capacidad, const vector<Objeto>& objetos) {
    int n = objetos.size();

    if (nivel == n) {
        if (valorActual > mejorValor) {
            mejorValor = valorActual;
            seleccionMejor = seleccionActual;}
 	return;}
 
    if (pesoActual + objetos[nivel].peso <= capacidad) {
        seleccionActual.push_back(objetos[nivel].id);
        mochilaRP(nivel + 1,
                  pesoActual + objetos[nivel].peso,
                  valorActual + objetos[nivel].valor,
                  capacidad, objetos);
        seleccionActual.pop_back();}

    double estimado = cotaSuperior(nivel + 1, pesoActual, valorActual, capacidad, objetos);
    if (estimado > mejorValor) {
        mochilaRP(nivel + 1, pesoActual, valorActual, capacidad, objetos);};}

int main() {
    int n;
    double capacidad;
    cout << "PROBLEMA DE LA MOCHILA POR RAMIFICACION Y PODA, NO SE PUEDEN PARTICIONAR OBJETOS" << endl;
    cout << "+ Holaaa, Cuantos objetos quisieras meter en la mochila???: " << endl;
    cout << "- Hola, serian "; 
    cin >> n;

    vector<Objeto> objetos(n);

    for (int i = 0; i < n; i++) {
        cout << "\n+ ¿Cuánto pesa el objeto " << i + 1 << "?" << endl;
	cout << "- Pesa ";
        cin >> objetos[i].peso;
        cout << "+ ¿Cuál es el valor del objeto " << i + 1 << "?" << endl;
	cout << "- Vale ";
        cin >> objetos[i].valor;
        objetos[i].id = i + 1;
        objetos[i].relacion = objetos[i].valor / objetos[i].peso;}

    cout << "\n+ ¿Cuál es la capacidad máxima de tu mochila?" << endl;
    cout << "- ";
    cin >> capacidad;

    sort(objetos.begin(), objetos.end(), comparar);

    mochilaRP(0, 0.0, 0.0, capacidad, objetos);

    cout << "\n+ El valor maximo en objetos que puedes llevar es: " << mejorValor << endl;
    cout << "- Que objetos cupieron?" << endl; 
    cout << "+ Los objetos seleccionados son: ";
    for (int id : seleccionMejor)
        cout << "Objeto " << id << "  ";
    cout << endl;
    cout << "- Gracias! Buen dia :)" << endl;
    return 0;}
