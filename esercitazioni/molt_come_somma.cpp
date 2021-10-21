#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	
	int res = 0;
	if (b<a) {  // ottimizzazione per minimizzare il numero di iterazioni
		a += b;
		b = a-b;
		a -= b;
	}
	for (int i=0; i<a; i++) {  // prodotto come sequenza di somme di due numeri
		res += b;
	}
	cout << a << " iterazioni" << endl;
	
	cout << a << " * " << b << " = " << res << endl;
	return 0;
}
