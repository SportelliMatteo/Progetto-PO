#include "dipendentejunior.h"

DipendenteJunior::DipendenteJunior() : Dipendente(){ }

DipendenteJunior::DipendenteJunior(string matricola, string nome, string cognome, double stipendio, list<string> skill, string stagista) : Dipendente(matricola, nome, cognome, stipendio){
    this->skill = skill;
    this->stagista = stagista;
}

list<string> DipendenteJunior::getSkill() const{
    return skill;
}

string DipendenteJunior::getStagista() const{
    return stagista;
}

void DipendenteJunior::setSkill(list<string> skill){
    this->skill = skill;
}

void DipendenteJunior::setStagista(string stagista){
    this->stagista = stagista;
}

DipendenteJunior* DipendenteJunior::clone() const {
    return new DipendenteJunior(*this);
}
