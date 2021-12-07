#include <iostream>

using namespace std;

int main() {
	int n;
	cout << "Dimensione del vettore: ";
	cin >> n;
	
	int *a = new int[n];
	
	for (int i=0; i<n; i++) {
		cout << "Elemento "<<i+1<<" : ";
		cin >> a[i];
	}

	for (int i=0; i<n; i++) {
		cout << "Elemento "<<i+1<<" : ";
		cout << a[i] << endl;
	}
	
	// Utilizza htop per visualizzare
	// l'utilizzo della memoria
	
	return 0;
}
