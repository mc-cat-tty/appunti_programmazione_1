#include <iostream>
#include <time.h>

using namespace std;

void copia_pari(const int[], const int, int[], int&);
inline const int rand_in_range(const int, const int);

int main() {
	const int DIM = 5;
	const int RANGE_INF = 0, RANGE_SUP = 10;
	int v[DIM], pari[DIM];
	int pari_dim = 0;
	
	srand(time(0));

	for (int i=0; i<DIM; i++) { // scorri in modo crescente per sfruttare cache line
			v[i] = rand_in_range(RANGE_INF, RANGE_SUP);
			cout << v[i] << endl;
	}
	
	copia_pari(v, DIM, pari, pari_dim);

	cout << endl;
	for (int i=0; i<pari_dim; i++) {
		cout << pari[i] << endl;
	}
}

// dim_out verrà inizializzato a zero
// output[] deve avere una dimensione pari o superiore a dim_in
void copia_pari(const int input[], const int dim_in, int output[], int &dim_out) {
	dim_out = 0;
	for (int i=0; i<dim_in; i++) {
		if (input[i]%2 == 0)
			output[dim_out++] = input[i];
	}
}

inline const int rand_in_range(const int inf, const int sup) {
	return rand()%(sup-inf+1) + inf;
}
