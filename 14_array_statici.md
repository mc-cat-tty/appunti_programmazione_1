# Array Statici

Tipi di dato derivati: riferimenti, strutturati (array, struct...), puntatori

Problema irrisolvibile con le conoscenze attuali: calcolare la media di n valori

Array: n-upla di N oggetti dello stesso tipo (omogenea) allocati in locazioni contigue della memoria
Ogni elemento viene individuato da un indice compreso fra 0 e N-1

Eg: dato un array `a` di dimensione N, l'elemento i-esimo è a[i] con i compreso tra 0 e N-1

## Sintassi
`[const] <tipo> <identificatore> [<espr_costante>];`

## Semantica
Viene allocato in memoria un array statico di dimensione <espr_costante>
Quindi, il numero di elementi dell'array è costante durante l'esecuzione del programma -> la dimensione dell'array viene dichiarata a tempo di scrittura del programma

## Digressione su VLA
Esistono i Variable Length Array, ma sono supportati da pochi compilatori e non sono portabili (non compatibili con tutte le macchine)

Esempio
```
int num_elem;
cin >> num_elem;

int vett[num_eleme];
```

ATTENZIONE: non fare, perchè può causare memory-corruption (nonchè bocciatura all'esame :( )

## Estensioni
Come mai è stato imposto che la grandezza degli array statici sia fissa?

Gli array statici vengono allocati nello _stack_ -> di dimensione limitata (assegnata dal SO)

Gli array dinamici vengono allocati nell'heap (come vedremo più avanti)

Hint: usa il flag `--pedantic-error` per evitare che il compilatore non permetta di definire VLA

[stampa_array.cpp](./esercitazioni/stampa_array.cpp)
[array_casuali.cpp](./esercitazioni/array_casuali.cpp)

## Dimensione
Nel caso di un array di char, ogni locazione di memoria ha dimensione 1 byte, equivalente alla dimensione di una cella => dimensione array in memoria = numero elementi

Nel caso di un int: dim array in memoria = 4\*num elementi

## Copia array
L'unico modo di copiare un array in un altro array è quello di utilizzare un ciclo che esegua la copia posto per posto.

## Vettori e array
I due termini sono interscambiabili, perchè l'array è la rappresentazione i memoria di un vettore matematico


[max_of_array.cpp](./esercitazioni/max_of_array.cpp)
[max_of_array_index.cpp](./esercitazioni/max_of_array_index.cpp)

## Dimensione array
Posso ottenere la dimensione in byte di un array con `sizeof(v)`
Per calcolare il numero di celle dell'array divido questo valore per la dimensione del tipo di dato memorizzato in `v`: `sizeof(v)/<tipe_of_v>`

## Mancanza di controllo degli indici
A tempo di esecuzione non viene vietato di accedere ad aree di memoria esterne all'array stesso.
=> injection, buffer overflow e le "peggiocose" sono possibili a causa della mancanza di controlli

## Inizializzazione
`[const] <tipo> <nome> [<dim_const>] = {<ele1>, <ele2>, ...};`

Un array che viene definito come costante deve essere inizializzato all'inizio del programma.

## Array come argomenti
`<dichiarazione_parametro_formale> ::= [const] <tipo> <identificatore> []`

Gli array sono passati automaticamente per riferimento, mai per copia. Quindi all'interno della funzione posso sempre modificare i valori contenuti in esso, a meno che non utilizzi il modificatore `const`

Le informazioni sulla dimensione dell'array non vengono passate alla funzione, è il programmatore che se ne deve occupare: var globale oppure costante globale (consigliata la prima soluzione).


[calcola_somma.cpp](./esercitazioni/calcola_somma.cpp)
[raddoppia_array.cpp](./esercitazioni/raddoppia_array.cpp)
[pari_array.cpp](./esercitazioni/pari_array.cpp)
