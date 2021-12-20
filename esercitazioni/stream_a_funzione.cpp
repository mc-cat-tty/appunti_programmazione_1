#include <iostream>
#include <fstream>

using namespace std;

bool scrivi(ostream &s, const char *str) {
	if (!s) {
		cerr << "Errore nell'apertura";
		return 1;
	}
	
	s << str;

	return static_cast<bool>(s);
}

int main() {
	ofstream f("out.txt");
	scrivi(f, "ciao\n");
	scrivi(cout, "ciao\n");
	f.close();
}
