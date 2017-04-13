#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleSceneCastle.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
#include "ModuleScoreRanking.h"
#include "ModuleUI.h"
#include "SDL\include\SDL_timer.h"

//TODO: remove this if not necesary
#include "ModuleInput.h"


ModuleSceneCastle::ModuleSceneCastle()
{
	// Background
	background_x = 0;
	background_y = -2108;
	background.w = SCREEN_WIDTH;
	background.h = 2108;

	soldier_left.PushBack({ 533, 373, 13, 26 });
	soldier_left.PushBack({ 550, 373, 13, 26 });
	soldier_left.PushBack({ 566, 373, 13, 26 });
	soldier_left.PushBack({ 582, 373, 13, 26 });
	soldier_left.speed = 0.1f;
	soldier_left_y = -145;
	soldier_left_x = 50;

	bridge_top.PushBack({ 37, 40, 122, 36 });
	bridge_top.PushBack({ 162, 40, 122, 46 });
	bridge_top.PushBack({ 288, 40, 120, 54 });
	bridge_top.PushBack({ 38, 104, 116, 73 });
	bridge_top.PushBack({ 163, 104, 113, 84 });
	bridge_top.PushBack({ 38, 229, 111, 107 });
	bridge_top.PushBack({ 38, 348, 111, 91 });
	bridge_top.PushBack({ 163, 349, 111, 104 });
	bridge_top.PushBack({ 288, 349, 110, 107 });
	bridge_top.speed = 0.08f;
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

	bridge_top_y = -718;
	bridge_top.Reset();

	houseFlag_y = -633;
	



	LOG("Loading SceneCastle assets");
	bool ret = true;
	background_y = -2036;

	App->player->Enable();
	App->ui->Enable();
	App->collision->Enable();
	App->enemies->Enable();

	graphics = App->textures->Load("Assets/maps/castle/map_castle_background.png");
	if (graphics == nullptr) {
		LOG("Cannot load the texture in SceneCastle");
		ret = false;
	}

	graphicsSoldier = App->textures->Load("Assets/maps/castle/castle_map_stuff.png");
	if (graphicsSoldier == nullptr) {
		LOG("Cannot load the animations spritesheet in SceneCastle");
		ret = false;
	}

	graphicsBridgeTop = App->textures->Load("Assets/maps/castle/castle_map_stuff.png");
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
		LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	//soldier animations
	if (soldier_left_y >= 30 && soldier_left_x >= -12 && graphicsSoldier != nullptr) {
		if (!App->render->Blit(graphicsSoldier, (int)soldier_left_x, soldier_left_y + SCREEN_HEIGHT, &(soldier_left.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
		if (!App->render->Blit(graphicsSoldier, (int)soldier_left_x - 6, soldier_left_y + SCREEN_HEIGHT + 20, &(soldier_left.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
		soldier_left_x -= 0.4f;
	}

	//bridge animation
	if (bridge_top_y >= -350 && graphicsBridgeTop != nullptr) {
		if (!App->render->Blit(graphicsBridgeTop, 65, bridge_top_y + SCREEN_HEIGHT, &(bridge_top.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN && App->sceneCastle->IsEnabled())
	{
		if (!App->textures->Unload(graphicsSoldier)) {
			LOG("Error unloading graphics in SceneCastle");
			status = UPDATE_ERROR;
		}
		graphicsSoldier = nullptr;
		if (!App->textures->Unload(graphicsBridgeTop)) {
			LOG("Error unloading graphics in SceneCastle");
			status = UPDATE_ERROR;
		}
		graphicsBridgeTop = nullptr;
		App->enemies->Disable();
		App->player->playerCollider->to_delete = true;
		background_y = -SCREEN_HEIGHT;
	}



	//TODO change the position of the player to private to be more pro
	if ((App->player->position.y < 0 && App->fade->FadeIsOver()) ||/*TODO: remove this condition*/ (App->input->keyboard[SDL_SCANCODE_RETURN] && App->fade->FadeIsOver()))
		App->fade->FadeToBlack(this, this);

	if (App->player->playerLost) {
		LOG("Player LOST");
		App->fade->FadeToBlack(this, App->scoreRanking);
	}

	//ENEMY SPAWN PHASE

	/*if (background_y == -1850) {
		App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, -25, -70);
		App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, -25, -30);
		App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, -25, 10);
		
	}*/
	if (background_y == -2000) {
		App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, -30, -32, ENEMY_MOVEMENT::TORPEDO_DIAGONALL_R);
		App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, -60, -64, ENEMY_MOVEMENT::TORPEDO_DIAGONALL_R);
		App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, -90, -96, ENEMY_MOVEMENT::TORPEDO_DIAGONALL_R);
		App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, -120, -128, ENEMY_MOVEMENT::TORPEDO_DIAGONALL_R); 
	}

	if (background_y == -1600) {
		App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, SCREEN_WIDTH, 30, ENEMY_MOVEMENT::TORPEDO_HORIZONTALR_L);
		App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, SCREEN_WIDTH + 40, 30, ENEMY_MOVEMENT::TORPEDO_HORIZONTALR_L);
		App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, SCREEN_WIDTH + 80, 30, ENEMY_MOVEMENT::TORPEDO_HORIZONTALR_L);
		App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, SCREEN_WIDTH + 120, 30, ENEMY_MOVEMENT::TORPEDO_HORIZONTALR_L);
	}

	if (background_y == -2000) {
		App->enemies->AddEnemy(ENEMY_TYPES::CASTLE_HOUSEFLAG, 149, -275, ENEMY_MOVEMENT::NO_MOVEMENT);
	}

	/*if (background_y == -2000)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::METALLICBALLOON, 112, -70);
	}*/

	if (App->input->keyboard[SDL_SCANCODE_K] && !App->player2->IsEnabled()) {
		App->player2->Enable();
	}

	return status;
}


bool ModuleSceneCastle::CleanUp()
{
	LOG("Unloading SceneCastle");

	bool ret = true;

	App->audio->Disable();

	if (graphicsSoldier != nullptr) {
		if (!App->textures->Unload(graphicsSoldier)) {
			LOG("Error unloading graphics in SceneCastle");
			ret = false;
		}
	}

	if (graphicsBridgeTop != nullptr) {
		if (!App->textures->Unload(graphicsBridgeTop)) {
			LOG("Error unloading graphics in SceneCastle");
			ret = false;
		}
	}
	if (graphicsHouseFlag != nullptr) {
		if (!App->textures->Unload(graphicsHouseFlag)) {
			LOG("Error unloading graphics in SceneCastle");
			ret = false;
		}
	}
	
	if (!App->textures->Unload(graphics)) {
		LOG("Error unloading graphics in SceneCastle");
		ret = false;
	}

	App->collision->Disable();
	App->enemies->Disable();
	App->ui->Disable();
	App->player->Disable();
	App->player2->Disable();

	return true;
}