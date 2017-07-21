#ifndef PLAYER_H
#define PLAYER_H

#include "gameobject.h"

class Player : public GameObject{
public:
	virtual void start();
	virtual void update(Input&, float);
	virtual void draw(Graphics&);
protected:
};

#endif