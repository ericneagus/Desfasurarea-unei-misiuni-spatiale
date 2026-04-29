#ifndef RESURSEMISIUNE_H
#define RESURSEMISIUNE_H

class ResurseMisiune {
private:
    float cantitate;
    float rataConsum;

public:
    ResurseMisiune(float initial, float rata);
    void consuma(float timp);
    void realimentare(float bonus);
    
    bool esteEpuizat() const;
    float getNivel() const { return cantitate; }
};

#endif