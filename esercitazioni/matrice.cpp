/*
Scrivere un programma che definisca una mat bdimensionale di interi 
(dim stabilite a tempo di scrittura) ed assegni ad ogni elemento un
valore letto da stdin
*/

#include <iostream>

using namespace std;

int main() {
	const int dimX = 3, dimY = 2;
	int M[dimY][dimX];
	for (int i=0; i<dimY; i++) {
		for (int j=0; j<dimX; j++) {
			cout << "Inserisci l'elemento ["<<i<<"]["<<j<<"]: ";
			cin >> M[i][j];
		}
	}
	
	for (int i=0; i<dimY; i++) {
		for (int j=0; j<dimX; j++) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
