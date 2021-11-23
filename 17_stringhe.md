# Stringhe
Una stringa di caratteri è una sequenza di carattere

Un letterale stringa è un "oggetto" del tipo: "Hello world"

## Letterali stringa notevoli - escaping
 - "\n" newline, ecc. ecc.
 - "" stringa nulla
 - "c" -> equivale quasi a 'c'

## Implementazioni delle stringhe in C\C++
Le stringhe non sono tipi primitivi, ma sono implementate con array di caratteri terminiati da '\0' (corrisponde al codice 0 della codifica ASCII)

Si può trovare il tipo astratto `string` nella standard libary, ma non lo utilizzeremo

## Definizione
`[const] char <identificatore> [<espr-costante>];`

## Terminatore

L'ultimo elemento deve essere SEMPRE il terminatore -> deve esserci abbastanza spazio nell'array per contenerlo

Eg: una stringa di 20 caratteri necessita 21 elementi char per essere memorizzata
Eg: in un array di dimensione 6 byte posso memorizzare al più 5 caratteri

Tutto ciò che si trova dopo il carattere terminatore deve essere considerato "nullo" oppure casuale.

Stringa => array di caratteri con terminatore
Non vale il contrario: non sempre un array di caratteri è una stringa -> potrebbe mancare il carattere terminatore

## Inizializzazione
char nome[] = "Marco";
char nome[6] = +...
char nome[] = {"M", "a", "r", "c", "o", "\0"};
char nome[6] = ...

## Assegnamento
Non è possibile assegnare un letterale stringa (o qualsiasi oggetto di tale tipo) ad un altro oggetto stringa. Bisogna copiare elemento per elemento.

## Definizione di parola
=> sequenza di caratteri non separati da spazi bianchi (spazio, tab, newline...)

## I/O di stringhe
cout << _stringa_ stampa tutti gli elementi di un vettore di caratteri fino a che non incontr a il terminatore

cin >> _stringa_ memorizza la prossima parola presente sul buffer dello stdin all'interno della variabile

// TODO: link esercizio def_stringa_io.cpp

## StackSmashing
Vedi programma sopra, inserendo stringa più lunga della dimensione della memoria allocata

## Errori comuni
```
char a[10];
a = "foo";
```

```
char a[10], b[10];
a = b;  // gli elementi vanno copiati uno ad uno
```

## Differenza tra stringhe di singoli caratteri e caratteri
'a' non equivale a "a"
Il primo elemento occupa 1 byte in memoria, il secondo 2b, in quanto è contenuto anche il terminatore all'interno dell'array di caratteri che rappresenta questa stringa in memoria

// TODO: add link to str_len.cpp
// TODO: add link to mult_str_len.cpp

W: quando copi il contenuto di una stringa in un'altra ricordati di aggiungere il carattere '\0' nell'ultima posizione

## Passaggio ad una funzione
Le stringe si passano nello stesso modo degli array (di caratteri). Ricorda che è possibile usare const. In questo caso non è necessario passare la lunghezza delle stringhe (terminatore presente alla fine di essa).

## Funzioni di libreria
Il linguaggio C/C++ è provvisto di una ricca libreria di funzioni per la gestione delle stringhe

`<cstring>` oppure `string.h` in C

- `strcpy(dst, src)` copia la stringa src in dst (adeguatamente grande)
- `strncpy(dst, src)` copia i primi n caratteri di src in dst (adeguatamente grande)
- `strcat(s1, s2)` concatena s1 ed s2; il risultato viene copiato in s1
- `strcmp(s1, s2)` ritorna:
	-	0			s1 == s2
	- > 1		s1 maggiore di s2 secondo l'ordine lessicografico
	- < 1		s1 minore di s2 secondo l'ordine lessicografico 

## strcmp()
Viene ritornata la differenza (char di s1 - char di s2) tra il codice ascii del primo carattere differente tra le due stringhe

// TODO: link conta_car.cpp
// TODO: compito verbosity.cpp

## Documentazione
www.cppreference.com

Vedi Null-terminated byte string

// TODO: link conta_occor2.cpp
// TODO: link copia_stringhe.cpp

// TODO: per compito implementare RSA su stringhe
// TODO: per esercizi vedi slides
