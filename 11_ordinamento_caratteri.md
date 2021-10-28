# Ordinamento
Ordine lessicografico: i caratteri sono ordinati e rispettano il seguente ordinamento. A seconda della codifica utilizzata posso avere ordinamenti differenti dei caratteri (ASCII e UNICODE hanno lo stesso ordinamento, perchè l'ultimo è estensione del primo).

eg: numeri < lettere maiuscole < lettere minuscole

## Casting
=> conversioni di tipo esplicite
Ricorda: il C è un linguaggio a tipizzazione forte, quindi il tipo di ogni variabile non cambia durante l'esecuzione del programma.
Esiste il *casting* o conversione esplicita, valido sia in C che in Cpp. Si effettua mettendo tra parentesi tonde il nuovo tipo di dato e  successivamente una espressione:
- cast `(<tipo_di_dest>)<espressione>`
- notazione funzionale `<tipo_di_dest>(<espressione>)`
- operatore _static_cast_ (solo Cpp) `static_cast<<tipo_dest>>(<espressione>)`

In tutti e tre i casi il valore dell'espressione viene convertito (interpretato in un certo modo) in <tipo_dest>

### Operatore static_cast
Perchè usare una notazione più pesante quando sono disponibili le altre due:
1. i cast sono highly dangerous
2. da utilizzare solo quando non si riesce a farne a meno (per non complicare il programma)
3. notazione pesante permette di notarlo di più
4. controllo più rigido da parte del compilatore

## cout
Stampa carattere o intero in base al tipo della variabile.

## cin
Conversione come sopra.
Esempio: se su stdin ho '1'
	cin >> (int)i; // in i trovo il valore 1
	cin >> (char)c; // in c trovo il valore corrispondente al carattere '1' secondo la codifica ASCII

### noskipws e skipws
Il comportamento di base del cin prevede che venga inserito almeno un carattere diverso da whitespace (tab, return, space...)

Con i modificatori `skipws` e `noskipws` posso alterare il comportamento di default.

cin continuerà comunque ad aspettarsi un invio (line feed) per confermare l'inserimento dei caratteri da stdin. -> *configurazione caninica* del terminale: è il terminale che invia i caratteri presenti su stdin solamente dopo aver premutoinvio. La configurazione non canonica è possibile, vedi `man termios`

## Operazioni sui char
Sono possibili tutte le operazioni viste fin'ora sugli int
