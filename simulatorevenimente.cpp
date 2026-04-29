#include "simulatorevenimente.h"
#include <cstdlib>
#include <ctime>

SimulatorEvenimente::SimulatorEvenimente() {
    srand(time(0));
    tipuriDezastre.push_back("Lovitura Asteroid");
    tipuriDezastre.push_back("Pierdere Oxigen");
    tipuriDezastre.push_back("Scurtcircuit Electric");
    tipuriDezastre.push_back("Eroare Bord");
}

bool SimulatorEvenimente::defectiune(int sansa) const {
    int nr = rand() % 100;
    if(nr < sansa) {
        return true;
    }
    return false;
}

std::string SimulatorEvenimente::genEvenimentAleator() const {
    int totalOptiuni = tipuriDezastre.size();
    int pozitie = rand() % totalOptiuni;
    return tipuriDezastre[pozitie];
}