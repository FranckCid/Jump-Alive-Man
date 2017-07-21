
#ifndef GAME
#define GAME

#include <SDL2/SDL.h>
#include <memory>
#include <vector>

class Input;
class Graphics;
class GameObject;

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
};

#endif