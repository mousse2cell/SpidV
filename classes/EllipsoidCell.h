/*
 * EllipsoidCell.h
 *
 *  Created on: 19 oct. 2011
 *      Author: mobilette
 */

#ifndef ELLIPSOIDCELL_H_
#define ELLIPSOIDCELL_H_

#include "Cell.h"

class EllipsoidCell: public Cell {
public:
	EllipsoidCell();
	EllipsoidCell(std::string id);
	EllipsoidCell(std::string id, CVector coord);
	EllipsoidCell(std::string id, int type, CVector coord);
	EllipsoidCell(std::string id, int type, CVector coord,std::vector<Force> forces);
	virtual ~EllipsoidCell();
	float evalOverlap(EllipsoidCell & ec);
	float getAxisX() const;
	float getAxisY() const;
	float getAxisZ() const;
	float getAzimuth() const;
	float getElevation() const;
private:
	float axisX,axisY,axisZ;
	float azimuth,elevation;
};

#endif /* ELLIPSOIDCELL_H_ */
