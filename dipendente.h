#ifndef DIPENDENTE_H
#define DIPENDENTE_H

#include <string>
using namespace std;

class Dipendente
{
private:
    string matricola;
    string nome;
    string cognome;
    double stipendio;

public:

    Dipendente();
    Dipendente(string, string, string, double);

    virtual ~Dipendente();

    virtual Dipendente* clone() const;

    string getMatricola() const;
    string getNome() const;
    string getCognome() const;
    double getStipendio() const;

    void setMatricola(string);
    void setNome(string);
    void setCognome(string);
    void setStipendio(double);

};

#endif // DIPENDENTE_H
