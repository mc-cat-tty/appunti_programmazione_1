#include <iostream>
#include <limits.h>

using namespace std;

inline const bool int_sum_overflow(const int a, const int b)  {
	return ((a>0 && b>0 && a>INT_MAX-b) || (a<0 && b<0 && a<INT_MIN-b));
}

int main() {
	const int MAX = 10;

	// Immissione n e sanificazione range input
	int n;
	do {
		cout << "Numeri da sommare: ";
		cin >> n;
		if (!(0<=n && n<=MAX))
			cout << "Valore non consentito" << endl;
	} while (!(0<=n && n<=MAX));
	
	// Calcolo iterativo somma e ricerca minimo
	int num_max = 0, s = 0;
	bool overflow = false;
	for (int i=0, num; i<n; i++) {
		cout << "Prossimo numero: ";
		cin >> num;
		if (int_sum_overflow(num, s))
			overflow = true;
		s += num;
		if (num > num_max)
			num_max = num;
	}

	cout 
		<< "Massimo numero inserito: " << num_max << endl
		<< "Somma: " << s << endl;
	if (overflow)
		cout << "Somma inattendibile a causa di overflow" << endl;
	
	return 0;	
}
