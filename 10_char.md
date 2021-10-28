# Tipo primitivo char
Tipo primitivo del C/C++. Occupa 1 byte (unità minima di memorizzazione quando differente)

## Caratteri speciali
Necessario l'escaping dei caratteri

'\n'	A capo
'\t'	Tab
'\''	Apice singolo
'\\'	Backslash
'\"'	Doppio apice

## Rappresentazione dei caratteri
=> associare per convenzione un numero interno (codice) ad ogni carattere
Per una corretta interpretazione dei caratteri è necessario indicare al calcolatore che una data locazione di memoria contiene un carattere -> tipo _char_

## Codice ASCII
=> codifica che, nella forma estesa, associa a 256 caratteri (occupa 1 byte) un codice. Nella forma ristretta vengono utilizzati solamente 7 bit.

## Tipo char
Sottoinsieme degli int rappresentabili con un solo byte.
`char` tradizionale - 1 byte - da -128 a 127
`unsigned char` - 1 byte - da 0 a 255

Per definizione l'unsigned char è sempre senza segno, mentre per il char non è definito dallo standard se debba avere segno o no.
