#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	char str[] = "Pippo";
	cout << str << endl;
	cin >> str;  // L'input di una stringa di dimensioni maggiori di 5 caratteri potrebbe sollevare uno StackSmashing error
	// non è comunque possibile leggere una riga intera, neanche utilizzando noskipws
	cout << str << endl;
	return 0;
}
