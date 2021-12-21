#include <iostream>
#include <fstream>

using namespace std;

struct partita_t {
	char nome[20];
	int tempo;
	int progresso;
};

bool salva(const partita_t &p, const char filename[]) {
	ofstream f(filename);
	if (!f)
		return false;
	
	f.write(reinterpret_cast<const char *>(&p), sizeof(p));	

	f.close();
	return static_cast<bool>(f);
}

int main() {
	partita_t p1_g1 =
		{
			"Francesco",
			10,
			5
		};
	salva(p1_g1, "partita.dat");
	return 0;
}
