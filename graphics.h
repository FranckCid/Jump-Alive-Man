#include <SDL2/SDL.h>

#ifndef GRAPHICS
#define GRAPHICS

class Graphics{
public:
	Graphics();
	~Graphics();
	void clear();
	void flip();
	//Draw functions
	void rect(int x, int y, int w, int h);
	void point(int x, int y);
private:
	SDL_Window* _window;
	SDL_Renderer *_render;
};

#endif
