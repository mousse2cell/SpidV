#ifndef CELL_H
#define CELL_H
#include <vector>
#include <iostream>
#include <sstream>

//#include "Force.h"
#include "protoClass.h"
#include "BoxForce.h"
#include "SphereForce.h"
#include "CellForce.h"
#include "CVector.h"
#include "../lib/GlobalDef.h"


class Cell
{
public:
	Cell(void);
	Cell(std::string id);
	Cell(std::string id, float radius, CVector coord);
	Cell(std::string id, int type, float radius, CVector coord);
	Cell(std::string id, int type, float radius, CVector coord,std::vector<Force> forces);
	~Cell(void);
	void setRadius(float radius);
	void setType(int type);
	void setForces(std::vector<Force> forces);
	void setCoord(CVector coord);
	int getType() const;
	CVector getCoord() const;
	CVector getOrigin() const;
	float getRadius() const;
	std::vector<Force> getForces() const;
	float evalDistance(const Cell &c) const;
	float evalOverlap(const Cell &c) const;
	void printCell() const;
	void addForce(Force & f);
	void checkAndSetForceWith(Cell & c);
	void checkAndSetForceWith(Box & c);
	void checkAndSetForceWith(Sphere & c);
	void applyForces();
	void moveTo(float x,float y, float z);
	void setNeighborhood(const std::vector<Cell*> n);
	std::vector<Cell*> getNeighborhood() const;
	void addNeighborhood(Cell* c);
    bool isDl() const;
    bool isDr() const;
    bool isHl() const;
    bool isHr() const;
    bool isWl() const;
    bool isWr() const;
    void setDl(bool dl);
    void setDr(bool dr);
    void setHl(bool hl);
    void setHr(bool hr);
    void setWl(bool wl);
    void setWr(bool wr);
    void setID(std::string i);
    std::string getID() const;
    void resetBoxCol();
    std::vector<Cell*>* splitIn(int val) const;
protected:
    std::string ID;
    int type;
    float radius;
    CVector coord;
    CVector origin;
    std::vector<Force> forces;
    std::vector<Cell*> neighborhood;
    bool WR;
    bool WL;
    bool DR;
    bool DL;
    bool HR;
    bool HL;
};

#endif
