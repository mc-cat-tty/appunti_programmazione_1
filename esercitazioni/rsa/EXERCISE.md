# Traccia dell'esercizio

Crittografia asimmetrica (RSA)

Dato un numero intero positivo N<r, esistono tre numeri interi positivi 
(e, d, r) tali che:
Cifratura   => 	C = (N^e) % r
Decifratura =>	N = (C^d) % r

La chiave di cifratura e' data dalla coppia di numeri interi positivi (e, r).
La chiave di decifratura e' data dalla coppia di numeri interi positivi (d, r).
Si puo' rappresentare sinteticamente una chiave (di cifratura/decifratura) con 
la terna (e, d, r).

L'algoritmo di costruzione delle chiavi e' il seguente:

1 generare due numeri primi distinti molto grandi p e q
2 calcolare r = p*q
3 calcolare f(r)=(p-1)*(q-1)
4 prendere un numero e<f(r) (meglio piccino) e primo con f(r)
  -> tale numero, insieme ad r, fornisce la chiave di cifratura
5 trovare un numero d tale che (d*e)%f(r) = 1
  -> tale numero, insieme ad r, fornisce la chiave di decifratura

Esempi di costruzione di chiavi

 p	 q	 r	 f(r)	 e	 d

 3	 5	 15	 8	 3	 11
 3	 5	 15	 8 	 5	 13
 2	 5	 10	 4	 3	 7
 17	 13	 221	 192	 11	 35
 19	 17	 323	 288	 5	 173

Alcune chiavi valide sono le seguenti:

(3, 11, 15) 	per cifrare/decifrare numeri interi positivi minori di 15
(5, 13, 15) 	per cifrare/decifrare numeri interi positivi minori di 15
(3, 7, 10)	per cifrare/decifrare numeri interi positivi minori di 10
(11, 35, 221)	per cifrare/decifrare numeri interi positivi minori di 221
(5, 173, 323)	per cifrare/decifrare numeri interi positivi minori di 323

------------------------------------------------------------------------

Nei  programmi  seguenti non  ci  si  occupa  della generazione  delle
chiavi,  ma  si  da  per   scontato  che  sia  giЃа  noto  quali  terne
costituiscono delle  chiavi valide!  In particolare  possiamo usare le
terne elencate sopra.

-------------------------------------------------------------------------

RSA intero

Traccia: Scrivere un programma che fornisca il seguente menu ed implementi le 
funzioni in esso elencate
	
	Chiave attualmente in uso: (5, 173, 323)
	1 Inserimento nuova chiave RSA
	2 Cifratura di un numero
	3 Decifratura di un numero
	4 Uscita

Il programma parte con la chiave predefinita (5, 173, 323). Se scegliamo di 
modificarla, il programma ci chiede di inserire una nuova terna di numeri.
Il programma non controlla se la nuova terna e' corretta o meno, sta a noi
assicurarci di fornire tre numeri corretti.
Se la chiave RSA e' corretta, il programma permette di cifrare/decifrare un 
numero. 
Realizzare la cifratura/decifratura all'interno di funzioni dedicate 
(quante ne occorrono?).
Memorizzare la terna in tre variabili globali.
Gestire le situazioni di errore, tranne, ovviamente, il controllo della
correttezza delle chiavi inserite.

(finito il programma, provare ad invertire l'uso della chiave di
cifratura con quella di decifratura ...)

Un possibile output e' il seguente:

        Chiave attualmente in uso: (5, 173, 323)

        1 Inserimento nuova chiave RSA
        2 Cifratura di un numero
        3 Decifratura di un numero
        4 Uscita
Scelta 2
Inserisci il numero da cifrare 123
Il numero cifrato e' 225

        Chiave attualmente in uso: (5, 173, 323)

        1 Inserimento nuova chiave RSA
        2 Cifratura di un numero
        3 Decifratura di un numero
        4 Uscita
Scelta 3
Inserisci il numero da decifrare 225
Il numero cifrato e' 123

-> Uno scheletro da cui partire e' nel file: rsa_intero_solo_menu.cc
-> Fare attenzione ai seguenti suggerimenti

----

Attenzione: l'elevamento a potenza e' una operazione che puo' 
portare ad overflow, perche' a^n puo' essere un numero enorme.
Dobbiamo, pertanto evitare un approccio del tipo:
. calcolo a^n
. dato il valore di a^n, calcolo il resto della divisione intera per r

Per evitare il problema, possiamo sfruttare la seguente proprieta':

		(a^n)%r = (   a  *  ( (a^(n-1))%r )  )%r

Sfruttando questa proprieta' si puo' realizzare sia una versione
ricorsiva che una versione iterativa del calcolo di (a^n)%r. Bisogna
cercare di mantenere limitato il valore calcolato in ciascuna
invocazione ricorsiva o iterazione.

Suggerimenti per la versione ricorsiva
Ad ogni passo ricorsivo, possiamo utilizzare il seguente schema:

1 dato il valore di a^(n-1), ne calcoliamo il resto della divisione intera per 
r (ottenendo un numero minore o uguale ad r)
2 moltiplichiamo il risultato per a
3 calcoliamo il resto della divisione intera per r (ottenendo, di nuovo, un 
numero minore di r)

Importante: se abbiamo fatto le cose per bene, potremmo accorgerci che
il calcolo del resto al passo 1 non e' necessario ...

Suggerimento per la versione iterativa:
PuЃт bastare esplicitare la precedente uguaglianza

	(a^1)%r = a%r

	(a^2)%r = ( a * (a%r) )%r

	(a^3)%r = ( a *  ((a^2)%r) )%r

	(a^4)%r = ( a *  ((a^3)%r) )%r

	...

Soluzione: Nel file rsa_intero.cc

------------------------------------------------------------------------------

RSA carattere

Scrivere un programma che fornisca il seguente menu e implementi le 
funzioni in esso elencate
	
	Chiave attualmente in uso: (5, 173, 323)
	1 Inserimento nuova chiave RSA
	2 Cifratura di un carattere
	3 Decifratura di un carattere
	4 Uscita

Il programma parte con la chiave predefinita (5, 173, 323). Se scegliamo di 
modificarla, il programma ci chiede di inserire una nuova terna di numeri.
Il programma non controlla se la nuova terna e' corretta o meno, sta a noi
assicurarci di fornire tre numeri corretti.
Se la chiave RSA e' corretta, il programma permette di cifrare/decifrare un 
carattere. 
Gestire le situazioni di errore, tranne, ovviamente, il controllo della
correttezza delle chiavi inserite.

        Chiave attualmente in uso: (5, 173, 323)

        1 Cambiamento chiave RSA
        2 Cifratura di un carattere
        3 Decifratura di un carattere
        4 Uscita
Scelta 2
Inserisci il carattere da cifrare c
Il carattere cifrato vale 131

        Chiave attualmente in uso: (5, 173, 323)

        1 Cambiamento chiave RSA
        2 Cifratura di un carattere
        3 Decifratura di un carattere
        4 Uscita
Scelta 3
Inserisci il numero da decifrare come carattere 131
Il carattere decifrato e' c

        Chiave attualmente in uso: (5, 173, 323)

        1 Cambiamento chiave RSA
        2 Cifratura di un carattere
        3 Decifratura di un carattere
        4 Uscita

------------------------------------------------------------------------------

Generazione chiavi RSA

Implementare l'algoritmo di generazione delle chiavi. In particolare
scrivere un programma che prende in ingresso il valore massimo e
minimo che possono assumere i due numeri primi iniziali.

Puo' tornarvi utile la funzione di libreria rand(), che genera un
numero casuale compreso tra 0 e RAND_MAX, ove RAND_MAX и una costante
predefinita (di cui quindi non si puт cambiare il valore).  Essa
permette di generare una sequenza di numeri pseudocasuali.  Tali
numeri si definiscono pseudocasuali perche', fissato il primo valore
della sequenza (chiamato seme), e' fissata tutta la sequenza di valori
che saranno generati nelle successive invocazioni della funzione
rand().  Infatti i numeri sono generati mediante una certa funzione
f(x) che, dato l'ultimo valore x generato, genera il prossimo valore
random.  Facciamo un esempio: supponiamo di aver dato come seme il
valore 1. Allora il primo valore generato dalla funzione rand() sara†ў
41 (se la funzione rand() sulla vostra macchina e' basata sullo stesso
algoritmo della funzione sulla mia macchina). La prossima volta che
verra' invocata la funzione rand() si otterra' il valore f(41), che e'
pari a 18647. Alla successiva invocazione si otterra' il valore di
f(18647), che e' pari a 6334, e cosi' via.  Pertanto, per ottenere
sequenze diverse, bisogna cambiare il valore del seme. Per cambiare il
valore del seme, si utilizza la funzione srand(n), ove n e' il nuovo
valore che si vuol dare al seme.

Per utilizzare le funzioni rand() ed srand(n) (e la costante
RAND_MAX), bisogna includere il file di intestazione "cstdlib".
