#ifndef EXCEPTIIMISIUNE_H
#define EXCEPTIIMISIUNE_H

#include <exception>
#include <string>

class ExceptieSpatiu: public std::exception{
    protected:
        std::string mesaj;
    public:
        ExceptieSpatiu(const std::string& m) : mesaj(m) {}
        virtual const char* what() const noexcept override {return mesaj.c_str(); }      
};

class esecStructural : public ExceptieSpatiu {
    public:
        esecStructural(const std::string& m) : ExceptieSpatiu("ALERTA STRUCTURALA: " + m) {}
};

class ResurseCritice : public ExceptieSpatiu {
    public:
        ResurseCritice(const std::string& m) : ExceptieSpatiu("RESURSE EPUIZATE: " + m) {}
};

class EroareComunicare : public ExceptieSpatiu {
    public:
        EroareComunicare(const std::string& m) : ExceptieSpatiu("SEMNAL PIERDUT: " + m) {}
};

#endif