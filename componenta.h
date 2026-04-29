#ifndef COMPONENTA_H
#define COMPONENTA_H

#include <string>
#include <memory>
#include <iostream>

class Componenta{
private:
    std:: string nume;
    static int contorObiect;
    virtual void sistemOperareUrgenta() = 0;
protected:
    float integritate;
    Componenta(const std::string& nume, float integritate);
public:
    virtual ~Componenta();
    void protocolUrgenta() {
        std::cout << "[SISTEM] Alerta! Se executa protocolul pentru: "<< nume<<'\n';
        sistemOperareUrgenta();
    }
    virtual std::unique_ptr<Componenta> clone() const = 0;
    virtual void afisare(std:: ostream& os) const;
    void setIntegritate(float val);
    float getIntegritate() const;
    std::string getName() const;
    void raportStare() const;
    bool esteCritica() const;

    static int getNrComponenteActive();
};


#endif