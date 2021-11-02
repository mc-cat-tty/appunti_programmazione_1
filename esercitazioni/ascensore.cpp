/*
* Esercizio "ascensore sgravata impazzita"
*/

#include <iostream>
#include <cmath>

using namespace std;

enum direzione {su, giu};

double singolo_impulso(double, direzione);

int main() {
	// struttura dati
	double pos = 0.;  // posizione iniziale (+20 metri dal suolo)

	int ch;
	int n;  // numero spostamenti

	const double epsilon = 1e-7;
	
	do {
		cout << pos << endl;
		// PROBLEMA: lo zero non viene rappresentato in modo preciso;
		if ((pos > 1.0-epsilon && pos < 1.0+epsilon))  // PERICOLO: pos potrebbe non essere esattamente a 1. Non usare l'uguaglianza pura, perchè viene fatto un controllo bit per bit tra i numeri.
			cout << "Non sicuro staccare le funi" << endl;
		else
			cout << "Sicuro staccare le funi" << endl;
		cout << endl;
		
		cout << "Movimento: ";	
		cin >> n;
		
		if (n>0 && pos+(n/10) >= 20)
			pos = 20;
		if (n<0 && pos-(n/10) <= -20)
			pos = -20;
		else
			for (int i=0; i<abs(n); i++)
				pos = singolo_impulso(pos, n > 0 ? su : giu);

	} while (n != 0);
	return 0;
}

double singolo_impulso(double n, direzione dir) {
	return n + (dir == su ? 0.1 : -0.1);
}
