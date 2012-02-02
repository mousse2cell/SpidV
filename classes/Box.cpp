#include "Box.h"
#include <iostream>

using namespace std;
Box::Box(void)
{
	width=-1;
	height=-1;
	depth=-1;
}

Box::Box(float width,float height, float depth):width(width),height(height), depth(depth)
{
	originwidth=width;
	originheight=height;
	origindepth=depth;
}


Box::Box(std::vector<Cell*> c,float width,float height, float depth): Container(c),width(width),height(height), depth(depth)
{
	originwidth=width;
	originheight=height;
	origindepth=depth;
}

Box::~Box(void)
{
}


float Box::getWidth() const{return this->width;}
float Box::getHeight() const{return this->height;}
float Box::getDepth() const{return this->depth;}
void Box::setWidth(float width){
	this->width=width;
}
void Box::setHeight(float height){
	this->height=height;
}
void Box::setDepth(float depth){
	this->depth=depth;
}

float Box::getOriginWidth() const{return this->originwidth;}
float Box::getOriginHeight() const{return this->originheight;}
float Box::getOriginDepth() const{return this->origindepth;}
void Box::setOriginWidth(float width){
	this->originwidth=width;
}
void Box::setOriginHeight(float height){
	this->originheight=height;
}
void Box::setOriginDepth(float depth){
	this->origindepth=depth;
}

void Box::printBox() const{
	std::string s="Box : "+(int)this->width+(int)this->height+(int)this->depth;
	std::cout << s << std::endl;
	for(unsigned int i=0;i<this->cells.size();i++){
		this->cells[i]->printCell();
	}
}

void Box::reduceISO(const float pas)
{
	setSize(width-pas,height-pas,depth-pas);
}

void Box::setSize(float w, float h, float d)
{
	if(width==-1){
		originwidth=w;
		originheight=h;
		origindepth=d;
	}
	width=w;
	height=h;
	depth=d;
	updateForces();
}

void Box::reduce(const float px, const float py, const float pz)
{
	setSize(width-px,height-py,depth-pz);
}

void Box::reduceWidth(const float pas)
{
	setSize(width-pas,height,depth);
}



void Box::reduceHeight(const float pas)
{
	setSize(width,height-pas,depth);
}



void Box::reduceDepth(const float pas)
{
	setSize(width,height,depth-pas);
}

void Box::updateForces()
{
	Box* tmpb=this;
	for(unsigned int i=0;i<cells.size();i++){
		cells[i]->checkAndSetForceWith(*tmpb);
		for(unsigned int j=0;j<cells.size();j++){
			if(i!=j){
				cells[i]->checkAndSetForceWith(*cells[j]);
			}
		}
	}
	applyForces();
}

void Box::applyForces()
{
	for(unsigned int i=0;i<cells.size();i++){
		cells[i]->applyForces();
	}
}


void Box::generateRandomCells(int nbcells,float radius){
	// instantiate new cells
	CVector coord;
	for(int i=0;i<nbcells;i++){
		coord.setX(rand()%(int)getWidth());
		coord.setY(rand()%(int)getHeight());
		coord.setZ(rand()%(int)getDepth());
		Cell* aCell=new Cell(to_string(i+1));
		aCell->setCoord(coord);
		aCell->setRadius(radius);
		addCell(aCell);
	}
}










