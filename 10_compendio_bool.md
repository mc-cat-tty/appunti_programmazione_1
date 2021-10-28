# Compendio bool
## Corto circuito logico
Un operatore logico binario è valutato in *corto circuito logico* se il secondo operando non è valutato se il risultato del primo è sufficiente a stabilire il risultato dell'operazione.
### Esempi
false && <espressione> || ... || <espressione>
true || <espressione> || ... || <espressione>

In entrambi i casi l'espressione non viene valutata (ricorda che entrambi gli operatori sono associativi a sinistra). In caso di una serie di n espressioni ci si ferma appena il risultato è sufficiente a determinare il risultato della catena di operazioni
