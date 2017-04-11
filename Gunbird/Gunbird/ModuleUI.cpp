#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleUI.h"
#include "ModulePlayer.h"


ModuleUI::ModuleUI()
{
	for (int i = 0; i < 3; i++)
	{
		livesCount[i] = true;
	}

	liveIcon.x = 255;
	liveIcon.y = 152;
	liveIcon.w = 15;
	liveIcon.h = 12;
}

ModuleUI::~ModuleUI()
{}

// Load assets
bool ModuleUI::Start()
{
	LOG("Loading ModuleUI assets");
	bool ret = true;

	graphics = App->textures->Load("Assets/Items/Items.png");

	if (graphics == nullptr) {
		LOG("Cannot load the texture in ModuleUI");
		ret = false;
	}

	return ret;
}

// Update: draw background
update_status ModuleUI::Update()
{

	update_status status = UPDATE_CONTINUE;


	if (App->player->playerLives >= 0) {
		if (!App->render->Blit(graphics, 5, 16, &liveIcon, 1.0f)) {
			LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
	}

	if (App->player->playerLives >= 1) {
		if (!App->render->Blit(graphics, 22, 16, &liveIcon, 1.0f)) {
			LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
	}

	if (App->player->playerLives >= 2) {
		if (!App->render->Blit(graphics, 38, 16, &liveIcon, 1.0f)) {
			LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
	}
	

	return status;
}

bool ModuleUI::CleanUp()
{
	LOG("Unloading ModuleUI");

	bool ret = true;

	if (!App->textures->Unload(graphics)) {
		LOG("Error unloading graphics in ModuleUI");
		ret = false;
	}

	return false;
}