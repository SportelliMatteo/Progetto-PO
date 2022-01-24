#ifndef DIPENDENTESENIOR_H
#define DIPENDENTESENIOR_H

#include "dipendentejunior.h"
#include "progetto.h"
#include <vector>
using namespace std;

class DipendenteSenior : public Dipendente{

private:
    list<string> reperibilita;
    list<string> listaSubordinati;

public:

    DipendenteSenior();
    DipendenteSenior(string, string, string, double, list<string>, list<string>);

    list<string> getReperibilita() const;
    list<string> getlistaSubordinati () const;

    void setReperibilita(list<string>);
    void setListaSubordinati(list<string>);

    DipendenteSenior* clone() const;

};

#endif // DIPENDENTESENIOR_H
