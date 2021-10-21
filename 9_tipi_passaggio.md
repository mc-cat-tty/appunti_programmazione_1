# Tipi passaggio dei parametri
=> tipo di inizializzazione dei parametri formali a partire dai parametri attuali.
- passaggio per valore
- passaggio per riferimento (no in C (?))

## Passaggio per valore o passaggio per copaia
La locazione di memoria di ogni parametri formale viene inizializzata copiando il valore di ciscun parametro attuale.
L'area di memoria dei parametri formali viene deallocata dopo il termine della funzione. I parametri formali sono privati alla funzione, ne consegue che ogni loro modifica è locale alla funzione (tempo di vita coincide con quello della funzione stessa).
In questo caso i valori dei parametri attuali non vengono mai modificati.
Modificare i parametri formali è una cattiva abitudine [vedi esercizio somma da 1 a n]. Si rende il codice poco leggibile, si creano effetti collaterali se il passaggio avviene per riferimento, la distinzione logica tra variabile ausiliaria, di ingresso e di uscita viene rotta. La modifica

### Vantaggi
- variabili del chiamante e del chiamato sono *disaccoppiate* -> ragionare per compartimenti stagni

### Svantaggi
- non posso modificare le variabili del chiamante _a priori_
- operazione costosa (soprattutto per dati di grosse dimensioni)

### const
=> qualificatore che non consente di modificare i parametri formali

Attenzione: const può creare una divergenza tra il prototipo della funzione e la sua definizione.

