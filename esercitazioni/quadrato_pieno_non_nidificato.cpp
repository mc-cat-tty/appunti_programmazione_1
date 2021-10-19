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
		cout << "# ";
		if (i%l==0)
			cout << endl;
	}
	return 0;
}
