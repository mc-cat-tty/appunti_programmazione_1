#include <iostream>

using namespace std;

int main() {
	const int MAX = 10;
	int l;
	do {
		cout << "Lato: ";
		cin >> l;
	} while (!(l>0 && l<=MAX));
	
	for (int i=1; i<=l*l; i++) {
		if (i%l == 0 || i%l == 1 || i<=l || i>=l*l-l)
			cout << "# ";
		else
			cout << "  ";
		if (i%l==0)
			cout << endl;
	}
	return 0;
}
