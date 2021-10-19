#include <iostream>
#include <limits.h>

using namespace std;

int main() {
	int a, b, res;

	cout << "Inserisci i due numeri da sommare: ";
	cin >> a >> b;
	
	res = a+b;
	bool overflow = false;
	if (a>0 && b>0 && INT_MAX-b<a)
		overflow = true;
	else if (a<0 && b<0 && INT_MIN-b>a)
		overflow = true;
	
	cout << a << " + " << b << " = " << res << endl;
	
	if (overflow) {
		cout << "Attenzione: il risultato non è attendibile causa overflow" << endl;
		return 1;
	}
	return 0;
}
