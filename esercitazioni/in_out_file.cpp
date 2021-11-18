#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

int main() {
	ofstream f("testo.txt");
	if (!f) {  // ricordati di controllare eventuali errori
		cerr << "Errore in apertura" << endl;
		return 1;
	}

	char c;
	cin >> noskipws;
	while (cin >> c)	f << c;

	f.close();  // ricordati di chiudere
}
