#include <iostream>
#include <cmath>

using namespace std;

int somma_quadrati(const int n, const int i) {
	int j, s;
	for (j = i; (s = i*i+j*j) < n; j++) ;
	// cout << "\t" << s << "\t" << i << "\t" << j << endl;
	return (s == n ? j : -1);
}

int main() {
	int n;
	int i, j;
	
	cout << "n: "; cin >> n;
	
	j = -1;
	for (i=1; i<=int(sqrt(n/2.0)) && j==-1; i++)  // i <= int(sqrt(n/2.0)) <==> i*i*2 <= n
		j = somma_quadrati(n, i);
	i--;	

	if (j != -1)
		cout << i << " " << j << endl;
	else
		cout << "Impossibile" << endl;
	
	return 0;
}
