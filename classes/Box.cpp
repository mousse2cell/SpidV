#include "Box.h"
#include <iostream>
#include <string>

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
	cout << s << endl;
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
