#ifndef COORDONATE_H
#define COORDONATE_H

#include <iostream>
#include <cmath>

class CoordonateNavigatie {
    private:
        float x,y,z;
        float vitezaCurenta;
    public:
        CoordonateNavigatie(float x=0, float y=0, float z=0, float viteza=0);
        void actualizarePozitie(const CoordonateNavigatie& destinatie,float timpSecunde);
        float calculeazaDistanta(const CoordonateNavigatie& alta) const;
        void afisareLocatie() const;
        bool esteInMiscare() const;
};

#endif