#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleBackground.h"

ModuleBackground::ModuleBackground()
{
	// Background
	background.x = 0;
	background.y = 0;
	background.w = 288;
	background.h = 2036;
}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Assets/maps/map_sea_background.png");
	App->audio->PlayMusic("Assets/audio/gunbird_sea_level_music.wav");
	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{

	update_status status = UPDATE_CONTINUE;

	// Draw everything --------------------------------------
	if (!App->render->Blit(graphics, 0, -2036 + SCREEN_HEIGHT, &background, 0.75f))
		status = UPDATE_ERROR;


	return status;
}