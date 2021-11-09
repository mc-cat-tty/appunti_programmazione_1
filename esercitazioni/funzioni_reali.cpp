#include <iostream>
#include <cmath>

using namespace std;

double val_assoluto(double);
double arrotonda_per_eccesso(double);
double arrotonda_per_difetto(double);

int main() {
	double n;
	cin >> n;
	
	cout << "fabs ceil floor" << endl;
	cout << fabs(n) << " ";
	cout << ceil(n) << " ";
	cout << floor(n) << " ";
	cout << endl;
	
	cout << val_assoluto(n) << " ";
	cout << arrotonda_per_eccesso(n) << " ";
	cout << arrotonda_per_difetto(n) << " ";
	cout << endl;
}

double val_assoluto(double n) {
	return n < 0. ? -n : n;
}

double arrotonda_per_eccesso(double n) {
	if (val_assoluto(n)-static_cast<int>(val_assoluto(n)) == 0)
		return n;
	
	return n > 0. ?
			static_cast<int>(n)+1.
			: static_cast<int>(n);
}

double arrotonda_per_difetto(double n) {
	if (val_assoluto(n)-static_cast<int>(val_assoluto(n)) == 0)
		return n;
	
	return n > 0. ?
			static_cast<int>(n)
			: static_cast<int>(n)-1.;
}
