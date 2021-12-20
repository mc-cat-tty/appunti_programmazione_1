#include <iostream>
#include <fstream>

using namespace std;

int main() {
	const char filename[] = "append.txt";
	fstream f(filename, ios_base::app);
	if (!f) {
		cerr << "errore apertura file";
		return 1;
	}
	cin >> noskipws;
	char c;
	while (cin >> c)
		f << c;
	f.close();
	return 0;
}
