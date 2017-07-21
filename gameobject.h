#ifndef GAMEOBJECT
#define GAMEOBJECT

#include "graphics.h"
#include "input.h"
#include "transform.h"

class GameObject{
public:
	virtual void start();
	virtual void update(Input&, float);
	virtual void draw(Graphics&);
protected:
	Transform transform;
};

#endif