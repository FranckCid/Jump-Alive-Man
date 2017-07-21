#include "game.h"
#include "gameobject.h"
#include "input.h"

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 1000/FPS;
}

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	this->loadScene();
	this->loop();
}

void Game::loadScene(){
	_objs.push_back(std::make_shared<GameObject>());
}

void Game::loop(){
	Graphics g;
	Input input;
	SDL_Event evnt;
	bool running = true;

	int LAST_UPDATE_TIME = SDL_GetTicks();

	for(auto &o : _objs){
		o->start();
	}
	while(running){
		input.newFrame();

		while(SDL_PollEvent(&evnt)){
			switch(evnt.type){
				case SDL_QUIT:
					running = false;
					break;
				case SDL_KEYDOWN:
					input.keyDown(evnt);
					break;
				case SDL_KEYUP:
					input.keyUp(evnt);
					break;
			}
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;

		this->update(input, std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;
		this->draw(g);
	}
}

void Game::update(Input& input, float delta){
	delta /= 10;
	for(auto &o : _objs){
		o->update(input, delta);
	}
}

void Game::draw(Graphics &g){
	g.clear();

	for(auto &o : _objs){
		o->draw(g);
	}

	g.flip();
}

Game::~Game(){
	SDL_Quit();
}