#include "centrucontrol.h"
#include "senzorexplorare.h"
#include <utility>

CentruControl::CentruControl(const std::string& nume) : numeMisiune(nume) {}

void swap(CentruControl& a, CentruControl& b) noexcept {
    using std::swap;
    swap(a.numeMisiune, b.numeMisiune);
    swap(a.inventar, b.inventar);
}
CentruControl::CentruControl(const CentruControl& a) : numeMisiune(a.numeMisiune) {
    for (const auto& comp : a.inventar) {
        this->inventar.push_back(comp->clone());
    }
}
CentruControl& CentruControl::operator=(CentruControl a) {
    swap(*this, a);
    return *this;
}
void CentruControl::adaugaComponenta(std::unique_ptr<Componenta> comp) {
    inventar.push_back(std::move(comp));
}
bool CentruControl::esteNavaFunctionala() const{
    int componenteDistruse = 0;
    for (int i=0;i<inventar.size();i++) {
        if(inventar[i]->getIntegritate() <= 0) {
            componenteDistruse++;
        }
    }
    return componenteDistruse == inventar.size();
}

void CentruControl::ruleazaDiagnostic() const {
    std::cout << "\n========== RAPORT TEHNIC ==========\n";
    for (int i = 0; i < inventar.size(); ++i) {
        std::cout << "[-] " << inventar[i]->getName() << " | Integritate: " 
                  << inventar[i]->getIntegritate() << "% ";
        if (inventar[i]->getIntegritate() <= 0) {
            std::cout << "[DEFECT CRITIC]";
        } else if (inventar[i]->getIntegritate() < 40) {
            std::cout << "[FUNCTIONARE DEGRADATA]";
        }
        std::cout << "\n";
    }
    std::cout << "====================================\n";
}



void CentruControl::simuleazaImpact() const {
    std::cout << "[SISTEM] Se analizeaza daunele..."<<'\n';
    for(int i =0; i < inventar.size(); i++) {
        float integritateNoua = inventar[i]->getIntegritate() - 30.0;
        inventar[i]->setIntegritate(integritateNoua);
        inventar[i]->protocolUrgenta();

        if(inventar[i]->esteCritica()) {
            std:: cout<< "!!! ALERTA: "<< inventar[i]->getName()<<" a cedat!"<<'\n';
        }
    }
}


void CentruControl::inspecteazaSenzori() const {
    std::cout << "\n[SCANARE DOWNCAST] Verificare senzori specializati:\n";
    for (const auto& comp : inventar) {
        auto senzorPtr = dynamic_cast<SenzorExplorare*>(comp.get());
        if (senzorPtr) {
            std::cout << "Senzor detectat! ";
            senzorPtr->scaneazaMediu(); 
        }
    }
}