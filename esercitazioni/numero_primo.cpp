#include <iostream>

using namespace std;

int main() {
	int n;
	bool primo = true;
	cin >> n;
	for (int i=2; i<n; i++) {  // soluzione inefficiente
		if (n%i == 0) {
			primo = false;
			break;
		}
	}
	cout << n;
	if (primo)
		cout << " è primo";
	else
		cout << " non è primo";
	cout << endl;
}
