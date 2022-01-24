 #include "gestore.h"
#include "dipendentesenior.h"

Gestore::Gestore(){ }

Gestore::Gestore(const Gestore& g){

    for(auto d : g.dipendenti){
        dipendenti.push_back(d->clone());
    }

    for(auto p : g.progetti){
        progetti.push_back(p->clone());
    }

}

void Gestore::clear(){

    for(auto d : dipendenti){
        delete d;
    }
    dipendenti.clear();

    for(auto p : progetti){
        delete p;
    }
    progetti.clear();

}

Gestore& Gestore::operator=(const Gestore& g){

    if(this != &g){
        clear();
        for(auto d : g.dipendenti){
            dipendenti.push_back(d->clone());
        }
        for(auto p : g.progetti){
            progetti.push_back(p->clone());
        }
    }
    return *this;
}

Gestore::~Gestore(){
    clear();
}

void Gestore::aggiungiDipendenteSenior(string matricola, string nome, string cognome, double stipendio, const list<string>& reperibilita, const list<string>& subordinati){

    for(auto d : dipendenti){
        if(matricola == d->getMatricola()){
            return;
        }
    }

    DipendenteSenior* dipendenteSenior = new DipendenteSenior(matricola, nome, cognome, stipendio, reperibilita, subordinati);

    dipendenti.push_back(dipendenteSenior);

}

list<DipendenteSenior*> Gestore::getDipendentiSenior() const {
    list<DipendenteSenior*> dipendetiSenior;
    for(auto d : dipendenti){
        DipendenteSenior* dipendenteSenior = dynamic_cast<DipendenteSenior*>(d);
        if(dipendenteSenior != nullptr){
              dipendetiSenior.push_back(dipendenteSenior);
        }
    }
    return dipendetiSenior;
}

void Gestore::aggiungiDipendenteJunior(string matricola, string nome, string cognome, double stipendio, const list<string>& skill, string stagista){

    for(auto d : dipendenti){
        if(matricola == d->getMatricola()){
            return;
        }
    }

    DipendenteJunior* dipendenteJunior = new DipendenteJunior(matricola, nome, cognome, stipendio, skill, stagista);

    dipendenti.push_back(dipendenteJunior);

}

list<DipendenteJunior*> Gestore::getDipendentiJunior() const{
    list<DipendenteJunior*> dipendetiJunior;
    for(auto d : dipendenti){
        DipendenteJunior* dipendenteJunior = dynamic_cast<DipendenteJunior*>(d);
        if(dipendenteJunior != nullptr){
              dipendetiJunior.push_back(dipendenteJunior);
        }
    }
    return dipendetiJunior;
}

void Gestore::aggiungiProgetto(string nome, string data, int durata, double budget, string responsabile){

    for(auto p : progetti){
        if(nome == p->getNome()){
            return;
        }
    }

    Progetto* progetto = new Progetto(nome, data, durata, budget, responsabile);

    progetti.push_back(progetto);

}

list<Dipendente*> Gestore::getDipendenti() const{
    return dipendenti;
}

list<Progetto*> Gestore::getProgetti() const{
    return progetti;
}

//B1: Visualizzare tutti i progetti di cui un dipendente senior è responsabile.
list<Progetto*> Gestore::b1(string matricola) const{
    list<Progetto*> progettiDipendente;
    for(auto p : progetti){
        if(p->getResponsabile() == matricola){
            progettiDipendente.push_back(p);
        }
    }
    return progettiDipendente;
}

bool Gestore::isDipendeteSeniorResponsabileDiJunior(string matricolaDipendeteSenior, string matricolaDipendenteJunior) const{
    for(auto d : dipendenti){
        DipendenteSenior* dipendenteSenior = dynamic_cast<DipendenteSenior*>(d);
        if(dipendenteSenior != nullptr && matricolaDipendeteSenior == dipendenteSenior->getMatricola()){
            list<string> subordinati = dipendenteSenior->getlistaSubordinati();
            for(auto s : subordinati){
                if(s == matricolaDipendenteJunior){
                    return true;
                }
            }
        }
    }
    return false;
}

//B2: Visualizzare tutti i progetti di cui un dipendente junior è partecipante.
list<Progetto*> Gestore::b2(string matricola) const{
    list<Progetto*> progettiDipendente;
    for(auto p : progetti){
        string responsabile = p->getResponsabile();
        if(isDipendeteSeniorResponsabileDiJunior(responsabile, matricola)){
            progettiDipendente.push_back(p);
        }
    }
    return progettiDipendente;
}

//Ritorno le skill del dipendente junior con matricola uguale a quella nei parametri
list<string> Gestore::getDipendenteJuniorSkills(string matricola) const{
    list<string> dipendenteJuniorSkills;
    for(auto d : dipendenti){
        if(d->getMatricola() == matricola){
            DipendenteJunior* dipendenteJunior = dynamic_cast<DipendenteJunior*>(d);
            if(dipendenteJunior != nullptr){
                dipendenteJuniorSkills = dipendenteJunior->getSkill();

            }
        }
    }
    return dipendenteJuniorSkills;
}

list<string> Gestore::b3(string nomeProgetto) const{
    list<string> skillsTotali;
    for(auto p : progetti){ //Scorro i progetti
        if(p->getNome() == nomeProgetto){ //Controllo se il nome del progetto corrente è uguale a quello nei parametri
            for(auto d : dipendenti){ //Se lo è, scorro i dipentendi
                if(p->getResponsabile() == d->getMatricola()){ //Controllo che il responsabile del progetto corrente ha matricola uguale a quella del responsabile del progetto nei parametri
                    DipendenteSenior* dipendenteSenior = dynamic_cast<DipendenteSenior*>(d);
                    if(dipendenteSenior != nullptr){ //Controllo che il dipendente corrente sia un dipendenteSenior e se lo è
                       list<string> subordinati = dipendenteSenior->getlistaSubordinati(); //Prendo tutti i subordinati del dipendenteSenior corrente
                       for(auto s : subordinati){ //Scorro i subordinati
                           list<string> skills = getDipendenteJuniorSkills(s); //Creo una lista di string e gli assegno le skill dei dipententi junior
                           for(auto skill : skills){ //Scorro le skill
                               if(find(skillsTotali.begin(), skillsTotali.end(), skill) == skillsTotali.end()){ //Cerco una skill per volta nella lista di skillTotali e verifico che non sia presente
                                   skillsTotali.push_back(skill); //Se non lo è, la inserisco
                               }
                           }
                       }
                   }
                }
            }
            break;
        }
    }
    return skillsTotali; //Ritorno le skill inserite.
}

list<string> Gestore::b4() const{
    list<string> skillsTotali;
    for(auto d : dipendenti){ //Scorro i dipendenti
        DipendenteJunior* dipendenteJunior = dynamic_cast<DipendenteJunior*>(d);
            if(dipendenteJunior != nullptr){ //Controllo che il dipendente corrente sia un dipendenteJunior e se lo è
            list<string> skills = dipendenteJunior->getSkill(); //Creo una list di string e gli assegno le skill di un dipendente junior
            for(auto s : skills){ //Scorro le skill
                if(find(skillsTotali.begin(), skillsTotali.end(), s) == skillsTotali.end()){ //Cerco una skill per volta nella lista di skillTotali e verifico che non sia presente
                    skillsTotali.push_back(s); //Se non lo è, la inserisco
                }
            }
        }
    }
    return skillsTotali; //Ritorno le skill inserite
}

vector<string> Gestore::b5() const{
    //Vado a inserire nel vettore skills creato le skill di ogni dipendenteJunior
    vector<string> skills;
    for(auto d : dipendenti){
        DipendenteJunior* dipendenteJunior = dynamic_cast<DipendenteJunior*>(d);
        if(dipendenteJunior != nullptr){
            list<string> dipendenteJuniorSkillsList = dipendenteJunior->getSkill(); //Prendo le skill del dipendente junior corrente
            vector<string> dipendenteJuniorSkills(dipendenteJuniorSkillsList.begin(), dipendenteJuniorSkillsList.end()); //Le skill del dipendente junior corrente vengono inserite in un vector
            skills.insert(skills.end(), dipendenteJuniorSkills.begin(), dipendenteJuniorSkills.end()); //Unisco le skill del dipendente junior corrente alle skill di tutti gli altri dipendenti junior
        }
    }

    //Controllo le occorrenze per 5 volte
    vector<string> skillsDiffuse;

    for(int i = 0; i < 5; i++){
        int max = INT_MIN;
        string skill = "";
        for(int j = 0; j < skills.size(); j++){
            int cont = 0;
            for(int k = 0; k < skills.size(); k++){
                if(j != k){
                    if(skills[j] == skills[k]){
                        cont++;
                    }
                }
            }
            if(cont > max){
                max = cont;
                skill = skills[j];
            }
        }
        if(skill != ""){ //Se il valore dell'ultima skill è diverso dalla stringa vuota
            skillsDiffuse.push_back(skill); //Allora la inserisco
        }
        skills.erase(remove(skills.begin(), skills.end(), skill), skills.end()); //Rimuove tutte le occorrenze di una skill all'interno del vector skills
    }

    return skillsDiffuse;

}

list<string> Gestore::getSkillDaMatricole(list<string> subordianati) const{

    list<DipendenteJunior*> dipendentiJunior = getDipendentiJunior();
    list<string> skills;
    for(auto s : subordianati){
        for(auto d : dipendentiJunior){
            if(s == d->getMatricola()){
                list<string> skillsDipendente = d->getSkill();

                skills.merge(skillsDipendente); //Per ogni subordinato presente nella lista tra i parametri prendo le skill e le metto tutte quante in un'unica lista
            }
        }
    }
    return skills;
}

//Visualizzare i progetti i cui dipendenti non hanno skill in comune.
list<Progetto*> Gestore::b6() const{

    list<DipendenteSenior*> dipendentiSenior = getDipendentiSenior();
    list<Progetto*> progetti = getProgetti();
    list<Progetto*> progettiSkillsNonDuplicate;
    for(auto p : progetti){
        list<string> skills;
        for(auto ds : dipendentiSenior){
            if(p->getResponsabile() == ds->getMatricola()){
                list<string> subordinati = ds->getlistaSubordinati();
                skills = getSkillDaMatricole(subordinati);
                break;
            }
        }
        vector<string> skillsVector;
        for(auto s : skills){
            skillsVector.push_back(s);
        }




        bool comune = false;
        for(int i = 0; i < skillsVector.size(); i++){
            for(int j = 0; j < skillsVector.size(); j++){
                if(i != j){ //Se la posizione è diversa
                    if(skillsVector[i] == skillsVector[j]){ //Se l'elemento è uguale
                        comune = true;
                        break;
                    }
                }
            }
            if(comune == true){
                break;
            }
        }
        if(comune == false){
            progettiSkillsNonDuplicate.push_back(p);
        }
    }
    return progettiSkillsNonDuplicate;
}

//B7: Visualizzare i progetti con il budget più basso tra tutti i progetti di un responsabile.
list<Progetto*> Gestore::b7(string matricola) const{

    double minBudget = DBL_MAX;

    for(auto p : progetti){
        if(p->getResponsabile() == matricola){
           if(p->getBudget() < minBudget){
               minBudget = p->getBudget();
           }
        }
    }

    list<Progetto*> progettiResponsabile;
    for(auto p : progetti){
        if(p->getResponsabile() == matricola){
           if(p->getBudget() == minBudget){
               progettiResponsabile.push_back(p);
           }
        }
    }
    return progettiResponsabile;
}

//B8: Visualizzare i progetti con il budget più alto tra tutti i progetti di un responsabile.
list<Progetto*> Gestore::b8(string matricola) const{

    double maxBudget = DBL_MIN;

    for(auto p : progetti){
        if(p->getResponsabile() == matricola){
           if(p->getBudget() > maxBudget){
               maxBudget = p->getBudget();
           }
        }
    }

    list<Progetto*> progettiResponsabile;
    for(auto p : progetti){
        if(p->getResponsabile() == matricola){
           if(p->getBudget() == maxBudget){
               progettiResponsabile.push_back(p);
           }
        }
    }

    return progettiResponsabile;

}

double Gestore::b9(string matricola) const{

    double sommaBudget = 0.0;
    double contaProgetti = 0.0;

    for(auto p : progetti){
        if(p->getResponsabile() == matricola){
            sommaBudget += p->getBudget();
            contaProgetti++;
        }
    }

    if(contaProgetti > 0){
        return sommaBudget / contaProgetti;
    }

    return 0;

}

bool comparaBudgetProgettiCrescente(Progetto* p1, Progetto* p2){
    if(p1->getBudget() < p2->getBudget()){
        return true;
    }
    return false;
}

list<Progetto*> Gestore::b10() const{

    list<Progetto*> progettiTmp = progetti;

    progettiTmp.sort(comparaBudgetProgettiCrescente);

    return progettiTmp;

}

bool comparaBudgetProgettiDecrescente(Progetto* p1, Progetto* p2){
    if(p1->getBudget() > p2->getBudget()){
        return true;
    }
    return false;
}

list<Progetto*> Gestore::b11() const{

    list<Progetto*> progettiTmp = progetti;

    progettiTmp.sort(comparaBudgetProgettiDecrescente);

    return progettiTmp;

}



bool comparaDataInizioProgettiCrescente(Progetto* p1, Progetto* p2){

    string data1 = p1->getDataInizio();

    string giorno1 = data1.substr(8, 2);
    string mese1 = data1.substr(5, 2);
    string anno1 = data1.substr(0, 4);

    string data2 = p2->getDataInizio();

    string giorno2 = data2.substr(8, 2);
    string mese2 = data2.substr(5, 2);
    string anno2 = data2.substr(0, 4);

    if(anno1 < anno2){
        return true;
    }
    if(anno1 == anno2 && mese1 < mese2){
        return true;
    }
    if(anno1 == anno2 && mese1 == mese2 && giorno1 < giorno2){
        return true;
    }

    return false;

}

list<Progetto*> Gestore::b12() const{

    list<Progetto*> progettiTmp = progetti;

    progettiTmp.sort(comparaDataInizioProgettiCrescente);

    return progettiTmp;

}

list<Progetto*> Gestore::b13() const{

    list<Progetto*> progettiTmp = progetti;

    progettiTmp.sort(comparaDataInizioProgettiCrescente);

    progettiTmp.reverse();

    return progettiTmp;

}

bool comparaPerB14(Progetto* p1, Progetto* p2){

    if(p1->getDurata() > p2->getDurata()){
        return true;
    }
    if(p1->getDurata() == p2->getDurata() && p1->getBudget() < p2->getBudget()){
        return true;
    }
    return p1->getNome() < p2->getNome();

}

//B14: Visualizzare tutti i progetti ordinati per durata decrescente, a parità di durata, ordinati per prezzo crescente e, a parità di prezzo, ordinati in ordine alfabetico del nome.
list<Progetto*> Gestore::b14() const{

    list<Progetto*> progettiTmp = progetti;

    progettiTmp.sort(comparaPerB14);

    return progettiTmp;

}

bool Gestore::isSkillDipendenteJuniorInProgetto(Progetto* p, string skill) const{
    list<string> subordinati;
    for(auto d : dipendenti){
        DipendenteSenior* dipendenteSenior = dynamic_cast<DipendenteSenior*>(d);
        if(dipendenteSenior != nullptr){
            if(p->getResponsabile() == dipendenteSenior->getMatricola()){
                subordinati = dipendenteSenior->getlistaSubordinati();
                break;
            }
        }
    }

    for(auto s : subordinati){
        list<string> skillsDipendente;
        for(auto d : dipendenti){
            DipendenteJunior* dipendenteJunior = dynamic_cast<DipendenteJunior*>(d);
            if(dipendenteJunior != nullptr){
                if(s == dipendenteJunior->getMatricola()){
                    skillsDipendente = dipendenteJunior->getSkill();
                    if(find(skillsDipendente.begin(), skillsDipendente.end(), skill) != skillsDipendente.end()){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

//C1: Il guadagno di una skill è definito come la somma dei budget di tutti i progetti in cui c’è almeno un dipendente con quella skill partecipante al progetto. Visualizzare tutte le skill con il guadagno più alto.
list<string> Gestore::c1() const{

    list<string> skillsSenzaDuplicati;

    for(auto d : dipendenti){
        DipendenteJunior* dipendenteJunior = dynamic_cast<DipendenteJunior*>(d);
        if(dipendenteJunior != nullptr){
            list<string> skillsDipendente = dipendenteJunior->getSkill();
            skillsSenzaDuplicati.merge(skillsDipendente);
        }
    }
    skillsSenzaDuplicati.sort();//ordino la lista
    skillsSenzaDuplicati.unique(); //Restituisce la lista senza duplicati

    double budgetMax = DBL_MIN;
    list<string> skillsGuadagnoPiuAlto;

    for(auto s : skillsSenzaDuplicati){
        double budget = 0.0;
        for(auto p : progetti){
           if(isSkillDipendenteJuniorInProgetto(p, s)){
               budget += p->getBudget();
               break;
           }
        }
        if(budget > budgetMax){
            budgetMax = budget;
            skillsGuadagnoPiuAlto.clear();
            skillsGuadagnoPiuAlto.push_back(s);
        }else if(budget == budgetMax){
            skillsGuadagnoPiuAlto.push_back(s);
        }
    }
    return skillsGuadagnoPiuAlto;
}

list<string> Gestore::getSkillFromDipendenteSenior(DipendenteSenior* dipendeteSenior) const{
    list<string> subordinati = dipendeteSenior->getlistaSubordinati();
    list<string> skillsDipendenteSenior;
    for(auto s : subordinati){
        for(auto d : dipendenti){
            DipendenteJunior* dipendenteJunior = dynamic_cast<DipendenteJunior*>(d);
            if(dipendenteJunior != nullptr){
                if(s == d->getMatricola()){
                    list<string> skills = dipendenteJunior->getSkill();
                    skillsDipendenteSenior.merge(skills);
                }
            }
        }
    }
    skillsDipendenteSenior.sort();
    skillsDipendenteSenior.unique();
    return skillsDipendenteSenior;
}

bool Gestore::isAsottoInsiemeProprioDiB(list<string> A, list<string> B) const{
    if(A.size() == 0){ //Verifico che A non sia vuoto
        return false;
    }
    for(auto e : A){ //Scorro gli elementi di A
        if(find(B.begin(), B.end(), e) == B.end()){ //Verifico che ogni elemento di A sia in B
            return false; //Se un elemento di A non è in B allora ritorno false
        }
    }
    for(auto e : B){ //Scorro gli elementi di B
        if(find(A.begin(), A.end(), e) == A.end()){ //Verifico che almeno un elemento di B non sia in A
            return true; //Se un elemento di B non è in A allora ritorno true
        }
    }
    return false; //In tutti gli altri casi ritorno false
}

//C2: Visualizzare i dipendenti senior indispensabili. Un dipendente senior D1 è considerato indispensabile se esiste un altro dipendente senior D2
//    tale che le skill dei subordinati di D1 sono un soprainsieme proprio delle skill dei subordinati di D2.
list<DipendenteSenior*> Gestore::c2() const{

   list<DipendenteSenior*> dipendentiSenior = getDipendentiSenior();
   list<DipendenteSenior*> dipendentiSeniorIndispensabili;

   for(auto d1 : dipendentiSenior){
       bool trovato = false;
       for(auto d2 : dipendentiSenior){
           if(d1->getMatricola() != d2->getMatricola()){
               list<string> skillsD1 = getSkillFromDipendenteSenior(d1);
               list<string> skillsD2 = getSkillFromDipendenteSenior(d2);
               if(isAsottoInsiemeProprioDiB(skillsD2, skillsD1) == true){
                   for(auto d : dipendentiSeniorIndispensabili){
                       if(d->getMatricola() == d1->getMatricola()){
                           trovato = true;
                       }
                   }
                   if(trovato == false){
                       dipendentiSeniorIndispensabili.push_back(d1);
                   }
               }
           }
       }
   }
   return dipendentiSeniorIndispensabili;
}

list<DipendenteJunior*> Gestore::c3(string matricola) const {
    list<DipendenteJunior*> empty;
    return empty;
}

list<string> Gestore::getSkillsFromProgetto(Progetto* p) const{

    list<string> skillsProgetto;

    for(auto d : dipendenti){
        DipendenteSenior* dipendenteSenior = dynamic_cast<DipendenteSenior*>(d);
        if(dipendenteSenior != nullptr){
            if(dipendenteSenior->getMatricola() == p->getResponsabile()){
                list<string> subordinati = dipendenteSenior->getlistaSubordinati();
                for(auto s : subordinati){
                    for(auto d : dipendenti){
                        DipendenteJunior* dipendenteJunior = dynamic_cast<DipendenteJunior*>(d);
                        if(dipendenteJunior != nullptr){
                            if(s == d->getMatricola()){
                                list<string> skillsDipendenteJunior = dipendenteJunior->getSkill();
                                skillsProgetto.merge(skillsDipendenteJunior);
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    skillsProgetto.sort();
    skillsProgetto.unique();
    return skillsProgetto;
}

int Gestore::skillsInComune(list<string> skillsP1, list<string> skillsP2) const{

    int cont = 0;
    for(auto s : skillsP1){
        if(find(skillsP2.begin(), skillsP2.end(), s) != skillsP2.end()){
            cont++;
        }
    }

    return cont;

}

int Gestore::skillsNonInComune(list<string> skillsP1, list<string> skillsP2) const{

    int cont = 0;
    for(auto s : skillsP1){
        if(find(skillsP2.begin(), skillsP2.end(), s) == skillsP2.end()){
            cont++;
        }
    }

    for(auto s : skillsP2){
        if(find(skillsP1.begin(), skillsP1.end(), s) == skillsP1.end()){
            cont++;
        }
    }

    return cont;

}

bool Gestore::termineStessoMeseEAnno(Progetto* p1, Progetto* p2) const{

    string dataInizioP1Std = p1->getDataInizio();
    int durataP1 = p1->getDurata();

    string dataInizioP2Std = p2->getDataInizio();
    int durataP2 = p2->getDurata();

    QString dataInizioP1 = QString::fromStdString(dataInizioP1Std);
    QString dataInizioP2 = QString::fromStdString(dataInizioP2Std);
    QString format = "yyyy/MM/dd";

    QDateTime dataInizioP1Formatted = QDateTime::fromString(dataInizioP1, format);
    QDateTime dataInizioP2Formatted = QDateTime::fromString(dataInizioP2, format);

    QDateTime dataFineP1Formatted = dataInizioP1Formatted.addMonths(durataP1); //Aggiungo alla data di inizio la durata in modo da ottenere la data di fine
    QDateTime dataFineP2Formatted = dataInizioP2Formatted.addMonths(durataP2);

    QString dataFineP1 = dataFineP1Formatted.toString(format);
    QString dataFineP2 = dataFineP2Formatted.toString(format);

    QStringList dataFineP1Splitted = dataFineP1.split("/");
    QStringList dataFineP2Splitted = dataFineP2.split("/");

    if(dataFineP1Splitted.at(0) == dataFineP2Splitted.at(0) && dataFineP1Splitted.at(1) == dataFineP2Splitted.at(1)){
        return true;
    }
    return false;
}

Progetto* Gestore::getProgettoFromNome(string nomeProgetto) const {
    for(auto p : progetti){
        if(p->getNome() == nomeProgetto){
            return p;
        }
    }
}

//C4: Visualizzare i progetti simili a un progetto specificato dall’utente. Un progetto è simile a un altro progetto se il
//    numero di skill che hanno in comune è almeno il doppio rispetto al numero di skill che non hanno in comune e se finiscono nello stesso mese.
list<Progetto*> Gestore::c4(string nomeProgetto) const{

    Progetto* p1 = getProgettoFromNome(nomeProgetto);


    list<Progetto*> progettiSimili;

    for(auto p2 : progetti){
        if(p1->getNome() != p2->getNome()){
            list<string> skillsP1 = getSkillsFromProgetto(p1);
            list<string> skillsP2 = getSkillsFromProgetto(p2);
            if(skillsInComune(skillsP1, skillsP2) >= (skillsNonInComune(skillsP1, skillsP2) * 2 )){
                if(termineStessoMeseEAnno(p1, p2) == true){
                    progettiSimili.push_back(p2);
                }
            }
        }
    }
    return progettiSimili;
}

list<DipendenteSenior*> Gestore::c5() const {
    list<DipendenteSenior*> empty;
    return empty;
}
