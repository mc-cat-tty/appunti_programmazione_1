#include <iostream>

using namespace std;

void moltiplica(int&, int);

int main() {	
	int x, y;
	cin >> x >> y;
	moltiplica(x, y);
	cout << x;
	return 0;
}

void moltiplica(int &a, int n) {
	a *= n;
}
