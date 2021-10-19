#include <iostream>

using namespace std;

int main() {
	int n, s = 0;
	cout << "Numero N: ";
	cin >> n;
	for (int i=1; i<=n; s+=i, i++) ;
	cout << s << endl;
	return 0;
}
