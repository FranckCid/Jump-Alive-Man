#ifndef GAMEOBJECT
#define GAMEOBJECT

#include "graphics.h"
#include "input.h"
#include "transform.h"

class GameObject{
public:
	virtual void start() = 0;
	virtual void update(Input&, float) = 0;
	virtual void draw(Graphics&) = 0;
protected:
	Transform transform;
};

#endif