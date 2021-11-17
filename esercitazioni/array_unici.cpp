#include <iostream>

using namespace std;

/*
* Conta il numero di occorrenze di x presenti in v
*
* @param x: target number
* @param v[]: vettore nel quale cercare le occorrenze di x
* @param dim: dimensione del vettore v[]
* @return: numero di occorrenze di x in v[]
*/
const int contavolte(const int x, const int v[], const int dim) {
	int count = 0;
	for (int i=0; i<dim; i++) {
		if (v[i] == x)
			count++;
	}
	return count;
}

/*
* Inserisce nell'array out gli elementi unici presenti nell'array in
*
* @param in[]: vettore di input
* @param out[]: parametro di output. Vettore nel quale verranno inseriti
*	gli elementi unici di in[]
* @param dim: dimensione di in[]
* @return la dimensione dell'array out[]
*/
const int creaunici(const int in[], int out[], const int dim) {
	int i_out = 0;
	for (int i=0; i<dim; i++)
		if (contavolte(in[i], in, dim) == 1)
			out[i_out++] = in[i];
	return i_out;
}

void stampa_array(const int v[], const int dim) {
	for (int i=0; i<dim; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	const int DIM = 11;
	int v1[DIM] = {2, 4, 3, 2, 7, 1, 3, 5, 1, 8, 9};
	int v2[DIM];  // 4 7 5 8 9

	
	cout << "Array originale: ";
	stampa_array(v1, DIM);

	int dim2 = creaunici(v1, v2, DIM);
	
	cout << "Array unici: ";
	stampa_array(v2, dim2);

	return 0;
}
