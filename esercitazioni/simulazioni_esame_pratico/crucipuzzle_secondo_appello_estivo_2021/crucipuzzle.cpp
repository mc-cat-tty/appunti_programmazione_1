#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const char FILENAME[] = "puzzle.dat";
const int MAX_STR_SIZE = 10;

typedef unsigned short int dim_t;

struct puzzle_t {
	char **tabella;  // matrice dinamica (sia righe che colonne)
	dim_t dim;  // dimensione NxN della tabella
};

void inizializza(puzzle_t &p) {
	p.tabella = NULL;
	p.dim = 0;
}

void reinizializza(puzzle_t &p, int n, bool is_fill_from_stdin) {
	if (p.dim != n && p.dim != 0) {
		for (int i=0; i<p.dim; i++) {
			delete[] p.tabella[i];  // dealloca i singoli array
		}
		delete[] p.tabella;  // dealloca l'array di puntatori
	}

	p.dim = n;

	// allocazione
	p.tabella = new char*[p.dim];
	for (int i=0; i<p.dim; i++) {
		p.tabella[i] = new char[p.dim];
	}

	if (is_fill_from_stdin) {
		// prendi in input
		char tmp;
		cout << "Immetti i caratteri: ";
		for (int i=0; i<n*n; i++) {
			cin >> tmp;
			p.tabella[i/n][i%n] = tmp >= 'A' && tmp <= 'Z' ? tmp : 'A';
		}
	}

	return;
}

void stampa_puzzle(puzzle_t &p) {
	for (int i = 0; i < p.dim*p.dim; i++) {
		cout << p.tabella[i/p.dim][i%p.dim] << " ";
		if ((i+1)%p.dim == 0)
			cout << endl;
	}
}

bool salva_puzzle(puzzle_t &p, const char filename[]) {
	ofstream f(filename);
	if (!f)
		return false;
	
	f.write(reinterpret_cast<char *>(&p.dim), sizeof(dim_t)*1);
	for (int i = 0; i < p.dim; i++) {
		f.write(reinterpret_cast<char *>(p.tabella[i]), sizeof(char)*p.dim);
	}

	f.close();
	return static_cast<bool>(f);
}

bool carica_puzzle(puzzle_t &p, const char filename[]) {
	ifstream f(filename);
	if (!f)
		return false;
	
	dim_t tmp;
	f.read(reinterpret_cast<char *>(&tmp), sizeof(dim_t)*1);
	reinizializza(p, tmp, false);
	for (int i = 0; i < p.dim; i++) {
		f.read(reinterpret_cast<char *>(p.tabella[i]), sizeof(char)*p.dim);
	}

	f.close();
	return static_cast<bool>(f);
}

void _to_zero(int v[], int dim) {
	for (int i=0; i<dim; i++)
		v[i] = 0;
}

bool cerca_parola_verticale(puzzle_t &p, const char w[]) {
	if (int(strlen(w)) == 0)
		return false;

	//int num_lettere = static_cast<int>('Z'-'A'+1);
	// creo un "array di lookup" per ogni lettera
	//int lk['Z'-'A'+1];

	for (int i = 0; i < p.dim; i++) {  // per ogni colonna
		// inizializzo ogni contatore a zero
		/*_to_zero(lk, num_lettere);

		for (int j=0; j<p.dim; j++) {  // per ogni riga
			lk[int(p.tabella[j][i]-'A')]++;
		}

		for (int z=0; z<int(strlen(w)); z++) {
			lk[int(w[z]-'A')]--;
		}

		// se tutte le lettere necessarie sono disponibili la parola potrebbe essere presente
		for (int z=0; z<num_lettere; z++) {
			if (lk[z] < 0)
				continue;  // è impossibile che la parola cercata sia contenuta nella colonna i
		}*/


		// cerco la parola a partire dall'alto e anche dal basso
		for (int j=0; j<p.dim && j<=p.dim-int(strlen(w)); j++) {
			bool equals_up_down = true;
			bool equals_down_up = true;
			for (int z=0; z<int(strlen(w)); z++) {
				// cout << j << " --- " << z << endl;
				if (w[z] != p.tabella[j+z][i]) {
					// cout << w[z] << " -- " << p.tabella[j+z][i] << endl;
					equals_up_down = false;
				}
				// cout << z << " -- " << p.dim-j-z << endl;
				if (w[z] != p.tabella[p.dim-j-z-1][i]) {
					// cout << w[z] << " -- " << p.tabella[j+z][i] << endl;
					equals_down_up = false;
				}
			}
			// cout << equals << endl;
			if (equals_up_down || equals_down_up)
				return true;
		}
	}

	return false;
}

bool cerca_parola_globale(puzzle_t &p, const char w[]) {
	if (int(strlen(w)) == 0)
		return false;
	const int num_caratteri = static_cast<int>('Z'-'A'+1);
	int lk[num_caratteri];
	_to_zero(lk, num_caratteri);
	for (int i=0; i<p.dim*p.dim; i++) {
		lk[int(p.tabella[i/p.dim][i%p.dim]-'A')]++;
	}
	for (int i=0; i<int(strlen(w)); i++) {
		lk[int(w[i]-'A')]--;
	}
	for (int i=0; i<num_caratteri; i++) {
		if (lk[i] < 0)
			return false;
	}
	return true;
}

int main()
{
	const char menu[] =
		"1. Reinizializza puzzle\n"
		"2. Stampa puzzle\n"
		"3. Salva puzzle\n"
		"4. Carica puzzle\n"
		"5. Trova parola in verticale\n"
		"6. Trova parola globalmente\n"
		"7. Esci\n";

	puzzle_t p;
	int n;
	char word[MAX_STR_SIZE];

	inizializza(p);

	while (true) {
		cout<<menu<<endl;
		int scelta;
		cin>>scelta;

		cout<<endl ; // per il corretto funzionamento del tester

		switch (scelta) {
		case 1:
			cout << "Dimensione: "; cin >> n;
			reinizializza(p, n, true);
			break;
		case 2:
			stampa_puzzle(p);
			break;
		case 3:
			salva_puzzle(p, FILENAME);
			break;
		case 4:
			carica_puzzle(p, FILENAME);
			break;
		case 5:
			cout << "Parola: "; cin >> word;
			// cerca_parola_verticale(p, word);
			if (cerca_parola_verticale(p, word))
				cout << endl << "PRESENTE" << endl;
			else
				cout << endl << "ASSENTE" << endl;
			break;
		case 6:
			cout << "Parola: "; cin >> word;
			if (cerca_parola_globale(p, word))
				cout << endl << "PRESENTE" << endl;
			else
				cout << endl << "ASSENTE" << endl;
			break;
			break;
		case 7:
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}

	return 1;
}
