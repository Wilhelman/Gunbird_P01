#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 15

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleAudio;
class ModuleParticles;
class ModuleCollision;
class ModuleFadeToBlack;
class ModuleWelcomeScreen;
class ModuleCharacterSelection;
class ModuleScoreRanking;
class ModuleSceneCastle;
class ModuleSceneMine;
class ModulePlayer;
class ModuleTorpedo;
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
	ModuleParticles* particles;
	ModuleCollision* collision;
	ModuleFadeToBlack* fade;
	ModuleWelcomeScreen* welcomeScreen;
	ModuleCharacterSelection* characterSelection;
	ModuleScoreRanking* scoreRanking;
	ModuleSceneCastle* sceneCastle;
	ModuleSceneMine* sceneMine;
	ModulePlayer* player;
	ModuleTorpedo* torpedo;

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