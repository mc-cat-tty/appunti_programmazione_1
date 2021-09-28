#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int a, b;
	cout << "Inserisci primo numero intero positivo: ";
	cin >> a;
	cout << "Inserisci secondo numero intero positivo: ";
	cin >> b;
	cout << abs((((a%b-1)*2+1)%2-1)/2) << endl;
	return 0;
}
