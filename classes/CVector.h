#pragma once

//Class to work with coordinate
class CVector
{
public:
	CVector(void);
	~CVector(void);
	CVector(float x,float y,float z);
	CVector operator+(const CVector &other);
	CVector operator*(float scalar);
	void setX(const float val);
	void setY(const float val);
	void setZ(const float val);
	float getX() const;
	float getY() const;
	float getZ() const;
private:
    float x,y,z;

};

