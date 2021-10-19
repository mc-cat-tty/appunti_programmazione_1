#include <iostream>

using namespace std;

int main() {
	int	scelta,									// scelta del menù
			num_anelli_ferro = 0,
			num_anelli_rame = 0,
			pos1_rame,							// prima posizione anello rame. 0 non presente.
			pos2_rame,							// seconda posizione anello rame. 0 non presente.
			pos,										// posizione inserimento o rimozione
			tipo;										// tipo di anello: 1 - ferro, 2 - rame

	bool	ok = true;							// flag che segnala se l'operazione è andata a buon fine
	while (true) {
		cout  << "1. Inserimento\n"
					<< "2. Estrazione\n"
					<< "3. Stampa\n"
					<< "4. Terminazione\n"
					<< "Scelta: ";

		cin >> scelta;
		
		switch(scelta) {
			case 1:
				cout << "Tipo anello (1-Ferro, 2-Rame): "; cin >> tipo;
				cout << "Posizione: "; cin >> pos;
				if (pos>=1 && pos<=num_anelli_rame+num_anelli_ferro+1) { // Range check
					if (tipo == 2 && num_anelli_rame < 2) { // check num max rame
						num_anelli_rame++;
						if (pos1_rame == 0)
							pos1_rame = pos;
						else if (pos2_rame == 0)
							pos2_rame = pos;
					}
					else if (tipo == 1) {
						num_anelli_ferro++;
					}
					else {
						ok = false;
						break;
					}
					if (pos <= pos1_rame && !(tipo==2 && num_anelli_rame==1))
						pos1_rame++;
					if (pos <= pos2_rame && !(tipo==2 && num_anelli_rame==2))
						pos2_rame++;
				}
				else {
					ok = false;
				}
				break;
			case 2:
				cout << "Posizione: "; cin >> pos;
				if (pos>=1 && pos<=num_anelli_rame+num_anelli_ferro) { // Range check
					// Rimuovo rame se presente, altrimenti ferro
					if (pos == pos1_rame && pos1_rame != 0) {
						num_anelli_rame--;
						pos1_rame = 0;
					}
					else if (pos == pos2_rame && pos2_rame != 0) {
						num_anelli_rame--;
						pos2_rame = 0;
					}
					else {
						num_anelli_ferro--;
					}
					
					// Scalo
					if (pos <= pos1_rame)
						pos1_rame--;
					if (pos <= pos2_rame)
						pos2_rame--; 
				}
				else {
					ok = false;
				}
				break;
			case 3:
				for (int i=1; i<=num_anelli_ferro+num_anelli_rame; i++) {
					if ((i == pos1_rame && pos1_rame != 0) || (i == pos2_rame && pos2_rame != 0))
						cout << "R";
					else
						cout << "F";
				}
				cout << endl;
				break;
			case 4:
				return 0;
			default:
				cout << "Scelta non valida" << endl;
		}
		if (!ok)
			cout << "Operazione non consentita" << endl;
		ok = true;
	}

	return 0;
}
