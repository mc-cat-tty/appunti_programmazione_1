#include <iostream>

using namespace std;

const int fattoriale(const int n) {
	int res = 1;
	for (int i=1; i<=n; i++)
		res*=i;
	return res;
}

int main() {
	int val;
	cout << "Numero: "; cin >> val;
	cout << "Fattoriale: " << fattoriale(val) << endl;
	return 0;
}
