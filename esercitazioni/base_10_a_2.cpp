#include <iostream>
#include <math.h>

using namespace std;

int main() {
	const int base_partenza = 10;
	const int base_arrivo = 2;

	int num_10;	// numero preso in input
	int num_2 = 0;	// risultato
	int count = 0;
	
	cout << "Numero in base 10: "; cin >> num_10;
	
	while (num_10!=0) {
		num_2 += (num_10%base_arrivo) * pow(base_partenza, count);
		num_10 /= base_arrivo;
		count++;
	}

	cout << "Numero in base 2: " << num_2 << endl;
	
	return 0;
}
