#include <iostream>
using namespace std;

int main() {
	int i, somma = 0;
	while (cin >> i) {
		somma += i;
	}
	cout << "Stato cin: " << !(!cin) << endl;
	cout << "Raggiunto EOF? " << cin.eof() << endl;
	cout << "Pulizia cin" << endl; cin.clear();
	cout << "Stato cin: " << !(!cin) << endl;
	cout << "Raggiunto EOF? " << cin.eof() << endl;
	cout << "Somma: " << somma << endl;
	return 0;
}
