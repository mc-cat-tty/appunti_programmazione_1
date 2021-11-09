#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int a;
	cin >> a;
	
	float b = float(a);
	
	int c = int(b);
	
	cout << setprecision(20) << a << " " << b << " " << c << endl;
}
