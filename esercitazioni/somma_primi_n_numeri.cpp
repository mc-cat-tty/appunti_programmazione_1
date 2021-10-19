#include <iostream>

using namespace std;

int main() {
	int s, i, n;
	cout << "Numero N: ";
	cin >> n;
	s = i = 0;
	while (i<n) {
		i++;
		s+=i;
	}
	cout << s << endl;
	return 0;
}
