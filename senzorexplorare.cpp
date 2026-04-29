#include "senzorexplorare.h"

SenzorExplorare::SenzorExplorare(const std::string &nume, float integritate, const std::string &tip, float precs)
    :Componenta(nume,integritate),tipSenzor(tip),precizie(precs), dateSalvate(false) {
    }

std::unique_ptr<Componenta> SenzorExplorare::clone() const{
    return std::make_unique<SenzorExplorare>(*this);
}

void SenzorExplorare::afisare(std::ostream& os) const {
    Componenta::afisare(os);
    os << " | Tip Senzor: "<< tipSenzor<< " | Precizie: "<< precizie * 100 << "%";
}

void SenzorExplorare::scaneazaMediu() {
    if (integritate > 10) std::cout << "[SENZOR] Scanare in curs pentru " << tipSenzor <<"..."<<'\n';
    else std::cout << "[SENZOR] Eroare: Integritate prea scazuta pentru scanare!"<<'\n';
}

void SenzorExplorare::sistemOperareUrgenta() {
    std::cout<< "[SENZOR] Alerta! Se salveaza datele in memoria interna."<<'\n';
    dateSalvate = true;
    precizie = 0;
}

