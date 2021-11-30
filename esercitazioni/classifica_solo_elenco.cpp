/*
	Scrivere un programma che gestisca i tempi di una serie di sciatori identificati da nome, tempo in secondi.
	Il programma deve mostrare a video il dato inserito espresso in minuti, secondi + la lunghezza del campo nome 
*/

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_DIM = 10;
const int MAX_NAME_LEN = 20;

struct sciatore_t {
	char nome[21];  // len max = 20 caratteri
	int secondi;  // tempo in secondi
};

enum err_t { OK, NO_SPACE_LEFT, DUPLICATE_NAME, NAME_TOO_LONG, NAME_NOT_FOUND };

void log(err_t e) {
	switch (e) {
		case OK:
			break;
		case NO_SPACE_LEFT:
			cout << "Spazio terminato" << endl;
			break;
		case DUPLICATE_NAME:
			cout << "Nome esistente" << endl;
			break;
		case NAME_TOO_LONG:
			cout << "Nome troppo lungo" << endl;
			break;
		case NAME_NOT_FOUND:
			cout << "Nome non trovato" << endl;
			break;
	}
}

void sec_to_min_sec(const int sec_in, int &min, int &sec) {
	min = sec_in/60;
	sec = sec_in%60;
}

int cerca(const char name[], sciatore_t lista[], const int dim) {
	for (int i=0; i<dim; i++) {
		if (strcmp(name, lista[i].nome) == 0)
			return i;
	}
	return -1;
}

err_t inserisci_sciatore(const char name[], sciatore_t lista[], int &dim, const int max_dim, const int max_name_len) {
	if (dim >= max_dim)
		return NO_SPACE_LEFT;
	if (int(strlen(name)) >= max_name_len)
		return NAME_TOO_LONG;
	if (cerca(name, lista, dim) != -1)
		return DUPLICATE_NAME;
	
	strcpy(lista[dim++].nome, name);
	return OK;
}

void stampa_elenco(const sciatore_t lista[], const int dim) {
	for (int i=0; i<dim; i++) {
		cout << "Nome: " << lista[i].nome << endl;
			// << "Tempo: " << min << " minuti e " << sec << " secondi" << endl;
	}
}

err_t inserisci_tempo(const char nome[], const int min, const int sec, sciatore_t lista[], const int dim) {
	int index = cerca(nome, lista, dim);
	if (index == -1)
		return NAME_NOT_FOUND;
	lista[index].secondi = min*60+sec;
	return OK;
}

int primo_classificato(const sciatore_t lista[], const int dim) {
	if (dim == 0)
		return -1;  // errore se non sono presenti partecipanti
	
	int min_i = 0;
	for (int i=1; i<dim; i++) {
		min_i = lista[i].secondi < lista[min_i].secondi ? i : min_i;
	}
	return min_i;
}

/*
int main() {
	sciatore_t sciatori[MAX_DIM];
	int dim = 0;
	
	while (!cin.eof()) {

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
*/

int main()
{
    int scelta ;
		
		char tmp_name[MAX_NAME_LEN+1];
		int tmp_min, tmp_sec;

		err_t err;

		sciatore_t sciatori[MAX_DIM];
		int dim = 0;

		int index_primo;

    while (true) {
        cout<<"Gestione classifica\n" ;
        cout<<"Menu\n" ;
        cout<<"1 Inserimento di un nuovo partecipante\n" ;
        cout<<"2 Stampa elenco partecipanti\n" ;
        cout<<"3 Gara\n" ;
        cout<<"4 Stampa primo classificato\n" ;
        cout<<"5 Uscita\n" ;

        cin>>scelta ;
        switch(scelta) {
            case 1:	
								cout << "Nome: ";
								cin >> tmp_name;
								// cout << "Tempo [secondi]: ";
								// cin >> tmp_sec;
								if ( (err = inserisci_sciatore(tmp_name, sciatori, dim, MAX_DIM, MAX_NAME_LEN)) != OK) {
									log(err);
								}
								break ;
            case 2:
								stampa_elenco(sciatori, dim);
								break ;
            case 3:
								for (int i=0; i<dim; i++) {
									cout << "Tempo di " << sciatori[i].nome << " [min, sec]: "; cin >> tmp_min >> tmp_sec;
									err = inserisci_tempo(sciatori[i].nome, tmp_min, tmp_sec, sciatori, dim);
									if (err != OK)
										log(err);
								}
                break ;
            case 4:
								index_primo = primo_classificato(sciatori, dim);
								if (index_primo == -1) {
									cout << "Non sono presenti partecipanti" << endl;
									break;
								}
								sec_to_min_sec(sciatori[index_primo].secondi, tmp_min, tmp_sec);
								cout << "Il primo classificato è " << sciatori[index_primo].nome << " con " 
									<< tmp_min << " minuti e "
									<< tmp_sec << " secondi"
									<< endl;
                break ;
            case 5:
                return 0 ;
            default:
                continue ;
        } // Fine switch
				fflush(stdin);
    } // Fine while
    return 0 ;
}
