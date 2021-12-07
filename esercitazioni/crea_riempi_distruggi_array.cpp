#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int n;  // dimensione array dinamico scelta dall'utente
	cout << "Dimensione array: ";
	cin >> n;
	
	int *a = new int[n];  // allocazione
	
	// riempimento
	for (int i=0; i<n; i++) {
		cout << "Elemento numero "<<i+1<<" : ";
		cin >> a[i];
	}
	
	// stampa
	cout << endl << "STAMPA" << endl;
	for (int i=0; i<n; i++) {
		cout << "Elemento numero "<<i+1<<" : ";
		cout << a[i] << endl;
	}
	
	int n2;  // nuova dimensione
	do {
		cout << "Quanti elementi vuoi conservare? ";
		cin >> n2;
	} while (!(n2>=0 && n2<=n));

	int *a2 = new int[n2];
	
	// copia
	memcpy(a2, a, sizeof(int)*n2);
	
	// deallocazione vecchio array	
	delete[] a;

	// stampa
	cout << endl << "STAMPA" << endl;
	for (int i=0; i<n2; i++) {
		cout << "Elemento numero "<<i+1<<" : ";
		cout << a2[i] << endl;
	}
	
	// deallocazione array nuovo
	delete[] a2;

	return 0;
}
