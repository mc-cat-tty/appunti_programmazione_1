# Costrutto for
Perchè introdurlo? è un'istruzione iterativa molto più espressiva di _while_ e _do ... while_, perchè riunisce in un unico posto la condizione, l'inizializzazione dell'indice e la sua modifica.

Infatti, ai costrutti _while_ e _do ... while_ manca un punto espliciti in cui inizializzare le variabili e un punto esplicito in cui inserire l'istruzione di modifica (all'interno dell'intestazione è presente solo la condizione).

## Sintassi
<istruzione-for> ::=
	for(<init>; <cond>; <istr_dopo_iter>)  // Intestazione del ciclo for
		<istruzione_corpo>

Dato che il linguaggio C++ permette la definizione di variabili in qualsiasi punto del main, può essere inserita un'istruzione di definizione come istruzione iniziale del costrutto for. L'ambito di visibilità della variabile si riduce al solo corpo del ciclo (insieme all'intestazione). Il tempo di vita della variabile coincide con la durata del ciclo.

## Espressioni composte
Richiedono l'utilizzo dell'espressione virgola (`,`)

Date le espressioni <espr1>, <espr2>, ..., <esprN> si può ottenere una _espressione composta_ concatenandole con l'operatore virgola: `<e1>, <e2>, ..., <eN>`. Le espressioni verranno valutate in maniera sequenziale e il valore dell'espressione composta sarà uguale a quello dell'ultima espressione valutata.

TODO: add esercizio della somma dei primi N numeri naturali

## Omissione istruzioni
Tutte le istruzioni presenti nell'intestazione del costrutto for possono essere omesse. Se manca la condizione, la si assume sempre vera.

## Cicli annidati
=> ciclo contenuto in un altro ciclo. Funziona con while, do ... while e for

TODO: link esercizi cicli annidati (da quadrato pieno)

## Modifica esecuzione iterazioni
Il *break* permette di uscire immediatamente da un ciclo. Il break fornisce un exit point dal ciclo (oltre alla valutazione della condizione); la maggiore flessibilità del programma potrebbe aumentarne la difficoltà, oltre a "violare" lo schema della programmazione strutturata (verso la logica spaghetti).

Il *continue* è utilizzabile solo in un ciclo e permette di saltare all'iterazione successiva.

