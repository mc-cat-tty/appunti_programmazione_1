#include <iostream>

using namespace std;

int calcola_durata(const int tempo_domanda, const int tempo_telefonata, const int intervallo_telefonata) {
	int tempo_rimanente_domanda = tempo_domanda;
	int tempo_totale = 0;
	
	do {
		if (tempo_totale % intervallo_telefonata == 0)
			tempo_totale += tempo_telefonata;  // arriva subito una chiamata
		else {
			tempo_totale++;
			tempo_rimanente_domanda--;
		}
	} while (tempo_rimanente_domanda > 0);
	
	return tempo_totale;
}

int main() {
	int t_dom, t_tel, delta_tel;
	cout << "Tempo totale da dedicare alle domande: "; cin >> t_dom;
	cout << "Durata di ogni telefonata: "; cin >> t_tel;
	cout << "Frequenza delle telefonate. Ogni x minuti: "; cin >> delta_tel;

	if (t_tel >= delta_tel) {
		cout << "Il professore resterà per sempre al telefono" << endl;
	}
	else {
		cout << "Il tempo totale sarà: " << calcola_durata(t_dom, t_tel, delta_tel) << endl;
	}
	return 0;
}
