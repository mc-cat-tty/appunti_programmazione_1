#!/bin/bash

# ISTRUZIONI PER L'ESECUZIONE DI QUESTO SCRIPT
# bash prova-sorgente-spedisci-data_esame.sh nome_vostro_file_sorgente

crea_tester ()
{
    cat <<- EOF > righe_da_ultima_stampa.cc
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using namespace std;

void turn_lowercase(string &s)
{
	for (unsigned int i = 0 ; i < s.size() ; i++)
		s[i] = tolower(s[i]);
}

bool confronta_contenuto_linee(string linea1, string linea2)
{
	turn_lowercase(linea1);
	turn_lowercase(linea2);

	string buf1, buf2;
	stringstream stream1(linea1), stream2(linea2);

	// controllo prima riga della stampa
	while (true) {
		stream1>>buf1;
		stream2>>buf2;

		if (!stream1 || !stream2 || buf1 != buf2)
			break;
	}

	if (stream1 || stream2)
		return false;

	return true;
}

int main(int argc, char** argv)
{

	if (argc < 2) {
		cerr<<"Argomenti mancanti"<<endl;
		return 1;
	}
	vector<string> linee_output;

	string linea_aggancio(argv[1]);
	string linea;
	bool buffering = false;

	while (getline( cin, linea )) {
		if (confronta_contenuto_linee(linea, linea_aggancio)) {
			buffering = true;
			linee_output.clear();
		}
		if (buffering)
			linee_output.push_back(linea);
	}

	// stampa le ultime linee a partire dall'ultima stampa
	for (std::vector<string>::const_iterator i = linee_output.begin();
	     i != linee_output.end(); ++i)
		std::cout << *i<<endl;

	return 0;
}
EOF

    g++ -Wall righe_da_ultima_stampa.cc -o righe_da_ultima_stampa

    if [ $? -ne 0 ]; then
	echo Compilazione del filtro delle righe di output fallita
	exit 1
    fi

    cat <<- EOF > controlla_output.cc
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

void turn_lowercase(string &s)
{
	for (unsigned int i = 0 ; i < s.size() ; i++)
		s[i] = tolower(s[i]);
}

bool confronta_contenuto_linee(string linea1, string linea2)
{
	turn_lowercase(linea1);
	turn_lowercase(linea2);

	string buf1, buf2;
	stringstream stream1(linea1), stream2(linea2);

	// controllo prima riga della stampa
	while (true) {
		stream1>>buf1;
		stream2>>buf2;

		if (!stream1 || !stream2 || buf1 != buf2)
			break;
	}

	if (stream1 || stream2)
		return false;

	return true;
}

int main(int argc, char** argv)
{
	if (argc < 3) {
		cout<<"Argomenti mancanti"<<endl;
		return 1;
	}

	int num_linee = atoi(argv[1]);

	cout<<"Ora leggo l'output del programma, e come parte finale di stampa dello stato"
	    <<endl<<"mi aspetto:"<<endl;

	for (int i = 0 ; i < num_linee ; i++)
		cout<<argv[i+2]<<endl;

	string linea;
	bool letta_una_linea = false;
	int indice_linea_corretta = 0;

	while (getline( cin, linea ) && indice_linea_corretta < num_linee) {
		letta_una_linea = true;
		string linea_corretta(argv[indice_linea_corretta+2]);

		if (!confronta_contenuto_linee(linea, linea_corretta)) {
			cout<<"La seguente riga:"<<endl;
			cout<<linea<<endl;
			cout<<"Non coincide con la riga attesa, ossia con:"
			    <<endl;
			cout<<linea_corretta<<endl;
		cout<<"Se ti sembra che invece la riga coincida e non riesci a"<<endl;
		cout<<"capire perche' venga ritenuta diversa, allora controlla"<<endl;
		cout<<"attentamente la presenza di eventuali spazi in piu' o in"<<endl;
		cout<<"meno nella tua riga, o di caratteri di punteggiatura in"<<endl;
		cout<<"piu' o in meno (tipo : ; , . accapo e così via)."<<endl;
		cout<<endl;
		cout<<"Un altro errore comune e' il non aver inserito un accapo PRIMA"<<endl;
		cout<<"della prima riga che mi aspetto di trovare. In tal caso, tale prima"<<endl;
		cout<<"prima riga non e' effettivamente una riga a se stante, ma risulta attaccata"<<endl;
		cout<<"alla riga precedente. Quando tu inserisci l'input manualmente, non ti accorgi"<<endl;
		cout<<"di questo errore, perché inserisci tu i newline nel terminale. Ma tali newline"<<endl;
		cout<<"non ci sono nell'output del programma."<<endl;
		cout<<endl;

			return 1;
		}
		indice_linea_corretta++;
	}

	cout<<endl;

	if (!letta_una_linea) {
		cout<<"Non ho trovato la prima tra le righe di stampa da controllare!"
		    <<endl;
		cout<<"Verifica la presenza di tale riga nell'output del tuo programma"<<endl
		    <<"e la correttezza del formato di tale riga."<<endl;
		cout<<"Se ti sembra che la riga ci sia, controlla attentamente,"<<endl;
		cout<<"nella tua riga di stampa, la presenza di eventuali spazi"<<endl;
		cout<<"in piu' o in meno, o di caratteri di punteggiatura in piu'"<<endl;
		cout<<"o in meno (tipo : ; , . accapo e così via)."<<endl;
		cout<<endl;
		cout<<"Un altro errore comune e' il non aver inserito un accapo PRIMA"<<endl;
		cout<<"della prima riga che mi aspetto di trovare. In tal caso, tale prima"<<endl;
		cout<<"prima riga non e' effettivamente una riga a se stante, ma risulta attaccata"<<endl;
		cout<<"alla riga precedente. Quando tu inserisci l'input manualmente, non ti accorgi"<<endl;
		cout<<"di questo errore, perché inserisci tu i newline nel terminale. Ma tali newline"<<endl;
		cout<<"non ci sono nell'output del programma."<<endl;
		cout<<endl;

		return 1;
	}

	cout<<"Test superato!!!"<<endl;
	cout<<"-------------------------------------------------------------"
	    <<endl;

	return 0;
}
EOF

    g++ -Wall controlla_output.cc -o controlla_output

    if [ $? -ne 0 ]; then
	echo Compilazione del controllore dell\'output fallita
	exit 1
    fi
}

# se il parametro $1 e' vuoto, allora non si e' superato il compito
stampa_msg_punto_insufficiente ()
{
    if [ "$1" != "" ]; then
	punto=$1
	echo Il tuo programma ha superato tutti i test relativi ai punti che
	echo precedono il punto $punto, ma non ha superato un test relativo al
	echo "punto $punto (ossia l'ultimo test effettuato finora)."
	echo
	echo "Il test del punto $punto potrebbe essere fallito semplicemente perche'"
	echo non hai ancora implementato il punto $punto.
	echo
	echo Per poter accedere alla correzione anche del $punto,
	echo "devi prima aver implementato il punto $punto ed aver corretto"
	echo "gli errori che fanno fallire l'ultimo test."
	echo
	echo "I docenti correggeranno SOLO i punti PRECEDENTI al punto $punto"
	echo
	if ! command -v sender &> /dev/null
	then
	    echo "Sono eseguito su un PC personale, non spedisco nulla."
	    rm controlla_output* righe_da_ultima_stampa*
	    exit
	else
		retval=$(sender $sorgente `whoami` | grep "moved successfully")
		if ! echo $retval | grep "not"
		then
			echo Ho spedito quindi il tuo compito per la correzione.
			echo Invocami di nuovo se vuoi fare spedire una nuova versione del tuo compito.
		else
			echo Non sono riuscito a spedire il file per la correzione.
			echo Contatta il docente del corso per chiarimenti se necessario.
		fi
	fi
	echo In ogni caso, hai superato abbastanza punti da poter accedere
	echo alla correzione del compito. Ho spedito quindi il compito
	echo per la correzione. Invocami di nuovo se vuoi fare
	echo spedire una nuova versione del tuo compito.
    else
	echo
	echo Per poter accedere alla correzione del compito,
	echo "devi prima correggere gli errori che fanno fallire l'ultimo test."
	echo
	echo Quindi NON ho spedito il tuo compito per la correzione.
    fi

    echo
    echo "Scorri in alto fino all'inizio dell'ultimo test, se vuoi controllare "
    echo "di che test si tratta e qual'e' stato l'input dato al tuo programma."
    echo
    echo Se il tuo programma ha stampato troppe righe, perche\' e\' entrato in
    echo un ciclo infinito, allora potrebbe tornarti utile redirezionare l\'output
    echo su un file, e poi analizzare il contenuto del file.
    echo Ad esempio, puoi eseguire
    echo "$0 <nome_tuo_file_sorgente.cc> > output_file.txt"
    echo ed aspettare che il test termini. Non vedrai nessun output, perche\'
    echo sta andando tutto dentro al file output_file.txt. Se il test impiega troppo
    echo a terminare, allora puoi fermarlo manualmente.
    echo Successivamente, apri il file output_file.txt e cerchi il test fallito.
    echo
    echo Un volta trovato il test fallito, un modo per riuscire a correggere gli errori
    echo nel tuo programma e\' provare ad eseguire il tuo programma manualmente,
    echo dando lo stesso input provato da me.
    echo
    echo Quando il tuo programma superera\' questo test, eseguiro\' anche i successivi.
    echo

    rm controlla_output* righe_da_ultima_stampa*

    exit 1
}

esegui_test ()
{
    if [ $# -le 3 ]; then
	echo
	echo !! Troppo pochi parametri passati alla funzione esegui_test !!
	echo Per il test "$1"
	echo Test successivi cancellati
	echo

	exit 1
    fi

    nome_test="$1"
    punto=$2
    input_test="$3"
    num_linee_da_controllare=$4
    prima_linea_stampa="$5"

    if [ $4 -gt 5 ]; then
	echo Numero di righe da controllare maggiore del massimo supportato

	exit 1
    fi

    if [ $# -le $(($num_linee_da_controllare + 3)) ]; then
	echo Troppo pochi parametri passati alla funzione esegui_test
	echo $#

	exit 1
    fi

    echo
    echo ==== Inizio test $nome_test ====
    echo
    echo Eseguo il programma fornendo il seguente input: "$input_test"
    echo

    echo Ecco l\'output del programma, in cui non vedrai l\'input:
    echo

    ( while true; do sleep 1; \
		     if [[ "$(cat output_eseguibile.txt | wc -l)" -gt 500 ]]; \
		     then touch infinite_loop ; killall -9 $eseguibile; break; fi \
      done ) &
    CHECK_PID=$!
    disown

    # il comando echo DEVE supportare l\'opzione -e
    echo -e "$input_test" | ./$eseguibile | tee output_eseguibile.txt

    if [ -f infinite_loop  ]; then
	rm infinite_loop
	echo
	echo -n "Purtroppo il tuo programma sembra entrare in un ciclo infinito"
	echo " con l'ultimo test."
	stampa_msg_punto_insufficiente $punto
	return
    else
	kill -9 $CHECK_PID 2>&1 > /dev/null
    fi

    if [ $num_linee_da_controllare -ne 0 ]; then
	cat output_eseguibile.txt | \
	    ./righe_da_ultima_stampa "$prima_linea_stampa" \
	    | ./controlla_output $num_linee_da_controllare \
				 "$prima_linea_stampa" \
				 "$6" "$7" "$8" "$9"
    else
	echo In questo test non controllo l\'output del programma
	echo
    fi

    if [ $? -ne 0 ]; then
	stampa_msg_punto_insufficiente $punto
    fi
}

# - inserire sempre la scelta di uscire dal programma a fine input
esegui_tutti_test ()
{
    # se, per un dato test, il programma legge in input una o più
    # righe (cioe' sequenze di caratteri che possono contenere anche
    # spazi), incluso eventuali righe vuote, oltre ad altri elementi
    # (caratteri, numeri, parole) per qualche funzionalita', allora,
    # per passare anche tale riga in input al programma, bisogna
    # inserire un \n alla fine della riga, nella stringa completa
    # dell'input

    esegui_test "stampa senza reinizializzazione" "" "2 7" 0

    esegui_test "reinizializzazione a vuoto senza stampa" "" "1 0 7" 0

    esegui_test "reinizializzazione senza stampa" "" "1 1 7" 0

    esegui_test "reinizializzazione" "" "1 3 2 7" 2 "012" "---"

    esegui_test "reinizializzazione a molti elementi" "" "1 20 2 7" 2 "01234567890123456789" "--------------------"

    # reinizializzazione con carattere non valido
    # reinizializzazione a 4 elementi
    # reinizializzazione a 4 elementi con carattere non valido



    # doppia reinizializzazione con seconda a vuoto
    esegui_test "doppia reinizializzazione con seconda a vuoto" "" "1 20 2 1 0 7" 0


    # doppia reinizializzazione con seconda a un elemento
    esegui_test "doppia reinizializzazione con seconda ad un elemento" "" "1 20 1 1 2 7" 2 0 '-'

    # doppia reinizializzazione con seconda a 4 elementi
    esegui_test "doppia reinizializzazione con seconda a 4 elementi" "" "1 20 1 4 2 7" 2 "0123" "----"


    # doppia reinizializzazione con prima a vuoto e seconda a 4 elementi
    esegui_test "doppia reinizializzazione con prima a vuoto e seconda a 4 elementi" "" "1 0 1 4 2 7" 2 "0123" "----"

    # doppia reinizializzazione con prima a vuoto e seconda a 16 elementi
    esegui_test "doppia reinizializzazione con prima a vuoto e seconda a 16 elementi" "" "1 0 1 16 2 7" 2 "0123456789012345" "----------------"

    # stampa senza reinizializzazioni o inserimenti

    # "reinizializzazione a lunghezza massima uno"
    # "reinizializzazione a lunghezza massima due"
    # "reinizializzazione a una operazione"

    # "vendita di un biglietto con stampa"

    # inserimento di un oggetto
    esegui_test "inserimento di un oggetto" 3 "1 0 1 16 2 3 2 3 2 7" 2 "0123456789012345" "--***-----------"

    esegui_test "inserimento di due oggetti" 3 "1 0 1 16 2 3 2 3 3 6 2 2 7" 2 "0123456789012345" "--***-**--------"

    esegui_test "inserimento di un oggetto all'inizio" 3 "1 16 3 0 1 2 7" 2 "0123456789012345" "*---------------"

    esegui_test "inserimento di un oggetto alla fine" 3 "1 16 3 15 1 2 7" 2 "0123456789012345" "---------------*"

    esegui_test "inserimento di un oggetto di lunghezza uno nel mezzo con spazio prima" 3 "1 16 3 2 1 2 3 6 2 2 3 5 1 2 7" 2 "0123456789012345" "--*--***--------"

    esegui_test "inserimento di un oggetto di lunghezza uno nel mezzo, con spazio al limite" 3 "1 16 3 2 3 3 6 2 3 5 1 2 7" 2 "0123456789012345" "--******--------"

    esegui_test "inserimento di un oggetto troppo grande" 3 "1 3 3 0 4 2 7" 2 "012" "---"

    esegui_test "inserimento di un oggetto sovrapposto" 3 "1 16 3 2 3 3 4 2 2 7" 2 "0123456789012345" "--***-----------"

    esegui_test "inserimento di un oggetto nel mezzo con spazio insufficiente" 3 "1 16 3 2 1 2 3 6 2 2 3 5 2 2 7" 2 "0123456789012345" "--*---**--------"

    # "sostituzione di due parole nella stessa riga"
    # "sostituzione di due parole in righe diverse"
    # "doppia sostituzione di una parola corta-lunga"
    # "doppia sostituzione di una parola lunga-corta"
    # "tentativo sostituzione fuori matrice"
    # reinizializzazione a due elementi più complessi, se ha senso per questo compito
    # reinizializzazione ad un elemento inconsistente
    # esegui_test "reinizializzazione a una operazione con indice uguale a 0" "" "1 1 A 0\n 2 7" 0
    # esegui_test "reinizializzazione a una operazione con indice troppo alto" "" "1 1 A 2\n 2 7" 0
    # inserimento di troppi elementi

    # "salvataggio"
    esegui_test "salvataggio" 4 "1 0 1 16 2 3 2 3 4 2 7" 2 "0123456789012345" "--***-----------"

    esegui_test "salvataggio e reinizializzazione" 4 "1 16 2 3 2 3 4 2 1 1 2 7" 2 "0" "-"

    # "caricamento"
    esegui_test "caricamento" 5 "5 2 7" 2 "0123456789012345" "--***-----------"


    # reinizializzazione a meno elementi dopo caricamento
    esegui_test "reinizializzazione a meno elementi dopo caricamento" 5 "5 1 1 2 7" 2 "0" "-"
    esegui_test "reinizializzazione a zero elementi dopo caricamento" 5 "5 1 0 2 7" 0

    # caricamento dopo reinizializzazione
    esegui_test "caricamento dopo reinizializzazione" 5 "1 5 5 2 7" 2 "0123456789012345" "--***-----------"

    # "inserimento dopo caricamento"

    esegui_test "inserimento dopo caricamento" 5 "5 1 16 2 3 2 3 2 7" 2 "0123456789012345" "--***-----------"

    esegui_test "caricamento dopo inserimento di due oggetti" 5 "1 0 1 12 2 3 2 3 3 6 2 5 2 7" 2 "0123456789012345" "--***-----------"

    esegui_test "inserimento 2 di un secondo oggetto nella stessa posizione di un primo oggetto" 6 \
		"1 16 3 2 3 6 2 2 2 7" 2 "0123456789012345" "--*****---------"

    esegui_test "inserimento 2 di un secondo oggetto nel mezzo di un primo oggetto" 6 \
		"1 16 3 2 3 6 3 2 2 7" 2 "0123456789012345" "---*****--------"

    esegui_test "inserimento 2 di un secondo oggetto che non ha spazio dopo" 6 \
		"1 16 3 2 3 6 1 2 2 7" 2 "0123456789012345" "-*****----------"

    return

    # "caricamento dopo inserimento di più elementi"

    # "salvataggio e caricamento dopo inserimento di meno elementi"

    # "solo caricamento dopo inserimento di meno elementi"

    # "estrai biglietto da insieme vuoto"

    # "estrai biglietto da insieme con un elemento"

    # "estrai tre biglietti da insieme vuoto"

    # "estrai tre biglietti da insieme con un elemento"

    # reinizializzazione dopo caricamento

    # eliminazione di un elemento

    # eliminazione di due elementi

    # eliminazione di tutti gli elementi

    # eliminazione di troppi elementi

    # accodamento di due utenti dopo eliminazione

    # "scambia su matrice vuota"

    # "scambia tra due parole non vuote"

    # "scambia con una parola vuota"

    # esegui_test "tentativo di scambio con una parola fuori matrice" 5 "4 5 0 0 2 0 5 0 0 2 10 2 7" 3 "Paperino" "Minnie" "Pippo Quo"

    # esegui_test "scambia con minima su matrice vuota" 6 "6 0 0 2 7" 3 "" "" ""

    # esegui_test "scambia parola non vuota con minima non vuota" 6 "4 2 6 0 0 2 7" 3 "Quo Paperino" "Minnie" "Pippo"

    # esegui_test "scambia parola vuota con minima non vuota" 6 "4 6 1 1 2 7" 3 "Pippo Paperino" "Minnie Quo" ""

    # esegui_test "tentativo di scambio con una parola fuori matrice" 6 "4 6 2 5 2 7" 3 "Pippo Paperino" "Minnie" "Quo"

    # prova funzionalità con contenuto inferiore al massimo possibile
    # prova funzionalità con contenuto inferiore al massimo possibile
    # assegnamento con più docenti che corsi: implicito nel test con caricamento
    # prova funzionalità con successo
    # prova funzionalità con fallimento
}

# MAIN

sorgente=$1
eseguibile=a.out

if [ "$(echo -e)" != "" ]; then
    echo "In questa shell il comando echo non rispetta l'opzione -e"
    echo "Devi eseguirmi con una shell che rispetti tale opzione"
    echo "Una tale shell e' bash"
    exit
fi

if [ "$sorgente" = "" ]; then
    echo
    echo Devi fornirmi il nome del file sorgente da collaudare.
    echo
    echo Ossia devi invocarmi cosi\':
    echo bash $0 nome_tuo_file_sorgente.cc
    echo

    exit 1
fi

if command -v sender &> /dev/null; then
   spedisci-sorgente $sorgente
fi

g++ -std=c++11 -Wall -Wsign-compare -Werror -pedantic-errors $sorgente

if [ $? -ne 0 ]; then
    echo Compilazione fallita.
    echo
    echo Il tuo programma deve almeno compilarsi per poter accedere alla correzione.
    exit 1
fi

if [ $? -ne 0 ]; then
    echo
    echo Compilazione del sorgente $sorgente fallita.
    echo Questo vuol dire che il file non e\' stato trovato dal compilatore,
    echo oppure che la compilazione ha generato degli errori o delle warning.
    echo Leggi le righe che precedono questo messaggio per vedere di che
    echo errore si tratta esattamente.
    echo
    echo Il tuo sorgente NON e\' stato spedito. Il sorgente deve compilarsi
    echo senza errori per poter essere spedito per la correzione.
    echo

    exit 1
fi

if [ ! -f $eseguibile ]; then
    echo Eseguibile $eseguibile non trovato
    exit 1
fi

crea_tester

esegui_tutti_test

echo Complimenti, il tuo programma ha superato tutti i test!
echo
if ! command -v sender &> /dev/null
then
    echo "Sono eseguito su un PC personale, non spedisco nulla."
else
	retval=$(sender $sorgente `whoami` | grep "moved successfully")
	if ! echo $retval | grep "not"
	then
		echo Ho spedito quindi il tuo compito per la correzione.
		echo Invocami di nuovo se vuoi fare spedire una nuova versione del tuo compito.
	else
		echo Non sono riuscito a spedire il file per la correzione.
		echo Contatta il docente del corso per chiarimenti se necessario.
	fi
fi

rm controlla_output* righe_da_ultima_stampa*
