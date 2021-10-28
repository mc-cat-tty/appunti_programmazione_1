#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	n<0 ? n=0 : 0;  // 0 corrisponde ad una nop
	n>10 ? n=10 : 0;
	cout << n << endl;
}
