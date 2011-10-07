#ifndef FORCE_H
#define FORCE_H

#include "protoClass.h"
#include "Cell.h"
#include "CVector.h"


class Force{
public:
    Force(void);
    Force(int t);
    Force(const Cell *c1,const Cell *c2);
    ~Force(void);
    CVector getValueXyz() const;
    void setValueXyz(CVector valueXyz);
    int getType() const;
    void setType(int type);
    void evalForce(const Cell &c1, const Cell &c2);
    void evalAttractiveForce(const Cell &c1,const Cell &c2);
    void evalRepulsiveForce(const Cell &c1,const Cell &c2);
    const Cell* getC1() const;
    void setC1(const Cell* c1);
    const Cell* getC2() const;
    void setC2(const Cell* c2);
    static const std::vector<int> AVAILABLE_FORCE;
private:
    int type; //attractive, repulsive or whatever
    CVector valueXYZ;
    const Cell* c1;
    const Cell* c2;
    static const float ATTRACTIVE_CONST=1;
    static const float REPULSIVE_CONST=1.5;
};



#endif
