#include <iostream>

using namespace std;

int ritorna_massimo(int a, int b) {
	if (a>b)
		return a;
	return b;
}

int main() {
	int x, y;
	cout << "Valori: "; cin >> x >> y;
	cout << "Massimo: " << ritorna_massimo(x, y) << endl;
	return 0;
}
