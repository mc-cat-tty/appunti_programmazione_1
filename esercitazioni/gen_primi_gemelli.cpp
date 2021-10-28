#include <iostream>
#include <cmath>

using namespace std;

bool is_primo(const int n);
bool is_primi_gemelli(const int a, const int b);
int primo_dispari_dopo(const int n);

// misura tempo di esecuzione con "time" (comando bash)
int main() {
	int a, b;
	do {
		cout << "Estremi a e b non negativi: "; cin >> a >> b;
	} while (!(a>0 && b>0));
	
	// parto dal primo dispari disponibile e scorro solamente i numeri dispari
	for (int i=primo_dispari_dopo(a); i<b-1; i+=2) {  // Arrivo fino a b-1 perchè nel corpo del ciclo faccio i+2 (arriva esattamente a b) 
		if (is_primi_gemelli(i, i+2))
			cout << "Primi gemelli: " << i << " " << i+2 << endl;
	}
	return 0;
}

int primo_dispari_dopo(const int n) {
	if (n%2 == 0)
		return n+1;
	return n;
}

bool is_prime(const int n) {  // Può essere ottimizzata
	for (int i=2; i<n; i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}

bool is_primi_gemelli(const int a, const int b) {
	if (abs(a-b) == 2 && is_prime(a) && is_prime(b))
		return true;
	return false;
}
