#include "gameobject.h"
#include <iostream>

GameObject::GameObject() : _pos(0, 0){}
GameObject::GameObject(float x, float y) : _pos(x, y){}

void GameObject::start(){}

void GameObject::update(Input& input, float elapsedTime){
	float spd = 3.0f * elapsedTime;
	std::cout << elapsedTime << std::endl;
	if(input.isKeyHold(SDL_SCANCODE_LEFT)){
		_pos.x = _pos.x - spd;
	}else if(input.isKeyHold(SDL_SCANCODE_RIGHT)){
		_pos.x = _pos.x + spd;
	}
	if(input.isKeyHold(SDL_SCANCODE_UP)){
		_pos.y = _pos.y - spd;
	}else if(input.isKeyHold(SDL_SCANCODE_DOWN)){
		_pos.y = _pos.y + spd;
	}
}

void GameObject::draw(Graphics&g){
	g.rect(_pos.x, _pos.y, 10, 10);
}