# Unsigned, short e long

Tipi interi:
|nome|dimensione|
-----------------
|int|32 bit|
|short int|16 bit|
|long int|64 bit|

Tipi naturali (no numeri negativi):
Stessa dimensione dei tipi non-unsigned, ma i valori rappresentabili raddoppiano, in quanto sono memorizzabili solo valori maggiori o uguali a zero

## long
=> usando il modificatore `long` viene assicurato che la dimensione sia almeno pari a quella degli int

## long long
Dato che la dimensione del tipo int dipende dalla word del calcolatore, dallo standard C++11 è stato introdotto il modificatore `long long int` -> almeno dimensione degli int, non meno di 64 bit

## Tipo carattere
char, signed char e unsigned char occupano tutti 8bit
Il char può essere signed o unsigned di default in base all'implementazione

## Tipo float
|nome|dimensione|
----------------
|float|32 bit|
|double|64 bit|
|long double|80 bit (10 bytes)|

## Espressioni letterali
Mediante i seguenti suffissi è possibile comunicare esplicitamente al compilatore il tipo di dato di un letterale:
U			unsigned int
UL		unsigned long
ULL		unsigned long long
L			long int
LL		long long int

## Overflow di un unsigned
Cosa succede se decremento il valore 0? Overflow

Eg:
MAX_UINT + 1U = 0
0U - 1U = MAX_UINT
MAX_UINT + 2U = 1

## Limits
`#include <limits.h>`

`numeric_limits<nome_tipo>::`
min()
max()
digits				numero cifre in base 2
digits10			numero cifre in base 10
is_signed			se ammette valori negativi
is_integer		true se è un tipo discreto

TODO: completa da slide a pagina 91, link: https://algogroup.unimore.it/people/paolo/courses/programmazione_I/vecchie_edizioni/edizione_2021/materiale_2021/lezioni/Cap_10-Enum-reali-conv-tipo.pdf

epsilon()			minimo valore tale che 1+epsilon != 1 -> precisione del tipo di dato
round_Error()	errore arrotondamento

## Espressioni eterogenee
Ogni qualvolta siamo in presenza di operazioni che coinvolgono operandi di diverso tipo
Soluzione:
- conversioni esplicite del programmatore
- conversioni implicite del compilatore (coercion)

Le conversioni implicite non sono illegali, ma avvengono secondo una certa lista di regole (tipicamente il compilatore le segnala con warning)

La conversione implicita avviene verso tipi di dato di gerarchia superiore. Il risultato sarà di questo tipo di dato.
Gerarchia: char < int < float < double < long double
Il tipo unsigned è di gerarchia superiore rispetto al tipo signed
Questo avviene in modo ripetuto per ogni espressione, secondo la priorità dell'operazione (eg: somma di prodotti)

## Assegnamento eterogeneo
- Se var è di ordine superiore all'espressione, quest'ultima viene convertita al tipo di dato della variabile. No perdita informazione (eg: double = char)
- Se var è di ordine inferiore all'espressione, avviene conversione con probabile perdita di informazione.

Esempi:
int a, b=2; float x=5.8;
a = b + x // == 7
Equivalente all'operazione implicita: `a = static_cast<int>(static_cast<float>(b) + x)`

Memorizzare un float in un int potrebbe portare ad una perdita di informazioni, perchè il valore massimo rappresentabile da un float è maggiore di quello memorizzabile da un intero.
Memorizzare un intero in un float potrebbe portare ad una perdita di informazione, in quanto la precisione di float e double è inferiore al numero di cifre garantite da float e double.

## cmath con i reali
`double fabs(double x);` -> valore assoluto di un numero reale
`double ceil(double x);` -> minimo intero maggiore di x
`double floor(double x);` -> massimo interno minore di x

## ctype con caratteri
Le seguenti funzioni ritornano 0 se falso, un numero intero altrimenti:
`int isalnum(int c)` -> se alfanumerico
`int isalpha(int c)` -> se alfabetico
`int isdigit(int c)` -> se carattere decimale
`int isxdigit(int c)` -> se carattere esadecimale
`int islower(int c)` -> se carattere minuscolo
`int isupper(int c)` -> se carattere maiuscolo

`int tolower(int c)` -> converte il carattere in minuscolo
`int toupper(int c)` -> converte il carattere in maiuscolo


TODO: esercizi https://algogroup.unimore.it/people/paolo/courses/programmazione_I/vecchie_edizioni/edizione_2021/materiale_2021/esercitazioni/lab7_visib_car_reali/Compiti%20per%20Casa/
