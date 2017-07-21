#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include <map>

class Input{
public:
	void newFrame();
	void keyUp(const SDL_Event&);
	void keyDown(const SDL_Event&);
	bool wasKeyUp(SDL_Scancode);
	bool wasKeyDown(SDL_Scancode);
	bool isKeyHold(SDL_Scancode);
private:
	std::map<SDL_Scancode, bool> _heldKeys;
	std::map<SDL_Scancode, bool> _pressedKeys;
	std::map<SDL_Scancode, bool> _releasedKeys;
};

#endif