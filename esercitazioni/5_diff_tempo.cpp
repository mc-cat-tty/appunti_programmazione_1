#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int min1, sec1, min2, sec2;
	cout << "Minuti e secondi primo tempo? ";
	cin >> min1 >> sec1;
	cout << "Minuti e secondi secondo tempo? ";
	cin >> min2 >> sec2;
	int res = abs(min1*60+sec1-(min2*60+sec2));
	cout << "Differenza (sec): " << res << endl;
	cout << "Differenza (min sec): " << (int)res/60 << " " <<  res%60 << endl;
}

