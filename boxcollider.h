#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "vector2.h"
#include "transform.h"

class BoxCollider{
public:
	//Collision check
	bool point(float x, float y){
		bool horizontal = (x >=transform.pos.x && x <=transform.scale.x +transform.scale.x);
		bool vertical = (y >=transform.pos.y && y <=transform.scale.y +transform.scale.y);
		return (horizontal && vertical);
	}

	bool rect(Transform& t2){
		Transform& t1 = this->transform;
		bool horizontal = (t1.pos.x < t2.pos.x + t2.scale.x) && (t1.pos.x + t1.scale.x > t2.pos.x);
		bool vertical = (t1.pos.y < t2.pos.y + t2.scale.y) && (t1.pos.y + t1.scale.y > t2.pos.y);
		return horizontal && vertical;
	}

	Transform transform;
protected:
};

#endif