#include "tile.h"
#include <iostream>

void Tile::start(){
	transform.pos.x = 100;
	transform.pos.y = 100;
	transform.scale.x = 10;
	transform.scale.y = 10;

	collider.transform.scale = transform.scale;
}

void Tile::update(Input&, float){
	collider.transform.pos = transform.pos;
}

void Tile::draw(Graphics&g){
	g.rect(transform.pos.x, transform.pos.y, transform.scale.x, transform.scale.y);
}

void Tile::checkCollisionWith(PhysicalGameObject&obj){
	if(collider.rect(obj.transform)){
		std::cout << "Obj coolided with player" << std::endl;
	}
}