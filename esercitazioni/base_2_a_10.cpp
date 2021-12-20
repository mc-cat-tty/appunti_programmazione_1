#include <iostream>
#include <math.h>

using namespace std;

int main() {
	const int base_partenza = 2;
	const int base_arrivo = 10;
	
	int num_2;  // numero preso in input
	int num_10 = 0;  // risultato
	int count = 0;  // contatore iterazioni
	
	cout << "Numero base 2: "; cin  >> num_2;
	
	while (num_2!=0) {
		num_10 += (num_2%base_arrivo) * pow(base_partenza, count);
		num_2 /= 10;
		count++;
	}

	cout << "Numero base 10: " << num_10 << endl;
	
	return 0;
}
