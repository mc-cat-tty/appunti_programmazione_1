# Continuo appunti array dinamici

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

