#include <iostream>
#include <cmath>

using namespace std;

int main() {
	short unsigned int lb;  // lunghezza della base
	do {
		cout << "Inserisci la lunghezza (intera) del lato: "; cin >> lb;
	} while (lb%2 == 0);
	
	short unsigned int lo = (lb-1)/2+1;  // lunghezza del lato obliquo (e altezza)
	// cout << lo << endl;  // tracing
	
	int n_ast;  // numero di asterischi
	int n_spaces;
	for (int i=0; i<lo; i++) {
		n_ast = 1 + i*2;
		// cout << n_ast << endl;  // tracing
		n_spaces = (lb - n_ast)/2;
		// cout << n_spaces << endl;  // tracing
		for (int j=0; j<lb; j++) {
			if (j>=n_spaces && j<n_spaces+n_ast)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	
	return 0;
}
