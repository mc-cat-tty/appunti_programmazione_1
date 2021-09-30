# Programmazione strutturata

La prima tecnica utilizzata per fare *branching* è il salto:
	- jump (linguaggio macchina)
	- goto (alto livello)

Un salto all'indietro corrisponde ad un ciclo.

*Spaghetti code* = logica a spaghetti = aggrovigliamento del codice

## Programmazione strutturata
Introdotta da Dijkstra
TODO: completa (con i tre tipi)

## Macchina di Turing
Vantaggi:
	- programmi leggibili
	- facili da mantenere

Perdiamo qualcosa? No
Macchina di Turing: macchina dotata di testina che può leggere o scrivere (0 o 1) su un nastro che scorre avanti o indietro. Vedi Doodle.

Tesi di Church-Turing: ogni codice può essere eseguito da una macchina di Turing (Test di Turing)

Teorema di Jacopini-Boem: ogni algoritmo può essere tradotto in un programma se si ha a disposizione un linguaggio Turing-completo:
	- TODO: completa

## Costrutti condizionali
	- scelta semplice o alternativa
	- scelta multipla

### Scelta semplice
Consente di scegliere tra due istruzioni alternative in base al verificarsi di una condizione.

<istruzione-scelta> ::=
	if (<condizione>)
		<istruzione-1>
	[else
		<istruzione-2>]

### Digressione sullo 0
Lo zero non è nè positivo nè negativo.

n>0 è NON negativo

### Indentazione
=> utile per migliorare leggibilità, ma non essenziale. Servono le parentesi graffe (istruzione composta) per eseguire un blocco di istruzioni in un ramo dell'if/else

TODO: add link esercizi

## Sanificazione e controllo delle eccezioni
Operazione illegale -> CPU lancia hardware exception -> OS associa errore -> terminazione forzata del programma (overflow, non inizializzazione)

## Good programming choices
- No *numeri magici* -> no numeri senza nome -> usa costanti con nome
- Nomi significativi (self-explanatory)
- Non replicare il codice. Se un bug è contenuto in una replica, probabilmente anche le altre repliche lo contengono. Codice riusabile.

TODO: link a es velocità download + reimplementa a casa + multiplo.cc + ordinati.cc
