#include <iostream>

using namespace std;

int main() {
	int n;  // input number
	char c;  // output char

	cout << "Inserisci numero: "; cin >> n;
	if (!(n>=static_cast<int>(' ') && n<=static_cast<int>('~'))) {
		cout << "Range non valido" << endl;
		return 1;
	}
		
	c = static_cast<char>(n);	
	cout << "Carattere corrispondente: " << c << endl;
	return 0;
}
