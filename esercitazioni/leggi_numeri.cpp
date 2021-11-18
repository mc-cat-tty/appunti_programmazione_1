/*
 *	WARNING: il seguente programma non funziona per standard inferiori a C++11
 *
 */

#include <iostream>

using namespace std;


int main() {
	int tmp, s = 0;  // s -> s
	// continuo a prendere in input degli interi finchè
	// non viene inserito un valore non valido oppure EO
	while (cin) {  // una soluzione funzionante per tutti gli standard è while(cin >> tmp) {...}
		cin >> tmp;
		s += tmp;
	}
	// l'oggetto cin non è più utilizzabile
	cout << "Somma: " << s << endl;
	cout << "Si è terminato con EOF? " << cin.eof() << endl;
	return 0;
}

// HINT: prova a compilare con -std=c++98
