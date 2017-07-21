#include "input.h"

void Input::newFrame(){
	_pressedKeys.clear();
	_releasedKeys.clear();
}

void Input::keyUp(const SDL_Event& e){
	_releasedKeys[e.key.keysym.scancode] = true;
	_heldKeys[e.key.keysym.scancode] = false;
}

void Input::keyDown(const SDL_Event& e){
	_pressedKeys[e.key.keysym.scancode] = true;
	_heldKeys[e.key.keysym.scancode] = true;
}


bool Input::wasKeyUp(SDL_Scancode k){ return _releasedKeys[k]; }
bool Input::wasKeyDown(SDL_Scancode k){ return _pressedKeys[k]; }
bool Input::isKeyHold(SDL_Scancode k){ return _heldKeys[k]; }