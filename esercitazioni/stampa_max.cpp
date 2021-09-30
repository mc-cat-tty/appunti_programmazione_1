#include <iostream>

using namespace std;

int main() {
	int a, b;
	cout << "Inserisci a e b: ";
	cin >> a >> b;
	int max = a>=b ? a : b;
	cout << "Il massimo tra i due numeri è: " << max << endl;
	return 0;
}
