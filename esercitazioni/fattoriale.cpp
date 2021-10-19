#include <iostream>
#include <limits.h>

using namespace std;

inline const int int_prod_overflow(const int a, const int b) {
	return	(( ((a>0 && b>0) || (a<0 && b<0)) && b!=0 && abs(a)>abs(INT_MAX/b) )
			||
			( ((a<0 && b>0) || (a>0 && b<0)) && b!=0 && abs(a)>abs(INT_MIN/b) ));
}

int main() {
	int n, fat = 1;
	do {
		cout << "Numero n diverso da 0: ";
		cin >> n;
	} while (n==0);
	// for (int i=1; i<=n; fat*=i, i++) ;
	bool overflow = false;
	for (int i=1; i<=n; i++) {
		overflow = overflow || int_prod_overflow(fat, i);
		fat *= i;
	}
	cout << "Risultato: " << fat << endl;
	if (overflow)
		cout << "Risultato inattendibile causa overflow" << endl;
	return 0;
}
