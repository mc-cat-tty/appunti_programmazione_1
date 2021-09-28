#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int n;
	cout << "Inserisci numero intero: ";
	cin >> n;
	cout << abs(n%2-1) << endl;
	return 0;
}
