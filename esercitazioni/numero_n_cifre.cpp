#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;

// return random number in range [min, max]
int rand_in_range(int min, int max);

int main() {
	int num_cifre;
	cin >> num_cifre;
	
	int max_num = pow(10, num_cifre);
	// cout << max_num << endl;
	
	srand(time(NULL));
	cout << rand_in_range(1, max_num);
}

int rand_in_range(int min, int max) {
	return rand()%(max-min) + min;
}
