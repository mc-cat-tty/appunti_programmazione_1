#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

int main() {
	ofstream fw("testo.txt");
	if (!fw) {  // ricordati di controllare eventuali errori
		cerr << "Errore in apertura" << endl;
		return 1;
	}

	char c;
	cin >> noskipws;
	while (cin >> c)	fw << c;

	fw.close();  // ricordati di chiudere

	ifstream fr("testo.txt");
	if (!fr) {
		cerr << "Errore in apertura" << endl;
		return 1;
	}
	
	fr >> noskipws;
	while (cout << c) {
		fr >> c;
		if (fr.eof())
			break;
	}
	fr.close();
}
