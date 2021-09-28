#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int a;
	cout << "Inserisci numero intero: ";
	cin >> a;
	cout << abs((a/abs(a)-1)/2) << endl;
	return 0;
}
