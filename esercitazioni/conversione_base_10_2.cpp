#include <iostream>

using namespace std;


int main() {
	int n,
			b = 1;  // base
	const int base_originale = 2;
	cout << "Numero intero positivo: ";
	cin >> n;
	while (b < n) {
		cout << (n/b)%base_originale;
		b *= base_originale;
	}
	cout << endl;
	return 0;
}
