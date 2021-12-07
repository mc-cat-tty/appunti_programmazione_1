#include <iostream>

using namespace std;

void crea_copia_array(const int v1[], const int dim, int* &v2) {
	v2 = new int[dim];
	for (int i=0; i<dim; i++)
		v2[i] = v1[i];
}

int main() {
	const int N = 3;
	int vettore[N] = {10, 20, 30};
	int *dest;

	crea_copia_array(vettore, N, dest);

	for (int i=0; i<N; i++)
		cout << dest[i] << " ";
	
	delete[] dest;
	
	return 0;
}
