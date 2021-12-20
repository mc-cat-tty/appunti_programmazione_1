#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout << "Numero: ";
	int n;
	cin >> n;
	cout << "Numero in base 16: " << hex << n << endl;
	cout << "Numero in base 10: " << dec << n << endl;  // riporto lo stream allo stato normale
}
