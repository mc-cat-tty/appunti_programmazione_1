# Matrici
=> tabella n-dimensionale ordinata di elementi

Utilizzeremo principalmente matrici bdimensionali

## Dimensione
Una dimensione NxM è da intendersi come una matrice di N righe ed M colonne

## Sintassi - matrice bdimensionale
```
[const] <tipo_dato> <nome_matrice> [<numero_righe>][<numero_colonne>];
```

## Riempimento matrice
Metodo 1: riempire riga per riga. All'interno di ogni riga riempio colonna per colonna. Utilizzo 2 cicli for innestati.
Meotodo 2: un solo ciclo for che fa uso dell'operatore modulo per determinare su quale riga/colonna si trova (oppure accedo come se fosse un array, con le righe allocate in memoria in modo contiguo) 

## Matrice k-dimensionale
```
[const] <tipo_dato> <nome_matrice> [<dim1>] [<dim2>] {[dimk]};
```

## Inizializzazione matrici
È possibile inizializzare le matrici come se fossero un array di più array.

Nella dichiarazione + inizializzazione di una matrice non è necessario specificare il numero di righe, perchè tale valore viene dedotto dal compilatore

```
int mat[][2] =
{
	{1, 2},
	{3, 4}
}
```

## Diagonanale
Matrici quadrate

### DIAGONALE PRINCIPALE
Indici: i, i => mi trovo sulla diagonale principale se i == i

### DIAGONALE SECONDARIA
Indici: i, N-i-1 => mi trovo sulla diagonale secondaria se i == N-i-1

Ho bisogno di un solo ciclo per accedere alla diagonale

## Raw major e column major
Il C è un linguaggio raw major, perchè memorizza in memoria le matrici come array contigui, ognuno dei quali rappresenta una riga
Linguaggi come il Fortran memorizza le colonne in modo sequenziale

## Memoria
In memoria le matrici sono rappresentate come righe contigue

## Passaggio a funzione
Equivalente al passaggio di array
=> sempre passate per riferimento

Sintassi:
```
[cont] <tipo_elementi> <identificatore> [] [<numero_colonne>]
```

Infatti: quando passo un array ad una funzione non esplicito il numero di elementi presenti nell'array

Per efettuare l'acccesso in memoria basta conoscere l'indirizzo della cella di memoria dell'elemento richiesto

Indice per l'elemento \[indice_riga][indice_colonna] è calcolato come segue:
indirizzo_matrice + byte_tipo_dato_elementi \* (indice_riga\*num_colonne + indice_colonna)

Vettorizzazione o linearizzazione di una matrice

## Array di strighe
Posso memorizzare un array di stringhe. Su ogni riga si trova una array di caratteri terminati di '\0', tutto lo spazio dopo il terminatore è purtroppo sprecato.

// TODO: traccia_disegno.cpp
// TODO: battaglia navale
// TODO: implementa il gioco della vita
// TODO: traccia_lista_esami.txt
