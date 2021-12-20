# Traduttori e compilatori
Un algoritmo è utile se esiste un _esecutore_ in grado di eseguirilo.

Un esecutore viene chiamato _automa esecutore_ -> deve essere in grado di eseguire una codifica dell'algoritmo

Gli automi venivano realizzati con congegni meccanici (Pascal - pascalina, Babbage) o implementati attraverso un modello matematico (modello funzionale - Hilbert, modello ... - Turing)

## Macchina virtuale
=> automa esecutore in grado di eseguire un programma C/C++ (o un qualsiasi altro linguaggio di programmazione) senza che esista una macchina reale
=> gira sulla macchina reale (processore) -> linguaggio macchina: sequenza di 0 e 1 -> operazioni elementari

## Linguaggio assembly
Linguaggio di basso livello in grado di essere tradotto 1:1 in linguaggio macchina

Non esiste il concetto di memoria/variabili, ma sono utilizzabili solamente i registri (cella di memoria interna al processore)

Le istruzioni sono parole mnemoniche che identificano una precisa sequenza di 0 e 1 intepretabile dalla CPU

## Problema della portabilittà
Il linguaggio macchina è il linguaggio di un processore, strettamente dipendente dall'instruction set della CPU -> il codice assembly non è portabile

Eg: Istruction Set x64 risolve parzialmente questo problema, perchè permette di utilizzare lo stesso codice per una famiglia di CPU
Ma se utilizzo una istruzione specifica di una CPU (oppure disponibile da una certa versione in poi) il programma non è più portabile

## Scelta del linguaggio macchina
È una buona scelta codificare un algoritmo in linguaggio macchina?
 - sì se devo utilizzare il programma su una sola architettura
 - no se devo rendere il codice portabile

## Livello di astrazione
C/C++ sono linguaggi di alto livello perchè si basano su un elaboratore ipotetico in grado di eseguire delle istruzioni che non appartengono ad un processore reale

Un linguaggio di alto livello è più vicino al linguaggio naturale, quindi mette a disposizione istruzioni e strutture dati più vicine al dominio del problema

L'esistenza di svariati linguaggi di programmazione

## Processo di traduzione
I traduttori trasformano il linguaggio sorgente in linguaggio macchina

2 tipi di traduttori:
- compilatori: genera un file eseguibile contenente tutto il programma. Non esegue il programma. Si dice che il compilatore *traduce* ogni istruzione.
- interpreti: esegue direttamente il codice sorgente senza generare un file eseguibile. Esegue una istruzione alla volta. Si dice che l'interprete *valuta* ogni istruzione.

## Programmi intepretati e compilati
Tipicamente i programmi compilati girano più velocemente dei programmi interpretati

I programma interpretati sono più portabili dei programmi scritti con un linguaggio compilato

Questa differenza si sta appiattendo sempre di più

## Programmi compilati
Gli header file spesso contengono solo delle dichiarazione

Linking del codice macchina delle funzioni messe a disposizione dalla libreria già compilata. Vengono messi a disposizione gli headerfile contenenti solamente le dichiarazioni e i prototipi delle funzioni

### Link delle librerie
A volte il complilatore non trova il percorso di una libreria: bisogna usare il flag `-lm`

### Fasi compilazione
- preprocessing -> esecuzione delle direttive al precompilatore (eg: gli include copiano e incollano pari pari gli headerfile importati, i define vengono risolti sostituendo il valore associato al simbolo)
- traduzione -> genera un file oggetto (file contenente il linguaggio macchina)
- linking -> si unisce il file oggetto (tipicamente _.o_) con il programma appena compilato. Si ottiene un file eseguibile.

## Fasi di sviluppo
1. progettazione
2. scrittura (codifica)
3. compilazione
4. esecuzione
5. collaudo (testing)
6. ricerca ed eliminazione degli errorri (debugging)

### Abiente di programmazione
ambiente di programmazione o di sviluppo => Linux stesso è un ambiente di sviluppo. Elementi di un ambiente di sviluppo:
- editor
- traduttore
- linker
- interprete
- debugger

### Tipi di ambienti di sviluppo
1. ambienti che mettono a disposizione singoli strumenti 
2. i singoli strumenti di sviluppo sono raggruppati sotto un'unica interfaccia grafica (IDE - Integrated Development Environment -)

### Confronto tra gli ambienti di sviluppo
Il vantaggio degli IDE è la semplicità e facilità d'uso

Il vantaggio dei sistemi non IDE (tipo UNIX) è il poter distinguere le varie fasi dello sviluppo e l'indipendenza tra i vari strumenti
