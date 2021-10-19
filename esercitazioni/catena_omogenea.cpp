#include <iostream>

using namespace std;

int main() {
	int scelta, num_anelli = 0, j;
	while (true) {
		cout  << "1. Inserimento\n"
					<< "2. Estrazione\n"
					<< "3. Stampa\n"
					<< "4. Terminazione\n"
					<< "Scelta: ";

		cin >> scelta;
		
		switch(scelta) {
			case 1:
				cout << "Posizione: ";
				cin >> j;
				if (j>=1 && j<=num_anelli+1)
					num_anelli++;
				break;
			case 2:
				cout << "Posizione: ";
				cin >> j;
				if (j>=1 && j<=num_anelli)
					num_anelli--;
				break;
			case 3:
				for (int i=0; i<num_anelli; i++) {
					cout << "F";
				}
				cout << endl;
				break;
			case 4:
				return 0;
			default:
				cout << "Non valido" << endl;
		}
	}
	return 0;
}
