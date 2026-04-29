#include "motorpropulsie.h"

MotorPropulsie::MotorPropulsie(const std::string& nume, float integritate, float combustibil, float putere)
    : Componenta(nume,integritate) , nivelCombustibil(combustibil), putereMotor(putere) {

    }

std::unique_ptr<Componenta> MotorPropulsie::clone() const{
    return std::make_unique<MotorPropulsie>(*this);
}

void MotorPropulsie::afisare(std::ostream& os) const {
    Componenta::afisare(os);
    os<< " | Combustibil: "<< nivelCombustibil << " litri | Putere: "<< putereMotor << "kN";
}

void MotorPropulsie::sistemOperareUrgenta() {
    std::cout << "[MOTOR] Oprire de urgenta! Se elibereaza combustibil pentru a preveni explozie."<<'\n';
    nivelCombustibil = 0;
    putereMotor = 0;
}

void MotorPropulsie::initiazaAccelerare() {
    if (nivelCombustibil > 0) {
        std::cout<<"[MOTOR] Accelerare pornita..."<<'\n';
    }
}