# Variabili di ingresso e uscita

Processo != programma -- il processo è un programma in esecuzione

input --> processo --> output

Libreria per I/O classica in Cpp: `#include <iostream>`

## Anatomia programma C++
`
_direttive_

int main() {
	_istruzioni_
}
`

## Stampare output su terminale
`cout << "stringa"`
cout = oggetto che rappresenta il buffer di uscita del terminale
<< = operatore accodamento sul buffer

Stringa = sequenza di caratteri delimitata da doppi apici

## Compilazione
In base alla versione del compiler potrebbe essere richiesto un valore di ritorno della funzione main()

I microprocessori comprendono solamente il linguaggio macchina -> linguaggio elementare a basso livello. Il C è un linguaggio ad alto livello (livello intermedio di fatto). Il compilatore è quel componente che traduce un file sorgente, scritto con un linguaggio ad alto livello, in linguaggio macchina

sorgente -> compilazione -> eseguibile

gcc - Gnu Compiler Collection | g++ - frontend al gcc per compilare sorgenti in C++

https://gcc.gnu.org/

`gcc --version`

### Procedura
```
cd _nome_cartella_
g++ nome_sorgente.cpp
./a.out
```

Di default viene assegnato il nome `a.out` all'eseguibile generato da g++. Il parametro `-o _nome_eseguibile_` permette di modificare il nome dell'eseguibile.

### Errori di compilazione
Il compilatore evidenzia solamente gli errori di tipo *sintattico*

- Warning -> qualcosa di sospetto è contenuto nel codice, ma riesco comunque a compilare
- Error -> non permette di compilare

Struttura: `filename:row:column: [error|warning]: testo errore

Linux identifica i file eseguibili attraverso la lista di permessi (presente flag "x")

## Esecuzione
`./exec`

Il percorso relativo viene utilizzato per indicare alla shell la posizione del file eseguibile. Di norma (niente percorso rel) i programmi vengono cercati nelle cartelle:
- /bin
- /usr
- /usr/bin
- /usr/local/bin


