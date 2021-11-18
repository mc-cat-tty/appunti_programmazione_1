# Array circolari e code

## Code
=> oggetti astratti molto utilizzati

Code: vettore di elementi in cui gli ele si possono estrarre e inserire sia in testa che in fondo

ele - ele - ele - ... - ele
^												^
testa										coda

Array lineare = array statico o dinamico

Costo inserimento e rimozione in testa: N+1, con N uguale al numero di elementi presenti -> O(N)

## Array o buffer circolare
L'elemento successivo all'ultimo corrisponde al primo. "Array nel mondo di PacMan"

Strutura dati composta da:
	- array lineare che contiene gli elementi di un array circolare
	- un puntatore al primo ele
	- un puntatore all'ultimo ele

Utilizzo l'aritmetica modulare per implementare la circolarità dell'array

### Inserimento in coda
`ultimo = (ultimo+1) % N

### Inserimento in testa
Il modulo non è definito per numeri negativi, quindi non si può fare `(primo-1)%N`

Possibili soluzioni:
	- controllo con if
	- sommo N e faccio il modulo: `(primo-1+N)%N`
		=> questa operazione la posso applicare sempre, perchè sommare un numero e fare il modulo corrisponde a non sommare niente. Il vantaggio è quello di non doversi preoccupare di valori negativi (oppure di uscire dal range)

### Controlli aggiuntivi
I puntatori di testa e di coda hanno lo stesso valore (differenza di 1 con coda davanti a testa) sia quando l'array è vuoto, sia quando l'array è pieno.

Soluzioni:
	- aggiungo una var alla struttura dati e mantengo il numero di elementi contenuti nell'array
	- mantengo il puntatore alla testa e il numero di elementi presenti nell'array. Il puntatore alla coda rimange ricavabile con `(puntatore_testa+numero_elementi)%N`

Abbiamo così raggiunto un doppio livello di astrazione: a partire da una struttura dati nota (l'array) siamo riusciti a creare un array circolare e da questo una coda.

TODO: implementa una coda utilizzando un array circolare + relative funzioni (4 in totale)

La differenza tra coda e array circolare è il livello di astrazione tra i due
