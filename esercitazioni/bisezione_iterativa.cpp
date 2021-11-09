#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

const double precision = numeric_limits<double>::epsilon();

// calcola la radice nell'intervallo [a, b], se esiste,
// della funzione f(x) definita a tempo di scrittura
// -1 se non sono presenti radici nell'intervallo
double bisezione(double a, double b, double epsilon);

// definisci sotto
double f(double x);

int main() {
	// cout << precision;  // DEBUGGING
	double a, b;
	double res;
	
	cout << "Precisione (minore possibile): " << precision << endl;
	do {
		cout << "Inserisci a e b: "; cin >> a >> b;
		res = bisezione(a, b, precision);
	} while (res == -1.0);
	
	cout << "La radice di f(x) nell'intervallo [" << a << ", " << b << "] è: " << res << endl;
}

// cambia il corpo di questa funzione
double f(double x) {
	// return exp(x) - x*x - 2.0;
	return exp(x);
}

double bisezione(double a, double b, double epsilon) {
	if (f(a)*f(b) > 0.0)
		return -1;
	
	double c, f_c;
	while (fabs(a-b) > epsilon) {
		c = (a+b)/2.0; f_c = f(c);
		if (f_c >= 0.0-epsilon && f_c <= 0.0+epsilon)
			return c;
		if (f_c*f(a) < 0.0)
			b = c;
		else if (f_c*f(b) < 0.0)
			a = c;
	}
	return -1;
}
