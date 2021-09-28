#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int a, b;
	cout << "Inserisci valore a: ";
	cin >> a;
	cout << "Inserisci valore b: ";
	cin >> b;
	a += b;
	b = a-b;
	a -= b;
	cout << "Dopo lo scambio: a=" << a << ", b=" << b << endl;
	return 0;
}
