#ifndef __ModuleScoreRanking_H__
#define __ModuleScoreRanking_H__

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleScoreRanking : public Module
{
public:
	ModuleScoreRanking();
	~ModuleScoreRanking();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect background;

};

#endif