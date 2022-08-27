#ifndef __SORTS_H__
#define __SORTS_H__
#include <iostream>
#include <functional>
#include <conio.h>
using namespace std;

template<typename T>
void imprimirArr(T* a, int n) { // funcion que imprime los valores de un arreglo o vector
	cout << "[";                // mediante la nomenclatura [a , b , c ]
	for (int i = 0; i < n; i++) {
		cout << (i ? ", " : "") << a[i];
	}
	cout << "]\n";
}

template<typename T>
void intercambio(T* a, int n, bool(*mayorQue)(T, T)) {
	// funcion lambda con declarado con un template con parametros de entrada
	// un valor tipo T variable, un entero, una funcion booleana (*mayorQue) con
	// parametros de entrada (T,T) variables
								imprimirArr(a, n);
	for (int i = 0; i < n - 1; i++) {
		// primer iterador i
		for (int j = i + 1; j < n; j++) {
			// segundo iterador j
			if (mayorQue(a[i], a[j])) {
				// se compara segun la funcion mayorQue, devuelve un valor de tipo bool
				// esta funcion compara el valor a[i] y a[j]
				T temp = a[j];
				a[j] = a[i];
				a[i] = temp;
								imprimirArr(a, n);
			}
		}
	}
}

template<typename T>
void burbuja(T* a, int n, function<bool(T, T)> mayorQue) {
	// la misma declaracion que la anterior funcion, pero en su declaracion se esta usando
	// un parametro de tipo fuction<bool(T, T)> que retorna un bool
								imprimirArr(a, n);
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (mayorQue(a[i], a[j])) {
				T temp = a[j];
				a[j] = a[i];
				a[i] = temp;
								imprimirArr(a, n);
			}
		}
	}
}
#endif // !__SORTS_H__

int main() {
	auto mayQ = [](float a, float b) {return a > b; };

	float a1[10], a2[10], a3[10], a4[10], a5[10];
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		a1[i] = rand() % 100;
		a5[i] = a4[i] = a3[i] = a2[i] = a1[i];
	}
	cout << "Paso a paso intercambio\n";
	intercambio<float>(a1, 10, mayQ);

	cout << "Paso a paso burbujar\n";
	burbuja<float>(a2, 10, mayQ);
	_getch();
	return 0;
 }


