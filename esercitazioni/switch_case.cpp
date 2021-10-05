#include <iostream>

using namespace std;

int main() {
	int a = 2, n;
	cin >> n;
	switch (n) {
		case 1:
			cout << "Ramo A";
			break;
		case 2:
			cout << "Ramo B";
			a = a*a;
			break;
		case 3:
			cout << "Ramo C";
			a = a*a*a;
			// break;
		default:
			a = 1;
	}

	cout << endl << a << endl;

	return 0;
}
