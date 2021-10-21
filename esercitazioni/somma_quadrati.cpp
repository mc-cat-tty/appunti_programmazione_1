#include <iostream>

using namespace std;

const int ricerca_j(const int n, const int i) {
	int j;
	for (j=i; j <= n-1 && i*i+j*j != n; j++);
	
	if (i*i+j*j == n)
		return j;
	return -1;
}

int main() {
	int n;
	cin >> n;
	for (int i=1, j; i <= n; i++) {
		j = ricerca_j(n, i);
		if (j != -1) {
			cout << "i:	" << i << " j: " << j << endl;
			return 0;
		}
	}
	return 1;
}
