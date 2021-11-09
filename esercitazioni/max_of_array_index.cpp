#include <iostream>
#include <time.h>

using namespace std;

inline int max(const int a, const int b);
inline int rand_in_range(const int inf, const int sup);

int main() {
	srand(time(0));
	const int dim = 5;
	int v[dim];	

	// generazione e stampa
	for (int i=0; i<dim; i++) {
		v[i] = rand_in_range(1, 100);
		cout << v[i] << endl;
	}
	
	// ricerca massimo
	int index = 0;
	for (int i=0; i<dim; i++) {
		if (v[index] < v[i]) {
			index = i;
		}
	}
	
	cout << "Il valore massimo presente nel vettore è: " << v[index] << endl;
	return 0;
}

inline int max(const int a, const int b) {
	return a > b ? a : b;
}

inline int rand_in_range(const int inf, const int sup) {
	return rand()%(sup-inf) + inf;
}
