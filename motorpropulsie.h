#ifndef MOTORPROPULSIE_H
#define MOTORPROPULSIE_H

#include "componenta.h"

class MotorPropulsie: public Componenta {
    private:
        float nivelCombustibil;
        float putereMotor;
        void sistemOperareUrgenta() override;
    public:
        MotorPropulsie(const std::string& nume, float integritate, float combustibil, float putere);
        std::unique_ptr<Componenta> clone() const override;
        void afisare(std::ostream& os) const override;
        void initiazaAccelerare();
};

#endif