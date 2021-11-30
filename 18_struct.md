# Struct
Problema: riuscire a rappresentare una entità del mondo reale e, successivamente, estendere questa soluzione per memorizzare molteplici entità del mondo reale.
Eg: idealmente array di persona, caratterizzata da altezza, età e peso

Vogliamo creare un nuovo tipo di dato che rappresenti una persona -> si utilizza la struct (struttura dati)
```
struct persona {
	char nome[16];  // stringa di 15 caratteri
	char cognome[21];
	// ...
	int altezza;
	int peso;
	int eta;
}
```

Da questo momento in poi posso dichiarare variabili di questo tipo di dato.
```
persona Mario;
```

Nota: in C++ non è necessario ripetere `struct`

## Definizione
Definizione: un oggetto di tipo struttura è una n-upla ordinata di n elementi ognuno dei quali viene detto campo o membro della struttura. A volte il tipo struttura viene chiamato _record_ (in linguaggi come l'SQL)

## Differenza con array
I tipi di dato contenuti possono essere eterogenei, non omogenei come negli array

Le struct a loro volta possono contenere oggetti strutturati come altre strutture o array.

## Sintassi
```
struct <nome_tipo> { <dichiarazione_membri> };  // il ; è necessario perchè potrei dichiarare direttamente un oggetto di tipo <nome_tipo>
```

Definizione di un oggetto strutturato: `<nome_tipo> <identificatore1> {, <identificatoren>}`

## Selezioni dei campi
`<nome_oggetto>.<nome_campo>`

Posso utizzare il campo come se fosse una normale variabile

// link: struttura.cpp

## Dimensione
=> numero di celle contigue tanto quanto sono i suoi campi. Attenzione all'ordine di definizione perchè conta (per gli accessi errati alla memoria).

## Passaggio a funzione
Le struct, di default, vengono passate alle funzioni per valori (deep copy = copia elemento per elemento)

Solitamente si passa ad una funzione un array di struct, così che venga passato per riferimento alla funzione

## Inizializzazione
```
struct coord {int x, y};
coord p1 = {3, 2};  // Attenzione: conta solo l'ordine dei campi
```

## Deep copy (assegnazione tra struct)
`coord p2 = p1` equivale a copiare campo per campo da p1 a p2

Non è consentito fare assegnamenti tra struct con nome tipo differente tra loro

Vale anche se se all'interno della struttura si trova un vettore, un vettore di vettori o qualsiasi altra cosa -> deep copy degli elementi una locazione alla volta

### Corretto e sbagliato
`struct frutto { char nome[20]; float peso, diametro; };`

`frutto mela = { "mela", 5, 2 };`  // corretto
`mela.nome = "melarossa";`  // sbagliato
`mela.nome = {'m', 'e', 'l'};`  // sbagliato

## Array di struct
=> possibile come se fosse un array normale.

## Sort di array di struct
Gli algo visti fin'ora restano validi, perchè tra le struct è possibile usare l'operatore di assegnamento

Dato che copiare svariate struct da una locazione di memoria all'altra è un'operazione dispendiosa, si può ordinare un array di indici che rappresentano (associati univicamente) agli elementi del vettore di struct e ordinare questo array.

// TODO: implementa le estensioni di classifica_solo_elenco.pp

## Progettazione strutture dati
Eg: da triangolo estrarre area e perimetro
triangolo deve contenere:
	- base min
	- base mag
	- h
	- lato obl 1
	- lato obl 2
Di tipo float/double (valori reali)

La stessa soluzione si potrebbe ottenere utilizzando un array, ma gli indici non sarebbero legati logicamente ad un univoco valore
=> maggiore leggibilità

Magic roule: se in una funzione utilizzo più di 7 parametri probabilmente mi perdo

Solitamente è più funzionale passare un intero oggeto al posto di passare ogni singolo elemnto di esso, nonostante la funzione operi solo su parte di essi
Se la funzione lavora su molti meno campi di quelli definiti nella struttura, allora è più vantaggioso passare solamente un membro della struct.

Si deve capire bene o male su quali elementi lavora la struttura senza leggerne l'implementazione

=> livello di astrazione appropriato

Utilizza modificatore const quando non modifichi i valori di una struttura
