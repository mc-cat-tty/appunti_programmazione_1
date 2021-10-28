# Portabilità
Un codice si dice portabile se può eseguire mantenendo il proprio comportamento invariato su differenti architetture. Non è portabile in caso contrario.

Un codice non portabile è altamente sconsigliato, almeno che non si stia lavorando su sistemi embedded (unica architettura utilizzata).

## Approccio bottom-up
Scrivo tutte le funzioni che mi servono e (forse) le utilizzo per implementare l'algo ad alto livello

## Approccio top-down
Scrivo solo i prototipi delle funzioni, commentandoli, e li utilizzo senza averli ancora implementati.
