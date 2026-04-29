#include "componenta.h"

int Componenta::contorObiect = 0;

Componenta::Componenta(const std::string& nume, float integritate) : nume(nume), integritate(integritate) {
    contorObiect++;
}

Componenta::~Componenta() {
    contorObiect--;
}

int Componenta::getNrComponenteActive() {
    return contorObiect;
}

void Componenta::setIntegritate(float valNoua) {
    integritate = valNoua;
    if(integritate<0) integritate = 0;
    if(integritate>100) integritate = 100;
}

float Componenta::getIntegritate() const {
    return integritate;
}

std::string Componenta::getName() const {
    return nume;
}

void Componenta::afisare(std::ostream& os) const {
    os << "Componenta: " <<nume << " | Integritate: "<<integritate<<"%";
}

void Componenta::raportStare() const {
    if (integritate > 80) std::cout << nume << "functionare nominala"<<'\n';
    else if(integritate > 20) std::cout << nume << "necesita verificare"<<'\n';
    else std::cout << nume << " VA ESUA!"<<'\n';
}

bool Componenta::esteCritica() const {
    return (integritate < 15);
}