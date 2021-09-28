#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int a;
	cout << "Immetti numero: ";
	cin >> a;
	cout << "Risultato: " << a%10 << a%100/10 << a/100 << endl;
	return 0;
}
