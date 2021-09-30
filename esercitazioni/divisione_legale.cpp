#include <iostream>

using namespace std;

int main() {
	int a, b;
	cout << "Inserisci a: ";
	cin >> a;
	cout << "Inserisci b: ";
	cin >> b;
	if (b==0) {
		cout << "Divisore non valido" << endl;
		return 1;
	}
	else {
		cout << "Risultato: " << a/b << endl;
		return 0;
	}
}
