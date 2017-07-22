#ifndef PHYSICALGAMEOBJECT_H
#define PHYSICALGAMEOBJECT_H

#include "boxcollider.h"
#include "gameobject.h"

class PhysicalGameObject : public GameObject{
public:
	virtual void checkCollisionWith(PhysicalGameObject&obj) = 0;
	BoxCollider collider;
protected:
};

#endif