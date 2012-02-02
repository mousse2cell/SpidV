#ifndef FORCE_H
#define FORCE_H

#include "protoClass.h"
#include "CVector.h"
#include <vector>
#include <iostream>


class Force{
public:
    Force(void);
    Force(int t);
    virtual ~Force(void);
    CVector getValueXyz() const;
    void setValueXyz(CVector valueXyz);
    int getType() const;
    void setType(int type);
    static const std::vector<int> AVAILABLE_FORCE;
protected:
    int type; //attractive, repulsive or whatever
    CVector valueXYZ;
    static const float ATTRACTIVE_CONST=1;
    static const float REPULSIVE_CONST=0.1;
};



#endif
