#ifndef SISTEMSUPORTVIATA_H
#define SISTEMSUPORTVIATA_H

#include "componenta.h"

class SistemSuportViata: public Componenta {
    private:
        float nivelOxigen;
        int capacitatePersoane;
        void sistemOperareUrgenta() override;
    public:
        SistemSuportViata(const std::string& nume, float integritate, float oxigen, int persoane);
        std::unique_ptr<Componenta> clone() const override;
        void afisare(std::ostream& os) const override;
        void proceseazaResurse(float timp); 
};


#endif