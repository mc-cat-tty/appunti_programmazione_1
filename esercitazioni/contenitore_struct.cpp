/*
* file: contenitore_no_struct.cpp
* author: francesco mecatti
*
* Seconda simulazione prova programmazione 1
*
*/
#include <iostream>

using namespace std;

const char MIN_CHAR = 'a';
const char MAX_CHAR = 'z';


const int DIM = int(MAX_CHAR)-int(MIN_CHAR)+1;

// struttura dati	
// cout << int(MAX_CHAR) - int(MIN_CHAR) + 1;
struct contenitore_t {
	int dim;
	int capienza;  // numero totale di elementi
	int dimensione_attuale;
	int array[DIM];
};

enum errore {OK = 0, ELE_NOT_VALID, NOT_ENOUGH_SPACE, TOO_SMALL_CAP, NUM_ERR};
const char error_msgs[NUM_ERR][50] = {"", "Elemento non valido", "Spazio finito", "Capienza troppo piccola"};

/* 
* stampa l'error message ed esce con errore
* @param msg: string, esce con errore
*/
void gestisci_errore(errore e) {
	cerr << error_msgs[e] << endl;
	// exit(1);
}

/*
* inizializza tutti i contatori a 0 e ritorna
* @param cont: alias al contenitore che si vuole inizializzare
* @return: void
*/
void inizializza(contenitore_t &cont) {
	for (int i=0; i<cont.dim; i++)
		cont.array[i] = 0;
}

/*
* incrementa il contatore di v[ele] e aggiorna il numero di elementi
* @param ele: elemento da inserire
* @param cont: struttura contenitore
* @return: tipo di errore se occurred, OK altrimenti
*/
errore inserisci(char ele, contenitore_t &cont) {
	if (ele<MIN_CHAR || ele>MAX_CHAR)
		return ELE_NOT_VALID;
	// cout << "valid" << endl;
	
	if (cont.dimensione_attuale >= cont.capienza)
		return NOT_ENOUGH_SPACE;
	// cout << "space" << endl;
	
	// cout << v[ele-MIN_CHAR] << endl;
	cont.array[ele-MIN_CHAR]++;
	cont.dimensione_attuale++;
	return OK;
}  // se esce senza errori ritorna 0 => OK

errore estrai(char ele, contenitore_t &cont) {
	if (ele<MIN_CHAR || ele>MAX_CHAR)
		return ELE_NOT_VALID;

	cont.dimensione_attuale -= cont.array[ele-MIN_CHAR];
	cont.array[ele-MIN_CHAR] = 0;
	return OK;
}  // se esce senza errori ritorna 0 => OK

errore modifica_capienza(int nuova_capienza, contenitore_t &cont) {
	if (nuova_capienza < cont.dimensione_attuale)
		return TOO_SMALL_CAP;
	
	cont.capienza = nuova_capienza;
	return OK;
}

void stampa(contenitore_t &cont) {
	cout << "<";
	for (int i=0; i<cont.dim; i++) {
		if (cont.array[i] != 0)
			cout << char(i+MIN_CHAR) << ":" << cont.array[i] << ", ";
	}
	cout << ">" << endl;
}

int main() {
	const char menu[] =
		"i - inserisci elemento\n"
		"e - estrai elementi\n"
		"m - modifica capienza\n"
		"c - stampa capienza\n"
		"q - stampa numero elementi\n"
		"s - stampa vettore\n"
		"t - termina programma\n";

	errore err;
	contenitore_t contenitore = {DIM, 0, 0, {}};
	
	// inizializzazione
	cout << "Capienza: "; cin >> contenitore.capienza;
	inizializza(contenitore);

	char ch;  // scelta utente
	char ele; int aux;
	while (true) {
		cout << menu << endl;
		cout << ">> "; cin >> ch;
		switch (ch) {
			case 'i':
				cout << "Nome elemento: "; cin >> ele;
				err = inserisci(ele, contenitore);
				if (err != OK) {
					// cout << err << endl;
					gestisci_errore(err);
				}
				break;
			case 'e':
				cout << "Nome elemento: "; cin >> ele;
				err = estrai(ele, contenitore);
				if (err != OK)
					gestisci_errore(err);
				break;
			case 'm':
				cout << "Nuova capienza: "; cin >> aux;
				err = modifica_capienza(aux, contenitore);
				if (err != OK)
					gestisci_errore(err);
				break;
			case 'c':
				cout << "Capienza: " << contenitore.capienza << endl;
				break;
			case 'q':
				cout << "Quanti elementi sono nel vettore? " << contenitore.dimensione_attuale << endl;
				break;
			case 's':
				stampa(contenitore);
				break;
			case 't':
				return 0;
				break;
			default:
				cout << "Scelta errata" << endl;
		}
	}
}
