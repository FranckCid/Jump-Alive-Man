#ifndef TILE_H
#define TILE_H

#include "physicalgameobject.h"
#include "boxcollider.h"

class Tile : public PhysicalGameObject{
public:
	virtual void start();

	virtual void update(Input&, float);

	virtual void draw(Graphics&g);

	virtual void checkCollisionWith(PhysicalGameObject&obj);
protected:
};

#endif