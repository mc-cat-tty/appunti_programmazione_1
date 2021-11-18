# Formattazione output
W: no argomento esame

## Manipolatori con argomenti
`cout << ... << setw(int n) << ...` Setta il numero minimo di cartteri a n per ogni cout
Per specificare il carattere con cui riempire il caratteri necessari a raggiungere la dimensione n bisogna usare `setfill(char c)`

Necessario includere `<iomanip>`

## Stampa a dx e sx
`cout << ... << right << ...`
`cout << ... << left << ...`
