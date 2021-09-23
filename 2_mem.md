# La memoria

## Intro
Con *memoria* si definisce il contenitore su cui l'elaboratore opera (memoria RAM).

La memoria viene vista dal processore come una serie contigua di celle. Ogni cella è l'unita minima di memoria allocabile, ovvero 1 byte = 8 bit. Ogni locazione minima di memoria viene individuata univocamente attraverso il suo *indirizzo* (un indiche che punta ad essa, indicando l'offset rispetto al primo address)

## Dimensione memoria
Una cella da 8 bit può contenere un valore massimo di 256 (2^8)

Per memorizzare il segno posso impiegare un bit che agisca da flag.

Per memorizzare valore più grandi di, per esempio, 256 devo accorpare più celle di memoria

Solitamente una variabile di tipo `int` è memorizzato accoroando 4 bytes.

## CPU
Tutte le operazioni sono eseguite da un processore, in grado di compiere azioni elementari:
- lettura scrittura copia
TODO

1 word = dimensione massima sulla quale un processore può operare

Linguaggio macchina = linguaggio in grado di essere compreso dal processore. Tutto è numero, comprese le istruzioni.

Il calcolatore esegue le istruzioni a partire da una locazione di memoria.

Cicli = salto indietro
Jump = salto avanti

Linguaggi ad alto livello = si basano sul concetto di astrazione. La memoria viene astratta in variabili. (barriera di astrazione"
