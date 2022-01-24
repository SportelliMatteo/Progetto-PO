#include "progetto.h"

Progetto::Progetto(){ }

Progetto::Progetto(string nome, string dataInizio, int durata, double budget, string responsabile){
    this->nome = nome;
    this->dataInizio = dataInizio;
    this->durata = durata;
    this->budget = budget;
    this->responsabile = responsabile;
}

string Progetto::getNome() const{
    return nome;
}

string Progetto::getDataInizio() const{
    return dataInizio;
}

int Progetto::getDurata() const{
    return durata;
}

double Progetto::getBudget() const{
    return budget;
}

string Progetto::getResponsabile() const{
    return responsabile;
}

void Progetto::setNome(string nome){
    this->nome = nome;
}

void Progetto::setDataInizio(string dataInizio){
    this->dataInizio = dataInizio;
}

void Progetto::setDurata(int durata){
    this->durata = durata;
}

void Progetto::setBudget(double budget){
    this->budget = budget;
}

void Progetto::setResponsabile(string responsabile){
    this->responsabile = responsabile;
}

Progetto* Progetto::clone() const{
    return new Progetto(*this);
}
