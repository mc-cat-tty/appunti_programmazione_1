#include <iostream>

using namespace std;

int main() {
	double num;
	cin >> num;

	int d = 1;  // denominatore
	double n = num;  // numeratore
	while (n-static_cast<int>(n) != 0){
		d *= 10;
		n *= 10;
	}
	
	cout << n << " " << d << endl;

	// algoritmo di Euclide
	int a = d, b = n;
	int mod;
	while (b) {
		mod = a%b;
		a = b;
		b = mod;
	}
	
	cout << a << endl;
	
	n /= a; d /= a;
	
	cout << num << " = " << n << "/" << d << endl;
}
