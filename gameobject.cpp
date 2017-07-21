#include "gameobject.h"
#include <iostream>

void GameObject::start(){
	transform.pos.x = 100;
	transform.pos.y = 100;
	transform.scale.x = 10;
	transform.scale.y = 10;
}

void GameObject::update(Input& input, float elapsedTime){
	float spd = 3.0f * elapsedTime;
	std::cout << elapsedTime << std::endl;
	if(input.isKeyHold(SDL_SCANCODE_LEFT)){
		transform.pos.x -= spd;
	}else if(input.isKeyHold(SDL_SCANCODE_RIGHT)){
		transform.pos.x += spd;
	}
	if(input.isKeyHold(SDL_SCANCODE_UP)){
		transform.pos.y -= spd;
	}else if(input.isKeyHold(SDL_SCANCODE_DOWN)){
		transform.pos.y += spd;
	}
	Vector2f a(0, 0);
	transform.pos = a + transform.pos;
}

void GameObject::draw(Graphics&g){
	g.rect(transform.pos.x, transform.pos.y, transform.scale.x, transform.scale.y);
}