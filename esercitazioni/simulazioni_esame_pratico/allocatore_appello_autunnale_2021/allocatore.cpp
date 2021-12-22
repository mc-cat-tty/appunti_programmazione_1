#include <iostream>
#include <fstream>

using namespace std;

struct block_t {
	int pos;
	int dim;
};

struct mem_t {
	block_t *block_v;
	int current_dim;
	int max_dim;
};


void inizializza_memoria(mem_t &m) {
	m.block_v = NULL;
	m.current_dim = 0;
	m.max_dim = 0;
}

void reinizializza_memoria(mem_t &m, int size) {
	if (m.max_dim != size) {
		delete[] m.block_v;
		m.block_v = new block_t[size];
		m.max_dim = size;
	}
	m.current_dim = 0;
}

void stampa_memoria(const mem_t &m) {
	for (int i=0; i<m.max_dim; i++) {
		cout << i%10;
	}
	cout << endl;
	
	int prossimo_blocco;
	int dimensioni;
	int posizione_corrente = 0;
	for (int i=0; i<m.current_dim; i++) {
		prossimo_blocco = m.block_v[i].pos;
		dimensioni = m.block_v[i].dim;
		for (; posizione_corrente<prossimo_blocco; posizione_corrente++)
			cout << "-";
		for (; posizione_corrente<prossimo_blocco+dimensioni; posizione_corrente++)
			cout << "*";
	}
	for (; posizione_corrente<m.max_dim; posizione_corrente++)
		cout << "-";
	cout << endl;
	return;
}

bool sposta_avanti(mem_t &m, int i, int steps) {
	if (i != m.current_dim-1 && m.block_v[i+1].pos-(m.block_v[i].pos+m.block_v[i].dim >= steps))
		return false;
	m.block_v[i].pos += steps;
	return true;
}

bool alloca_oggetto(mem_t &m, int pos, int dim, bool shifta) {
	if (m.current_dim >= m.max_dim || pos+dim > m.max_dim || dim == 0 || pos >= m.max_dim)
		return false;
	
	// cout << "superata la marea di controlli";
	
	int i;
	for (i = 0; i < m.current_dim; i++) {
		if (m.block_v[i].pos <= pos && m.block_v[i].pos+m.block_v[i].dim-1 >= pos) {
			if (shifta && sposta_avanti(m, i, pos-m.block_v[i].pos+dim))  // se lo spazio per spostare il blocco successivo c'è
				break;  // si procede all'inserimento
			return false;  // mentre se la posizione già occupata e non si vuole shiftare si fallisce
		}
		if (pos < m.block_v[i].pos) {
			if ( (m.block_v[i].pos > pos + dim - 1) 
				  || (shifta && sposta_avanti(m, i, pos+dim-m.block_v[i].pos))
				)
				break;  // lo spazio per l'allocazione è sufficiente. il blocco va inserito in posizioe i per mantenere la lista ordinata
			else
				return false;
		}
	}

	// cout << "Trovato il successivo";

	if (m.current_dim+1 >= m.max_dim)
		return false;
	for (int j=m.current_dim-1; j>=i; j--) {
		m.block_v[j+1].pos = m.block_v[j].pos;
		m.block_v[j+1].dim = m.block_v[j].dim;
	}
	m.block_v[i].pos = pos;
	m.block_v[i].dim = dim;
	m.current_dim++;
	return true;
}

bool salva_memoria(mem_t &m, const char fn[]) {
	ofstream f_out(fn);
	if (!f_out)
		return false;
	
	f_out.write(reinterpret_cast<char *>(&(m.max_dim)), sizeof(int)*1);
	f_out.write(reinterpret_cast<char *>(&(m.current_dim)), sizeof(int)*1);
	f_out.write(reinterpret_cast<char *>(m.block_v), sizeof(block_t)*m.current_dim);
	
	f_out.close();
	return static_cast<bool>(f_out);
}

bool carica_memoria(mem_t &m, const char fn[]) {
	ifstream f_in(fn);
	if (!f_in)
		return false;

	f_in.read(reinterpret_cast<char *>(&(m.max_dim)), sizeof(int)*1);
	// cout << m.max_dim << endl;
	reinizializza_memoria(m, m.max_dim);
	f_in.read(reinterpret_cast<char *>(&(m.current_dim)), sizeof(int)*1);
	// cout << m.current_dim << endl;
	m.block_v = new block_t[m.current_dim];
	f_in.read(reinterpret_cast<char *>(m.block_v), sizeof(block_t)*m.current_dim);

	f_in.close();
	return static_cast<bool>(f_in);
}

int main()
{
	const char menu[] =
		"1. Reinizializza memoria\n"
		"2. Stampa memoria\n"
		"3. Alloca oggetto\n"
		"4. Salva memoria\n"
		"5. Carica memoria\n"
		"6. Alloca oggetto 2\n"
		"7. Esci\n";

	mem_t mem;
	int n;
	int p, d;

	const char filename[] = "memoria.dat";

	inizializza_memoria(mem);

	while (true) {
		cout<<menu<<endl;
		int scelta;
		cin>>scelta;

		cout<<endl ; // per il corretto funzionamento del tester

		switch (scelta) {
		case 1:
			cout << "Dimensione della memoria: "; cin >> n;
			reinizializza_memoria(mem, n);
			break;
		case 2:
			stampa_memoria(mem);
			break;
		case 3:
			cout << "Posizione: "; cin >> p;
			cout << "Dimensione: "; cin >> d;
			alloca_oggetto(mem, p, d, false);
			break;
		case 4:
			salva_memoria(mem, filename);
			break;
		case 5:
			carica_memoria(mem, filename);
			break;
		case 6:
			cout << "Posizione: "; cin >> p;
			cout << "Dimensione: "; cin >> d;
			alloca_oggetto(mem, p, d, true);
			break;
		case 7:
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}

	return 1;
}
