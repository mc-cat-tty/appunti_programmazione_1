# Compendio C/C++

Non è generalmente possibile utilizzare un linguaggio di programmazione "as is"

Sono utili le librerie per evitare di reinventare la ruota e semplificare il processo di astrazione

## Libreria standard
Sia in C che in Cpp è presente una *libreria standard*

La stdlib del C è un sottoset della stdlib del Cpp

Entrambe sono suddivise in sezioni che svolgono compiti diversi

Esistono molte altre librerie, come le librerie `boost` del Cpp

## Moduli
In C++ la libreria standard è suddivisa in moduli.

In generale il nome di una libreria in Cpp si ottiene a partire dal nome della libreria C, rimuovendo il suffisso ".h" ed aggiungendo "c" come prima lettera

## I/O formattato in C
All'interno della `stdio.h` sono presenti `printf(const char format[], ...)` e `scanf(const char format[], <indirizzi_variabili>)`

Queste due funzioni hanno un numero di parametri variabile (funzioni *variadiche*)

Le funzioni variadiche si possono essere usate sia in C che in Cpp. Si utilizza un'estensione della sintassi vista fin'ora. Per recuperare gli args si utilizzano funzioni presenti nella libreria standard.

### Confronto con cin e cout
Rispetto al C, la stampa e l'input formattato in C++ permette di non specificare il tipo di dato da stampare o prendere in input, perchè il compilatore deduce automaticamente qual'è il tipo di dato utilizzato (delle variabili di destinazione/origine)

### Corruzione della memoria
=> molto frequente in C, in quanto se si sbaglia a passare l'indirizzo della variabile a scanf -> comporta la scrittura in una locazione non adeguatamente grande, oppure la scrittura sull'area di memoria di un puntatore

### Performance
scanf, printf, << e >> hanno la stessa velocità di lettura/scrittura perchè gli operatori << e >> vengono sostituiti a tempo di compilazione

## Direttiva #define
Negli ultimi standard del C è stato introdotto il qualificatore `cosnt`, prima si utilizzava la direttiva al precompilatore `#define`

-> a tempo di compilazione viene sostituito simbolo per simbolo con il valore associato ad esso dal define

## typedef
In C è necessario dichiarare un oggetto di tipo struct nel seguente modo:
```
struct <nome_struttura> <identificatore>;
```

Quindi per evitare di scrivere tutto per esteso si utilizza:
```
typedef struct persona persona_t;
```

La stessa cosa vale per gli enum e per tipi di dato frequentemente utilizzati.
```
typedef unsigned long int uint32;
```

typedef permette di migliorare la leggibilità.

## Allocazione memoria dinamica
In C si usa `malloc()` (al posto di `new`) presente nella stdlib

```
<nometipo>* <identificatore> = (<nometipo>*) malloc(<dimensione>);
```

Differenze:
- `new` casta automaticamente l'indirizzo allocato al tipo di dato dichiarato
- `new` calcola la dimensione dell'area di memoria al posto di utilizzare sizeof e moltiplicare per la lunghezza dell'array

E per liberare la memoria (al posto di `delete[]`):
```
free(<indirizzo>);
```

## Compilazione
```
gcc program.c
```

L'estensione è differente, ma questo non ha importanza (il compilatore potrebbe arrabbiarsi)
