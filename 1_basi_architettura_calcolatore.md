# Accenni architettura del calcolatore

## Composizione
Componenti:
 - CPU
 - mobo: bus e interconnessione componenti
 - RAM: memoria volatile
 - Disco fisso: memoria permanente

## CPU speed
La velocità di una CPU viene misurata in _istruzioni al secondo_ o _flops_ (floating point operations per second).
La frequenza (espressa in Hz) della CPU non indica la sua velocità, ma i cicli di clock (alto-basso) in un secondo, ovvero la frequenza con cui vengono eseguite le operazioni elementari.

CPU socket

## Hard Disk and SSD
Tipo di disco rigido costituito da una serie di dischi di materiale ferromagnetico, che ruotano ad alte velocità [rpm]. Una serie di testine alterano il magnetismo del disco.

SSD - Dischi a stato solido -> costituiti come la RAM, ma non sono volatili

Vedi M2 + PCIe

www.pctechguide.com

## Sistema Operativo

App
^
|
interface
^
|
OS manage
^
|
OS kernel
^
|
HW

TODO: schema


## Boot process
Pulsante accensione -> BIOS (memoria non volatile che gestisce il tipo di hw e punta al MBR) -> MBR Master Boot Record (bootloader) (zona di memoria del discho fisso che ha il compito di caricare il sistema)


## Compilatore
g++ - GNU ...

TODO: completa

Editor != IDE
Editor testuale != editor ipertestuale (Word)
