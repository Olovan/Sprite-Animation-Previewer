#ifndef VEC2_H_BTPOKQ7A
#define VEC2_H_BTPOKQ7A

#include <string>


namespace msgl { namespace core {

class Vec2
{
public:
	float x;
	float y;

	Vec2 ();
	Vec2 (float x, float y);
	Vec2 (const Vec2 &copy);

	Vec2 operator+(const Vec2 &other);
	Vec2 operator-(const Vec2 &other);
	Vec2 operator*(const Vec2 &other);
	Vec2 operator/(const Vec2 &other);

	std::string toString();
	bool isPositive();

private:
	/* data */
};

}} //NameSpace


#endif /* end of include guard: VEC2_H_BTPOKQ7A */
