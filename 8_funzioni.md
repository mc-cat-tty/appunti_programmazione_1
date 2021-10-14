## Le funzioni

## Istruzioni composte
=> una istruzione composta è racchiusa tra parentesi graffe e viene genericamente chiamata *blocco*.

Istruzione composta = sequenza di istruzioni racchiuse tra parentesi graffe.
```
{
	<istruzione>
	<istruzione>
	...
}
```

Possono essere comprese anche istruzioni di definizione.

## Funzioni
Lo svantaggio di non usare funzioni è
	- replicazione del codice: difficile manutenzione e fixing di bug.
	- scarsa leggibilità: le funzioni permettono di dare un nome alle istruzioni composte.


## Cast implicito ed esplicito
Cast implicito -> `(int) n` => prendi conf di bit di n e leggila come se fosse un intero.
Cast esplicito -> `static_cast<int>(n)` => converti il numero contenuto in n e convertilo in un intero

## Significato funzioni
L'astrazione delle funzioni è disponibile in tutti i linguaggi ad alto livello. Una funzione è un costrutto che rispecchia l'astrazione matematica di funzione. Può avere molti parametri, ma UN SOLO valore di ritorno.

Permettono di dare un nome significativo ad un blocco di codice e richiamarlo nel programma.

## Elementi chiave
1. chiamata o invocazione della funzione: sospensione del programma corrente ed esecuzione delle istruzioni associate alla funzione. Ogni invocazione di una funzione corrisponde alla valutazoine di una espressione (funzione eseguita e risultato valutato).
2. dichiarazione o definizione

## Anatomia
TODO: inserisci definizione formale di funzione

### Intestazione
`<tipo-risultato> <nome-funzione> <lista-parametri-formali>`


Parametro formale = il valore passato all'invocazione viene inserito all'interno della variabile definita dal parametro formale.
Il valore di ritorno = il risultato della funzione ritorna un valore del tipo dichiarato.

### corpo
Istruzione composta che esegue istruzioni e ritorna un valore.

La parola chiave `return` permette di ritornare un valore.

## void
Le funzioni il cui valore di ritorno è `void` eseguono istruzioni, senza ritornare nulla.
Funzioni di questo tipo non possono essere inserite all'interno di espressioni.

Il `void` può essere usato anche all'interno della lista dei parametri formali: `void stampa_n_volte (void)`; equivale a non inserire niente all'interno delle parentesi.

## Procedure e funzioni
Procedura = funzione che non ritorna niente (funzione void in cpp).

## Parametri
- formali: variabile presente nella dichiarazione della funzione e utilizzabile dalle istruzioni della stessa.
- attuali: parametro che sto attualmente passando alla funzione.

## Esecuzione funzione
1. calcolo parameteri attuali
2. viene definito ogni parametri formale della funzione e inizializzato al valore del parametro formale
3. esecuzione funzione
4. se l'invocazione della funzione fa parte di un'espressione, la sua invocazione viene sostituita con il valore di ritorno della funzione stessa.

Ne deriva che ad ogni parametro formale deve corrispondere un parametro attuale (stesso numero di elementi)

## Funzione main()
Il main è una funzione al pari di tutte le altre. Il calcolatore cerca la funzione main per avviare il nostro programma (entry-point), esegue le istruzioni e recupera il valore di ritorno (intero) che viene chiamato exit-status, valutato dalla bash.

## Scope variabili
I parametri formali sono *oggetti locali* alla funzione (sia variabili che costanti). Allo stesso modo, le variabili/costanti dichiarate all'interno del corpo della funzione sono oggetti locali alla funzione.

Eg: `int ritorna_incremento(const int a) {...}`

I parametri costanti non sono modificabili all'interno del corpo della funzione.

TODO: fai esercitazione 6
