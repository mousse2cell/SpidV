#ifndef CELL_H
#define CELL_H
#include <vector>
#include "Force.h"
#include "CVector.h"

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
	void printCell() const;
private:
	int type;
	CVector coord;
	double radius;
	std::vector<Force> forces;
};

#endif
