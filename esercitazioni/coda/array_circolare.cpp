#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_DIM = 10;

struct array_circolare_t {
	int v[MAX_DIM];
	int dim;
	int start;
};

enum err_t {OK, FINE_SPAZIO, FINE_ELEMENTI, NUM_ERR};
enum position {TAIL, HEAD};

void log(err_t e) {
	switch (e) {
		case OK:
			clog << "Ok";
			break;
		case FINE_SPAZIO:
			cerr << "Fine spazio";
			break;
		case FINE_ELEMENTI:
			cerr << "Fine elementi";
			break;
		default:
			cerr << "Errore sconosciuto";
	}
	clog << endl;
	return;
}

void stampa(array_circolare_t &a) {
	clog << "Stampa" << endl;
	for (int i=0; i<a.dim; i++) {
		cout << setw(3) << a.v[(a.start+i)%MAX_DIM] << " ";
		clog << (a.start+i)%MAX_DIM << endl;
	}
	cout << endl;
	return;
}

err_t inizializza(array_circolare_t &a) {
	clog << "Inizializza" << endl;
	a.dim = 0;
	a.start = 0;
	return OK;
}

err_t inserisci(array_circolare_t &a, position p, int ele) {
	clog << "Inserisci" << endl;
	if (a.dim == MAX_DIM)
		return FINE_SPAZIO;
	
	if (p == HEAD) {
		a.start = (a.start+MAX_DIM-1)%MAX_DIM;
		a.v[a.start] = ele;
		// clog << a.start << endl;
	}
	else if (p == TAIL) {
		a.v[(a.start+a.dim)%MAX_DIM] = ele;
		clog << (a.start+a.dim)%MAX_DIM << endl;
	}
	
	a.dim++;
	clog << a.dim << endl;
	clog << a.start << endl;

	return OK;
}

err_t rimuovi(array_circolare_t &a, position p, int &out) {
	if (a.dim == 0)
		return FINE_ELEMENTI;
	
	if (p==HEAD) {
		out = a.v[a.start];
		a.start = (a.start+1)%MAX_DIM;
	}
	else if (p == TAIL) {
		out = a.v[(a.start+a.dim)%MAX_DIM];
	}
	
	a.dim--;
	
	return OK;
}

int numero_elementi(array_circolare_t &a) {
	clog << "numero_elementi" << endl;
	return a.dim;
}

void test() {
	cout << "Start circular array testing" << endl;
	array_circolare_t ac;

	inizializza(ac);
	stampa(ac);

	log(inserisci(ac, HEAD, 10));
	log(inserisci(ac, TAIL, 20));
	log(inserisci(ac, HEAD, 30));
	log(inserisci(ac, TAIL, 0));
	
	stampa(ac);

	log(inserisci(ac, HEAD, 0));
	log(inserisci(ac, HEAD, 0));
	log(inserisci(ac, TAIL, 0));
	log(inserisci(ac, TAIL, 0));
	log(inserisci(ac, TAIL, 0));
	log(inserisci(ac, TAIL, 0));
	
	stampa(ac);
	
	log(inserisci(ac, TAIL, 0));  // errore perchè array pieno
	
	cout << numero_elementi(ac) << endl;
	
	int tmp;

	log(rimuovi(ac, TAIL, tmp));
	log(rimuovi(ac, TAIL, tmp));
	log(rimuovi(ac, TAIL, tmp));
	log(rimuovi(ac, TAIL, tmp));

	stampa(ac);

	log(rimuovi(ac, HEAD, tmp));
	log(rimuovi(ac, HEAD, tmp));
	log(rimuovi(ac, HEAD, tmp));
	log(rimuovi(ac, HEAD, tmp));
	
	stampa(ac);
	
	log(rimuovi(ac, HEAD, tmp));
	log(rimuovi(ac, HEAD, tmp));
 	
	stampa(ac);
	
	log(rimuovi(ac, HEAD, tmp)); // fallisce perchè vuoto
	
	stampa(ac);
	
	log(inserisci(ac, HEAD, 10));
	log(inserisci(ac, TAIL, 20));
	log(inserisci(ac, HEAD, 30));
	log(inserisci(ac, TAIL, 0));
	
	stampa(ac);

	
	return;
}

int main() {
	test();
	return 0;
}
