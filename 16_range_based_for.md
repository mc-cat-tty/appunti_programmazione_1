# Range based for

Dato un array di tipo `T` e nome `A`

```
for ([const] T &<identificatore>: A)
	<istruzioni>
```

<identificatore> scorre tutti gli elementi di A. È un identificatore, per cui resta possibile modificare l'i-esimo elemento di A (se non si usa const). Questo identificatore resta visibile solamente all'interno del blocco di istruzioni eseguite dal for.

Utilizzo solo per array statici (no terminatori, no oversized)

Vantaggi:
	- no inizializzazione
	- no var ausiliria

Svantaggi:
 - non è supportato da tutti i compilatori
