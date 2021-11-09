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

[stampa_array.cpp](esercitazioni/stampa_array.cpp)
