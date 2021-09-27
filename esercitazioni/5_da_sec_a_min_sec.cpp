#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int sec;
	cout << "Tempo in secondi? ";
	cin >> sec;
	cout << "Equivalgono a " << (int)sec/60 << " min, " << sec%60 << " sec" << endl;
}

