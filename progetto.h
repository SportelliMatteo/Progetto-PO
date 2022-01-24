#ifndef PROGETTO_H
#define PROGETTO_H

#include <string>
using namespace std;

class Progetto {

private:
    string nome;
    string dataInizio;
    int durata;
    double budget;
    string responsabile;

public:
    Progetto();
    Progetto(string, string, int, double, string);

    string getNome() const;
    string getDataInizio() const;
    int getDurata() const;
    double getBudget() const;
    string getResponsabile() const;

    void setNome(string);
    void setDataInizio(string);
    void setDurata(int);
    void setBudget(double);
    void setResponsabile(string);

    Progetto* clone() const;

};

#endif // PROGETTO_H
