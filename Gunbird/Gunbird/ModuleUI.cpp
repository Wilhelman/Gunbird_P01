#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleUI.h"
#include "ModulePlayer.h"


ModuleUI::ModuleUI()
{
	// Background

	background.w = SCREEN_WIDTH;
	background.h = 2108;

}

ModuleUI::~ModuleUI()
{}

// Load assets
bool ModuleUI::Start()
{
	background.x = 0;
	background.y = 37;
	background.w = 18;
	background.h = 32;

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

	// Draw everything --------------------------------------
	if (!App->render->Blit(graphics, 0, 0, &background, 1.0f)) {
		LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
		status = UPDATE_ERROR;
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