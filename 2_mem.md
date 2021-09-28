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

## RAM
Ad ogni processo viene assegnata una porzione di memoria RAM, strutturata come sequenza di celle contigue.

Byte = dimensione sufficiente ad allocare un tipo di dato char (dimensione esatta non definita dallo standard)

## Oggetto
Oggetto = astrazione di cella di memoria, caratterizzato da un valore memorizzato in una sequenza di celle contigue.

Ogni oggetto è identificato da un *indirizzo in memoria*. Indirizzo prima cella in cui è memorizzato (della sequenza). Ogni oggetto è caratterizzato da un *valore*, ovvero il numero che sta dentro alla sequenza di celle.

Il *tipo di dato* definisce come interpretare un oggetto (i valori possibili) e quali operazioni sono consentite.

## Tipi di dato primitivi

|Nome|Categoria|
|----|---------|
|int|sottoinsieme interi|
|float|sottoinsieme reali|
|double|sottoinsime reali a maggiore precisione|
|char|caratteri|
|bool|booleano|

Il tipo _int_ ha un insieme di valori limitato, rispetto all'insieme dei valori contenuti in Z.

Il numero massimo di bit allocati per un int dipende dalla lunghezza della WORD della macchina su cui lavoro, tipicamente 16 o 32 bit. Range: [-2^15, 2^15-1]


### Operazioni `int`
/ -> divisione intera
% -> modulo della divisione

TODO: link esercitazione moltiplicazione

## Espressioni letterali
=> nomenclatura: costanti senza nome - letterali

Valore numerico all'interno del codice ==> letterale numerico.

Questi valori costanti possono essere associate ad un nome (costante con nome), che funge da identificatore, fermo restando che il valore della costante non può variare come quello delle variabili. La costante può essere definita come _astrazione simbolica di un valore_. L'associazione identificatore-valore non cambia mai.

Nelle variabili l'associazione identificatore-indirizzo non varia, ma il valore contenuto può essere modificato.

TODO: link esercizio costante intera e stampa valore assegnato


