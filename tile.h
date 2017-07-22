#ifndef TILE_H
#define TILE_H

#include "physicalgameobject.h"
#include "boxcollider.h"
#include <iostream>

class Tile : public PhysicalGameObject{
public:
	virtual void start(){
		transform.pos.x = 100;
		transform.pos.y = 100;
		transform.scale.x = 10;
		transform.scale.y = 10;

		collider.transform.scale = transform.scale;
	}

	virtual void update(Input&, float){
		collider.transform.pos = transform.pos;
	}

	virtual void draw(Graphics&g){
		g.rect(transform.pos.x, transform.pos.y, transform.scale.x, transform.scale.y);
	}

	virtual void checkCollisionWith(PhysicalGameObject&obj){
		if(collider.rect(obj.transform)){
			std::cout << "ASD" << std::endl;
		}
	}
protected:
};

#endif