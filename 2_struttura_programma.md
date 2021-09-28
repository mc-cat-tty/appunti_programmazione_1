# Struttura semplificata di un programma

In prog1 vedremo solamente programmi contenuti in un unico file sorgente.

## Step compilazione
1. il file sorgente viene interpretato dal *pre-processore* e le direttive (iniziano con #) unwrappate
2. la nuova versione estesa del programma viene memorizzata in un file temporaneo
3. il file temporaneo passa per il compilatore

## Dichiarazione e definizione
Dichiarazione = istruzione in cui viene introdotto un nuovo *identificatore*

Definizione sottoinsieme di dichiarazione: allocazione spazio moemoria

## Struttura C
```
<direttive al pre-processore>
int main() {
	<dichiarazione>
	<dichiarazione>
	<dichiarazione>
	...
	<istruzione diversa da dichiarazione>
	<istruzione diversa da dichiarazione>
	<istruzione diversa da dichiarazione>
}
```

Vietate le dichiarazioni in mezzo al codice

## Struttura Cpp
```
<direttive al pre-processore>
int main() {
	<istruzione qualsiasi>
	<istruzione qualsiasi>
	<istruzione qualsiasi>
	...
}
```

## Funzione main
Funzione speciale, tre caratteristiche principali:
1. deve essere sempre presente
2. entry point del programma
3. dopo l'ultima istruzione del main il programma termina

## Problem solving
1. capire il problema
2. cercare idea risolutiva
3. definire l'algoritmo
4. testarlo su carta
5. implementarlo
6. testarlo
