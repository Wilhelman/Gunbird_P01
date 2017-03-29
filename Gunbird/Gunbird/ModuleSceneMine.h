#ifndef __ModuleSceneMine_H__
#define __ModuleSceneMine_H__

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneMine : public Module
{
public:
	ModuleSceneMine();
	~ModuleSceneMine();

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