# Notazione posizionale
## Rappresentazione binaria
L'insieme dei possibili valori utilizzati da un calcolatore è {0, 1}; quindi la base è 2.

Numero: sequenza di cifre.

Cifra: simbolo che rappresenta un singolo numero.

Il valore della base-1 è il massimo valore assumibile da una cifra. Quindi la base rappresenta il numero di possibili cifre.

Notazione parentesi quadre, con cui si indica la base del numero, posto al pedice della parentesi.

## Base esadecimale
Base = 16.

Ogni cifra in base 16 rappresenta una possibile combinazione di 4 cifre in base 2.

Le cifre della base 10 vengono estese da A, B, C, D, E, F.

## Algoritmo di conversione
Il passaggio da una base all'altra è sempre possibile attraverso un algoritmo di conversione.

Prendiamo un numero natuale N memorizzato in memoria (non importa dove). L'elaboratore è in grado di eseguire calcoli su questo numero.
Data una qualsiasi base _b_, il valore dela cifra i-esima è dato da *(N/b^i)%b*

Ogni C++ literal è interpretato come un numero in base 10.

## Shifting
n\*2^i -> shifta a sx tutte le cifre del numero
n/2^i -> shifta a dx tutte le cifre del numero

TODO: link

## Complemento a 2
=> metodo per rappresentare i numeri negativi sulla macchina.

La prima soluzione potrebbe essere dedicare 1 bit per segnalare la presenza di segno positivo o negativo. Si sprecherebbe una configurazione (il valore zero resta invariato indipendentemente dal segno)

Quindi: utilizzo il primo bit per segnalare se il numero è negativo o positivo. Se il numero è negativo sommo una costante (2^N con N numero di bit disponibili).

I nuovi range diventano:
	- [0, 2^(N-1)-1]
	- [-2(N-1)]

Vantaggi:
	- una sola rappresentazione per lo zero: tutti i bit a 0

Gli interi in C++ sono rappresentati in complemento a 2.
