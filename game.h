
#ifndef GAME
#define GAME

#include <SDL2/SDL.h>
#include <memory>
#include <vector>

#include "player.h"
#include "input.h"
#include "tile.h"
#include "physicalgameobject.h"

class Game{
public:
	Game();
	~Game();
private:
	void loadScene();
	void loop();
	void update(Input&, float delta);
	void draw(Graphics&);	
	std::vector<std::shared_ptr<GameObject> > _objs;
	std::vector<std::shared_ptr<PhysicalGameObject> > _physicalObjs;
};

#endif