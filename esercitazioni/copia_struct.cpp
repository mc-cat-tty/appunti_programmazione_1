#include <iostream>

using namespace std;

struct point {
	int x;
	int y;
};

void stampa (point &p) {
	cout << p.x << " " << p.y << endl;
}

struct vect {
	int _[10];
};

void stampa(vect &v) {
	for (int i=0; i<10; i++)
		cout << v._[i] << " ";
	cout << endl;
	return;
}

int main() {
	point p1, p2;
	p1 = {1, 2};
	stampa(p1);
	stampa(p2);
	cout << endl;
	p2 = p1;
	stampa(p1);
	stampa(p2);
	cout << endl;
	
	vect v = {{1, 2, 3, 4, 5}};
	vect c;
	c = v;
	stampa(v);
	stampa(c);
}
