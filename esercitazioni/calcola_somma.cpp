#include <iostream>
#include <time.h>

using namespace std;

const int somma(const int[], const int);
inline const int rand_in_range(const int, const int);

int main() {
	const int DIM = 5;
	const int RANGE_INF = 0, RANGE_SUP = 10;
	int v[DIM];
	
	srand(time(0));

	for (int i=0; i<DIM; i++) { // scorri in modo crescente per sfruttare cache line
			v[i] = rand_in_range(RANGE_INF, RANGE_SUP);
			cout << v[i] << endl;
	}
	
	cout << endl << somma(v, DIM) << endl;
}

const int somma(const int v[], const int dim) {
	int somma = 0;
	for (int i=0; i<dim; i++) {
		somma += v[i];
	}
	return somma;
}

inline const int rand_in_range(const int inf, const int sup) {
	return rand()%(sup-inf+1) + inf;
}
