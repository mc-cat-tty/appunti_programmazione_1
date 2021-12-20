# Algoritmi e programmi
formulazione di un problema -(metodo risolutivo "astratto")-> individuzione algo -(codifica in un linguaggio di programmazione)-> programma

Un programma mandato in esecuzione diventa un processo, in grado di prendere in input dei dati e di fornire i risultati in uscita

## Proprietà di un algoritmo
- eseguibile in un tempo finito
- non ambiguo
- 

## Costo computazionale
Il costo computazione di un algoritmo dipende dal numero di passi elementari che sono necessari per arrivare ad una soluzione

Questo valore dipende da:
- dall'insieme di valori in ingresso
- dall'insieme delle azioni elementari che posso eseguire sui dati. Eg: in base a come è implementato ogni passo elementare a basso livello dipende il costo computazionale dell'istruzione ad alto livello

Necessaria una notazine che renda il significato di costo computazione indipendente da questi due fattori.

Eg: N passi per lavorare su N elementi (solitamente sempre presente perchè i dati li devo almeno prendere in input)
Eg: Due cicli innestati di N valori diventa N^2 -> non importa l'efficienza di ogni singolo passo, perchè comunque l'algoritmo con costo pari a N è sempre più ottimizzato

Importa la *pendenza* del costo dell'algoritmo -> ovvero la derivata prima del costo di un algoritmo

### Ordine di costo
Un algo ha un ordine O(N) se esiste una costante _c_ tale che il numero di operazioni la variare dell'input cresce al più _c\*N_

### Ordini di costo notevoli
- costo lineare				O(N)
- costo quadratico		O(N^2)	eg: algo di insertion sort
- costo polinomiale		O(N^i)
- costo esponenziale	O(a^N)	l'algo non può essere completato in un tempo ragionevole
- costo costante			O(1)		permette di eseguire le operazioni in un tempo che non dipende dalla dimensione dell'input (eg: hashmap)

### Confronto costo algoritmi
Non sempre un algoritmi con ordine di costo maggiore è il migliore per risolvere un problema che coinvolge un piccolo set di dati (perchè la notazione O-grande mi indica il costo per N che tende all'infinito)

Verifica sempre i "costi di basso livello"
