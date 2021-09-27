#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int min, sec;
	cout << "Minuti? ";
	cin >> min;
	cout << "Secondi? ";
	cin >> sec;
	cout << "Equivalgono a " << min*60+sec << " secondi" << endl;
}

