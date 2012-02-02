#ifndef BOX_H
#define BOX_H

#include "Container.h"

class Box:  public Container{
public:
	Box(void);
	Box(float width, float height, float depth);
	Box(std::vector<Cell*>,float width,float height, float depth);
	~Box(void);
	float getWidth() const;
	float getHeight() const;
	float getDepth() const;
	void setWidth(float width);
	void setHeight(float height);
	void setDepth(float depth);
	float getOriginWidth() const;
	float getOriginHeight() const;
	float getOriginDepth() const;
	void setOriginWidth(float width);
	void setOriginHeight(float height);
	void setOriginDepth(float depth);
	void printBox() const;
	void setSize(float w,float h,float d);
	void reduceISO(const float pas);
	void reduce(const float px, const float py, const float pz);
	void reduceWidth(const float pas);
	void reduceHeight(const float pas);
	void reduceDepth(const float pas);
	void generateRandomCells(int nbcells, float radius);
	void updateForces();
	void applyForces();
private:
	float width, height, depth;
	float originwidth, originheight, origindepth;
};

#endif
