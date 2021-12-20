#include <iostream>
#include <fstream>

using namespace std;

int main() {
	const char FILENAME[] = "testo.txt";
	ofstream f(FILENAME);	
	if (!f) {
		cerr << "Errore nell'apertura del file in scrittura" << endl;
		return 1;
	}

	cout << "Inserisci il contenuto del file un carattere alla volta e termina con EOF :" << endl;
	char c;
	while (cin.get(c)) {
		f << c;
	}
	f.close();

	ifstream f2(FILENAME);
	if (!f2) {
		cerr << "Errore nell'apertura del file in lettura" << endl;
	}
	
	cout << "Il file contiene: " << endl;
	int rows = 0;
	while (f2.get(c)) {
		cout << c;
		if (c == '\n')
			rows++;
	}
	cout << endl << "Numero di righe: " << rows << endl;
	
	return 0;
}
