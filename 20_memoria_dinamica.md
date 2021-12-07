# Memoria dinamica
Spesso non si conosce quanti dati memorizzare a tempo di scrittura del programma
=> vogliamo allocare memoria a tempo di esecuzione -> allocazione dinamica della memoria

Quando lancio un processo il SO riserva al programma una certa quantità di memoria. Questo spazio allocato in modo contiguo è suddiviso in segmenti.
Uno di questi segmenti è chiamato _heap_ (oppure memoria livera o memoria dinamica). All'interno di questo segmento posso allocare memoria in modo arbitrario a tempo di esecuzione, pur rispettando la dimensione fornita dal SO.

I: l'indirizzo di memoria del primo byte dell'heap è costante durante tutta l'esecuzione del programma

## Oggetti dinamici
Utilizzeremo array dinamici -> possono cambiare dimensione a tempo di esecuzione.

In C standard si usa `malloc()`

In Cpp useremo `new`:
```
new <nome_tipo> [<num_elementi>];
```
<num_elementi> può essere una espressione qualsiasi
W: il vettore sopra dichiarato non ha nome (identificatore)

`new` alloca solamente un certo spazio in memoria (heap)

Return value: indirizzo di memoria del primo elemento -> indirizzo dell'area di memoria riservata

## Puntatore
Dobbiamo memorizzare questo indirizzo in una variabile per poter accedere all'area di memoria allocata mediante un identificatore

Def: un oggetto di tipo puntatore è una variabile che ha per valore un indirizzo di memria (numero naturale)

### Dichiarazione
```
[const] <tipo_oggetto_puntato> * [const] <identificatore> [= <indirizzo>];
```

Il primo _const_ va inserito se il puntatore fa riferimento ad un oggetto non modificabile
Il secondo _const_ va inserito se il valore del puntatore non deve essere modificato dopo l'inizializzazione

Esempio: allocaizone di un array di N elementi
```
int *p = new int[N];
```

### Accesso agli elementi
=> identico a quello degli array -> operatore parentesi quadri

W: non vengono effettuati controlli sulla dimensione e l'accesso in memoria come visto fin'ora

I: `htop` o `top` per visualizzare l'utilizzo di memoria di un processo

### Valori, operazioni, tempo di vita
Il puntatore nullo (NULL) è un puntatore che contiene 0 come valore.

Prevede che le operazioni siano correlate al tipo di dato a cui si punta.

I puntatori seguono le stesse regole su visibilità e tempo di vita di tutte le altre variabili (ma non l'area di memoria allocata dall'operatore new)

### Tempo di vita di un array dinamico
Non confondere un puntatore con l'array ad esso associare.

Una volta allocato un array dinamico esiste fino alla fine del programma (anche quando scompaiono tutti i riferimenti ad esso, compreso il puntatore) oppure fino a che non viene _deallocata_ l'area di memoria.

### Dealocazione area di memoria
=> per liberare un area di memoria

```
delete[] <indirizzo_da_deallocare>
```

W: perdendo qualsiasi riferimento ad un array dinamico la memoria non può essere deallocata, quindi rimane occupata ma non utilizzabile fino alla terminazione del procesos

I: l'operatore `delete` può essere applocato anche al puntatore nullo

W: un errore di gestione della memoria si verifica quando viene deallocata un'area di memoria mai allocata nell'heap oppure già allocata

Hint: utilizza sempre il delete alla fine di una funzione/del main per evitare _memory leak_ -> errore difficile da trovare a meno che non si controlli in continuazione la memory footprint del programma.

### Passaggio per riferimento alle funzioni
```
[const] <nometipo>< <identificatore> []
// oppure
[const] <nometipo> * <identificatore>
```

Gli array sono sempre passati per riferimento

Il parametro formale contiene una copia dell'indirizzo dell'array (quindi questo tipo di passaggio è per valore)

Il nome dell'array è equivalente al nome del primo elemento

### Ritorno da parte di funzioni
Posso allocare un array dinamico dentro ad una funzione e farmi ritornare il puntatore ad esso, dove sono memorizzati i valori di ritorno. Dovrò ricordarmi di deallocare l'area di memoria allocata nella funzione.

Alla fine della funzione viene deallocato solo il *puntatore* e non la memoria da esso puntata.

I: con "dinamico" non si intende che la dimensione dell'array viene conosciuta solamente a tempo di esecuzione del programma, non che è possibile modificarne la dimensione dinamicamente.

Quando ritorno un vettore ho anche bisogno della sua dimensione. I metodi sono:
	- struct con 2 campi
	- passo dim per riferimento e ritorno il puntatore al vettore
	- passo il puntatore al vettore per riferimento e ritorno la dimensione

### Riferimento ad un puntatore
```
[const] <nometipo>* & <identificatore> = <nomeoggetto>
```

La variabile così definita è un riferimento a puntatore e può tornare utile per modificare un oggetto di tipo puntatore.

Esempio:
```
void creaVett(int* &v, int &num) { ... }
```

## Dangling reference
Oppure pending pointer

Quando si ha un puntatore che punta ad un'area di memoria che non è stata allocata oppure che è stata deallocata. Il comportamento del programma diventa non deterministico (in base alla disposizione e quantità della memoria il programma funziona oppure no)

## Esaurimento memoria
In assenza di memoria libera disponibile l'operatore new fallisce e viene generata un'eccezione

### Memory leak
=> problema derivante dalla mancata deallocazione degli oggetti dinamici, che comporta un esaurimento della RAM/swap totale

Il memory leak può verificarsi anche all'interno di una funzione

## Tipo di array dinamici
### Strighe dinamiche
```
char * const str = new char[11];
```

### Array dinamico di strutture
```
struct persona { ... };

persona* const t = new persona[dim];
```

### Matrici dinamiche
=> array dinamico di array (statico, anche se in realtà funziona anche con gli array din di array din)

```
int (*p) [10] = new int[n][10];
```
Passaggio a funzione:
```
[const] <nometipo> (*<identificatore>) [<espr_costante>];
```
### Esercizi
// TODO: percorso_semplificato.cpp
// TODO: percorso.cpp
// TODO: pila.cpp

