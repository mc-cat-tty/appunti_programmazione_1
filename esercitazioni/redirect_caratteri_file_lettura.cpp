#include <iostream>
#include <fstream>

using namespace std;

const char filename[] = "redirect.txt";

int main() {
	char c;
	ofstream fo(filename);
	
	if (!fo) {

		cerr << "Errore apertura";
		return 1;
	}
	
	cin >> noskipws;
	while (cin >> c)
		fo << c;
	
	fo.close();

	ifstream fi(filename);
	
	if (!fi) {
		cerr << "Errore apertura file in lettura";
		return 1;
	}
	
	fi >> noskipws;
	while (fi >> c)
		cout << c;
	
	fi.close();

	return 0;
}
