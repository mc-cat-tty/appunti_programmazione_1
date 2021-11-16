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
* @param v: vettore
* @param dim: dimensione del vettore (numero lettere minuscole)
* @return: void
*/
void inizializza(int v[], int dim) {
	for (int i=0; i<dim; i++)
		v[i] = 0;
}

/*
* incrementa il contatore di v[ele] e aggiorna il numero di elementi
* @param num_ele: numero di elementi prsenti nel contenitore
* @param ele: elemento da inserire
* @return: tipo di errore se occurred, OK altrimenti
*/
errore inserisci(char ele, int v[], int &num_ele, int capienza) {
	if (ele<MIN_CHAR || ele>MAX_CHAR)
		return ELE_NOT_VALID;
	// cout << "valid" << endl;
	
	if (num_ele >= capienza)
		return NOT_ENOUGH_SPACE;
	// cout << "space" << endl;
	
	// cout << v[ele-MIN_CHAR] << endl;
	v[ele-MIN_CHAR]++;
	num_ele++;
	return OK;
}  // se esce senza errori ritorna 0 => OK

errore estrai(char ele, int v[], int &num_ele) {
	if (ele<MIN_CHAR || ele>MAX_CHAR)
		return ELE_NOT_VALID;

	num_ele -= v[ele-MIN_CHAR];
	v[ele-MIN_CHAR] = 0;
	return OK;
}  // se esce senza errori ritorna 0 => OK

errore modifica_capienza(int nuova_capienza, int num_ele, int &capienza) {
	if (nuova_capienza < num_ele)
		return TOO_SMALL_CAP;
	
	capienza = nuova_capienza;
	return OK;
}

void stampa(int v[], int dim) {
	cout << "<";
	for (int i=0; i<dim; i++) {
		if (v[i] != 0)
			cout << char(i+MIN_CHAR) << ":" << v[i] << ", ";
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


	// struttura dati	
	// cout << int(MAX_CHAR) - int(MIN_CHAR) + 1;
	const int DIM = int(MAX_CHAR)-int(MIN_CHAR)+1;
	int capienza = 0;  // numero totale di elementi
	int dimensione_attuale = 0;
	int contenitore[DIM];
	errore err;
	
	// inizializzazione
	cout << "Capienza: "; cin >> capienza;
	inizializza(contenitore, DIM);

	char ch;  // scelta utente
	char ele; int aux;
	while (true) {
		cout << menu << endl;
		cout << ">> "; cin >> ch;
		switch (ch) {
			case 'i':
				cout << "Nome elemento: "; cin >> ele;
				err = inserisci(ele, contenitore, dimensione_attuale, capienza);
				if (err != OK) {
					cout << err << endl;
					gestisci_errore(err);
				}
				break;
			case 'e':
				cout << "Nome elemento: "; cin >> ele;
				err = estrai(ele, contenitore, dimensione_attuale);
				if (err != OK)
					gestisci_errore(err);
				break;
			case 'm':
				cout << "Nuova capienza: "; cin >> aux;
				err = modifica_capienza(aux, dimensione_attuale, capienza);
				if (err != OK)
					gestisci_errore(err);
				break;
			case 'c':
				cout << "Capienza: " << capienza << endl;
				break;
			case 'q':
				cout << "Quanti elementi sono nel vettore? " << dimensione_attuale << endl;
				break;
			case 's':
				stampa(contenitore, DIM);
				break;
			case 't':
				return 0;
				break;
			default:
				cout << "Scelta errata" << endl;
		}
	}
}
