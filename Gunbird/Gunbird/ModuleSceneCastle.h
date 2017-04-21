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
	float soldier_left_y;
	float soldier_left_x;


	Animation soldier_left_wall;
	float soldier_left_wall_y;
	float soldier_left_wall_x;

	Animation soldier_up;
	float soldier_up_y;
	float soldier_up_x;

	Animation soldier_up_blink;
	float soldier_up_blink_y;
	float soldier_up_blink_x;

	Animation bridge_top;
	float bridge_top_y;

	float houseFlag_y;

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
	float background_x;
	float background_y;

	float background_speed;
	

};

#endif