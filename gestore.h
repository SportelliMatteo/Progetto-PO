#ifndef GESTORE_H
#define GESTORE_H

#include <string>
#include <list>
#include <algorithm>
#include <QDateTime>
#include <float.h>
#include "dipendente.h"
#include "dipendentesenior.h"
#include "dipendentejunior.h"
#include "progetto.h"
#include <iostream>
using namespace std;

/*
* La classe Gestore contiene tutti i metodi da implementare per il progetto divisi per sezione.
*
* Sono consentite le seguenti modifiche alla classe:
* - Si deve modificare list<???>/vector???> scegliendo tra list o vector e sostituendo ??? con il tipo scelto da voi. Ad esempio:
*    list<???>/vector<???> getDipendenti() const; potrebbe essere list<Dipendente> getDipendenti() oppure list<Dipendente*> getDipendenti() oppure vector<Dipendente> getDipendenti(), ecc.
* - Si possono aggiungere nuovi metodi e campi.
* - Si possono aggiungere funzioni.
* - Si possono includere librerie e file.
* - Si devono implementare i metodi nel file Gestore.cpp.
*
* Tutto il resto non va modificato.
*
* Nel caso in cui non sia voglia implementare un metodo si può lasciare vuoto restituendo l'oggetto opportuno.
* Ad esempio, si supponga di non implementare il metodo c3, nel file Gestore.cpp si può scrivere il seguente codice:
*
* list<Dipendente*> Gestore::c3() const {
*     list<Dipendente*> empty;
*     return empty;
* }
*/

class Gestore {

    private:
        list<Dipendente*> dipendenti;
        list<Progetto*> progetti;

        void clear();

    public:

        Gestore();
        Gestore(const Gestore&);
        Gestore& operator=(const Gestore&);
        ~Gestore();

        /*
        ***
        SEZIONE A
        ***
        */

        //A1: Aggiunta di un dipendente senior.
        void aggiungiDipendenteSenior(string matricola, string nome, string cognome, double stipendio, const list<string>& reperibilita, const list<string>& subordinati);

        list<DipendenteSenior*> getDipendentiSenior() const;

        //A2: Aggiunta di un dipendente junior.
        void aggiungiDipendenteJunior(string matricola, string nome, string cognome, double stipendio, const list<string>& skill, string stagista);

        list<DipendenteJunior*> getDipendentiJunior() const;

        //A3: Aggiunta di un progetto.
        void aggiungiProgetto(string nome, string data, int durata, double budget, string responsabile);

        //A4: Visualizzare tutti i dipendenti.
        list<Dipendente*> getDipendenti() const;

        //A5: Visualizzare tutti i progetti.
        list<Progetto*> getProgetti() const;

        /*
        ***
        SEZIONE B
        ***
        */
        //B1: Visualizzare tutti i progetti di cui un dipendente senior è responsabile.
        list<Progetto*> b1(string matricola) const;

        bool isDipendeteSeniorResponsabileDiJunior(string matricolaDipendeteSenior, string matricolaDipendenteJunior) const;

        //B2: Visualizzare tutti i progetti di cui un dipendente junior è partecipante.
        list<Progetto*> b2(string matricola) const;

        //Ritorno le skill del dipendente junior con matricola uguale a quella nei parametri
        list<string> getDipendenteJuniorSkills(string matricola) const;

        //B3: Visualizzare tutte le skill (senza duplicati) dei dipendenti partecipanti a un progetto.
        list<string> b3(string nomeProgetto) const;

        //B4: Visualizzare le skill presenti in tutti i dipendenti.
        list<string> b4() const;

        //B5: Visualizzare le 5 skill più diffuse tra i dipendenti.
        vector<string> b5() const;

        list<string> getSkillDaMatricole(list<string> subordianati) const;

        //B6: Visualizzare i progetti i cui dipendenti non hanno skill in comune.
        list<Progetto*> b6() const;

        //B7: Visualizzare i progetti con il budget più basso tra tutti i progetti di un responsabile.
        list<Progetto*> b7(string matricola) const;

        //B8: Visualizzare i progetti con il budget più alto tra tutti i progetti di un responsabile.
        list<Progetto*> b8(string matricola) const;

        //B9: Visualizzare la media dei budget di tutti i progetti di un responsabile.
        double b9(string matricola) const;

        //B10: Visualizzare tutti i progetti ordinati per budget crescente.
        list<Progetto*> b10() const;

        //B11: Visualizzare tutti i progetti ordinati per budget decrescente.
        list<Progetto*> b11() const;

        //B12: Visualizzare tutti i progetti ordinati per data di inizio crescente.
        list<Progetto*> b12() const;

        //B13: Visualizzare tutti i progetti ordinati per data di inizio decrescente.
        list<Progetto*> b13() const;

        //B14: Visualizzare tutti i progetti ordinati per durata decrescente, a parità di durata, ordinati per prezzo crescente e, a parità di prezzo, ordinati in ordine alfabetico del nome.
        list<Progetto*> b14() const;

        /*
        ***
        SEZIONE C
        ***
        */

        bool isSkillDipendenteJuniorInProgetto(Progetto* p, string skill) const;

        //C1: Il guadagno di una skill è definito come la somma dei budget di tutti i progetti in cui c’è almeno un dipendente con quella skill partecipante al progetto. Visualizzare tutte le skill con il guadagno più alto.
        list<string> c1() const;

        list<string> getSkillFromDipendenteSenior(DipendenteSenior* dipendeteSenior) const;

        bool isAsottoInsiemeProprioDiB(list<string> A, list<string> B) const;

        //C2: Visualizzare i dipendenti senior indispensabili. Un dipendente senior D1 è considerato indispensabile se esiste un altro dipendente senior D2 tale che le skill dei subordinati di D1 sono un soprainsieme proprio delle skill dei subordinati di D2.
        list<DipendenteSenior*> c2() const;


        /*C3: Visualizzare tutti i dipendenti junior influenzati da un dipendente senior. Un dipendente junior D1 influenza un altro dipendente junior D2 se
                - D2 è uno stagista di D1, oppure
                - D1 influenza un dipendente junior D e D influenza DJ
              Un dipendente senior DS influenza un dipendente junior DJ se DJ è un subordinato di DS oppure se esiste un dipendente D che è subordinato di DS e D influenza DJ. */
        list<DipendenteJunior*> c3(string matricola) const;

        list<string> getSkillsFromProgetto(Progetto* p) const;

        int skillsInComune(list<string> skillsP1, list<string> skillsP2) const;

        int skillsNonInComune(list<string> skillsP1, list<string> skillsP2) const;

        bool termineStessoMeseEAnno(Progetto* p1, Progetto* p2) const;

        Progetto* getProgettoFromNome(string nomeProgetto) const;

        //C4: Visualizzare i progetti simili a un progetto specificato dall’utente. Un progetto è simile a un altro progetto se il numero di skill che hanno in comune è almeno il doppio rispetto al numero di skill che non hanno in comune e se finiscono nello stesso mese.
        list<Progetto*> c4(string nomeProgetto) const;


        //C5: Una coppia di dipendenti senior D1,D2 è considerata ottimale se la combinazione dei loro giorni di reperibilità copre l’intera settimana (ad esempio, D1 è reperibile da lunedì a venerdì e D2 è reperibile da mercoledì a domenica) e se tutti i loro progetti non hanno intersezioni di date (ad esempio i progetti di D1 iniziano tutti il 1 gennaio 2021 e durano 11 mesi e i progetti di D2 iniziano tutti il 1 dicembre 2021). Visualizzare tutte le coppie (senza duplicati) di dipendenti senior ottimali.
        list<DipendenteSenior*> c5() const;


};

#endif // GESTORE_H

