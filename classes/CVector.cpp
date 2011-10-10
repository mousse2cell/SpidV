#include "CVector.h"
#include <iostream>

CVector::CVector(void):x(0.0f),y(0.0f),z(0.0f)
{
}


CVector::~CVector(void)
{
}


void CVector::setX(const float val){this->x=val;}
void CVector::setY(const float val){this->y=val;}
void CVector::setZ(const float val){this->z=val;}
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

void CVector::print() const
{
	std::cout<<"x : "<<x<<" || y : "<<y<<" || z : "<<z<<std::endl;
}


