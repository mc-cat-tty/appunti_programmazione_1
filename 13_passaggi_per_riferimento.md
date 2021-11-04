# Passaggi di parametri per riferimento
Esempio di problema: vogliamo scambiare due variabili all'interno di una funzione, portando le modifiche all'esterno di essa (scambiare il valore dei parametri attuali)

Per superare i limiti della semantica per copia occorre utilizzare il passaggio di varibili per riferimento. Se una funzione dichiara (nella sua intestazione) che un parametro costituisce un riferimento, allora il parametro formale non è più una variabile locale, bensì un riferimento alla variabile passata come parametro attuale. Le modifiche a questo riferimento si propagano fuori dalla funzione stessa.

Il passaggio per riferimento è disponibile in molti linguaggi, ma non in C: necessario usare i puntatori (tipo derivato riferimento).

Un riferimento è un identificatore associato all'indirizzo di una variabile (di un oggetto) e non al valore della stessa.

Quando si dichiara un oggetto, gli si assegna un riferimento di default, quello che fin'ora abbiamo chiamato nome dell'oggetto.

## Sintassi riferimento
`<definizione_riferimento> ::= <tipo_riferimento> <identificatore> = <nome_oggetto>;`
`<tipo_riferimento> ::= <tipo_oggetto> &`

È equivalente ad assegnare un'ulteriore etichetta (alias) ad un identificatore già definito -> l'inizializzazione di un riferimento è obbligatoria all'atto della sua definizione

Una volta definito e inizializzato, un riferimento si riferisce sempre allo stesso oggetto.

Il modificatore `const` proibisce la modifica del valore associato al riferimento

Ogni modifica fatta sul riferimento verrà fatta anche sull'oggetto originale.

## Effetti collaterali
I passaggi per riferimento e l'utilizzo di variabili globali sono i due meccanismi che ci consentono di avere effetti collaterali.
=> permettono interazione tra diverse parti del programma

Attenzione: rendono il programma più difficilmente debuggabile

## Parametri di input e output
Posso avere:
	- parametri solo di ingresso		oggetti usati esclusivamente il lettura
	- parametri solo di uscita			oggetti mai usati in lettura, ma solo per memorizzare il valore di ritorno
	- parametri di ingresso/uscita	oggetti letti e poi sovrascritti con risultato

=> questo mi permetti di avere più valori di uscita dalla funzione (un solo valore di ritorno sempre e comunque).

Hint: buona prassi commentare le funzioni (comportamento e utilizzo dei parametri).
