#ifndef SENZOREXPLORARE_H
#define SENZOREXPLORARE_H

#include "componenta.h"
#include <vector>

class SenzorExplorare: public Componenta {
    private:
        std::string tipSenzor;
        float precizie;
        bool dateSalvate;
        void sistemOperareUrgenta() override;
    public:
        SenzorExplorare(const std::string& nume, float integritate, const std::string& tip, float precizie);
        std::unique_ptr<Componenta> clone() const override;
        void afisare(std::ostream& os) const override;
        void scaneazaMediu();

};

#endif