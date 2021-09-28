#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int a;
	cout << "Inserisci numero intero: ";
	cin >> a;
	cout << a/abs(a) << endl;
	return 0;
}
