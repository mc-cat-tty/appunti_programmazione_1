# Assegnamento
Espressione di assegnamento:
`nomevar = espressione`

Istruzione  assegnamento:
`<espressione assegnamento>`

Tabella dei simboli: simbolo -> indirizzo

Ogni assegnamento implica una scrittura della porzione di memoria in cui è contenuta la variabile.

*lvalue* = left value
*rvalue* = right value

`lvalue = rvalue` <--> _indirizzo = espressione_
Ordine esecuzione: risoluzione espressione rvalue, assegnamento al valore del simbolo di sinistra.

Anche l'espressione di assegnamento ha un risultato (un proprio valore), ovvero *l'indirizzo della variabile*. In C il risultato dell'assegnamento è il valore del rvalue.

Assegnamento multiplo: `c = d = 2`. Parti da destra: `c = (d = 2)`. Funziona sia in C che in C++

TODO: link esercizio e completa
