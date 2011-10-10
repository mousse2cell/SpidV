#include "classes/Box.h"
//#include "classes/Force.h"
#include "classes/CVector.h"
#include "classes/DisplayWindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <SDL/SDL.h>


using namespace std;

int main()
{
	Box customBox(200,200,200);
	int nbcells=20;
	int radius=20;
	float dt=1;
	float maxtime=20;
	vector<Force> listForces;
	
	CVector coord;
	// instantiate new cells 
	for(int i=0;i<nbcells;i++){
		coord.setX(rand()%200);
		coord.setY(rand()%200);
		coord.setZ(rand()%200);
		Cell* aCell=new Cell();
		aCell->setCoord(coord);
		aCell->setRadius(radius);
		customBox.addCell(aCell);
	}

	for(int i=0;i<=maxtime;i+=dt){
		customBox.reduceDepth(10);
	}

	DisplayWindow window(&customBox);
	window.displayScene();
	customBox.printBox();
	customBox.deleteCells();

	return 0;
}
