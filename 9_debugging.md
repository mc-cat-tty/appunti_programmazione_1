# Debugging
=> ricerca di bug (logici o di altro tipo) in un programma

## Debugger
Utile ma difficile da usare

## Testing
Testo (teoricamente) tutti i possibili input e verifico che l'output sia quello desiderato.

Due tipi di testing:
	> white box
		Il programmatore si mette nei panni del compilatore, per controllare che sia formalmente corretto, e dell'esecutore (CPU), per controllare che il programma venga eseguito come pensato.
	> black box
		Faccio finta di non conoscere il codice sorgente del programma e lo testo con vari input (possibilmente tutti i valori possibili)
		Scelgo input agli estremi del dominio e input al di fuori di esso, per accertarmi che il programma sia robusto.

Cosa succede se il test fallisce?
	Due tipi di fallimento:
		- il programma crasha. Esso viene terminato forzatamente dal SO a causa di un operazione illegale (come la divisione per zero)
		- il programma termina correttamente ma il risultato è scorretto. Errore logico contenuto nel programma. Questo tipo di errore viene chiamato *bug* o *baco*. Le tarme/cimici un tempo bloccavano l'esecuzione dei relé e delle valvole, causando problemi nel funzionamento dei computer.

Hint: non programmare mai al 100% delle tue capacità intellettuali, perchè debuggare un codice può diventare 5 volte più complicato di scriverlo.

## Analisi statica del codice
=> rilettura accurata del codice nell'ottica di trovare gli errori.

### Duck programming
=> prendere una paperella e spiegarle il funzionamento del programma.

### Pair programming
=> una persona scrive il codice, mentre un'altra guarda il codice scritto ed, evenutalmente, evidenzia errori logici.

## Tracing
=> tracciare l'evoluzione del valore delle variabili per individuare dove avviene una lettura/scrittura non desiderata.

Il tracing di cicli viene spesso "rallentato" utilizzando delle `cin`, che attendono un qualche input da stdin.
