#include <iostream>

using namespace std;

int main() {
	int a, b, x;
	cout << "Inserisci a, b, x: ";
	cin >> a >> b >> x;
	cout << "a<=x<=b? " << ((a<=x) && (x<=b)) << endl;
	return 0;
}

