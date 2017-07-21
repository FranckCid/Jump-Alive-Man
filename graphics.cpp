#include "graphics.h"
#include <algorithm>

Graphics::Graphics(){
	_window = SDL_CreateWindow("Jump Alive Man", 0, 0, 600, 600, 0); 
	_render = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

Graphics::~Graphics(){
	SDL_DestroyRenderer(_render);
	SDL_DestroyWindow(_window);
}

void Graphics::clear() {
	SDL_SetRenderDrawColor(_render, 0xff, 0x00, 0x00, 0xff);
	SDL_RenderClear(_render);
}

void Graphics::flip() {
	SDL_RenderPresent(_render);
}

//Draw Functions

void Graphics::rect(int x, int y, int w, int h){
	SDL_SetRenderDrawColor(_render, 0xff, 0xff, 0xff, 0xff);
	const SDL_Rect rect = {x, y, w, h};
	SDL_RenderFillRect(_render, &rect);
}