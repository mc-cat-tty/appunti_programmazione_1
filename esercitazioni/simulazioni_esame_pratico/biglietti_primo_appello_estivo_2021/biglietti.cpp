#include <iostream>
#include <cstring>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAX_STR_LEN = 100;  // Chiamata M nella traccia
const int DEFAULT_V_DIM = 2;
const char FILENAME[] = "lotteria.txt";

typedef unsigned int id_t;

struct biglietto_t {
	char proprietario[MAX_STR_LEN+1];
	id_t id;
};

struct lotteria_t {
	biglietto_t *biglietti_v;
	int current_dim;
	int max_dim;
};

void inizializza(lotteria_t &l) {
	l.biglietti_v = NULL;
	l.current_dim = 0;
	l.max_dim = 0;
}

/*
// ritorna il progressivo attuale e incrementa il contatore
inline int next_progressivo(lotteria_t &l) {
	id_t tmp = l.progressivo;
	l.progressivo++;
	return tmp;
}
*/

// costo ammortizzato O(1)
void espandi(lotteria_t &l) {
	// determino la dimensione del nuovo array
	int new_dim;
	if (l.max_dim == 0)
		new_dim = DEFAULT_V_DIM;
	else
		new_dim = l.max_dim*2;
	
	// alloco una nuova area di memoria e trasferisco il contenuto
	biglietto_t *tmp_p = new biglietto_t[new_dim];
	if (l.biglietti_v != NULL) {  // se non si tratta della prima allocazione
		memcpy(tmp_p, l.biglietti_v, sizeof(biglietto_t)*l.current_dim);

		// dealloco la vecchia area di memoria
		delete[] l.biglietti_v;
	}

	l.biglietti_v = tmp_p;
	l.max_dim = new_dim;
}

int cerca_id(lotteria_t &l, id_t id) {
	for (int i=0; i<l.current_dim; i++) {
		if (l.biglietti_v[i].id == id)
			return i;
	}
	return -1;
}

void vendi_biglietto(lotteria_t &l, const char nome[], id_t numero) {
	biglietto_t biglietto;
	strcpy(biglietto.proprietario, nome);
	if (cerca_id(l, numero) != -1)  // se trovo un altro biglietto con lo stesso id ritorno
		return;
	biglietto.id = numero;

	if (l.current_dim >= l.max_dim) {
		espandi(l);
	}

	l.biglietti_v[l.current_dim++] = biglietto;  // possibile perchè copia membro a membro tra le struct
}

bool stampa_biglietti(lotteria_t &l, ostream &stream, bool on_file) {
	if (on_file) {
		if (!stream)  // stream in stato di errore
			return false;
		stream << l.max_dim << " " << l.current_dim << endl;
	}
	for (int i=0; i<l.current_dim; i++) {
		stream << l.biglietti_v[i].proprietario << " " << l.biglietti_v[i].id << endl;
	}
	return static_cast<bool>(stream);
}

bool carica_biglietti(lotteria_t &l, const char filename[]) {
	ifstream f(filename);
	if (!f)
		return false;

	f >> l.max_dim >> l.current_dim;
	delete[] l.biglietti_v;  // dealloco la vecchia area di memoria

	l.biglietti_v = new biglietto_t[l.max_dim];
	for (int i=0; i<l.current_dim; i++) {
		f >> l.biglietti_v[i].proprietario >> l.biglietti_v[i].id;
	}

	f.close();
	return static_cast<bool>(f);
}


// ritorna l'indice del biglietto estratto, oppure -1
// nel caso in cui non sia possible estrarre nessun biglietto
int _estrazione_biglietto(lotteria_t &l) {
	if (l.current_dim == 0)
		return -1;
	
	return rand()%l.current_dim;  // ritorna un valore tra 0 e l.current_dim-1
}

void stampa_estrazione_biglietto(lotteria_t &l) {
	int e = _estrazione_biglietto(l);

	if (e == -1)
		cout << "NESSUNO 0" << endl;
	else
		cout << l.biglietti_v[e].proprietario << " " << l.biglietti_v[e].id << endl;
}

void estrai_n_biglietti(lotteria_t &l, int n) {
	if (l.current_dim == 0) {
		cout << "NESSUNO 0" << endl;
		return;
	}

	if (l.current_dim < n)
		n = l.current_dim;
	for (int i=0; i<n; i++) {
		stampa_estrazione_biglietto(l);
	}
}

int main()
{
	const char menu[] =
		"1. Vendi biglietto\n"
		"2. Stampa biglietti venduti\n"
		"3. Salva biglietti venduti\n"
		"4. Carica biglietti venduti\n"
		"5. Stampa vincitore\n"
		"6. Stampa primi n vincitori\n"
		"7. Esci\n";

	lotteria_t lotteria;
	char str[MAX_STR_LEN+1];
	int n;

	inizializza(lotteria);
	srand(time(NULL));

	while (true) {
		cout<<menu<<endl;
		int scelta;
		cin>>scelta;

		cout<<endl ; // per il corretto funzionamento del tester

		switch (scelta) {
		case 1:
			cout << "Nome acquirente e numero biglietto: "; cin >> str; cin >> n;
			vendi_biglietto(lotteria, str, n);
			break;
		case 2:
			stampa_biglietti(lotteria, cout, false);
			break;
		case 3:
		{
			ofstream f(FILENAME);
			if (!stampa_biglietti(lotteria, f, true)) {
				cerr << "Stampa su file fallita" << endl;
				return 1;
			}
			f.close();
			break;
		}
		case 4:
			if (!carica_biglietti(lotteria, FILENAME)) {
				cerr << "Lettura da file fallita" << endl;
				return 1;
			}
			break;
		case 5:
			stampa_estrazione_biglietto(lotteria);
			break;
		case 6:
			cin >> n;
			estrai_n_biglietti(lotteria, n);
			break;
		case 7:
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}

	return 1;
}
