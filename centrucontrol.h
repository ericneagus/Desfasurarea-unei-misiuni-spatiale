#ifndef CENTRUCONTROL_H
#define CENTRUCONTROL_H

#include "componenta.h"
#include <vector>
#include <memory>

class CentruControl {
    private:
        std::string numeMisiune;
        std::vector<std::unique_ptr<Componenta>> inventar;
    public:
        CentruControl(const std::string& nume);
        CentruControl(const CentruControl& a);
        CentruControl& operator=(CentruControl a);
        friend void swap(CentruControl& a, CentruControl& b) noexcept;
        bool esteNavaFunctionala() const;
        void adaugaComponenta(std::unique_ptr<Componenta> comp);
        void ruleazaDiagnostic() const;
        void simuleazaImpact() const;
        void inspecteazaSenzori() const;
};

#endif