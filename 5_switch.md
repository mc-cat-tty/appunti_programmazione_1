# Costrutto switch
## Sintassi e semantica

istruzione-scelta-multipla ::=
	switch (<espressione-selezione>) {
		case <etichetta-1>: <sequenza-istruzioni-1> [break;]
		case <etichetta-2>: <sequenza-istruzioni-2> [break;]
		...
		[default: <sequenza-istruzioni> [break;]]
	}

l'_espressione di selezione_ deve essere di tipo *numerabile*: int, char o enum.
