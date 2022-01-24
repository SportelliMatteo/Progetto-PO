#include "dipendentesenior.h"
#include <iostream>
using namespace std;

DipendenteSenior::DipendenteSenior() : Dipendente(){

}

DipendenteSenior::DipendenteSenior(string matricola, string nome, string cognome, double stipendio, list<string> reperibilita, list<string> listaSubordinati) : Dipendente(matricola, nome, cognome, stipendio) {
    this->reperibilita = reperibilita;
    this->listaSubordinati = listaSubordinati;
}

list<string> DipendenteSenior::getReperibilita() const{
    return reperibilita;
}

list<string> DipendenteSenior::getlistaSubordinati () const{
    return listaSubordinati;
}

void DipendenteSenior::setReperibilita(list<string> reperibilita){
    this->reperibilita = reperibilita;
}

void DipendenteSenior::setListaSubordinati(list<string> listaSubordinati){
    this->listaSubordinati = listaSubordinati;
}

DipendenteSenior* DipendenteSenior::clone() const{
    return new DipendenteSenior(*this);
}
