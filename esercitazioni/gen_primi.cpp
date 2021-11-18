#include <iostream>
#include <cmath>

using namespace std;

bool is_primo(const int n) {
	if (n>=1 && n<=3)
		return true;
	if (n%2 == 0)
		return false;
	for (int i=3; i<=static_cast<int>(sqrt(n)); i+=2)
		if (n%i == 0)
			return false;
	return true;
}

int prossimo_primo(const int n) {
	int i;
	for (i=n; !is_primo(i); i++) ;
	return i;
}

int main() {
	int a;
	do {
		cout << "Insersci a: ";
		cin >> a;
	} while (!(a>0));

	int np = 0;  // numero primo generato dalla fun
	while (true) {
		np = prossimo_primo(np);
		if (np > a) break;
		cout << np << endl;
		np++;
	}
	return 0;
}
