#include <iostream>

using namespace std;

int main() {
	const int dim = 5;
	int V[dim];

	for (int i=0; i<dim; i++) {
		cout << "Inserisci elemento " << i+1 << ": ";
		cin >> V[i];
	}
	 
	for (int i=0; i<dim; i++)
		cout << "Valore " << i+1 << ": " << V[i] << endl;

	return 0;

}
