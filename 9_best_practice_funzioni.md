# Best practice funzioni

## Input variabili
È meglio prendere in input le variabili necessarie nella funzione o utilizzare un parametro formale?
La soluzione migliore è la seconda, perchè rende il codice più modulare e riutilizzabile.

## Output variabili
Analogamente a quanto sopra detto, anche per l'output è meglio ritornare i valori delle funzioni, così da non replicare il codice.

## Chiamate incrociate
In questi casi è necessario dichiarare la funzione prima di definirla. Dal punto in cui viene dichiarata la funzione in poi è possibile usare la stessa.

### Prototipi e definizioni
Dichiarazione o prototipo di funzione: sola intestazione di una funzione seguita da punto e virgola (niente graffa). Nel prototipo di una funzione non è necessario l'identificatore dei parametri formali (al compilatore basta sapere il tipo di parametro che è possibile passare).

Il prototipo:
	- è un "avviso ai naviganti"
	- non causa produzione di codice eseguibile, è un mero avviso al compilatore
	- può essere ripetuto più volte all'interno del programma, l'importante è che le varie dichiarazioni non siano in contraddizione tra loro

La definizione:
	- contiene il codice della funzione
	- non può apparire più volte
	- il nome dei parametri formali è obbligatorio

-> il prototipo può comparire più volte (per esempio su più file header), ma la definizione deve essere unica.

### Controlli compilatore
Il compilatore controlla che l'invocazione sia *sintatticamente* corretta:
	- numero parametri (formali e attuali devono coincidere)
	- tipo di ciascun parametro formale
	- tipo valore di ritorno

Il compilatore segnala solamente errori sintattici. Per ottenere più warning (sensibilità più alta da parte del compilatore) possiamo usare il flag `-Wall` e `--pedantic`.
Eg: è possibile passare un bool ad un parametro formale di tipo int (dal punto di vista della memoria sono la stessa cosa)

Il compilatore sostituisce ogni chiamata a funzione con un'istruzione di salto (in codice macchina).



