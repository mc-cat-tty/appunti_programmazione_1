# Enumerati

Problema: il tipo *int* è troppo generico
Proposta: usare un nuovo tipo di dato per identificare meglio l'insieme dei valori assegnabili ad una data variabile

Vantaggi:
	- leggibilità
	- correttezza (non posso assegnare valori "fuori dal range")

## enum
=> insieme di costanti intere definite dal programmatore. Ogni costante è identificata da un nome (enumeratore).
Esempio: `enum colori_t {rosso, verde, giallo};`
Alle tre costanti sopra riportate vengono assegnati valori numerici a partire da 0 (rosso==0, verde==1, giallo==2)

Viene così creato un nuovo tipo di dato che permette di definire oggetti.

## Dichirazione
`<dichirazione_enumerato> ::= enum <identificatore> {<lista_dichiarazione_enumeratori>`
`<lista_dichiarazione_enumeratori> ::= <dich_enumeratore> {, <dich_enumeratore>}`
`<dich_enumeratore> ::= <identificatore> [= <espressione>]`

Il valore di un enumeratore viene stabilito a partire dal precedente, che viene incrementato di una unità.

## Definizione
Questa dichirazione segue le stesse regole di visibilità di qualunque altra dichiarazione.

Se dichiaro un enumeratore con lo stesso nome di un enumeratore già dichiarato, perdo la visibilità di quest'ultimo.

## Ordinamento
Gli enumerati sono tipi ordinati, quindi posso fare confronti tra gli enumeratori (sempre possibile stabilire una relazione di ordine).

## Rappresentazione in memoria
Tipicamente ogni enumerato occupa la stessa quantità di memoria occupata da un int (4 byte).

Il compilatore impedisce di assegnare ad un enumerato un valore differente dal tipo di dato (il casting è consentito).

Operazioni e confronti tra enumerati
=> possibile ma rompe la tipizzazione forte del Cpp

## enum class
=> risolve il problema posto sopra. Ogni volta che si vuole utilizzare un enumeratore definito in una enum class è necessario anteporre `<nome_classe>::`. In più è possibile evitare di perdere la visibilità di un operatore con lo stesso nome di uno già definito.

Altri vantaggi (a differenza degli enum):
	- non permesse operazioni pericolose
	- possibile associare gli enumeratori a valori diversi da int

Requisiti: standard C++11
