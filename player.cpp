#include "player.h"
#include <iostream>

void Player::start(){
	transform.pos.x = 100;
	transform.pos.y = 100;
	transform.scale.x = 10;
	transform.scale.y = 10;

	collider.transform.scale = transform.scale;
}

void Player::update(Input& input, float elapsedTime){

	collider.transform.pos = transform.pos;

	float spd = 1.0f * elapsedTime;
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

void Player::draw(Graphics&g){
	g.rect(transform.pos.x, transform.pos.y, transform.scale.x, transform.scale.y);
}

void Player::checkCollisionWith(PhysicalGameObject&obj){
	if(collider.rect(obj.transform)){
		std::cout << "ASD" << std::endl;
	}
}