/*
Scrivere un programma che definisca una mat bdimensionale di interi, la
inizializzi e conti il numero di valori positivi, negativi e nulli
*/

#include <iostream>
#include <ctime>

using namespace std;

int main() {
	const int dim_r= 100, dim_c = 100;
	int M[dim_r][dim_c];
	
	srand(time(0));
	
	// Inizializzazione
	for (int i=0; i<dim_r; i++) {
		for (int j=0; j<dim_c; j++) {
			M[i][j] = (rand()%3) - 1;
		}
	}
	
	int pos, neg;
	pos = neg = 0;
	
	for (int i=0; i<dim_r; i++) {
		for (int j=0; j<dim_c; j++) {
			if (M[i][j] > 0)
				pos++;
			else if (M[i][j] < 0)
				neg++;
		}
	}
	
	cout
		<< "Pos: " << pos << endl
		<< "Neg: " << neg << endl
		<< "Nulli: " << dim_r*dim_c-(pos+neg) << endl;
	
	return 0;
}
