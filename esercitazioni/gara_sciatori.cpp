/*
	Scrivere un programma che gestisca i tempi di una serie di sciatori identificati da nome, tempo in secondi.
	Il programma deve mostrare a video il dato inserito espresso in minuti, secondi + la lunghezza del campo nome 
*/

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_DIM = 10;

struct sciatore_t {
	char nome[21];  // len max = 20 caratteri
	int secondi;  // tempo in secondi
};

void sec_to_min_sec(const int sec_in, int &min, int &sec) {
	min = sec_in/60;
	sec = sec_in%60;
}

int main() {
	sciatore_t sciatori[MAX_DIM];
	int dim = 0;
	
	while (!cin.eof()) {
		cout << "Nome: ";
		cin >> sciatori[dim].nome;
		cout << "Tempo [secondi]: ";
		cin >> sciatori[dim++].secondi;
	}
	dim--;  // quando esco incremento dim, ma non è stato inserito l'oggetto
	// cout << dim;
	
	int min_tempo_i = 0;
	for (int i=1; i<dim; i++) {
		min_tempo_i = sciatori[i].secondi < sciatori[min_tempo_i].secondi ? i : min_tempo_i;
	}
	
	int min, sec;
	sec_to_min_sec(sciatori[min_tempo_i].secondi, min, sec);
	cout << "Il vincitore è " << sciatori[min_tempo_i].nome << " con "
		<< min << " minuti e " << sec << " secondi" << endl
		<< "Dimensione del nome: " << strlen(sciatori[min_tempo_i].nome) << endl;
	
	return 0;
}

