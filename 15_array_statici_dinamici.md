# Array statici di dimensione "dinamica"

L'array è un tipo di dato derivato, quindi ha anche un tipo di dato di riferimento. Un array è una ennupla di oggetti dello stesso tipo (tipo di riferimento) allocati in posizioni contigue della memoria.

La scrittura `array[i]` indica l'i-esimo elemento di array <--> 0<=i<=n-1

Gli array statici non cambiano la loro dimensione durante l'esecuzione del programma. La loro dimensione deve essere definita a tempo di scrittura mediante una costante (letterale o non)

Gil array statici vengono allocati nello stack del programma, un'area di memoria dalla dimensione limitata assagnata dal SO.

L'operazione di assegnamento non è definita tra due array, per cui è necessario copiare elemento per elemento

Un vettore dinamico può cambiare la propria dimensione durante l'esecuzione del programma.

Posso ottenere la dimensione di un array statico dividendo il numero di byte occupati in memoria da esso per il numero di byte occupati dal singolo elemento: `sizeof(array)/sizeof(array[i])`

Il linguaggio C non prevede controlli sull'indice utilizzato per accedere all'array -> usato per injection e buffer oveflow (compromissione stack del programma)

Inizializzazione: `char cv[4] = {'a', 'b', 'c', 'd'};` oppure `char cv[] = {'a', 'b', 'c', 'd'}`. L'inizilizzazione risulta obbligatoria quando dichiaro l'array come const.

Passaggio di vettori come argomenti: `void fun(char c, int v[]) {...}`. Gli array sono sempre passati per riferimento, se non voglio che il contenuto venga modificato uso `const`. All'interno della funzione non posso sapere la dimensione dell'array, perchè ho solo un riferimento al primo elemento dell'array. Posso passare la dimensione dell'array alla funzione, oppure utilizzare un terminatore (necessariamente un valore escluso da quelli che possono essere assunti dalle celle dell'array) per individuare la fine dell'array.

## Array dinamici

Spesso la dimensione del vettore si conosce solo a tempo di esecuzione. Possiamo usare un array statico "sovradimensionato", utilizzando solamente lo spazio necessario.

Due metodi:
	- mantenere in memoria il numero di "celle" utilizzate
	- utilizzare un terminatore posto dopo l'ultimo elemento valido dell'array. Se tutto l'intervallo del tipo di dato è assumibile dai valori nell'array non posso usare questa tecnica

Esiste l'oggetto `vector` nella C++ standard library

Attenzione: la memoria riservata ad un programma contiene dati e strutture dati del programma, letterali definiti dal programmatore, funzioni e tabelle di supporto, generate dal compilatore. Attraverso un accurato uso degli indici dell'array posso accedere a locazioni non utilizzate o "riservate" (non dovrebbero essere accessibili)

Errori come il `segmentation fault` segnalano che si è cercato di accedere al di fuori dello spazio allocato. La `memory corruption` è un errore di scrittura, sollevato dal OS quando si cerca di sovrascrivere una parte di memoria non consentita.

I moderni OS etichettano alcune aree della memoria come non modificabili (memoria protetta in scrittura o lettura).

Segmentation fault: dato che la memoria è divisa in segmenti, questo errore viene sollevato quando si cerca di accedere ad un segmento non proprio.

## Selection sort

Trovo l'elemento più piccolo dell'array e lo metto all'inizio del vettore (posizione corrente del puntatore)

```
// il primo indice (i) scorre gli elementi da 0 a N-1
	// il secondo indice (j) scorre gli elementi da i+1 a N
		// trovo il minimo
	// scambio il minimo con l'elemento in posizione corrente (i)
```


