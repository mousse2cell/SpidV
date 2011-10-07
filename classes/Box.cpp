#include "Box.h"
#include <iostream>

using namespace std;
Box::Box(void)
{
}

Box::Box(int width,int height, int depth):width(width),height(height), depth(depth)
{
}


Box::Box(int width,int height, int depth, std::vector<Cell>):width(width),height(height), depth(depth), cells(cells)
{
}

Box::~Box(void)
{
}


int Box::getWidth() const{return this->width;}
int Box::getHeight() const{return this->height;}
int Box::getDepth() const{return this->depth;}
std::vector<Cell*> Box::getCells() const{return this->cells;}
void Box::setWidth(int width){
	this->width=width;
}
void Box::setHeight(int height){
	this->height=width;
}
void Box::setDepth(int depth){
	this->depth=depth;
}
void Box::setCells(std::vector<Cell*> cells){
	this->cells=cells;
}
void Box::addCell(Cell* cell){
	this->cells.push_back(cell);
}
void Box::printBox() const{
	std::string s="Box : "+this->width+this->height+this->depth;
	std::cout << s << std::endl;
	for(unsigned int i=0;i<this->cells.size();i++){
		this->cells[i]->printCell();
	}
}
void Box::deleteCells(){
	for(unsigned int i=0;i<this->cells.size();i++){
		delete(this->cells[i]);
	}
	this->cells.clear();
}

void Box::reduceISO(const int pas)
{
	setSize(width-pas,height-pas,depth-pas);
}

void Box::setSize(int w, int h, int d)
{
	width=w;
	height=h;
	depth=d;
	updateForces();
}

void Box::reduceWidth(const int pas)
{
	setSize(width-pas,height,depth);
}



void Box::reduceHeight(const int pas)
{
	setSize(width,height-pas,depth);
}



void Box::reduceDepth(const int pas)
{
	setSize(width,height,depth-pas);
}

void Box::updateForces()
{
	for(unsigned int i=0;i<cells.size();i++){
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











