#ifndef VECTOR2_F
#define VECTOR2_F

template <typename T> 
class __Vector2{
public:
	__Vector2(T a, T b) : x(a), y(b){}
	T x;
	T y;
};

typedef __Vector2<float> Vector2f;
typedef __Vector2<double> Vector2d;
typedef __Vector2<int> Vector2i;

#endif