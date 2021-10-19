#include <iostream>
#include <limits.h>

using namespace std;

int main() {
	int	a,		// fattore 1
		b,		// fattore 2
		res;	// prodotto

	cout << "Immettere i due fattori: ";
	cin >> a >> b;

	bool overflow = false;
	res = a*b;
	if (((a>0 && b>0) || (a<0 && b<0)) && b!=0 && abs(a)>abs(INT_MAX/b))
		overflow = true;
	else if (((a>0 && b<0) || (a<0 && b>0)) && b!=0 && abs(a)>abs(INT_MIN/b))
		overflow = true;
	
	cout << a << " * " << b << " = " << res << endl;
	if (overflow) {
		cout << "Attenzione: operazione soggetta a overflow" << endl;
		return 1;
	}
	return 0;
}
