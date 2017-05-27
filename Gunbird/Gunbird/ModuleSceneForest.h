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

	Animation miner_down;
	Animation miner_up;
	Animation miner_rigth;
	Animation miner_drigth;
	Animation miner_dleft;

public:
	ModuleSceneForest();
	~ModuleSceneForest();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* graphics = nullptr;
	SDL_Texture* motionless_trees = nullptr;
	SDL_Rect background;
	SDL_Rect m_trees;
	float background_x;
	float background_y;

	float background_speed;

	uint player2joined;

	
};

#endif