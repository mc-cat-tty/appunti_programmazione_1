#include <iostream>
#include <fstream>

using namespace std;

struct partita_t {
	char nome[20];
	int tempo;
	int progresso;
};

void stampa(const partita_t &p) {
	cout << "Nome: " << p.nome << endl;
	cout << "Tempo: " << p.tempo << endl;
	cout << "Progresso: " << p.progresso << endl;
}

bool carica(partita_t &p, const char filename[]) {
	ifstream f(filename);
	if (!f)
		return false;
	f.read(reinterpret_cast<char *>(&p), sizeof(partita_t));
	f.close();
	return static_cast<bool>(f);
}

int main() {
	partita_t p1;
	carica(p1, "partita.dat");
	stampa(p1);
	return 0;
}
