#ifndef CVector_H
#define CVector_H

class CVector
{
public:
	CVector(void);
	~CVector(void);
	CVector(float x,float y,float z);
	CVector operator+(const CVector &other);
	CVector operator*(float scalar);
	//bool operator==(float scalar);
	bool containsOnly(float scalar);
	void setX(const float val);
	void setY(const float val);
	void setZ(const float val);
	float getX() const;
	float getY() const;
	float getZ() const;
	void print() const;
private:
    float x,y,z;

};

#endif
