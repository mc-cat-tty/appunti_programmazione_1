#include <iostream>

using namespace std;

int main() {
	const int MAX = 10;
	int l;
	do {
		cout << "Lato: ";
		cin >> l;
	} while (!(l>0 && l<=MAX));
	
	for (int i=0; i<l; i++) {
		for (int j=0; j<l; j++) {
			cout << "# ";
		}
		cout << endl;
	}
	return 0;
}
