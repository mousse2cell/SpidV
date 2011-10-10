#ifndef BOX_H
#define BOX_H

#include "Cell.h"
#include <vector>

class Box
{
public:
	Box(void);
	Box(float width, float height, float depth);
	Box(float width,float height, float depth, std::vector<Cell>);
	~Box(void);
	float getWidth() const;
	float getHeight() const;
	float getDepth() const;
	std::vector<Cell*> getCells() const;
	void setWidth(float width);
	void setHeight(float height);
	void setDepth(float depth);
	void setCells(std::vector<Cell*> cells);
	void addCell(Cell* cell);
	void printBox() const;
	void deleteCells();
	void setSize(float w,float h,float d);
	void reduceISO(const float pas);
	void reduceWidth(const float pas);
	void reduceHeight(const float pas);
	void reduceDepth(const float pas);
	void updateForces();
	void applyForces();
private:
	float width, height, depth;
	std::vector<Cell*> cells;
};

#endif
