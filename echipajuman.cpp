#include "echipajuman.h"
#include <algorithm>

void EchipajUman::inroleazaAstronaut(const std::string& nume, const std::string& rol) {
    membrii.push_back({nume, rol, 100});
    std::cout << "[ECHIPAJ] Astronautul " << nume << " a fost alocat postului de " << rol << ".\n";
}

void EchipajUman::afecteazaSanatate(float dauna) {
    for(int i=0; i<membrii.size();i++) {
        if(membrii[i].esteViu) {
            float variatie  = (rand() % 10) -5;
            float daunaReala = dauna + variatie;

            membrii[i].nivelSanatate -= daunaReala;
            if(membrii[i].nivelSanatate<=0) {
                membrii[i].nivelSanatate = 0;
                membrii[i].esteViu = false;
            }
        }
    }
}

void EchipajUman::raporteazaStatusEchipaj() const {
    std::cout << "========== Status Echipaj (" << membrii.size() << " membrii) ==========\n";
    for (const auto& astro : membrii) {
        std::cout << "Astronaut: " << astro.nume << " | Rol: " << astro.rol 
                  << " | Sanatate: " << astro.nivelSanatate << "%\n";
    }
}

int EchipajUman::getNumarMembri() const {
    int vii = 0;
    for(int i =0; i < membrii.size();i++)
        if(membrii[i].esteViu) vii++;
    return vii;
}