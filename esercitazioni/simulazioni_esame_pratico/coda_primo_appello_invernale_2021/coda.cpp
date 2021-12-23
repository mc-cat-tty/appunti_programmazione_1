#include <iostream>
#include <fstream>

using namespace std;

const char FILENAME[] = "coda.txt";

typedef char user;

struct queue_t {
	user *users_v;  // array dinamico di utenti accodati
	int max_dim;  // dimensione dell'array
	int current_dim;  // numero di elementi nella coda
	int head;  // puntatore alla testa
	// Il puntatore alla coda è calcolato a partire da head
};

void inizializza(queue_t &q) {
	q.users_v = NULL;
	q.max_dim = q.current_dim = q.head = 0;
}

void reinizializza(queue_t &q, int new_dim) {
	if (new_dim != q.max_dim) {
		if (q.users_v != NULL) {  // se non si tratta della prima allocazione
			delete[] q.users_v;  // dealloca vecchia area di memoria
		}
		q.users_v = new user[new_dim];
		q.max_dim = new_dim;
	}
	q.current_dim = 0;  // perdo logicamente tutti i dati, in tutti i casi
	q.head = 0;  // tail e head punteranno allo stesso elemento inizialmente
}

int get_wrapped_tail(queue_t &q, int step) {  // step is positive (forward)
	// cout << q.head << " " << q.current_dim << " " << step << endl;
	return (q.head+q.current_dim+step)%q.max_dim;
}

int get_wrapped_head(queue_t &q, int step) {  // step is positive (forward)
	return (q.head+step)%q.max_dim;
}

bool check_service_code(char c) {
	if (c < 'A' || c > 'Z')
		return false;
	return true;
}

bool enqueue(queue_t &q, user c) {
	if (q.current_dim == q.max_dim || !check_service_code(c))
		return false;
	// cout << get_wrapped_tail(q, 0) << endl;
	q.users_v[get_wrapped_tail(q, 0)] = c;
	q.current_dim++;
	return true;
}

bool stampa_coda(queue_t &q, ostream &stream, bool on_file) {
	if (!stream)  // stream in stato di errore
		return false;

	if (on_file)
		stream
			<< q.max_dim << " "
			<< q.current_dim << " "
			<< q.head << endl;

	for (int i=0; i<q.current_dim; i++) {
		stream << q.users_v[get_wrapped_head(q, i)] << " ";
	}

	if (!on_file)
		stream << endl;
	return static_cast<bool>(stream);  // ritorno lo stato dello stream
}

bool carica_coda(queue_t &q, const char filename[]) {
	ifstream f(filename);
	if (!f)
		return false;

	int tmp;
	f >> tmp;  // max_dim
	// cout << tmp << endl;

	reinizializza(q, tmp);
	f >> tmp;  // current_dim
	int trash;
	f >> trash;
	// il puntatore a head non importa, posso inserire i vecchi elementi a partire dalla posizione 0
	// cout << tmp << endl;

	user u;
	for (int i=0; i<tmp; i++) {
		f >> u;
		enqueue(q, u);
	}

	f.close();
	return static_cast<bool>(f);
}

// ritorna l'ultimo elemento della coda (puntato da head)
bool dequeue(queue_t &q) {
	if (q.current_dim == 0)
		return false;
	q.head = get_wrapped_head(q, 1);
	q.current_dim--;
	return true;
}

bool servi_prossimo_utente(queue_t &q) {
	return dequeue(q);
}
/*
void swap(user *x, user *y) {
	user tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

bool anticipa_serivizio(queue_t &q, char c) {
	if (q.current_dim == 0 || !check_service_code(c))
		return false;

	for (int i=0; i<q.current_dim; i++) {
		if (q.users_v[i] == c)
			continue;
		for (int j=i+1; j<q.current_dim; j++) {
			if (q.users_v[j] == c) {
				cout << "scambio " << q.users_v[i] << " " << q.users_v[j] << endl;
				swap(q.users_v+i, q.users_v+j);
				break;
			}
		}
	}

	return true;
}*/

bool anticipa_serivizio(queue_t &q, char c) {
	if (q.current_dim == 0 || !check_service_code(c))
		return false;

	int last = 0;
	user *tmp_v = new user[q.current_dim];

	for (int i=0; i<q.current_dim; i++) {
		if (q.users_v[i] == c) {
			tmp_v[last++] = q.users_v[i];
			q.users_v[i] = 'x';  // marcato logicamente
		}
	}

	for (int i=0; i<q.current_dim; i++) {
		// sposto tutti i rimanenti caratteri validi in coda anticipata
		if (q.users_v[i] != 'x') {
			tmp_v[last++] = q.users_v[i];
		}
	}

	for (int i=0; i<q.current_dim; i++) {
		q.users_v[get_wrapped_head(q, i)] = tmp_v[i];
	}
	
	delete[] tmp_v;

	return true;
}

int main()
{
	const char menu[] =
		"1. Reinizializza coda\n"
		"2. Accoda utente\n"
		"3. Stampa coda\n"
		"4. Salva coda\n"
		"5. Carica coda\n"
		"6. Servi prossimo utente\n"
		"7. Anticipa servizio\n"
		"8. Esci\n";

	queue_t q;

	inizializza(q);

	while (true) {
		cout<<menu<<endl;
		int scelta;
		cin>>scelta;

		cout<<endl ; // per il corretto funzionamento del tester

		switch (scelta) {
		case 1:
		{
			int n;
			cout << "Nuova dimensione: "; cin >> n;
			reinizializza(q, n);
			break;
		}
		case 2:
		{
			user c;  // utente con codice c
			cout << "Codice utente: "; cin >> c;
			if (!enqueue(q, c)) {
				// cerr << "Errore nell'inserimento di un utente";
				// return 1;
				;
			}
			break;
		}
		case 3:
			stampa_coda(q, cout, false);
			break;
		case 4:
		{
			ofstream f(FILENAME);
			if (!stampa_coda(q, f, true)) {
				cerr << "Errore nella scrittura su file";
			}
			f.close();
			break;
		}
		case 5:
			if (!carica_coda(q, FILENAME))
				cerr << "Errore caricamento coda" << endl;
			break;
		case 6:
			if (!servi_prossimo_utente(q))
				cerr << "Errore nella rimozione di un utente" << endl;
			break;
		case 7:
		{
			char c;
			cout << "Servizio: "; cin >> c;
			if (!anticipa_serivizio(q, c))
				cerr << "Coda probabilmente vuota" << endl;
			break;
		}
		case 8:
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}

	return 1;
}
