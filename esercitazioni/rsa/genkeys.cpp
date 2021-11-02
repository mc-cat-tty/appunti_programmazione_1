/**
*
* genkeys.cpp
* Francesco Mecatti
*
* Program to generate 32-bit long (at most) RSA keys.
*
*/

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

using namespace std;


// return if n is prime
bool is_prime(int n);

// return next prime number after n
// if n is prime returns n
int next_prime(int n);

// return random number between min and max (included)
int rand_in_range(int min, int max);

// return random prime number between min and max
// return -1 if there are no prime numbers in the range
int rand_prime(int min, int max);

// compute the greatest common divisor of a and b
int gcd(int a, int b);

// funzione Toziente di Eulero
int phi(int n);

long int pow_mem_safe(long int, long int);

bool is_prod_overflow(long int, long int);

long int fast_mod_pow(long, long, long);

// Print a pair of keys and exit
int main() {
	srand(time(NULL));
	
	/*
	// debugging is_prime
	int a; cin >> a;
	cout << is_prime(a);
	return 0;
	*/
	
	/*
	// debugging next_prime
	int a; cin >> a;
	cout << next_prime(a);
	return 0;	
	*/

	/*
	// debugging rand_in_range
	int a, b; cin >> a >> b;
	cout << rand_in_range(a, b);
	return 0;
	*/
	
	/*
	// debugging rand_prime
	int a, b; cin >> a >> b;
	cout << rand_prime(a, b);
	return 0;
	*/
	
	/*
	// debugging gcd
	int a, b; cin >> a >> b;
	cout << gcd(a, b);
	return 0;
	*/
	
	/*
	// debugging phi
	int z; cin >> z;
	cout << phi(z);
	return 0;
	*/
	
	/*
	// debugging pow
	long int x, y; cin >> x >> y;
	cout << pow_mem_safe(x, y);
	return 0;
	*/

	// STRUTTURA DATI
	long int
		p, q,		// fattori
		n,			// modulo
		phi_n,		// toziente di n
		e,			// chiave pubblica
		d;			// chiave privata

	int min, max;
	cin >> min >> max;  // input the range boundaries
	
	// STEP 1: find p, q both prime with p!=q
	do {	
		p = rand_prime(min, max);
		q = rand_prime(min, max);
	} while (!(p!=q) || q==-1 || p==-1);
	// cout << p << " " << q << endl;
	n = p*q;
	// cout << n << endl;
	
	phi_n = (p-1)*(q-1);  // perchè sono primi e, di conseguenza, anche coprimi tra loro
	
	// STEP 2: find a suitable e -> must be coprime with phi_n and 1<e<phi_n
	do {
		e = rand_in_range(2, phi_n-1);  // escludi gli estremi
	} while (gcd(e, phi_n) != 1);
	// cout << e << endl;
	
	// STEP 3: calcola d => inverso modulare di e
	/* d = pow_mem_safe(e, phi(phi_n)-1);
	cout << d << endl;
	if (d == -1)  // overflow occured
		return 1;
	d %= phi_n;*/
	d = fast_mod_pow(e, phi(phi_n)-1, phi_n);
	
	cout << "(" << e << ", " << d << ", " << n << ")" << endl;
	return 0;
}

bool is_prime(int n) {
	if (n>=1 && n<=3)
		return true;
	if (n%2 == 0)
		return false;
	for (int i=3; i<=static_cast<int>(sqrt(n)); i+=2) {
		if (n%i == 0)
			return false;	
	}
	return true;
}

int next_prime(int n) {
	for (int i=n; ; i++)
		if (is_prime(i))
			return i;
}

int rand_in_range(int min, int max) {
	return (rand()%(max-min+1))+min;
}

int rand_prime(int min, int max) {
	int res = next_prime(rand_in_range(min, max));
	if (res>=min && res<=max)
		return res;
	return -1;
}

int gcd(int a, int b) {
	if (b == 0)
		return a; 
	return gcd(b, a%b);
}

int phi(int n) {
	int count = 0;
	for (int i=1; i<n; i++) {
		if (gcd(i, n) == 1)
			count++;
	}
	return count;
}

bool is_prod_overflow(long int a, long int b) {
	if (abs(a)>abs(LONG_MAX/b))
		return true;
	return false;
}

long int pow_mem_safe(long int b, long int e) {
	long int res = 1;
	for (long int i=0; i<e; i++) {
		if (is_prod_overflow(res, b))
			return -1;
		res *= b;
	}
	return res;
}

long int fast_mod_pow(long int b, long int e, long int m) {
    // (ab) % m = [(a % m) * (b % m)] % m
    if (e == 0) return 1;
    return ((b % m) * (fast_mod_pow(b, e-1, m) % m)) % m;
}

