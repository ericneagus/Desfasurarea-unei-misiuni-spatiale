#include "coordonate.h"

CoordonateNavigatie::CoordonateNavigatie(float x,float y,float z, float viteza) : x(x),y(y),z(z), vitezaCurenta(viteza) {}
void CoordonateNavigatie::actualizarePozitie(const CoordonateNavigatie& destinatie, float timpSecunde) {
    float dx = destinatie.x - this->x;
    float dy = destinatie.y - this->y;
    float dz = destinatie.z - this->z;
    float dist = std::sqrt(dx*dx + dy*dy + dz*dz);

    if (dist < 1.0) return;

    float pas = this->vitezaCurenta * timpSecunde;
    if(pas>dist) dist = pas;

    this->x += (dx/dist) * pas;
    this->y += (dy/dist) * pas;
    this->z += (dz/dist) * pas;

    std::cout<< "[NAVIGATIE] Pozitie actualizata dupa "<< timpSecunde<<" secunde.\n";
}

float CoordonateNavigatie::calculeazaDistanta(const CoordonateNavigatie& alta) const{
    return std::sqrt(std::pow(alta.x - x, 2) +
                     std::pow(alta.y - y,2) +
                     std::pow(alta.z - z,2));
}

void CoordonateNavigatie::afisareLocatie() const {
    std::cout << "Coordonate actuale: ["<<x<<", "<<y<<", "<<z<<"] | Viteza: "<<vitezaCurenta<<"km/s"<<'\n';
}

bool CoordonateNavigatie::esteInMiscare() const {
    return vitezaCurenta > 0;
}