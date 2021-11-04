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

Memorizzazione esponente: si potrebbe utilizzare il complemento a due, ma è stao deciso di usare un offset => esponente = _num-offset_ -> viene memorizzato num

La prima cifra della mantissa deve sempre essere diversa da zero -> siamo in base 2, quindi è uguale a 1. Questo permette di evitare la memorizzazione degli zeri anteposti al numero.
Siamo arrivati ad un numero nella forma 1.xxxxx -> non è necessario memorizzare l'1, basta xxxxx

Valore minimo: -offset se num=0
Valore massimo: tutti i bit a 1
Zero: se num=offset

TODO: vedi ieee754 floating point converter

## Conversion
Per ogni cifra binaria a destra della virgola il valore decimale viene dimezzato

## Precisione
=> La precisione P di un dato tipo di dato numerico viene definita come il numero massimo di cifre (in base b) tali che, qualsiasi numero rappresentato su P cifre, è rappresentabile in modo esatto dal tipo di dato.

Tipicamente il float (4 byte) hanno un precisione di 6 cifre decimali, mentre il double (8 byte) ne ha 15. Inoltre esistono i long double, che occupano 10 byte in memoria.

=> la precisione è data dal numero di bit (in base 2) memorizzabili nella mantissa + 1 (bit non memorizzato). Eg. la precisione in base 2 degli interi è 31 (ricorda bit segno)

## Memorizzare numeri > 1 in float/double
È possibile memorizzare numeri maggiori di 1 utilizzando l'esponente, ma non possiamo essere sicuri che le cife dopo la P-esima siano corrette (assimilate a zeri)
=> questo problema prende il nome di *troncamento* -> necessario per memorizzazione

## Memorizzazione di numeri non scrivibili come somma degli inversi delle potenze di 2
=> numeri come 0.1 non possono essere rappresentati in modo corretto sulla macchina

## Operazioni miste
=> In un'operazione ad operatori misti basta che uno sia ti tipo reale che il risultato diventa reale
-> upcast (il compilatore "alza" il tipo di dato)

## Rappresentazione dello zero
La mantissa, per definizione ha la prima cifra diversa da zero, quindi 0 non sarebbe rappresentabile -> se tutti i bit sono esattamente a zero, il numero complessivo è considerato come zero.

## Confronto approssimato
Hint: usa range quando fai confronti tra numeri reali per far fronte ad eventuali errori di approssimazione dovuti alla memorizzazione dei numeri float e double.

## exit
Per uscire dal programma in qualsiasi punto di esso si può chiamare la funzione `void exit(int n)`

Warning: l'operatore `%` non esiste per float e double
