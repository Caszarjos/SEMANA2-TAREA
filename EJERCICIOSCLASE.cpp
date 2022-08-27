#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main1() {
	// declaracion con tipos autamaticos
	auto f1 = [](auto x, auto y) {return x + y; };
	cout << f1(2.7, 3.9) << endl;

	//declaracion con tipo de funcion explicita
	function<int(int, int)> f2 = [](int x, int y) {return x + y; };
	cout << f2(3, 4) << endl;

	//invocar a la funcion al momento de crearla
	auto cuadrado = [](int x) {return x * x; }(5);
	cout << cuadrado << endl;

	return 0;
}
int main2() {
	int sum = [](int x, int y) {return x + y; }(5, 4);

	auto mul = [](int x, int y) {return x * y; };

	cout << "sum(5,4)=>" << sum << endl;
	cout << "mul(5,4)=>" << mul(5, 4) << endl;
	return 0;
}
int main4() {
	int duplicarDosVeces = [](int x) 
		// declaracion de una funcion lambda [] con parametros (int x)
	{
		return [](int y) {return y * 2; }(x) * 2;
		// retorna una lambda expresion [] con parametros (int y) y retorna
		// una el parametro 'y' por 2, la variable 'y' tomara por valores 
		// a 'x' * 2, ya que esta declara al final de la expresion lambda
	}(5);
	// por ultimo, esta expresion lambda declara a x = 5, para iniciar su ejecucion
	cout << "duplicar dos veces (5)=>" << duplicarDosVeces;
	return 0;
}

int main5() {
	auto addtwointegers = [](int x) ->function<int(int)> 
		// declaracion de la funcion 'addtwointegers' que es una lambda expresion
		// no usara valores externos [], como parametro tiene el entero x 
		// retornara una variable de tipo function<int(int)> que recibe un int y retorna un int
	{
		return [=](int y) {return x + y; };
		// la funciona retorna otra funcion lambda [=] la cual usara variables externas
		// como unico parametro tiene el entero y, y retornara la suma de x+y
	};
	auto higherorder = [](function<int(int)> f, int z)
		// declaracion de la funcion 'higherorder' que es una lambda expresion
		// como parametros tiene una funcion<int(int)> y un entero z
	{
		return f(z) * 2; 
		// retornara el resultado de la multiplicacion de una funcion f() por 2
	};
	auto answer = higherorder(addtwointegers(7), 8);
	// se declara variable de tipo auto, que adopta un valor automatico a su creacion
	// la cual llama a la funcion higherorder, ubicando como parametros la funcion
	// addtwointegers(7) y 8

	cout << answer << endl;
	return 0;
}

class Scale {
private:
	int _scale; // declaracion de variable _scale
public:
	explicit Scale(int scale) :_scale(scale) {} // constructor
	void ApplyScale(const vector<int>& v) const { 
		// funcion con parametro de entrada un vector constant pasado por referencia

		for_each( // funcion que itera en todos los valores del vector
			v.begin(),  // busca el primer valor del vector
			v.end(),    // busca el ultimo valor del vector
			[=](int n) {cout << n * _scale << endl; } 
			// funcion lambda que usara valores externos su ejecutacion [=]
			// como parametros de entrada tiene el entero n
			// para cada valor se repetira la funcion cout << n * _scale << endl
		);
	}
};
int main6() {
	vector<int> values;
	values.push_back(1);
	values.push_back(2);
	values.push_back(3);
	values.push_back(4);

	Scale s(3);
	s.ApplyScale(values);
	return 0;
}

int suma(int x, int y) {
	return x + y;
}
int suma2(int& xR, int& yR) {
	xR = xR + yR;
	return xR;
}
int suma3(const int& xR, const int& yR) {
	return xR + yR;
}
int mainSuma() {
	int x = 23, y = 34;
	suma(x, y);
	suma2(x, y);
	suma3(x, y);
	return 0;
}


template<typename T> // declaracion del template
void negate_all(vector<T>& v) { // vector v pasada por valor
	for_each( // funcion for_each, itera todo el vector
		v.begin(), // localiza el primer valor del vector
		v.end(),   // localiza el ultimo valor del vector v
		[](T& n) {n = -n; }  // funcion que se usara para cada valor del vector
	);
}
template<typename T>  // declaracion del template
void print_all(const vector<T>& v) { // vector v constante pasado por referencia
	for_each(  // funcion que itera en todo el vector
		v.begin(),  // localiza el primer valor del vector
		v.end(),    // localiza el ultimo valor del vector
		[](const T& n) {cout << n << endl; }  // funcion que se repetira con cada iteracion
	);
}
int main7() {

	vector<int> v;
	v.push_back(34);
	v.push_back(-43);
	v.push_back(56);
	
	print_all<int>(v);
	negate_all(v);
	cout << "After negate_all(): " << endl;
	print_all(v);
	_sleep(4000);
	return 0;
}

template<typename T>
void imprimirArr(T a, int n) {
	cout << "[";
	for (int i = 0; i < n; i++) {
		cout << (i ? ", " : "") << a[i];
	}
	cout << "]\n";
}
int main8() {
	vector<int> v{ 44,11,77,55,66,33,22,88 };
	sort( 
		// funcion sort que ordenara el vector v, como parametros de entrada 
		// tiene el inicio y final del vector, asi como la direccion (ascendente o descendente)
		v.begin(), // se obtiene el comienzo del vector
		v.end(),   // se obtiene el valor final
		[&](const int left, const int right) {return left > right; }
		// logica de ordenacion
	);
	imprimirArr<vector<int>>(v, v.size());
	// se llama a la funcion imprimirArr que imprimira los valores del vector
	_sleep(5000);
	return 0;
}

int main9() {
	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10,12,13,15,19,20 };
	int multi = 5;

	size_t count = count_if( // llamada a la funcion count_if que retorna valoren en size_t
		vec.begin(),   // inicio del vector
		vec.end(),     // finalizacion del vector
		[=](int num) {return !(num % multi); }  // criterio para contar
	);

	cout << "Integer that ar multiple of ";
	cout << multi << " => " << count << endl;
	_sleep(5000);
	return 0;
}

int main10() {
	vector<int> vec{ 1,2,3,4,5 };

	size_t count = count_if( // llamada la funcion count_if
		vec.begin(), // inicio del vector
		vec.end(),   // final del vector
		[](int num)->bool {return num % 2; } 
		// contar numeros divisibles entre 2
		// retorna un tipo bool
	);

	cout << "Integer that are Odd=> " << count << endl;

	count = count_if( 
		vec.begin(),
		vec.end(),
		[](int num)-> bool {return !(num % 2); } 
		// contar numeros que no son divisible entre 2
		// retorona un tipo bool
	);
	cout << "Integer that are Even=> " << count << endl;
	_sleep(5000);
	return 0;
}

template<class InputIt, class T, class BinaryOperation>
constexpr // since C++20
T accumulate(InputIt first, InputIt last, T init,
	BinaryOperation op)
{
	for (; first != last; ++first) {
		init = op(move(init), *first); // std::move since C++20
	}
	return init;
}

int main11() {
	int arr[] = { 1,2,3,4,5 }; 
	auto factorial = [](int i, int j) {return i * j; }; 
	// funcion lambda que retorna el producto de 'i' y 'j' 
	auto res = accumulate(arr, arr + 5, 1, factorial);
	// declara variable res como el resultado de la funcion accumulate
	// la cual pide como parametros la posicion del arr, la posicion final del arr
	// el valor inicial y la funcion lambda que se usara
	cout << "5!=" << res << endl;
	_sleep(5000);
	return 0;
}

