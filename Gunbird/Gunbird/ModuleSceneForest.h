#ifndef __ModuleSceneForest_H__
#define __ModuleSceneForest_H__

#include "Module.h"
#include "Globals.h"
#include "Animation.h"
#include "ModuleParticles.h"

struct SDL_Texture;

class ModuleSceneForest : public Module
{
private:
	int spawned = 0;

public:
	ModuleSceneForest();
	~ModuleSceneForest();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* graphics = nullptr;
	SDL_Rect background;
	float background_x;
	float background_y;

	float background_speed;


	uint player2joined;


};

#endif