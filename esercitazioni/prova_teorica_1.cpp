#include <iostream>

using namespace std;

int main(void) {
	// definizione della "struttura dati" per la risoluzione del problema
	int a, b;
	int res = 1;  // se b<=0 non entro nel ciclo, il risultato è già calcolato
	cout << "Valori: ";
	cin >> a >> b;
	for(int i=1; i<=b; i++) {
		res *= a;
}
	cout << res << endl;
	return 0;
}
