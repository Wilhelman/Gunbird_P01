#ifndef __ModuleSceneSea_H__
#define __ModuleSceneSea_H__

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneSea : public Module
{
public:
	ModuleSceneSea();
	~ModuleSceneSea();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect background;
	int background_x;
	int background_y;

};

#endif