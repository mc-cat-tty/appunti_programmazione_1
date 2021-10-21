#include <iostream>

using namespace std;

inline const int my_sqrt(const int n) {
	int i;
	for (i=1; i*i<=n; i++);
	return i-1;
}

int main() {
	int val;
	cin >> val;
	cout << my_sqrt(val) << endl;
	return 0;
}
