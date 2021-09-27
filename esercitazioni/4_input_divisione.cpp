#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int a, b, ris, resto;
	cout << "Primo valore: ";
	cin >> a;
	cout << "Secondo valore: ";
	cin >> b;
	resto = a%b;
	ris = (int)a/b;
	cout << a << "/" << b << "=" << ris << " con resto " << resto << endl;
	return 0;
}
