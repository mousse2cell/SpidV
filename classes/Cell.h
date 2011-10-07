#ifndef CELL_H
#define CELL_H
#include <vector>
#include "Force.h"
#include "CVector.h"
#include "../lib/GlobalDef.h"

class Cell
{
public:
	Cell(void);
	Cell(int type, double radius, CVector coord);
	Cell(int type, double radius, CVector coord,std::vector<Force> forces);
	~Cell(void);
	void setRadius(double radius);
	void setType(int type);
	void setForces(std::vector<Force> forces);
	void setCoord(CVector coord);
	int getType() const;
	CVector getCoord() const;
	double getRadius() const;
	std::vector<Force> getForces() const;
	float evalDistance(const Cell &c) const;
	float evalOverlap(const Cell &c) const;
	void printCell() const;
	void addForce(Force & f);
	void checkAndSetForceWith(const Cell & c);
	void applyForces();
	void moveTo(float x,float y, float z);
private:
	int type;
	CVector coord;
	double radius;
	std::vector<Force> forces;
};

#endif
