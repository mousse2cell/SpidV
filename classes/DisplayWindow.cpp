/*
 * displayWindow.cpp
 *
 *  Created on: 6 oct. 2011
 *      Author: mobilette
 */

#include "DisplayWindow.h"
#include "math.h"
#include <iostream>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

/*DisplayWindow::DisplayWindow() {
	// TODO Auto-generated constructor stub

}
DisplayWindow::DisplayWindow(Box* b){
	this->box=b;
}
DisplayWindow::~DisplayWindow() {
	// TODO Auto-generated destructor stub
}

Box* DisplayWindow::getBox() const
{
    return box;
}

void DisplayWindow::setBox(Box* box)
{
    this->box = box;
}
void DisplayWindow::Dessiner()
{

	glClear( GL_COLOR_BUFFER_BIT );

	    glMatrixMode( GL_MODELVIEW );
	    glLoadIdentity( );

	    gluLookAt( 100, 100, -250, 100, 100, 100, 0, 1, 0 );
	    this->drawBounds();
	    for(unsigned int i=0;i<this->box->getCells().size();i++){
			glColor3ub(rand()%255,rand()%255,rand()%255); //face rouge
			Sphere(30,30,this->getBox()->getCells()[i]->getRadius(),this->box->getCells()[i]->getCoord());
	    }

	    glFlush();
	    SDL_GL_SwapBuffers();
	    //Sphere(10,10);
}
void DisplayWindow::displayScene(){
	SDL_Event event;
	SDL_Init(SDL_INIT_VIDEO);
	atexit(SDL_Quit);
	SDL_WM_SetCaption("Status", NULL);
	SDL_SetVideoMode(1024, 800, 32, SDL_OPENGL);

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective(70,(double)640/480,1,1000);

	this->Dessiner();

	for (;;)
	{
		SDL_WaitEvent(&event);

		switch(event.type)
		{
			case SDL_QUIT:
			exit(0);
			break;
		}
		this->Dessiner();

	}
}

void DisplayWindow::Sphere(int a,int b,int radius, CVector coord) {
	float xd=coord.getX();
	float yd=coord.getY();
	float zd=coord.getZ();
	float da = ( M_PI / a );
	float db = ( 2.0f * M_PI / b );
	glBegin(GL_QUADS);
	//glColor3f(1.0,0.0,0.0);
	glNormal3f(0,0,1);
	for( int i = 0; i < a + 1 ; i++ ) {
		float r0 = radius*sin ( i * da );
		float y0 = radius*cos ( i * da );
		float r1 =  ( (i+1) * da );
		float y1 = cos ( (i+1) * da );

		for( int j = 0; j < b + 1 ; j++ ) {
			float x0 = r0 * sin( j * db );
			float z0 = r0 * cos( j * db );
			float x1 = r0 * sin( (j+1) * db );
			float z1 = r0 * cos( (j+1) * db );

			float x2 = r1 * sin( j * db );
			float z2 = r1 * cos( j * db );
			float x3 = r1 * sin( (j+1) * db );
			float z3 = r1 * cos( (j+1) * db );

			//glColor3f((x0+x1+x2+x3)/4.0,(y0+y1)/2.0,(z0+z1+z2+z3)/4.0);

			glVertex3f(xd+x0,yd+y0,zd+z0);
			glVertex3f(xd+x1,yd+y0,zd+z1);
			glVertex3f(xd+x3,yd+y1,zd+z3);
			glVertex3f(xd+x2,yd+y1,zd+z2);
		}
	}
	glEnd();
}

void DisplayWindow::drawBounds() {
	int x1=this->getBox()->getWidth();
	int y1=this->getBox()->getHeight();
	int z1=this->getBox()->getDepth();
	int x0=0;
	int y0=0;
	int z0=0;
	 //glLineWidth(10);

	 glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
	//glNormal3f(0,0,1);
	glBegin(GL_QUADS);
	glColor3ub(255,0,0);
	glVertex3f(x0,y0,z0);
	glVertex3f(x0,y0,z1);
	glVertex3f(x1,y0,z1);
	glVertex3f(x1,y0,z0);

	glVertex3f(x0,y1,z0);
	glVertex3f(x0,y1,z1);
	glVertex3f(x0,y0,z1);
	glVertex3f(x0,y0,z0);

	glVertex3f(x1,y1,z0);
	glVertex3f(x1,y1,z1);
	glVertex3f(x0,y1,z1);
	glVertex3f(x0,y1,z0);

	glVertex3f(x1,y0,z0);
	glVertex3f(x1,y0,z1);
	glVertex3f(x1,y1,z1);
	glVertex3f(x1,y1,z0);


	glVertex3f(x0,y0,z1);
	glVertex3f(x0,y1,z1);
	glVertex3f(x1,y1,z1);
	glVertex3f(x1,y0,z1);


	glVertex3f(x0,y0,z0);
	glVertex3f(x0,y1,z0);
	glVertex3f(x1,y1,z0);
	glVertex3d(x1,y0,z0);

	glEnd();
	//à décommenter pour avoir les wireframe
	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

}

void DisplayWindow::updateDisplay() const
{
	//SDL_FillRect(sdl_screen,NULL, 0x000000);
	//SDL_Flip(sdl_screen);
}
*/





