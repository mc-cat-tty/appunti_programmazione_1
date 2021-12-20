# Introduzione alle liste
N.B.: questo capitolo non è presente all'esame

Liste: struttura dati dinamica => cambiano dimensione a tempo di esecuzione del programma

Le strutture dati dinamiche permettono di risolvere problemi efficacemente mediante alcuni algoritmi.

Esempio: memorizzare una sequenza di valori la cui lunghezza non è conosciuta a priori.

Possibile soluzione: utilizzare un array dinamico riallocato ogni volta che si renda necessario. Ogni riallocazione costa O(N), ma questa operazione non la faccio tutte le volte, quindi l'algoritmo ha _costo ammortizzato_ O(1) -> costo costante. Ma l'estrazione costa O(N) tutte le volte perchè devo ricompattare la sequenza di dati.

Altra soluzione: allocare 1 elemento alla volta con l'operatore `new`. Memorizzo una variabile puntatore che punta alla prima locazione che contiene il primo elemento. Quando diventa necessario memorizzare il primo elemento alloco la memoria necessaria e memorizzo l'indirizzo nel puntatore. Al prossimo elemento avrò bisogno di un'area di memoria per l'elemento e un'altra variabile puntatore che punta all'elemento successivo.

## Struttura dati
Per ogni elemento della lista memorizzo il suo valore e un puntatore all'elemento successivo

```
struct {
	int v;  // valore dell'elemento corrente
	int *p;  // puntatore al prossimo elemento
}
```

Per segnalare l'ultimo elemento si memorizza `NULL` (equivalente a 0) nella variabile puntatore dell'ultimo elemento.

## Terminologia

Abbiamo appena creato una *linked list*

Diremo che ciascun elemento contiene un:
	- campo informazione (oppure più informazioni)
	- campo puntatore

Il primo elemento della lista è chiamato *head* (testa). L'ultimo elemento è chiamato *tail* (coda).

Esistono due tipi di liste:
	- single linked list
	- double linked list (ogni elemento contiene un riferimento all'elemento precedente e successivo)

## Implementazioni
Esistono molte librerie che implementano le liste.

Nella libreria std del Cpp è presente il tipo di dato `<list>`

## Confronto array-liste
Data una sequenza di N oggetti...

...se uso un array occupo meno memoria (quasi la metà rispetto alla lista), il costo di inserimento è O(1) finchè non serve la riallocare la lista, altrimenti O(N).

...se uso una lista occupo quasi il doppio della memoria, posso inserire e rimuovere elementi, sia in testa che in coda in O(1)

## Fine corso
Consigli per il futuro:
 - http://www.topcoder.com/
 - http://www.hackerrank.com/


