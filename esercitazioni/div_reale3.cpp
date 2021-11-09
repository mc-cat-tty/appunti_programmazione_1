#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int a, b;
	double a_real;
	
	cout << "[a/b] -> inserisci a: "; cin >> a;
	cout << "[a/b] -> inserisci b: "; cin >> b;
	a_real = a;
	cout << setprecision(15) << a_real/b << endl;	
	return 0;
}
