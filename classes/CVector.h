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
	CVector operator/(float scalar);
	void multiply(float const v);
	void substract(float const v);
	void reverseSign();
	//bool operator==(float scalar);
	bool containsOnly(float scalar);
	void setX(const float val);
	void setY(const float val);
	void setZ(const float val);
	float getX() const;
	float getY() const;
	float getZ() const;
	float getAbsoluteMax() const;
	void random();
	void random(float const max);
	float distanceTo(float const x1,float const y1, float const z1) const;
	float distanceTo(CVector other) const;
	void print() const;
	bool isEmpty() const;
	void setEmpty(bool const b);
private:
    float x,y,z;
    bool empty;
};

#endif
