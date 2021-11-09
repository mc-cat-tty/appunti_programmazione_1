#include <iostream>
#include <time.h>

using namespace std;

int main() {
	srand(time(0));
	const int dim = 5;
	int v[dim];	

	for (int i=0; i<dim; i++) {
		v[i] = rand();
	}

	for (int i=0; i<dim; i++) {
		cout << v[i] << endl;
	}
}
