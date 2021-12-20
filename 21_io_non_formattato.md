# Input Output non formattato
Fino ad ora abbiamo visto I/O formattato => gli operatori `<<` e `>>` stampano o prendono in input su uno stream sequenze di caratteri

Esistono anche operazioni di i/o non formattate che operano su sequenze di byte -> trasferimento di byte da uno stream alla memoria o dalla memoria allo stream

Ogni volta che faccio lettura o scrittura in modalità non formattata agisco in modo sequenziale sulla memoria

Le funzioni di lettura e scrittura non formattate sono *funzioni membro* degli stream -> per invocarle si usa l'operatore punto

## Buffer
Un buffer è un array di byte utilizzato per operazioni di I/O

Il tipo char ha esattamente la dimensioni di un byte -> tipo di dato utilizzato per operazioni di I/O non formattato

## Funzioni membro degli istream
- get() - ritorna il valore del prossimo byte nello stream di ingresso (intero).
	```
	int i;
	while ( (i = cin.get()) != EOF ) { ... }
	```
- get(char &c) - preleva un byte dallo stdin e lo assegna alla variabile (tipo carattere) passata in ingresso. Nel caso in cui venisse incontrato EOF `c` rimane invariata e il metodo riorna false.
	```
	char c;
	while (cin.get(c)) { ... }
	```
- get(char \*buf, int n, [char delimitatore]) - Legge una sequenza di byte dallo stdin e la copia in buf. Aggiunge automaticamente '\0' alla fine. La lettura va avanti finchè non si sono letti n byte OPPURE finchè non si incontra '\n' (delimitatore di default). L'istream viene messo in stato di errore se la riga è vuota oppure incontra il '\n' da solo (vedi dopo).
- peek() - ritorna il valore del prossimo byte presente su un istream senza consumare il carattere -> può essere utile per evitare lo stato di errore dell'istream
	```
	char *riga;
	while (cin.peek() == '\n') ;  // pulisco righe vuote
	cin.get(riga, MAXLEN);
	cin.get();  // butto via '\n' 
	```
- read(char \*buf, int n) - funzione di più basso livello rispetto a get(). Non aggiunge delimitatore e non va in stato di errore. Il delimitatore non esiste. read() cerca di leggere esattamente n bytes, e ritorna il valore effettivamente letto.

// TODO: link file_conta_linee.cpp

## Funzioni membro degli ostream
- put(char c) - equivalente della get
- write(char \*buf, int n) - equivalente di read()

## File di testo e binari
I file binari memorizzano i dati "grezzi" provenienti dalla memoria -> sono una sequenza di byte (numeri)

Un file è una sequenza di byte a cui è associato un nome

## Puntatori ed array
Sappiamo che `<tipo> *` memorizza un puntatore. Si può passare un array al posto di `<tipo> *` il nome di un array, perchè esso corrisponde all'indirizzo del primo elemento.

Il tipo char * memorizza indirizzi di qualunque tipo di variabile -> qualunque tipo di dato è convertibile in un array di caratteri

```
reinterpreter_cast<char *>(<indirizzo_oggetto>);  // reinterpreta l'oggetto come se fosse un array di caratteri
```

Una sequenza di byte equivale ad un array di byte. Un array di byte è interpretabile come un array di caratteri. Quindi ogni tipo di dato può essere considerato un array di caratteri.

Rimane da capire come determinare la dimensione di un oggetto: uso `sizeof(<tipo_dato>)`
Oppure nel caso in cui sia un array: `sizeof(<tipo_dato>)*<numero_elementi>`

```
int a[] = {1, 2, 3};
of.write(reinterpreter_cast<char*>(a), sizeof(a[0])*3);
```

La dimensione finale del file sarà di esattamente 12 byte

### Numeri reali e memoria
Memorizzando un numero reale con questo metodo posso mantenere tutti i byte salvati in memoria evitando troncamenti

// TODO: link scrivi_leggi_array.cpp
// TODO: link studente_su_file.cpp

## File di testo
Per leggere e scrivere file di testo si usano tipicamente le scritture formattate perchè ogni byte equivale ad un char

## Efficienza
Le letture e scritture formattate possono essere effettuate mediante cicli for, perchè gli stream memorizzano un i dati in un buffer prima di eseguire la scrittura

Le letture e scrutture non formattate sono inefficienti se effettuate mediante cicli, perchè non vene interposto un buffer tra la scruttura e la memoria.

## Puntatori e alias
W: puntatori e alias ad una variabile sono estremamente diversi. Quando utilizzo un alias il valore e l'indirizzo di alias e variabile rimangono uguali.

## Dereferenziazione
Per ottenere l'indirizzo di una variabilie che non sia un array si utilizza l'operatore `&`, che dereferenzia (prende l'indirizzo) della variabile alla quale è applicato

### Sintassi
```
& <identificatore_oggetto>
```

### Semantica
Ritorna l'indirizzo dell'oggetto

// TODO: vedi es per casa (x2)

## Accesso sequenziale e casuale
Quando opero sui file posso accedere in modo casuale al file (non sequenziale). Questo non è possibile con gli stream.
Quando accedo in modo "randomico" ad un file posso decidere arbitrariamente dove leggere o scrivere.
Sugli stream è possibile solamente l'accesso sequenziale.

Il byte a partire da quale avverrà la prossima operazione è dato da un contatore che parte da 0. Il suo valore può essere modificato con queste funzioni:

```
seekg(nuovo_valore);  // sposto la testina per un file di input (g sta per get)
seekp(nuovo_valore);  // sposto la testina per un file di output (p sta per put)
```

Le due funzioni possono essere invocate con due argomenti:
```
seekg(offset, origine);
seekp(offset, origine);
```

Dove `origine` può essere:
- `ios::beg` (argomento default del secondo parametro)
- `ios::end` (parto dalla fine andando all'indietro)
