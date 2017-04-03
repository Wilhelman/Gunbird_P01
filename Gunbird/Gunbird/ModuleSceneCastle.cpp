#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleSceneCastle.h"
#include "ModuleSceneMine.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"

//TODO: remove this if not necesary
#include "ModuleInput.h"


ModuleSceneCastle::ModuleSceneCastle()
{
	// Background
	background_x = 0;
	background_y = -2108;
	background.w = SCREEN_WIDTH;
	background.h = 2108;

	soldier_left.PushBack({ 0, 28, 11, 25 });
	soldier_left.PushBack({ 16, 28, 12, 24 });
	soldier_left.PushBack({ 33, 28, 11, 25 });
	soldier_left.PushBack({ 49, 29, 11, 24 });
	soldier_left.speed = 0.1;
	soldier_left_y = -145;
	soldier_left_x = 50;

	bridge_top.PushBack({ 0, 0, 121, 35 });
	bridge_top.PushBack({ 125, 0, 116, 46 });
	bridge_top.PushBack({ 0, 64, 115, 72 });
	bridge_top.PushBack({ 125, 64, 112, 83 });
	bridge_top.PushBack({ 0, 189, 110, 106 });
	bridge_top.PushBack({ 0, 309, 110, 90 });
	bridge_top.PushBack({ 125, 309, 110, 103 });
	bridge_top.PushBack({ 250, 309, 110, 106 });
	bridge_top.speed = 0.08;
	bridge_top.loop = false;
	bridge_top_y = -710;
}

ModuleSceneCastle::~ModuleSceneCastle()
{}

// Load assets
bool ModuleSceneCastle::Start()
{
	background_x = 0;
	background_y = -2108;
	background.w = SCREEN_WIDTH;
	background.h = 2108;

	soldier_left_y = -145;
	soldier_left_x = 50;
	soldier_left.Reset();

	bridge_top_y = -710;
	bridge_top.Reset();

	LOG("Loading SceneSea assets");
	bool ret = true;
	background_y = -2036;

	App->player->Enable();

	graphics = App->textures->Load("Assets/maps/castle/map_castle_background.png");
	if (graphics == nullptr) {
		LOG("Cannot load the texture in SceneCastle");
		ret = false;
	}

	graphicsSoldier = App->textures->Load("Assets/maps/castle/map_castle_soldier.png");
	if (graphicsSoldier == nullptr) {
		LOG("Cannot load the animations spritesheet in SceneCastle");
		ret = false;
	}

	graphicsBridgeTop = App->textures->Load("Assets/maps/castle/map_castle_bridge.png");
	if (graphicsSoldier == nullptr) {
		LOG("Cannot load the animations spritesheet in SceneCastle");
		ret = false;
	}

	if (!App->audio->PlayMusic("Assets/audio/gunbird_welcome_CastleScreen_music.ogg"))
		ret = false;
	return ret;
}

// Update: draw background
update_status ModuleSceneCastle::Update()
{

	update_status status = UPDATE_CONTINUE;

	int speed = 1;
	if (background_y < -SCREEN_HEIGHT) {
		background_y += speed;
		soldier_left_y += speed;
		bridge_top_y += speed;
	}

	// Draw everything --------------------------------------
	if (!App->render->Blit(graphics, background_x, background_y + SCREEN_HEIGHT, &background, 0.75f)) {
		LOG("Cannot blit the texture in SceneCastle %s\n",SDL_GetError());
		status = UPDATE_ERROR;
	}

	//soldier animations
	if (soldier_left_y >= 30 && soldier_left_x>=-12) {
		if (!App->render->Blit(graphicsSoldier, (int)soldier_left_x, soldier_left_y + SCREEN_HEIGHT,&(soldier_left.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
		if (!App->render->Blit(graphicsSoldier, (int)soldier_left_x-6, soldier_left_y + SCREEN_HEIGHT + 20, &(soldier_left.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
		soldier_left_x -= 0.4;
	}

	//bridge animation
	if (bridge_top_y >= -300) {
		if (!App->render->Blit(graphicsBridgeTop, 65, bridge_top_y + SCREEN_HEIGHT, &(bridge_top.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
	}

	//TODO change the position of the player to private to be more pro
	if ((App->player->position.y < 0 && App->fade->FadeIsOver()) ||/*TODO: remove this condition*/ (App->input->keyboard[SDL_SCANCODE_RETURN] && App->fade->FadeIsOver()))
		App->fade->FadeToBlack(this, App->sceneMine);

	return status;
}

bool ModuleSceneCastle::CleanUp()
{
	//TODO check if we can control this
	LOG("Unloading SceneCastle");

	App->player->Disable();
	App->textures->Unload(graphics);
	App->textures->Unload(graphicsSoldier);
	App->textures->Unload(graphicsBridgeTop);
	App->audio->StopMusic();

	return true;
}