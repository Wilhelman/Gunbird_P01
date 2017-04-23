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
	background_speed = 0.5f;
	// Background
	background.w = SCREEN_WIDTH;
	background.h = 2108;

	soldier_left.PushBack({ 533, 373, 13, 26 });
	soldier_left.PushBack({ 550, 373, 13, 26 });
	soldier_left.PushBack({ 566, 373, 13, 26 });
	soldier_left.PushBack({ 582, 373, 13, 26 });
	soldier_left.speed = 0.1f;
	soldier_left_y = -145;
	soldier_left_x = 50;
	soldier_left_wall.loop = true;

	soldier_left_wall.PushBack({ 533, 373, 13, 26 });
	soldier_left_wall.PushBack({ 550, 373, 13, 26 });
	soldier_left_wall.PushBack({ 566, 373, 13, 26 });
	soldier_left_wall.PushBack({ 582, 373, 13, 26 });
	soldier_left_wall.speed = 0.06f;
	soldier_left_wall_y = -145;
	soldier_left_wall_x = 50;

	soldier_up.PushBack({ 534, 345, 15, 24 });
	soldier_up.PushBack({ 554, 345, 15, 24 });
	soldier_up.PushBack({ 573, 345, 15, 24 });
	soldier_up.PushBack({ 592, 345, 15, 24 });
	soldier_up.speed = 0.05f;
	soldier_up_y = -145;
	soldier_up_x = 50;

	soldier_up_blink.PushBack({ 534, 345, 15, 24 });
	soldier_up_blink.PushBack({ 554, 345, 15, 24 });
	soldier_up_blink.PushBack({ 573, 345, 15, 24 });
	soldier_up_blink.PushBack({ 592, 345, 15, 24 });
	soldier_up_blink.speed = 0.05f;
	soldier_up_blink_y = -145;
	soldier_up_blink_x = 50;

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
	spawned = 0;
	//setting bckground
	background_x = 0;
	background_y = -2108;

	soldier_left_wall_y = -145;
	soldier_left_wall_x = 50;
	soldier_left_wall.Reset();

	soldier_up_y = -145;
	soldier_up_x = 50;
	soldier_up.Reset();

	bridge_top_y = -718;
	bridge_top.Reset();

	houseFlag_y = -633;

	soldier_left_y = -145;
	soldier_left_x = 50;
	soldier_left.Reset();


	LOG("Loading SceneCastle assets");
	bool ret = true;
	background_y = -2036;

	App->player->Enable();
	App->ui->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	App->particles->Enable();

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

	if (background_y < -SCREEN_HEIGHT) {
		background_y += background_speed;
		soldier_left_y += background_speed;
		soldier_left_wall_y += background_speed;
		bridge_top_y += background_speed;
	}

	// Draw everything --------------------------------------
	if (!App->render->Blit(graphics,(int)background_x, (int)background_y + SCREEN_HEIGHT, &background, 0.75f)) {
		LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	//BACKGROUND ANIMATIONS
	{
		//soldier animations
		if (background_y <= -1800.0f && soldier_left_x >= -12 && graphicsSoldier != nullptr) {
			if (!App->render->Blit(graphicsSoldier, (int)soldier_left_x, (int)soldier_left_y + SCREEN_HEIGHT, &(soldier_left.GetCurrentFrame()), 0.75f)) {
				LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
			if (!App->render->Blit(graphicsSoldier, (int)soldier_left_x - 6, (int)soldier_left_y + SCREEN_HEIGHT + 20, &(soldier_left.GetCurrentFrame()), 0.75f)) {
				LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
			soldier_left_x -= 0.4f;
		}


		if (background_y <= -1800.0f && graphicsSoldier != nullptr) {
			/*if (background_y >= -1880)
			{
				if (!App->render->Blit(graphicsSoldier, (int)soldier_up_x + 35, (int)soldier_up_y + SCREEN_HEIGHT, &(soldier_up_blink.GetCurrentFrame()), 0.5f)) {
					LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
					status = UPDATE_ERROR;
				}
			}*/
			if (background_y <= -1810.0f)
			{ 
				if (!App->render->Blit(graphicsSoldier, (int)soldier_up_x + 35, (int)soldier_up_y + SCREEN_HEIGHT, &(soldier_up.GetCurrentFrame()), 0.75f)) {
					LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
					status = UPDATE_ERROR;
				}
			}

			if (background_y <= -1800.0f)
			{
				if (!App->render->Blit(graphicsSoldier, (int)soldier_up_x + 50, (int)soldier_up_y + SCREEN_HEIGHT + 20, &(soldier_up.GetCurrentFrame()), 0.75f)) {
					LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
					status = UPDATE_ERROR;
				}
			}
		}


		if (background_y <= -1650 && graphicsSoldier != nullptr) {
			if (!App->render->Blit(graphicsSoldier, (int)soldier_left_wall_x + 90,(int) soldier_left_wall_y + SCREEN_HEIGHT - 297, &(soldier_left_wall.GetCurrentFrame()), 0.75f)) {
				LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
			if (!App->render->Blit(graphicsSoldier, (int)soldier_left_wall_x + 70, (int)soldier_left_wall_y + SCREEN_HEIGHT - 297, &(soldier_left_wall.GetCurrentFrame()), 0.75f)) {
				LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
			if (!App->render->Blit(graphicsSoldier, (int)soldier_left_wall_x + 50, (int)soldier_left_wall_y + SCREEN_HEIGHT - 297, &(soldier_left_wall.GetCurrentFrame()), 0.75f)) {
				LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
			soldier_left_wall_x -= 0.4f;
		}

		//bridge animation
		if (bridge_top_y >= -350 && graphicsBridgeTop != nullptr) {
			if (!App->render->Blit(graphicsBridgeTop, 65, (int)bridge_top_y + SCREEN_HEIGHT, &(bridge_top.GetCurrentFrame()), 0.75f)) {
				LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
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
		App->fade->FadeToBlack(this, this,1.0f);

	if (App->player->playerLost) {
		LOG("Player LOST");
		App->fade->FadeToBlack(this, App->scoreRanking);
	}

	//ENEMY SPAWN PHASE
	{
		
		if ((int)background_y == -1950 && spawned == 0)
		{
			spawned = 1;
			App->enemies->AddEnemy(ENEMY_TYPES::METALLICBALLOON, 112, -70, ENEMY_MOVEMENT::BALLOON_PATH_CASTLE);
		}

		if ((int)background_y == -2000 && spawned == 1) {
			spawned = 2;
			App->enemies->AddEnemy(ENEMY_TYPES::CASTLE_HOUSEFLAG, 149, -275, ENEMY_MOVEMENT::STAY);
		}

		if ((int)background_y == -1840 && spawned == 2) {
			spawned = 3;
			App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, -25, -50, ENEMY_MOVEMENT::TURRET_1_PATH);
			App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, -25, -15, ENEMY_MOVEMENT::TURRET_2_PATH);
			App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, -25, 15, ENEMY_MOVEMENT::TURRET_3_PATH);
		}
		
		
		if ((int)background_y == -1800 && spawned == 3) {
			spawned = 4;
			App->enemies->AddEnemy(ENEMY_TYPES::CASTLE_HOUSEFLAG_2, 78, -340, ENEMY_MOVEMENT::STAY);

		}

		if ((int)background_y == -1780 && spawned == 4) {
			spawned = 5;
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, -30, -32, ENEMY_MOVEMENT::TORPEDO_DIAGONALL_R);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, -60, -64, ENEMY_MOVEMENT::TORPEDO_DIAGONALL_R);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, -90, -96, ENEMY_MOVEMENT::TORPEDO_DIAGONALL_R);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, -120, -128, ENEMY_MOVEMENT::TORPEDO_DIAGONALL_R);
		}


		if ((int)background_y == -1500 && spawned == 5) {
			spawned = 6;
			
			App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, 15, -45, ENEMY_MOVEMENT::STAY);	
			App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, 165, -45, ENEMY_MOVEMENT::STAY); // fix
			App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, -20, -85, ENEMY_MOVEMENT::TURRET_1_PATH);
			App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, 235, -85, ENEMY_MOVEMENT::TURRET1_L_PATH);// fix
			App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, 15, -375, ENEMY_MOVEMENT::STAY);
			App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, 170, -375, ENEMY_MOVEMENT::STAY);

			App->enemies->AddEnemy(ENEMY_TYPES::CASTLE_VASE, 10, -135, ENEMY_MOVEMENT::STAY);
			App->enemies->AddEnemy(ENEMY_TYPES::CASTLE_VASE, 185, -135, ENEMY_MOVEMENT::STAY);

			App->enemies->AddEnemy(ENEMY_TYPES::CASTLE_VASE, 8, -345, ENEMY_MOVEMENT::STAY);
			App->enemies->AddEnemy(ENEMY_TYPES::CASTLE_VASE, 185, -348, ENEMY_MOVEMENT::STAY);
			
		}

		if ((int)background_y == -1300 && spawned == 6) {
			spawned = 7;
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, SCREEN_WIDTH, 70, ENEMY_MOVEMENT::TORPEDO_HORIZONTALR_L);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, SCREEN_WIDTH + 30, 70, ENEMY_MOVEMENT::TORPEDO_HORIZONTALR_L);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, SCREEN_WIDTH + 60, 70, ENEMY_MOVEMENT::TORPEDO_HORIZONTALR_L);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, SCREEN_WIDTH + 90, 70, ENEMY_MOVEMENT::TORPEDO_HORIZONTALR_L);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, SCREEN_WIDTH + 120, 70, ENEMY_MOVEMENT::TORPEDO_HORIZONTALR_L);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, SCREEN_WIDTH + 150, 70, ENEMY_MOVEMENT::TORPEDO_HORIZONTALR_L);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, SCREEN_WIDTH + 180, 70, ENEMY_MOVEMENT::TORPEDO_HORIZONTALR_L);
			
		}

		if ((int)background_y == -1050 && spawned == 7) {
			spawned = 8;
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 70, -32, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 120, -32, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);

			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 10, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 50, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 140, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 180, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
		}
		if ((int)background_y == -1025 && spawned == 8) {
			spawned = 9;
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 10, -32, ENEMY_MOVEMENT::TORPEDO_DIAGONAL_L_FINAL);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 50, -32, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 140, -32, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 180, -32, ENEMY_MOVEMENT::TORPEDO_DIAGONAL_R_FINAL);

			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 70, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 120, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 112, -122, ENEMY_MOVEMENT::TORPEDO_DIAGONAL_R_FINAL);
		}

		if ((int)background_y == -900 && spawned == 9) {
			spawned = 10;
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 70, -32, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 120, -32, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);

			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 10, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 50, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 140, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 180, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
		}
		if ((int)background_y == -875 && spawned == 10) {
			spawned = 11;
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 10, -32, ENEMY_MOVEMENT::TORPEDO_DIAGONAL_L_FINAL2);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 50, -32, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 140, -32, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 180, -32, ENEMY_MOVEMENT::TORPEDO_DIAGONAL_R_FINAL2);

			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 70, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 120, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 112, -122, ENEMY_MOVEMENT::TORPEDO_DIAGONAL_L_FINAL2);
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_KP_2] && !App->player2->IsEnabled()) {
		App->player2->Enable();
	}

	/*if (App->input->keyboard[SDL_SCANCODE_F9] == KEY_STATE::KEY_DOWN)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::METALLICBALLOON, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, ENEMY_MOVEMENT::STAY);
	}*/

	return status;
}


bool ModuleSceneCastle::CleanUp()
{
	LOG("Unloading SceneCastle");

	bool ret = true;

	//App->audio->Disable();

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

	
	if (!App->textures->Unload(graphics)) {
		LOG("Error unloading graphics in SceneCastle");
		ret = false;
	}

	App->collision->Disable();
	App->particles->Disable();
	App->enemies->Disable();
	App->ui->Disable();
	App->player->Disable();
	App->player2->Disable();

	return true;
}