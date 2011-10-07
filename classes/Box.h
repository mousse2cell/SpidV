#ifndef BOX_H
#define BOX_H

#include "Cell.h"
#include <vector>

class Box
{
public:
	Box(void);
	Box(int width, int height, int depth);
	Box(int width,int height, int depth, std::vector<Cell>);
	~Box(void);
	int getWidth() const;
	int getHeight() const;
	int getDepth() const;
	std::vector<Cell*> getCells() const;
	void setWidth(int width);
	void setHeight(int height);
	void setDepth(int depth);
	void setCells(std::vector<Cell*> cells);
	void addCell(Cell* cell);
	void printBox() const;
	void deleteCells();
	void setSize(int w,int h,int d);
	void reduceISO(const int pas);
	void reduceWidth(const int pas);
	void reduceHeight(const int pas);
	void reduceDepth(const int pas);
	void updateForces();
	void applyForces();
private:
	int width, height, depth;
	std::vector<Cell*> cells;
};

#endif
