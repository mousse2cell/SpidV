#include "Force.h"
#include "Box.h"
#include "Cell.h"
#include <math.h>

Force::Force(void):type(-1)
{
}


Force::~Force(void)
{
}
Force::Force(int t):type(t)
{
}

const std::vector<int> Force::AVAILABLE_FORCE(1,2);

CVector Force::getValueXyz() const
{
    return valueXYZ;
}

void Force::setValueXyz(CVector valueXyz)
{
    valueXYZ = valueXyz;
}

int Force::getType() const
{
    return type;
}



void Force::setType(int type)
{
    this->type = type;
}
















