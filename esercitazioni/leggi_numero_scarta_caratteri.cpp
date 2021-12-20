#include <iostream>

using namespace std;

int main() {
	int i;
	cout << "Immettere un numero: ";
	while (!(cin>>i)) {
		if (cin.eof())
			break;
		cin.clear();
		cin.ignore();  // scarta carttere successivo
		// posso scartare una riga intera con cin.igonre(srd::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	// sono riuscito a leggere un numero oppure è arrivato eof
	if (cin.eof()) {
		cerr << "Lettura fallita" << endl;
		return 1;
	}
	else {
		cout << "Numero letto: " << i << endl;
		return 0;
	}
}
