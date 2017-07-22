#ifndef PLAYER_H
#define PLAYER_H

#include "physicalgameobject.h"
#include "boxcollider.h"

class Player : public PhysicalGameObject{
public:
	virtual void start();
	virtual void update(Input&, float);
	virtual void draw(Graphics&);
	virtual void checkCollisionWith(PhysicalGameObject&obj);
protected:
};

#endif