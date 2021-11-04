# Ingegneria del codice

Obiettivi -> codice:
 - leggibile
 - robusto
 - manutenibile

## Principi ingegneria del codice

1. il codice deve essere formattato in modo opportuno (indentazione e spaziatura)
2. usare nomi significativi per le variabili
3. usare strutture dati chiare
4. anche le funzioni devono avere un nome significativo 
5. cercare di raggruppare concetti correlati (separare i gruppi di variabili per concetto, utilizzare più andate a capo per separare blocchi di codice logicamente separati)
6. non duplicare il codice (replicare il codice porta ad uno sviluppo, testing e manutenzione in parallelo, quindi fonte di errori). Lasciare codice duplicato solo se renderlo modulare complica di più le cose.
7. riutilizzare il codice già disponibile, ma con spirito critico. Non reinventare la ruota
8. usare un corretto livello di astrazione. Usare nomi significativi appartenenti al dominio del problema
9. scegliere un tipo di dato appropriato
10. aggiungere commenti
11. non fare assunzioni

Hint: progettare il codice in anticipo e renderlo facilmente estensibile, mantenendo il codice modulare

Hint: se puoi usa i double, a meno che non si stia sviluppando su un ambiente memory-constrained

## Complessità
- complessità/costo computazionale: misura il costo di un algoritmo in termini di passi elementari per arrivare alla soluzione
- complessità e funzioni: difficoltà richiesta da un frammento di codice per essere compreso (numero variabili da tenere a mente...)

Attenzione agli effetti collaterali: minimizzare passaggi per riferimento (senza const) e variabili globali, numero scelte e cicli (strutture di controllo), soprattutto se nidificate (non andare oltre 3 livelli di nidificaizone)
Come ridurre le nidificazioni? inserire cicli e controlli all'interno di funzioni

### Formattazione
Riduci il numero di colonne utilizzato per scrivere il programma. Mantieni sotto le 80 colonne (i vecchi terminali erano larghi 80\*64)

### Commenti
Usa commenti, il giusto numero. Per le funzioni descrivi varibili aspettate, parametri ingresso e uscita, descrivi brevemente la funzione e se ci sono effetti collaterali. Non scrivere quello che il codice fa perchè è palese dedurlo dallo stesso.

## Warning
`g++ -Wall source.cpp` per abilitare tutti i warning
`g++ -Wall -pedantic source.cpp` per un livello di maggior sensibilità (disabilita estensioni del linguaggio C/C++, facendo emergere più warning)
`g++ -Wall -Werror source.cpp` trasforma i warning in errori che bloccano la compilazione

Torvald's rants: https://github.com/corollari/linusrants
Comments coding style: https://lwn.net/Articles/694755/

## Coding style
Mantenere un coding style consistente


