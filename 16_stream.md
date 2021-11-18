# Stream

## Input stream

Definizioni:
	- stream: sequenza di caratteri
	- istream: meccanismo per convertire sequenze di caratteri in valori di vari tipi (input stream)
	- cin -> standard istream. Appartiene al namespace std


L'istream viene riempito dal SO con una sequenza di caratteri. Il suo contenuto viene passato al programma dal SO (bash) quando riceve in ingresso un linefeed (se in modalità standard)

### Input formattato
=> quando i caratteri inseriti vengono interpretati in modo contestuale alla variabile che ospiterà il suddetto dato

I whitespaces vengono scartati. Utilizzati solo come separatori tra i vari token (a meno che non venga utilizzato il manipolatore no-skip-whitespaces)

### Stream state
Ciascun I/O stream ha un proprio stato: insieme di flag (valori booleani) che indicano lo stato delllo stream. Ogni operazione che fallisce porta lo stream ad uno stato di errore.

### EOF
La condizione che causa il fallimento in lettura e porta lo stream in uno stato di errore è la lettura del marcatore EOF - End Of File -
=> Questo segnale può essere passato premendo Ctrl-D su una riga vuota (mondo UNIX)

Utilizzato per chiudere terminale

### Wrong format
Quando l'istream non riesce a convertire i dati passati in modo da salvarli nella variabile passata.

### Gestione errori
Una operazione di input che fallisce è un'operazione nulla:
	- Negli standard precedenti a C++11 lo stream di input non viene toccato. Il valore della variabile a cui doveva essere assegnato il dato resta invariato.
	- Negi standard successivi a C++11 viene assegnato il valore 0, declinato al tipo di dato passato (0, 0.0, carattere nullo...)

Lo stato dello stream può essere verificato con un if. cin ritorna true (valore diverso da zero) se lo stream non entra in stato di errore. false (zero) altrimenti (formato input errato o fine lettura a causa EOF)

### Esempi controllo stato cin
```
if (!(cin >> i))
	cout << "stato errore"
```

```
while (!(cin >> i)) {...}  // attende valore valido
```

### Funzioni membro cin

Se f è un io stream posso invocare funzioni membro con l'operatore punto.
Esempi:
	- `cin.clear()` -> riporta lo stream in condizione "buona". Pulisco contenuto stream e flag. cin può essere riutilizzato.
	- accesso ai flag. Vedi [reference](https://en.cppreference.com/w/cpp/io/basic_istream)

// TODO link to leggi_numeri.cpp


Posso verificare se è stato raggiunto l'EOF con `cin.eof()` -> funzione membro che ritorna true se è stato consumato il carattere EOF.

Una volta che cin entra in uno stato di errore non può più essere riutilizzato a meno che non venga "ripulito"

## Output stream
=> sono sempre stream (sequenze di caratteri) che convertono tali sequenze in valori human readable in base al tipo di variabile passata

Standard output stream: cout
Standard error stream: cerr
=> entrambi appartengono al namespace std

Es: `cout << 'a'` -> a basso livello viene mandato il byte 97, che rappresenta la lettere 'a' secondo la codifica ASCII

La shell, prima di far partire il programma, aggancia lo stdout del processo ad un oggetto speciale del sistema operativo. Attraverso questo oggetto la shell legge i caratteri da stampare (passati dal programma)

Gli stream di I/O entrano in uno stato bloccato finchè o non si preme un tasto da passare su cin o non si invia endl/\r/si fa un flush

Tutto va bene quando editor, compilatore e terminale utilizzano tuti la stessa codifica (solitamente ASCII a 7 bit), in altri casi potrebbe essere usata una codifica differente (per esempio, potrebbero non essere rappresentate le lettere accentate).

### Esempio
`cout << 12` passa il carattere '1' e il carattere '2' alla shell

### Note
Ogni volta eseguo un cin consumo un carattere dalla coda interna allo stream.

Se il terminale si trova il modalità canonica i caratteri inseriti nella coda vengono passati solamente quando viene inserito un linefeed

La cin si blocca solamente in attesa dell'inserimento di un carattere

Eg: `char a; cin >> a;` con inserimento di "Ciao\n" su stdin -> consumo solo il carattere 'C'. Tutto il resto, compreso '\n' resta nel buffer di cin

### Rimuovere caratteri da stdin
`cin.ignore()` -> getta via i caratteri presenti sul buffer di stdin

```
while (!(cin >> n)) {  // ATTENZIONE: non esco neanche con EOF
	cin.clear();
	cin.ignore();
	cout << "Immetti un numero valido: ";
}
```

Eliminazione riga: svuotare l'istream fino al prossimo newline -> `cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');`

Utilizza controllo su eof per ritornare dal programma se necessario.

## Bufferizzazione in uscita
Abbiamo già utilizzato `fflush(stdout)`

L'operatore `<<` su stdout non spedisce immediatamente lo stream di caratteri su stdout. Dato che l'operazione di scrittura è costosa, cout aspetta di riempire il buffer prima di scrivere su stdout. Solitamente cout è configurato per inviare sullo stdout una riga alla volta; quando incontra '\n' il buffer viene svuotato sul terminale.

L'operazione di scrittura di un'intera stringa costa quanto la scrittura di un solo carattere.

### Operazione di bufferizzazione
=> la memoria RAM (memoria tampone) viene utilizzata per rendere più efficienti le operazioni di I/O

Eg: durante il download di un file i dati vengono memorizzati temporanemente sulla RAM e scritti a blocchi (se il file è di grandi dimensioni) oppure il fiele viene scritto direttamente una volta completato il download in RAM. Questo avviene perchè la velocità di download è maggiore di quella di scrittura (vedi connessioni 50kb)

TODO: link buffer_stdout.cpp -> 'ciao' non viene stampato perchè il buffer di output non viene svuotato. Terminando il programma in modo naturale il buffer di output viene svuotato. Se il processo è killato dal SO no.

Il buffer di output è statico (implementato con buffer circolare): possono essere memorizzati solo x caratteri. Quando si raggiunge la dimensione del buffer il buffer viene svuotato.

TODO: link buffer_stdout_full.cpp

## Sincornizzazione cin/cout
Prima di ogni `cin` il buffer di output viene svuotato (no necessità di endl o simili). L'utente deve visualizzare il messaggio in out prima di inserire un input

TODO: allega buffer_out_sinc.cpp

## flush
Comando che forza il buffer di output ad essere svuotato sul terminale: `std::flush(ostream& os)`

## Creazione di stream
=> per scrivere su file
I seguenti stream sono definiti in `<fstream>` e possono essere utilizzati per scrivere e leggere su file:
	- ifstream
	- ofstream

Un file è visto come sequenza di byte.

Un io stream viene associato ad un file mediante un'operazione chiamata apertura del file. Gli stessi operatori utilizzati per cin e cout possono essere usati per scrivere e leggere su file.

Per aprire un file è necessario indicare il percorso del file:
	- relativo (alla cartella di lavoro)
	- assoluto (rispetto alla radice)
	- solo nome file -> cartella di lavoro

Spesso può accadere che l'apertura di un file non vada a buon fine (apertura in lettura di un file con soli permessi di lettura, file già aperto ecc.)

```
ifstream f("percorso_file");  // oppure ofstream f("...") per scrittura
if (!f) cerr << "apertura fallita" << endl;
```

Come per gli operatori cin e cout è possibile controllare lo stato dello stream associato ad un file

WARNING: l'apertura di un file in lettura comporta il troncamento se il file esiste già o la creazione di un nuovo file se non esiste.

Oppure `fstream("nome_file", ios_base::in)` e `fstream("nome_file", ios_base::out)`

I file possono essere aperti anche il "lettoscrittura".

Lo stato di un fstream può essere controllato con i soliti flag. È utile verificare, per esempio, se una scrittura sia andata a buon fine o meno. Anche la scrittura formattata è consentita (di default).

Altra possibilità: lettura e scrittura non formattata -> dati grezzi in binario

### Accesso a file
L'accesso ai file è sequenziale, posso leggere e scrivere solamente agendo sul byte successivo a quello puntato dal puntatore.

Un file può essere aperto anche con la funzione `open()`

TODO: link in_out_redirect.cpp in_outfile.cpp

WARNING: ricorda di chiudere il file per essere sicuro che tutto venga scritto (buffer svuotato): `f.close()`
Al momento del return avverrebbe la chiusura implicita del file, ma se il programma viene terminato in modo forzato dal SO non è detto che il buffer venga svuotato.

TODO: link write_read_file.cpp

TODO: esercizio. Copia di un file con programma C

### Modalità append
È possibile aprire un file in scrittura evitando il troncamento. Uso modalità append. Quello che scrivo viene messo in coda al file, senza sovrascrivere i byte già presenti.

```
ofstream f("nome_file", ios_base::app);
```

TODO: scrivi_leggi_array_fomattato.cpp (vedi cartella FTP)
TODO: leggi da file una sequenza di interi di al più 100 ele finchè non se ne trova uno uguale a 0...
TODO: fai esercizi da questo punto in poi

### Passaggio stream come argomenti
`void fun(istream &cin, ostream &cout);`
-> posso passsare sia cin e cout che due filestream di input/output

Questo mi permette di creare funzioni che scrivono/leggono su stream
