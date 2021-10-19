# Tipi di dato

## Operatore sizeof(<espressione>)
Ritorna la dimensione (in byte) di un tipo di dato oppure di un espressione (dato stesso, variabile, espressione numerica, confronto). Se viene passata un'espressione, la funzione ritorna il numero max di bytes, e di conseguenza di `char`, necessari per memorizzare tutti i possibili valori dell'espressione stessa.

### Dimensione interi
Dato che la dimensione di un tipo di dato è platform-dependent, d'ora in poi ragioneremo sui risultati ottenuti dalla nostra (mia) macchina. `sizeof(int) == 4`, per cui un interno è memorizzato su 4\*8=32 bit di memoria. Il tipo di dato `int` potrà quindi contenere i valori nell'intervallo [-2^(8\*4-1), 2^(8\*4-1)-1] = [-2147483648, 2147483647]

TODO: vedi esercizio numero bytes oggetto int

## Overflow
=> se superiamo i valori limite. Viene chiamato *overflow* se si supera il limite superiore, *underflow* altrimenti.

Quando il risultato di un'espressione è troppo grande o troppo piccolo per essere contenuto nel tipo di dato del risultato (o nell'oggetto a cui si vuole assegnare tale valore). Non vengono sollevati errori (overflow flag ALU (?)) dal SO, quindi il processo non viene abortito; si va però incontro ad un errore logico, in quanto il risultato dell'espressione non è correlato con l'operazione effettuata.

Eg: `i=2147483647; i++; i == -2147483648`
Perchè (*in questo caso*) il dato è rappresentato come segue: <1 bit segno><8\*n-1 bit valore (assoluto)>. Dal test precedente possiamo dedurre che `n` vale 4 byte.

### Check
Supponendo l'operazione `int a, b; int x = a+b`, la variabile x andrà in:
- *overflow* se _INT_MAX-b<a_
- *underflow* se _INT_MIN-b>a_

TODO: link esercizio check overflow di somma e moltiplicazione
