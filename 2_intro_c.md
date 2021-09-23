#

TODO: completa

## Storia del C

Definito nel 1972 (AT&T Bell Labs) per 

## C con le classi
In circolazione già dal 1980. Prime versioni di quello che sarebbe diventato il C++. Inventato da Bjarne Stroustrup.

https://www.stroustrup.com/

Molte applicazioni sono scritte in C++. Utilizzato soprattutto per game engines e programmi HPC. https://www.stroustrup.com/applications.html

## Memoria
*Variabile* = "contenitore in grado di memorizzare un dato. Varia durante l'esecuzione del programma. Ogni variabile deve essere definita prima di essere utilizzata.

Nel momento della definizione:
` _tipo_ _identificatore_ [= _inizializzazione_]`

Per dichiarare più variabili dello stesso tipo è possibile fare:
`_tipo_ _var1_ [= _val_iniziale_], var2 = [= _val_iniziale_]`

NOTA: le partentesi quadre contengono elementi opzionali [...], tutto il resto è obbligatorio.

### Tipi di dato
`int` variabile di tipo intero.

Ogni variabile è costituita da un _identificatore_ (alias nome della variabile) e da un 

```
int a;  // definizione di var di nome _a_ e tipo int
int a = 10;  // definizione di var di nome _a_ e tipo int + inizializzazione al valore 10
```

## Processi
Elencabili su Linux con il comando `top`

## Stream
=> flusso di caratteri. Successione di righe, ciascuna costituita da 0 o più caratteri e delimitate da "\n" (fine riga).

Il linguaggio C++ non prevede istruzioni per ingresso e uscita di caratteri (di base). Per queto devono essere implementata da librerie esterne (`iostream`).

Oggetti `istream` e `ostream`

Il SO assegna ad ogni processo tre differenti stream:
- cin - stream ingresso
- cout - stream uscita
- cerr - stream uscita per errori

Il C è un linguaggio case-sensitive

TODO: aggiungi link a esercitazione

## Valore di ritorno
Ogni processo ritorna un valore quando termina. Può essere letto e utilizzato dal programma che lo ha invocato.
Tipicamente il valore 0 indica che non ci sono stati errori (valore implicito, ma dipende dal compilatore).

Nota bene: l'output deve essere esattamente quello richiesto (tester automatici)

"parola riservata"

## cin
Operatore ingresso: `>>` applicato ad un oggetto di tipo _istream_
-> il valore del testo di input viene interpretato in automatico, in base al tipo di dato della variabile.

Gestione errori: se `cin` non riesce a trovare il tipo di dato cercato, lo stream entra in uno stato di errore e assegna un valore di default alla variabile, che dipende dallo standard utilizzato.

## Valore di default delle variabili
Dipende. Nella maggior parte dei casi il valore è `undefined`. Potrebbe essere 0, a seconda del compilatore utilizzato.

## Visibilità delle variabili
Una variabile è *visibile* a partire dal punto in cui viene definita nel testo del programma. La definizione di un var è una singola istruzione.

`v = 4` assegnamento: "assegno il valore 4 alla variabile v"

## Standard del C++
Gli standard evolvono con il tempo, in quanto vengono introdotti nuovi funzionamenti del linguaggio. Non è detto che un sorgente scritto per uno standard compili anche per uno differente.

Esempio: se la lettura fallisce
- std\<C++11 - errore
- std\>=C++11 - valore assegnato = 0


