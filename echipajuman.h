#ifndef ECHIPAJUMAN_H
#define ECHIPAJUMAN_H

#include <string>
#include <vector>
#include <iostream>

class EchipajUman {
private:
    struct Astronaut {
        std::string nume;
        std::string rol;
        float nivelSanatate;
        bool esteViu = true;
    };

    std::vector<Astronaut> membrii;

public:
    void inroleazaAstronaut(const std::string& nume, const std::string& rol);
    void afecteazaSanatate(float dauna);
    int getNumarMembri() const;
    float getSanatate() const;
    void raporteazaStatusEchipaj() const;
};

#endif