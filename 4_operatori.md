# Operatori

- additivi
- moltiplicativi
- ...
- di confronto (relazione, uguaglianza)
- logici
- assegnamento
- accodamento

## Operatori logici

x == true --> x
x == false --> !x

La seconda forma viene preferita per compattezza.

OVERLOADING degli operatori = dare più significato di quello che hanno (eg. assegnare un int ad un bool)

## Priorità
Accodamento ha priorità minore rispetto agli altri, attento a valutare espressioni mentre fai in o out da stream.

## Assegnamento
a += 1 --> a = a + 1
...

## Incremento e decremento
- prefisso: effettua incremento/decremento, poi valuta l'espressione (usa la variabile). Ritorna _lvalue_ della variabile (indirizzo). Eg. (++a) = 4 è valido
- postfisso: usa la variabile, poi effettua l'incremento/decremento della variabile. Ritorna _rvalue_ della variabile (ovvero il suo valore). Eg. (a++) = 4 non è valido

## Espressioni
= costrutto sintattico costituito da letterali, identificatori, operatori e parentesi tonde

## Associatività
= ordine con cui vengono valutati operatori con la stessa precedenza

Associatività operatore di assegnamento -> dx (da destra a sinistra)

TODO: aggiungi tabella priorità operatori

TRACING = seguire passo passo le istruzioni

