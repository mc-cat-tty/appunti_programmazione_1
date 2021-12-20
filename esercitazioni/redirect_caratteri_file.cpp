#include <iostream>
#include <fstream>

using namespace std;

int main() {
	char c;
	ofstream f("redirect.txt");
	if (!f) {
		cerr << "Errore apertura";
		return 1;
	}
	cin >> noskipws;
	while (cin >> c)
		f << c;
	f.close();
	return 0;
}
