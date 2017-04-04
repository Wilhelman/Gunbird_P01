#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleSceneMine.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleScoreRanking.h"
#include "ModuleCollision.h"

//TODO: remove this if not necesary
#include "ModuleInput.h"

ModuleSceneMine::ModuleSceneMine()
{
	// Background
	background_x = 0;
	background_y = -3535;
	background.w = SCREEN_WIDTH;
	background.h = 3535;
}

ModuleSceneMine::~ModuleSceneMine()
{}

// Load assets
bool ModuleSceneMine::Start()
{
	LOG("Loading SceneMine assets");
	bool ret = true;

	background_y = -3535;
	
	App->player->Enable();
	App->collision->Enable();

	graphics = App->textures->Load("Assets/maps/map_mine_background.png");
	if (graphics == nullptr) {
		LOG("Cannot load the texture in SceneMine");
		ret = false;
	}
	if (!App->audio->PlayMusic("Assets/audio/gunbird_mine_level_music.ogg"))
		ret = false;
	return ret;
}

// Update: draw background
update_status ModuleSceneMine::Update()
{

	update_status status = UPDATE_CONTINUE;

	int speed = 1;
	if (background_y< -SCREEN_HEIGHT)
		background_y += speed;

	// Draw everything --------------------------------------
	if (!App->render->Blit(graphics, background_x, background_y + SCREEN_HEIGHT, &background, 0.75f)) {
		LOG("Cannot blit the texture in Scene Mine %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	//TODO change the position of the player to private to do it better

	if ((App->player->position.y < 0 && App->fade->FadeIsOver()) || App->input->keyboard[SDL_SCANCODE_RETURN] && App->fade->FadeIsOver())
		App->fade->FadeToBlack(this, App->scoreRanking);

	return status;
}

bool ModuleSceneMine::CleanUp()
{
	//TODO check if we can control this
	LOG("Unloading Scene Mine");

	App->audio->Disable();
	App->textures->Unload(graphics);
	App->player->Disable();
	
	

	return true;
}