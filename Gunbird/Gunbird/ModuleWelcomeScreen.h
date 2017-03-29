#ifndef __ModuleWelcomeScreen_H__
#define __ModuleWelcomeScreen_H__

#include "Module.h"
#include "Globals.h"
#include "Animation.h"

struct SDL_Texture;

class ModuleWelcomeScreen : public Module
{
public:
	ModuleWelcomeScreen();
	~ModuleWelcomeScreen();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	Animation welcomeScreenAnimation;

};

#endif