#include <iostream>

using namespace std;

int main() {
	int voto;
	cout << "Inserisci voto: ";
	cin >> voto;
	if (voto > 27)  // Ramo if
		cout << "Prog1 è il miglior corso" << endl; 
	else  // Ramo else
		cout << "Non ho seguito le lezioni" << endl;
	return 0;
}
