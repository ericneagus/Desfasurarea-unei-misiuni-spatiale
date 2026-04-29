#include "sistemsuportviata.h"

SistemSuportViata::SistemSuportViata(const std::string& nume, float integritate, float oxigen, int persoane)
    : Componenta(nume,integritate), nivelOxigen(oxigen), capacitatePersoane(persoane) {}\

std::unique_ptr<Componenta> SistemSuportViata::clone() const {
    return std::make_unique<SistemSuportViata>(*this);
}

void SistemSuportViata::afisare(std::ostream& os) const{
    Componenta::afisare(os);
    os<< " | Oxigen: "<< nivelOxigen <<"% | Echipaj suportat: "<< capacitatePersoane;
}

void SistemSuportViata::proceseazaResurse(float timp) {
    nivelOxigen -= (0.1 * capacitatePersoane * timp);
    if (nivelOxigen < 0) nivelOxigen = 0;
}

void SistemSuportViata::sistemOperareUrgenta() {
    std::cout << "[LIFE-SUPPORT] Scadere de presiune! Oxigen scazut!"<<'\n';
}