# Visibilità e tempo di vita degli oggetti

## Dichiarazioni globali
=> dichiarazione variabili e costanti fuori dal corpo di una funzione.

Possono essere inserite 

## Variabile locale
= contrario di _Globale_. In questo caso la variabile è locale ad un blocco.

## Caratteristiche statiche e dinamiche
Caratteristica statica: non cambia durante l'esecuzione del programma
Caratteristica dinamico: cambia durante esecuzione programma

### Esempio
Una variabile ha:
	- nome statico
	- indirizzo statico
	- valore dinamico
	- tipo statico

Il C/C++ è un linguaggio con tipizzazione STATICA e FORTE (il tipo viene controllato dal compilatore)

## Visibilità e tempo di vita
Visibilità = arte del testo del programma in cui si può utilizzare un certo itentificatore. Regole di visibilità statiche.
Tempo di vita = in quali momenti della vita del programma. Il tempo di vita degli identificatori è DINAMICO in C/C++.

### Blocco
Il campo di visibilità di un identificatore dichiarato all'interno di un blocco di codice è il blocco stesso (dal punto della dichiarazione alla fine del blocco).
L'unica eccezione viene rappresentata dai blocchi innestati: _shadowing_. In questo caso l'identificatore del blocco esterno rimane in vita, ma viene "nascosto" ad esso (non visibile nel blocco innestato). ATTENZIONE: lo shadowing avviene solamente se nel blocco interno ridefinisco l'identificatore, se lo utilizzo solamente viene modificato il valore di quello esterno.

Il tempo di vita va dal momento della definizione alla fine del blocco stesso.

### Corpo del main
Tempo di vita pari alla durata dell'intero programma (coincide con il tempo di vita del main).

Campo di visibilità limitato al corpo del main.

### Identificatori globali
Tempo di vista pari alla durata dell'intero programma.

Visibili dal punto della dichiarazione fino alla fine del file. Se in presenza di blocchi innestati -> shadowing.

## Unicità identificatori
L'associazione di un identificatore ad un oggetto è UNICO per tutto il suo campo di visibilità.

## Valori iniziali
Il valore iniziale di una variabile GLOBALE è ZERO; in tutti gli altri casi è casuale (garbage).

TODO: add esercizio scope

## Dipendenze
Tra tue parti di un programma si dice che c'è dipendenza se una delle due parti funziona correttamente solo se anche l'altra funziona correttamente.

Questo va in contrasto con l'utilizzo delle variabili globali, perchè generano dipendenza con tutti i punti del programma in cui vengono utilizzate. -> aumentano complessità programma
