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

Dato che la maggior parte delle volte la dimensione del vettore è nota a tempo di esecuzione del programma, creiamo un vettore abbastanza grande da poter contenere tu
