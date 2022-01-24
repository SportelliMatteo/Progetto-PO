#include "dipendente.h"

Dipendente::Dipendente() { }

Dipendente::Dipendente(string matricola, string nome, string cognome, double stipendio){
    this->matricola = matricola;
    this->nome = nome;
    this->cognome = cognome;
    this->stipendio = stipendio;
}

void Dipendente::setMatricola(string matricola){
    this->matricola = matricola;
}

void Dipendente::setNome(string nome){
    this->nome = nome;
}

void Dipendente::setCognome(string cognome){
    this->cognome = cognome;
}

void Dipendente::setStipendio(double stipendio){
    this->stipendio = stipendio;
}

string Dipendente::getMatricola() const{
    return matricola;
}

string Dipendente::getNome() const{
    return nome;
}

string Dipendente::getCognome() const{
    return cognome;
}

double Dipendente::getStipendio() const{
    return stipendio;
}

Dipendente* Dipendente::clone() const{
  return new Dipendente(*this);
}

Dipendente::~Dipendente() {
}
