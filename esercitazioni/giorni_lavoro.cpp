#include <iostream>

using namespace std;

enum giorno_t {lun, mar, mer, gio, ven, sab, dom};

void stampa_turno(giorno_t);

int main() {
	stampa_turno(lun);
	stampa_turno(gio);
	stampa_turno(dom);
}

void stampa_turno(giorno_t g) {
	switch (g) {
		case lun: case mer: case ven:
			cout << "mattina e pomeriggio";
			break;
		case mar: case gio:
			cout << "mattina";
			break;
		case sab: case dom:
			cout << "riposo";
	}
	cout << endl;
}
