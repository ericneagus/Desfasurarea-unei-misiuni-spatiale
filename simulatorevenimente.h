#ifndef SIMULATOREVENIMENTE_H
#define SIMULATOREVENIMENTE_H

#include <string>
#include <vector>

class SimulatorEvenimente {
private:
    std::vector<std::string> tipuriDezastre;

public:
    SimulatorEvenimente();
    std::string genEvenimentAleator() const;
    bool defectiune(int sansa) const;
};

#endif