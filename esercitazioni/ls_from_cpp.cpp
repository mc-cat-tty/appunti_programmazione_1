#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	int status;
	status = system("ls");
	cout << "ho finito" << endl;
	return status;
}
