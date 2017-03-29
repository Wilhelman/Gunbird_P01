#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 12

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleAudio;
class ModuleFadeToBlack;
class ModuleWelcomeScreen;
class ModuleCharacterSelection;
class ModuleScoreRanking;
class ModuleSceneSea;
class ModuleSceneMine;
class ModulePlayer;
class Module;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleAudio* audio;
	ModuleFadeToBlack* fade;
	ModuleWelcomeScreen* welcomeScreen;
	ModuleCharacterSelection* characterSelection;
	ModuleScoreRanking* scoreRanking;
	ModuleSceneSea* sceneSea;
	ModuleSceneMine* sceneMine;
	ModulePlayer* player;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__