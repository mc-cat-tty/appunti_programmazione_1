#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main() {
	while (true) {
		cout << time(0) << endl;
		system("sleep 1");		
	}
	return 0;
}
