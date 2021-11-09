#include <iostream>
#include <time.h>

using namespace std;

void raddoppia_array(int[], const int);
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
	
	raddoppia_array(v, DIM);
	
	cout << endl;
	for (int i=0; i<DIM; i++) {
		cout << v[i] << endl;
	}
}

void raddoppia_array(int v[], const int dim) {
	for (int i=0; i<dim; i++) {
		v[i] *= 2;
	}
}

inline const int rand_in_range(const int inf, const int sup) {
	return rand()%(sup-inf+1) + inf;
}
