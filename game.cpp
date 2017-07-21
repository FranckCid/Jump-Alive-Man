#include "game.h"
#include "player.h"
#include "input.h"

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	this->loadScene();
	this->loop();
}

void Game::loadScene(){
	_objs.push_back(std::make_shared<Player>());
}

void Game::loop(){
	Graphics g;
	Input input;
	SDL_Event evnt;
	bool running = true;

	Uint64 NOW = 0, LAST = 0;
	double deltaTime = 0;

	for(auto &o : _objs){
		o->start();
	}
	while(running){
		input.newFrame();

		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();

		deltaTime = (double)((NOW - LAST) * 1000 / SDL_GetPerformanceFrequency());

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

		this->update(input, deltaTime);
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