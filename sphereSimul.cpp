
/*#include "math.h"
#include "mex.h"
#include "matrix.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "classes/Sphere.h"
#include "classes/Force.h"
#include "classes/Cell.h"
#include "classes/CVector.h"

#if !defined(MAX)
#define	MAX(A, B)	((A) > (B) ? (A) : (B))
#endif

#if !defined(MIN)
#define	MIN(A, B)	((A) < (B) ? (A) : (B))
#endif


static void launchSphere(
		   double   * sphere_radius,
           double   * cells_radius,
           double   * nb_cells,
           double   * dt,
           double   * max_time,
           double   * reduce_factor,
		   double   * originalCoord,
           double   * finalCoord
		   )
{
    Sphere customSphere;
	CVector c;
	customSphere.setCentroid(c);
	customSphere.setRadius(*sphere_radius);
	srand((unsigned)time(0));
	std::vector<Force> listForces;
	customSphere.generateRandomCells(*nb_cells,*cells_radius);
	std::vector<Cell*> cells=customSphere.getCells();
    for(int i=0;i<cells.size();i++){
		originalCoord[i*3]=cells[i]->getCoord().getX();
        originalCoord[i*3+1]=cells[i]->getCoord().getY();
        originalCoord[i*3+2]=cells[i]->getCoord().getZ();
	}
	customSphere.updateForces();
	for(float i=0;i<=*max_time;i+=*dt){
		customSphere.reduce(*reduce_factor*(*dt));
	}
    //std::cout<<customSphere.getRadius()<<endl;
    cells=customSphere.getCells();
    for(int i=0;i<cells.size();i++){
		finalCoord[i*3]=cells[i]->getCoord().getX();
        finalCoord[i*3+1]=cells[i]->getCoord().getY();
        finalCoord[i*3+2]=cells[i]->getCoord().getZ();
	}
    return;
}
void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )
{
   
        //---------Declaration------------
    double * pData;
    mwSize pSize[2];
    mwSize nDims,length;
    double * sphere_radius,  * cells_radius, * nb_cells, * dt, * max_time, * reduce_factor;
    int nb_lab;
    double * originalCoord, * finalCoord;
    double * fgind, * bgind;
    //Check for proper number of arguments
    if (nrhs != 6) {
    	mexErrMsgTxt("6 input arguments required [Sphere radius, Cells radius, Number of cells, dt, max time, reduce factor].");
    } else if (nlhs > 2) {
    	mexErrMsgTxt("Too many output arguments.");
    }
    sphere_radius = mxGetPr(prhs[0]);
    cells_radius = mxGetPr(prhs[1]);
    nb_cells = mxGetPr(prhs[2]);
    dt = mxGetPr(prhs[3]);
    max_time = mxGetPr(prhs[4]);
    reduce_factor = mxGetPr(prhs[5]);
    pSize[0] = *nb_cells;
    pSize[1] = 3;
    length=mxGetNumberOfElements(prhs[0]);
    // Create a matrix for the return argument
    plhs[0] = mxCreateNumericArray(2, pSize, mxDOUBLE_CLASS,mxREAL); 
    plhs[1] = mxCreateNumericArray(2, pSize, mxDOUBLE_CLASS,mxREAL); 
    if (dt <= 0 || max_time <= 0 || nb_cells <= 0 || sphere_radius <=0 || cells_radius <= 0 ) {
    	mexErrMsgTxt("Sphere radius, Cells radius, Number of cells, dt and max time must be > 0.");
    }
    originalCoord=mxGetPr(plhs[0]);
    finalCoord=mxGetPr(plhs[1]);
    launchSphere(sphere_radius, cells_radius, nb_cells, dt, max_time, reduce_factor,originalCoord, finalCoord);
    
    return;
}

*/
