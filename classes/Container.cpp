/*
 * Container.cpp
 *
 *  Created on: 14 oct. 2011
 *      Author: mobilette
 */

#include "Container.h"
#include "Sphere.h"

Container::Container() {
	// TODO Auto-generated constructor stub

}

Container::Container(std::vector<Cell*> c):cells(c) {
	// TODO Auto-generated constructor stub

}

Container::~Container() {
	// TODO Auto-generated destructor stub
}

//void Container::updateContainerTree(QTreeWidget* qt){}

std::vector<Cell*> Container::getCells() const{
	return cells;
}
void Container::setCells(std::vector<Cell*> cells){
	this->cells=cells;
}
void Container::addCell(Cell* cell){
	this->cells.push_back(cell);
}
void Container::deleteCells(){
	for(unsigned int i=0;i<this->cells.size();i++){
		delete(this->cells[i]);
	}
	this->cells.clear();
}

void Container::splitCells(int val){
	if(val==1) return;
	std::vector<Cell*> cellstmp;
	for(unsigned int i=0;i<this->cells.size();i++){
		cells.erase(cells.begin()+i);
		std::vector<Cell *>* tmp=cells[i]->splitIn(val);
		for(unsigned int j=0;j<tmp->size();j++)
			cellstmp.push_back(tmp->at(j));
		delete(tmp);
	}
	std::copy(cellstmp.begin(), cellstmp.end(), std::back_inserter(cells));
}


