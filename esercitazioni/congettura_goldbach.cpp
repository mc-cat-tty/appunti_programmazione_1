/*
 Secondo la congettura di Goldbach ogni numero primo maggiore di 2 può essere scritto come sommma di due numeri primi
*/

#include <iostream>

using namespace std;

const int fine_intervallo_goldbach(const int a, const int b);  // ritorna il primo numero (dell'intervallo), se esiste, che non rispetta la congettura
const bool is_goldbach(const int n);
const bool is_primo(const int n);
// const int prossimo_primo(const int n);  // primo numero primo successivo ad a

int main() {
	int a, b;
	do {
		cout << "Estremi: "; cin >> a >> b;
	} while (!(a>2 && b>2));
	cout << fine_intervallo_goldbach(a, b) << endl;
	return 0;
}

const bool is_primo(const int n) {
	for (int i=2; i<n; i++)
		if (n%i == 0)
			return false;
	return true;
}

/*
const int prossimo_primo(const int n) {
	for (int i=n; ; i++)
		if (is_primo(i))
			return i;
}*/

/*const bool is_goldbach(const int n) {
		for (int i=1; i<=n/2; i++) {
			for (int j=1; j<=n/2; j++) {
				if (prossimo_primo(j) + prossimo_primo(i) == n)
					return true;
			}
		}
		return false;
}*/

const bool is_goldbach(const int n) {  // Versione ottimizzata
		for (int p1=2; p1<=n/2; p1++) {
			if (is_primo(p1) && is_primo(n-p1)) {
				cout << "[DEBUG]" << n << "=" << p1 << "+" << n-p1 << endl;  // Add tracing
				return true;
			}
		}
		return false;
}

const int fine_intervallo_goldbach(const int a, const int b) {
	int start = a, end = b;
	if (start%2 != 0)  // se numero dispari
		start++;  // diventa pari
	for (int i=start; i<=end; i+=2) {
		if (!is_goldbach(i))
			return i;
	}
	return 0;  // se tutti i numeri rispettano la congettura ritorno un valore fuori dal range
}
