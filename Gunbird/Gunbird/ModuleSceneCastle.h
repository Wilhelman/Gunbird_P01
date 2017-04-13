#ifndef __ModuleSceneCastle_H__
#define __ModuleSceneCastle_H__

#include "Module.h"
#include "Globals.h"
#include "Animation.h"
#include "ModuleParticles.h"

struct SDL_Texture;

class ModuleSceneCastle : public Module
{
private:
	
	Animation soldier_left;
	uint soldier_left_y;
	float soldier_left_x;

	Animation bridge_top;
	uint bridge_top_y;
	
	Animation houseFlag;
	uint houseFlag_y;

public:
	ModuleSceneCastle();
	~ModuleSceneCastle();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* graphicsHouseFlag = nullptr;
	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphicsSoldier = nullptr;
	SDL_Texture* graphicsBridgeTop = nullptr;
	SDL_Rect background;
	int background_x;
	int background_y;
	

};

#endif