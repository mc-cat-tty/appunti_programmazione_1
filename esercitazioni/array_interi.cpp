#include <iostream>

using namespace std;

enum Ordinamento {CRESCENTE, DECRESCENTE};

void stampa_vettore(int v[], int dim) {
	for (int i=0; i<dim; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

void ordina(int v[], int dim, Ordinamento ord) {
	int s_index;
	// insertion sort
	for (int i=0; i<dim-1; i++) {
		s_index = i;
		for (int j=i+1; j<dim; j++) {
			if (ord == CRESCENTE && v[j] > v[s_index])
				s_index = j;
			else if (ord == DECRESCENTE && v[j] < v[s_index])
				s_index = j;
		}
		int aux = v[s_index];
		v[s_index] = v[i];
		v[i] = aux;
	}
}

int main() {
	const short int DIM = 10;
	int v[] = {100, 222, 3, 41, 54, 6, 7, 8, 9, 10};
	
	stampa_vettore(v, DIM);
	
	// ricerca massimo e minimo
	int max, min;
	max = min = v[0];
	for (int i=1; i<DIM; i++) {
		v[i] > max ? max = v[i] : 0;
		v[i] < min ? min = v[i] : 0;
	}
	cout << "Min: " << min << " Max: " << max << endl;

	ordina(v, DIM, CRESCENTE);
	stampa_vettore(v, DIM);
	
	ordina(v, DIM, DECRESCENTE);
	stampa_vettore(v, DIM);

	return 0;
}
