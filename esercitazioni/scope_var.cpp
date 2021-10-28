#include <iostream>

using namespace std;

int x = 100;

void fun(int n) {
	cout << "	[fun] x chiamante: " << n << " e x globale: " << x << endl;
	x++; cout << "	[fun] incremento" << endl;
	cout << "	[fun] x chiamante: " << n << " e x globale: " << x << endl;
	{
		int x = 1;
		cout << "	[fun] [blocco interno] x chiamante: " << n << " x blocco fun: " << x << endl;
		x++; cout << "	[fun] incremento" << endl; 
		cout << "	[fun] [blocco interno] x chiamante: " << n << " x blocco fun: " << x << endl;
	}
}

int main() {
	cout << "[main] x globale: " << x << endl;
	x++; cout << "[main] incremento" << endl;
	cout << "[main] x globale: " << x << endl;
	{
		int x = 5;
		cout << "[main] [blocco interno] x blocco main: " << x << endl;
		x++; cout << "[main] [blocco interno] incremento" << endl;
		cout << "[main] [blocco interno] x blocco main: " << x << endl;
		fun(x);
	}
	fun(x);
}
