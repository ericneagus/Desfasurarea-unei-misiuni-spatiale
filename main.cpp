#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
#include <thread>

#include "componenta.h"
#include "motorpropulsie.h"
#include "senzorexplorare.h"
#include "sistemsuportviata.h"
#include "centrucontrol.h"
#include "coordonate.h"
#include "echipajuman.h"
#include "exceptiimisiune.h"
#include "simulatorevenimente.h"

int main() {
    try{
        CentruControl nasa("Misiune Marte");
        CoordonateNavigatie nava(0,0,0,20.0);
        CoordonateNavigatie destinatie(500,750,250,0);
        SimulatorEvenimente simulator;

        nasa.adaugaComponenta(std::make_unique<MotorPropulsie>("XO-PROPULSOR",100,1000,500));
        nasa.adaugaComponenta(std::make_unique<SenzorExplorare>("SCANNER-ALPHA",100,"TOPOGRAFIE",0.95));
        nasa.adaugaComponenta(std::make_unique<SistemSuportViata>("OXY-GEN",100,100,3));

        EchipajUman echipaj;

        float ProcentDesatru = 55.0;

        echipaj.inroleazaAstronaut("Kael Orion","Ship Commander");
        echipaj.inroleazaAstronaut("Lyra Voss","Chief Engineer");
        echipaj.inroleazaAstronaut("Dr. Elian Zarek","Science Specialist");
        echipaj.inroleazaAstronaut("Nova Krynn","Elite Pilot");

        bool misiuneActiva = true;
        std::cout<<" >>> DECOLARE REUSITA! Incepe calatoria spre Marte(500km) <<<"<<'\n';
        while(misiuneActiva) {
           float distantaRamasa = nava.calculeazaDistanta(destinatie);
           
           echipaj.raporteazaStatusEchipaj();
           
           if(simulator.defectiune(ProcentDesatru)) {
            std::string dezastru = simulator.genEvenimentAleator();
            std::cout<<'\n'<<"[ALERTA] " <<dezastru<<"!"<<'\n';
            echipaj.afecteazaSanatate(30.0);
            nasa.simuleazaImpact();
           }

           nasa.ruleazaDiagnostic();

           if(nasa.esteNavaFunctionala() || echipaj.getNumarMembri() == 0) {
            std::cout<<'\n'<<"[ESEC] Nava a fost distrusa sau nu mai sunt astronauti."<<'\n';
            misiuneActiva = false;
           }

           else if(distantaRamasa< 15.0) {
            std::cout<<'\n'<<"[SUCCES] Nava a ajuns cu succes la destinatie!"<<'\n';
            misiuneActiva = false;
           }

           nava.afisareLocatie();
           std:: cout<<'\n'<<"---Distanta pana la destinatie: "<< distantaRamasa<< " km---"<<'\n';
            nava.actualizarePozitie(destinatie,1.0);
            std::this_thread::sleep_for(std::chrono::milliseconds(900));

        }
    } catch(const std::exception& e){
        std:: cerr << "Eroare critica de sistem: "<< e.what() << std::endl;
    }
    std::cout << "\n--- Program incheiat. ---\n";
    return 0;
}