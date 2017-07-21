#ifndef GAMEOBJECT
#define GAMEOBJECT

#include "graphics.h"
#include "input.h"
#include "vector2.h"

class GameObject{
public:
	GameObject();
	GameObject(float x, float y);
	virtual void start();
	virtual void update(Input&, float);
	virtual void draw(Graphics&);
protected:
	Vector2f _pos;
};

#endif