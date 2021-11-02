/**
*
* enc_dec_char.cpp
* Francesco Mecatti
*
* Program to encrypt and decrypt characters through the RSA algorithm.
*
*/

#include <iostream>

using namespace std;

// print menu items and get choice
// return: menu choice
int menu(int e, int d, int r);

// compute res = (msg^exp) % mod and return the result
// return: -1 if error, correct result otherwise
int rsa(int msg, int exp, int mod);

// compute b^e%m
// return: -1 if error (overflow/underflow), result otherwise
int fast_mod_pow(int b, int e, int m);

// print menu and do selection in a loop
int main() {
	// struttura dati:
	//   - messaggio (input da cifrare/decifrare)
	//   - esponente per encrypting
	//   - esponente per decrypting
	//   - modulo
	char c; int n;
	int	e = 5, 
		d = 173,
		r = 323;  // default key

	int ch;
	char discard_char;

	// cout << pow(2, 3);  // debugging
	// return 0;
	
	while (true) {
		ch = menu(e, d, r);
		
		switch (ch) {
			case 1:
				cout
					<< endl
					<< "Inserisci la chiave [\"(e, d, r)\"]: ";
				cin >> discard_char >> e  >> discard_char >> d >> discard_char >> r >> discard_char;
				// cout << e << d << r;  // debugging
				break;
			case 2:  // cifratura
				cout
					<< endl
					<< "Carattere: ";
				cin >> c;
				cout << "Carattere cifrato: " << rsa(static_cast<int>(c), e, r) << endl;
				break;
			case 3:  // decifratura
				cout
					<< endl
					<< "Numero: ";
				cin >> n;
				cout << "Carattere decifrato: " << static_cast<char>(rsa(n, d, r)) << endl;
				break;
			case 4:
				return 0;
			default:
				cout << "Opzione non valida" << endl;
		}
		
		cout << endl;
	}
}

int menu(int e, int d, int r) {
	cout
		<< "Chiave in uso: (" << e << ", " << d << ", " << r << ")" << endl
		<< endl
		<< "1. Inserimento chiave RSA" << endl
		<< "2. Cifratura carattere" << endl
		<< "3. Decifratura carattere" << endl
		<< "4. Exit" << endl
		<< ">> ";

	int s;
	cin >> s;
	return s;
}

// wrap memory-safe modular exponentiation
int rsa(int msg, int exp, int mod) {
	return fast_mod_pow(msg, exp, mod);
}

int fast_mod_pow(int b, int e, int m) {
	// (ab) % m = [(a % m) * (b % m)] % m
	if (e == 0) return 1;
	return ((b % m) * (fast_mod_pow(b, e-1, m) % m)) % m;
}
