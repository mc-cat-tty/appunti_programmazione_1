#include <iostream>

using namespace std;

void stampa_occorrenze (int v[], int dim) {
	int c;
	for (int i=0; i<dim; i++) {
		c = 0;
		if (v[i] > 0) {
			c++;
			for (int j=i+1; j<dim; j++) {
				if (v[j] == v[i]) {
					c++;
					v[j] = 0;
				}
			}
		cout << "Valore " << v[i] << " presente " << c << " volte" << endl;
		}
	}
}

int main() {
	int a[12] = {9, 8, 1, 1, 1, 2, 3, 4, 2, 3, 3, 9};
	stampa_occorrenze(a, 12);
	return 0;
}
