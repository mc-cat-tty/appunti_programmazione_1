# Float and double
Numeri con componenti frazionari. Comunemente chiamati reali, ma nella realtà

## Notazione scientifica
`2.4e2` => 2.4 * 10^2
Funziona sia per gli esponenti negativi che per quelli positivi

## Letterali reali
Per inidcare che una costante lettereale è da inerpretare come reale, è necessario porre un punto alla fine di essa, indipendentemetne dalla presenza della parte decimale. `102.`

## Downcast e upcast
Downcast -> perdita di informazioni
Upcast -> eg: da int a float

## Stampa numeri reali
Il numero stampato su stdout da cout potrebbe non coincidere con il numero presente in memoria. I numeri reali vengono stampati con un ragionevole numero di cifre dopo la virgola.

## Rappresentazione in memoria
- virgola fissa
- virgola mobile: ho un limite massimo di cifre significative che posso rappresentare e sposto la virgola in base al valore della parte decimale

### Componenti in virgola mobile
- segno
- mantissa (_significand_): cifre del numero (intere e decimali)
- esponente in base 10: indica la posizione della virgola

Il numero si immagina nella forma: mantissa\*10^esponente

La posizione iniziale della virgola si trova al terzo posto a partire da destra.

Esponente:
- positivo: spostamento della virgola di n cifre verso destra
- negativo: spostamento virgola verso sinistra

## Float vs double
Entrambi vengono rappresentati in virgola mobile
Sottoinsieme dei numeri reali -> sono un'approssimazione sia come range di valori rappresentabili che come numero di cifre contenuto nella mantissa

I numeri periodici vengono approssimati

## Manipolatore `setprecision`
=> setta un numero massimo di cifre per un numero in virgola mobile
`#include <iomanip>`
L'istruzione `setprecision(<cifre-dopo-la-virgola>)` ha un effetto permanente

TODO: vedi divisione_reale.cpp

Approssimazione migliore del tipo double: 16esima cifra dopo la virgola

## Standard IEEE754
=> definisce la rappresentazione tipica di float e double.
