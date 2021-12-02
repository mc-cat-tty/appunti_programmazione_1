#include <iostream>

using namespace std;

int calcola_somma(int riga[], int dim_riga) {
	int count = 0;
	
	for (int i=0; i<dim_riga; i++) {
		count += riga[i];
	}
	
	return count;
}

int main() {
	const int dim_r = 3, dim_c = 3;
	int M[dim_r][dim_c];

	for (int i=0; i<dim_r; i++) {
		for (int j=0; j<dim_c; j++) {
			cout << "Elemento ["<<i<<"]["<<j<<"]: ";
			cin >> M[i][j];
		}
	}


	for (int i=0; i<dim_r; i++) {
		for (int j=0; j<dim_c; j++) {
			cout << M[i][j] << " ";
		}
		cout << "  " << calcola_somma(M[i], dim_c);  // Passo un vettore riga e il numero di elementi presenti in esso
		cout << endl;
	}
	
	return 0;
}
