#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleSceneSea.h"

ModuleSceneSea::ModuleSceneSea()
{
	// Background
	background_x = 0;
	background_y = -2036;
	background.w = SCREEN_WIDTH;
	background.h = 2036;
}

ModuleSceneSea::~ModuleSceneSea()
{}

// Load assets
bool ModuleSceneSea::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Assets/maps/map_sea_background.png");
	App->audio->PlayMusic("Assets/audio/gunbird_sea_level_music.wav");
	return ret;
}

// Update: draw background
update_status ModuleSceneSea::Update()
{

	update_status status = UPDATE_CONTINUE;

	int speed = 1;
	if(background_y< -SCREEN_HEIGHT)
		background_y += speed;

	// Draw everything --------------------------------------
	if (!App->render->Blit(graphics, background_x, background_y + SCREEN_HEIGHT, &background, 0.75f))
		status = UPDATE_ERROR;


	return status;
}