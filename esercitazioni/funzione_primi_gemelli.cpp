#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(const int n) {  // is_prime è snake-case, isPrime è camel-case
	if (n>0 && n<=3)
		return true;
	if (n%2 == 0)
		return false;

	for (int i=3; i<=static_cast<int>(sqrt(n)); i+=2) {
		if (n%i == 0)
			return false;
	}
	return true;
}

int main() {
	int val1, val2;
	cin >> val1 >> val2;
	if ((abs(val1-val2) == 2) && is_prime(val1) && is_prime(val2))
		cout << "Primi gemelli";
	return 0;
}
