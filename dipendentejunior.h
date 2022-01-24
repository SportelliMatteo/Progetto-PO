#ifndef DIPENDENTEJUNIOR_H
#define DIPENDENTEJUNIOR_H

#include "dipendente.h"
#include "progetto.h"
#include <string>
#include <list>
using namespace std;

class DipendenteJunior : public Dipendente{

private:
    list<string> skill;
    string stagista;

public:

    DipendenteJunior();
    DipendenteJunior(string, string, string, double, list<string>, string);

    list<string> getSkill() const;
    string getStagista() const;

    void setSkill(list<string>);
    void setStagista(string);

    DipendenteJunior* clone() const;

};

#endif // DIPENDENTEJUNIOR_H
