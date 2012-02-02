#include "CVector.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

CVector::CVector(void):x(0.0f),y(0.0f),z(0.0f)
{
	empty=false;
}


CVector::~CVector(void)
{
	empty=true;
}


void CVector::setX(const float val){this->x=val;empty=false;}
void CVector::setY(const float val){this->y=val;empty=false;}
void CVector::setZ(const float val){this->z=val;empty=false;}
float CVector::getX() const{return this->x;}
float CVector::getY() const{return this->y;}
/*bool CVector::operator ==(float scalar)
{
	if(this->x==scalar || this->y==scalar || this->z==scalar)
		return true;
	else
		return false;
}*/

bool CVector::containsOnly(float scalar)
{

	if(this->x==scalar && this->y==scalar && this->z==scalar){
			return true;
	}else{
			return false;
	}
}

float CVector::getZ() const{return this->z;}
float CVector::getAbsoluteMax() const{
	return fmax(abs(x),fmax(abs(y),abs(z)));
}
CVector::CVector(float x,float y,float z):x(x),y(y),z(z)
{

}


CVector CVector::operator+(const CVector &other)
{
    CVector result;
    result.x = x + other.x;
    result.y = y + other.y;
    result.z = z + other.z;
    return result;
}

CVector CVector::operator*(float scalar)
{
    CVector result;
    result.x = x * scalar;
    result.y = y * scalar;
    result.z = z * scalar;
    return result;
}

CVector CVector::operator/(float scalar){
	CVector result;
	    result.x = x / scalar;
	    result.y = y / scalar;
	    result.z = z / scalar;
	    return result;
}
void CVector::multiply(float const v){
	x = x * v;
	y = y * v;
	z = z * v;
}
void CVector::substract(float const v){
	x = x - v;
	y = y - v;
	z = z - v;
}
void CVector::reverseSign(){
	x = -x;
	y = -y;
	z = -z;
}
void CVector::random(){
	x=((float)rand()/(float)RAND_MAX);
	y=((float)rand()/(float)RAND_MAX);
	z=((float)rand()/(float)RAND_MAX);
	empty=false;
}
void CVector::random(float const max){
	float sign;
	do{
		sign=(float)((rand()%3)-1);
	}while(sign==0);
	x=sign*((float)rand()/(float)RAND_MAX);
	do{
		sign=(float)((rand()%3)-1);
	}while(sign==0);
	y=sign*((float)rand()/(float)RAND_MAX);
	do{
		sign=(float)((rand()%3)-1);
	}while(sign==0);
	z=sign*((float)rand()/(float)RAND_MAX);
	//if((rand()%2)-1==0) this->substract(1.0f);
	this->multiply(max);
	empty=false;
}

float CVector::distanceTo(float const x1,float const y1, float const z1) const{
	return sqrt(pow(x-x1,2)+pow(y-y1,2)+pow(z-z1,2));
}
float CVector::distanceTo(CVector  other) const{
	return distanceTo(other.getX(),other.getY(),other.getZ());
}
void CVector::print() const
{
	std::cout<<"x : "<<x<<" || y : "<<y<<" || z : "<<z<<std::endl;
}

bool CVector::isEmpty() const{
	return empty;
}

void CVector::setEmpty(bool const b){
	empty=b;
}


