#include <iostream>

using namespace std;

int main() {
	const int a = 1, b = 10;
	int controllo, i;

	cout << "Inserisci controllo: ";
	cin >> controllo;
	
	cout << "Inserisci i: ";
	cin >> i;

	if (controllo)
		if (a<=i && b>=i)
			cout << "i è incluso nell'intervallo";
		else
			cout << "i non è incluso nell'intervallo";
	else
		cout << "Nessun controllo";
	cout << endl;		
}
