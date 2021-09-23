# Ambiente UNIX

Ambiente multiutente, nato per fornire un OS a più utenti che accedevano allo stesso mainframe.

Procedura di _login_ e _logout_

## Comandi
`
ls [sth]
cd dirname
mkdir _newdirname_
passwd
cat _filename_
file _filename_
pwd
exit
`
Concetto di estensione inesistente negli ambienti UNIX, introdotto con DOS. UNIX usa i magic bytes per determinare il tipo di file.

Manuali:
`
man _command_
info _command_
apropos _command_
`
## Shortcuts
Ctrl+a -> inizio riga
Ctrl+e -> fine riga
Ctrl+r -> search in commands history
Ctrl+d -> logout
...

## Filesystem
Organizzato come un albero, a partire dalla radice "/"

In UNIX tutto è un file. Solamente i processi sono un'entità a parte

Ogni file è costitutio da una serie di bytes

### Tipologia di files
 - file regolare
 - dir
 - link simbolico
 - socket
 - named pipe
 - ...

## Users management
Dimensione in bytes [ls -l]

3 gruppi di permessi: proprietario, gruppo, altri [ls -l]
Tipi di permessi: R, W, X

Secondo valore di _ls -l_ -> numero di link al file

### Gestione gruppi e utenti
`chown`

TODO: completa

`find` e `locate`
`grep`

