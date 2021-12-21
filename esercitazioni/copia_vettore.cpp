#include <iostream>

using namespace std;

void copia_vett(const int* const src, int n, int* &dst) {
	dst = new int[n];
	for (int i=0; i<n; i++)
		dst[i] = src[i];
	return;
}

int main() {
	const int a[3] = {1, 2, 3};
	int* b = NULL;
	copia_vett(a, 3, b);
	for (int i=0; i<3; i++)
		cout << b[i] << " ";
	cout << endl;
	delete[] b;
	return 0;
}
