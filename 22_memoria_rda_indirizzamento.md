# Classi di memorizzazione
- automatica
- statica
- dinamica

## Oggetti statici
- oggetti globali
- oggetti dichiarati con l'attributo static

Esistono per tutto il tempo di vita del programma

Se non inizializzati hanno valore 0

## Oggetti dinamici
Hanno un valore casuale (bullshits)

Il tempo di vita va dal momento dell'allocazione a quello della deallocazione dell'area di memoria

## RDA
Record di attivazione: struttura dati che rappresenta l'ambiente della funzione e contiene:
- parametri formali inizializzati con i parametri attuali
- variabili e costanti locali
- indirizzo del record di attivazione del chiamante (da riattivare una volta finita l'esecuzione della funzione)
- indirizzo di ritorno (dal quale riprendere l'esecuzione dopo aver ritornato)

## Base ed offset
L'indirizzo a cui inizia il record di attivazione di una funzione viene chiamato indirizzo *base*
Ogni oggetto è identificato da un *offset* calcolato a partire dall'indirizzo base

Ogni oggetto locale è identificato da un indirizzo calcolato come base+offset

## Prologo
=> codice aggiuntivo inserito dal compliatore per creare il RDA, inizializzare il base pointer ed eseguire la prima istruzione della funzione

## Dimensione
=> dipende dal numero di variabili/costanti locali e dai parametri formali cha abbiamo dichiarato

Gli RDA sono memorizzati nello _stack_ (pila) -> struttura dati LIFO

L'RDA viene deallocato solo al termine dell'esecuzione

Gli RDA sono innestati: vengono allocati secondo l'ordine delle chiamate e deallocati in ordine inverso

Il C e C++ sono linguaggi imperativi e funzionali

### Catena dinamica
=> rappresenta la storia di come sono state chiamate le funzioni una dopo l'altra

## Valore di ritorno
È diponibile una sola area di memoria come valore di ritorno -> per questo ho un solo valore possibile, che può essere al massimo un puntatore

### Epilogo
Pezzo di codice inserito dal compilatore che si occupa di distruggere e deallocare l'RDA di una funzione

## Spazio di indirizzamento
Ad un processo, quando viene lanciato, viene associata un'area di memoria chiamata _spazio di indirizzamento_ (assegnata dal SO) così suddivisa:

testo e istruzioni
costanti
oggetti statici inizializzati
oggetti statici non inizializzati
heap (memoria dinamica)
area libera (che può ridursi dall'alto o dal basso)
stack

Eg: spectre e meltdown permettevano di leggere i valori rimasti sulla cache della CPU a causa di meccanismi della branch prediction mal gestiti

Gli oggetti statici sono automaticamente inizializzati a zero

Lo stack cresce verso l'alto, l'heap verso il basso. Quando lo spazio libero viene esaurito le due aree di memoria non sono ulteriormente incrementabili
