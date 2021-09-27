#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int a, b, aux;
	cout << "Inserisci valore a: ";
	cin >> a;
	cout << "Inserisci valore b: ";
	cin >> b;
	// aux = a;
	// a = b;
	// b = aux;
	a = a^b;
	b = a^b;
	a = a^b;
	cout << "Dopo lo scambio: a=" << a << ", b=" << b << endl;
	return 0;
}
