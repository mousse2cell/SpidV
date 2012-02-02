#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "classes/Sphere.h"
#include "classes/Force.h"
#include "classes/Cell.h"
#include "classes/CVector.h"


int main(int argc, char *argv[])
{
	double sphere_radius = 200;
    double cells_radius = 20;
    double nb_cells = 20;
    double dt = 1;
    double max_time = 150;
    double reduce_factor = 0.1;
	Sphere customSphere;
	CVector c;
	customSphere.setCentroid(c);
	customSphere.setRadius(sphere_radius);
	srand((unsigned)time(0));
	std::vector<Force> listForces;
	customSphere.generateRandomCells(nb_cells,cells_radius);
	std::vector<Cell*> cells=customSphere.getCells();

	customSphere.updateForces();
	for(float i=0;i<=max_time;i+=dt){
		customSphere.reduce(reduce_factor*(dt));
	}
	//std::cout<<customSphere.getRadius()<<endl;
	cells=customSphere.getCells();
    return 0;
}
