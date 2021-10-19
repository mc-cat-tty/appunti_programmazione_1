#include <iostream>

using namespace std;

int main() {
	// Struttura dati
	int n,			// numero anelli
		pos_1 = 0,	// posizione rame 1. 0 se libera (fuori dal range)
		pos_2 = 0;	// posizione rame 2. 0 se libera (fuori dal range)
	
	// Variabili di appoggio
	int scelta,		// scelta switch
		materiale,	// 1 ferro, 2 rame
		pos,		// posizione scelta per inserimento
		error = false;
	
	while (true) {
		cout	<< "1. inserimento"	<< endl
				<< "2. rimozione"	<< endl
				<< "3. stampa"		<< endl
				<< "4. exit"		<< endl;
		cout << ">> "; cin >> scelta;
		
		switch (scelta) {
			case 1:
				cout << "Ferro (1) o rame (2)? "; cin >> materiale;
				cout << "Posizione? "; cin >> pos;
				if (!(pos>=1 && pos<=n+1) || (materiale == 2 && pos_1!=0 && pos_2!=0)) {
					error = true;
					break;  // esco se pos fuori dal range o inserimento rame ma posto finito
				}
				n++;
				if (pos <= pos_1)  // se inserisco un anello a sinistra di un rame shifto la sua posizione a destra
					pos_1++;
				if (pos <= pos_2)
					pos_2++;
				if (materiale == 2) {
					if (pos_1 == 0)
						pos_1 = pos;
					else if (pos_2 == 0)
						pos_2 = pos;
				}
				break;
			case 2:
				cout << "Posizione? ";  cin >> pos;
				if (!(pos>=1 && pos<=n)) {
					error = true;
					break;
				}
				n--;
				if (pos == pos_1)
					pos_1 = 0;
				if (pos == pos_2)
					pos_2 = 0;
				if (pos < pos_1)
					pos_1--;
				if (pos < pos_2)
					pos_2--;
				break;
			case 3:
				for (int i = 1; i <= n; i++) {
					if (i == pos_1 || i == pos_2)
						cout << "R";
					else
						cout << "F";
				}
				cout << endl;
				break;
			case 4:
				return 0;
			default:
				error = true;
				break;
		}
		
		if (error)
			cout << "Errore" << endl;
		error = false;
	}
	
	return 0;
}
