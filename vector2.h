#ifndef VECTOR2_F
#define VECTOR2_F

template <typename T> 
class __Vector2{
public:
	__Vector2() : x(0), y(0){}
	__Vector2(T a, T b) : x(a), y(b){}
	__Vector2(const __Vector2&v) : __Vector2(v.x, v.y){}
	__Vector2& operator+=(const __Vector2&v){
		x += v.x;
		y += v.y;
		return *this;
	}
	__Vector2& operator-=(const __Vector2&v){
		x -= v.x;
		y -= v.y;
		return *this;
	}
	__Vector2& operator+(const __Vector2&v) const{
		return __Vector2(*this) += v;
	}
	__Vector2& operator-(const __Vector2&v) const{
		return __Vector2(*this) += v;
	}
	T x;
	T y;
};

typedef __Vector2<float> Vector2f;
typedef __Vector2<double> Vector2d;
typedef __Vector2<int> Vector2i;

#endif