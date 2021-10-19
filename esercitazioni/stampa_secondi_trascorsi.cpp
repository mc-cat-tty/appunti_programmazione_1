#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main() {
	int start_time, sec = 0, sec_max = 10;
	// cout << "Numero massimo di secondi da attendere: ";
	// cin >> sec_max;
	start_time = time(0);
	while (sec<sec_max) {
		system("sleep 1");
		sec = time(0)-start_time;
		cout << "\r" << sec << flush;
	}
	cout << endl;
	return 0;
}
