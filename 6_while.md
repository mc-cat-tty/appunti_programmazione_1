# Costrutto while e do-while

TODO: link esercizio "ciao mondo"

##  Le istruzioni iterative
Le istruzioni iterative, anche chiamate di iterazione o cicliche, sono l'ultimo costrutto (di controllo) fondamentale della programmazione strutturata; permettono di ripetere una data istruzione (semplice o composta) fintantoché una condizione risulta vera. Per il teorema di Jacopini-Bohm posso implementare qualsiasi algoritmo usanto struttre di controllo iterative, condizionali e istruzioni composte.

Il linguaggio C++ fornisce tre differenti tipi di istruzioni iterative, per aumentare l'espressività del linguaggio:
- while
- do ... while
- for

## Sintassi while
<istruzione-while> ::= while(<condizione>) <istruzione>

Il corpo del ciclo viene ripetuto finché la condizione è vera; appena risulta falsa si esce dal ciclo. L'istruzione deve modificare la condizione per evitare un ciclo infinito.

### Parantesi su invocazione comandi bash
All'interno di un programma C/C++ possono essere invocati comandi bash, attraverso la funzione _system_: `system("<comando>");`. L'esecuzione del programma non esce dalla funzione system finchè il comando lanciato non termina. Necessario importare `stdlib.h`.

TODO: link esercitazioni fino a stampa secondi

### time
Libreria `<ctime.h>`

L'istruzione `time(0)` ritorna il numero di secondi trascorsi a partire dall'epoch (1 gennaio 1970).

### Segnali di interruzione
Premento Ctrl+C mentre un processo in esecuzione, viene mandato il segnale SIGINTR (interruzione) a quest'ultimo. Se questo non dovesse bastare è necessario recuperare il suo _pid_ attraverso `ps x` o `ps ax`, quindi inviare un segnale di interruzione SIGKILL con `kill -9 <pid>`.

### Modificatori stdout
Il carattere speciale "\r" inviato sullo stdout riporta il cursore all'inizio della riga

Il manipolatore `flush` equivale a fare `fflush(stdout)`, quindi forza il buffer di output ad essere stampato.

## Struttura dati
=> insieme di oggetti (variabili o costanti) con nome. Le strutture dati vengono utilizzate per rappresentare dati del problema reale.

## do ... while

### Sintassi
<istruzione-do-while> :: = do <istuzione> while(<condizione>);

### Semantica
=> il costrutto `do ... while` è equivalente al `while`, escluso l'ordine in cui viene eseguito il corpo del ciclo e la condizione. In questo modo il corpo del ciclo viene sempre eseguito almeno una volta (torna utile, per esempio, nel controllo di valori di input).
