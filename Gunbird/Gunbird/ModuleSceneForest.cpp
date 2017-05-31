#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleSceneForest.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
#include "ModuleScoreRanking.h"
#include "ModuleUI.h"
#include "ModuleCharacterSelection.h"
#include "SDL\include\SDL_timer.h"

//TODO: remove this if not necesary
#include "ModuleInput.h"


ModuleSceneForest::ModuleSceneForest()
{
	background_speed = 0.5f;
	// Background
	background.w = SCREEN_WIDTH;
	background.h = 2800;
	m_trees.w = SCREEN_WIDTH;
	m_trees.h = 2800;

	miner_down.PushBack({ 17, 13, 15, 23 });
	miner_down.PushBack({ 215, 13, 15, 23 });
	miner_down.PushBack({ 238, 13, 15, 23 });
	miner_down.PushBack({ 259, 13, 15, 23 });
	miner_down.speed = 0.05f;
	miner_down.loop = true;

	miner_up.PushBack({ 17, 125, 15, 23 });
	miner_up.PushBack({ 39, 125, 15, 23 });
	miner_up.PushBack({ 63, 125, 15, 23 });
	miner_up.PushBack({ 86, 125, 15, 23 });
	miner_up.speed = 0.02f;
	miner_up.loop = true;

	miner_rigth.PushBack({ 68, 50, 11, 22 });
	miner_rigth.PushBack({ 93, 50, 11, 23 });
	miner_rigth.PushBack({ 117, 50, 12, 22 });
	miner_rigth.PushBack({ 19, 88, 11, 23 });
	miner_rigth.speed = 0.05f;
	miner_rigth.loop = true;

	miner_drigth.PushBack({ 176, 12, 15, 23 });
	miner_drigth.PushBack({ 176, 43, 15, 23 });
	miner_drigth.PushBack({ 176, 76, 15, 23 });
	miner_drigth.PushBack({ 176, 112, 15, 23 });
	miner_drigth.PushBack({ 176, 146, 15, 23 });
	miner_drigth.speed = 0.05f;
	miner_drigth.loop = true;

	miner_dleft.PushBack({ 154, 12, 15, 23 });
	miner_dleft.PushBack({ 154, 43, 15, 23 });
	miner_dleft.PushBack({ 154, 76, 15, 23 });
	miner_dleft.PushBack({ 154, 112, 15, 23 });
	miner_dleft.PushBack({ 154, 146, 15, 23 });
	miner_dleft.speed = 0.05f;
	miner_dleft.loop = true;

}

ModuleSceneForest::~ModuleSceneForest()
{}

// Load assets
bool ModuleSceneForest::Start()
{
	spawned = 0;
	//setting bckground
	background_x = 0;
	background_y = -2800.0f;

	//EXAMPLE
	/*soldier_left_wall_y = -145;
	soldier_left_wall_x = 50;
	soldier_left_wall.Reset();*/

	miner_up_y = 0;

	LOG("Loading SceneForest assets");
	bool ret = true;

	if(App->characterSelection->characterSelected_P1 != CHARACTER_SELECTED::NONE_SELECTED && App->characterSelection->characterSelected_P2 != CHARACTER_SELECTED::NONE_SELECTED)
		App->ui->p2 = true;

	
	// ENABLING SELECTED CHARACTER

	if (App->characterSelection->characterSelected_P1 == CHARACTER_SELECTED::VALNUS_SELECTED)
	{
		App->player->Enable();
		App->ui->Enable();
	}
	else if (App->characterSelection->characterSelected_P1 == CHARACTER_SELECTED::TETSU_SELECTED)
	{
		App->player2->Enable();
		App->ui->Enable();
	}

	if (App->characterSelection->characterSelected_P2 == CHARACTER_SELECTED::VALNUS_SELECTED)
	{
		App->player->Enable();
		App->ui->Enable();
	}
	else if (App->characterSelection->characterSelected_P2 == CHARACTER_SELECTED::TETSU_SELECTED)
	{
		App->player2->Enable();
		App->ui->Enable();
	}

	if (App->player2->playerLives > 0 && App->ui->p2 == true)
		App->player2->Enable();

	App->collision->Enable();
	App->enemies->Enable();
	App->particles->Enable();

	graphics = App->textures->Load("Assets/maps/forest/map_forest_background_.png");
	motionless_trees = App->textures->Load("Assets/maps/forest/Motionless_Trees.png");
	graphic_miner = App->textures->Load("Assets/maps/forest/Forest_stuff.png");

	if (graphics == nullptr ||motionless_trees == nullptr) {
		LOG("Cannot load the texture in SceneForest");
		ret = false;
	}

	//EXAMPLE:
	/*graphicsSoldier = App->textures->Load("Assets/maps/castle/castle_map_stuff.png");
	if (graphicsSoldier == nullptr) {
		LOG("Cannot load the animations spritesheet in SceneCastle");
		ret = false;
	}*/

	if (!App->audio->PlayMusic("Assets/audio/gunbird_jungle_level_music.ogg"))
		ret = false;

	LOG("Loading audio fx when player 2 joins the game");
	player2joined = App->audio->LoadFx("Assets/audio/effects/Valnus_Start.wav");

	return ret;
}

// Update: draw background
update_status ModuleSceneForest::Update()
{
	if (App->characterSelection->player2_joined)
		App->characterSelection->player2_joined = false;

	update_status status = UPDATE_CONTINUE;

	if (background_y < -SCREEN_HEIGHT) {
		background_y += background_speed;
		//EXAMPLE:
		//soldier_left_y += background_speed;
	}

	// Draw everything --------------------------------------
	if (!App->render->Blit(graphics, (int)background_x, (int)background_y + SCREEN_HEIGHT, &background, 0.75f)) {
		LOG("Cannot blit the texture in SceneJungle %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	if (background_y >= -2350.0 && graphic_miner != nullptr) {
		if (!App->render->Blit(graphic_miner, (int)190, (int)160 + miner_up_y, &(miner_up.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
		if (!App->render->Blit(graphic_miner, (int)150, (int)160 + miner_up_y, &(miner_up.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
		if (!App->render->Blit(graphic_miner, (int)170, (int)140 + miner_up_y, &(miner_up.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
		if (!App->render->Blit(graphic_miner, (int)120, (int)140 + miner_up_y, &(miner_up.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
		if (!App->render->Blit(graphic_miner, (int)140, (int)120 + miner_up_y, &(miner_up.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
		if (background_y >= -2130.0) {
			miner_up_y -= -0.4f;
		}
	}


	if (!App->render->Blit(motionless_trees, (int)background_x, (int)background_y + SCREEN_HEIGHT, &m_trees, 0.75f)) {
		LOG("Cannot blit the texture in SceneJungle %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	//BACKGROUND ANIMATIONS
	{
		//soldier animations EXAMPLE
		/*if (background_y <= -1800.0f && soldier_left_x >= -12 && graphicsSoldier != nullptr) {
			if (!App->render->Blit(graphicsSoldier, (int)soldier_left_x, (int)soldier_left_y + SCREEN_HEIGHT, &(soldier_left.GetCurrentFrame()), 0.75f)) {
				LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
			if (!App->render->Blit(graphicsSoldier, (int)soldier_left_x - 6, (int)soldier_left_y + SCREEN_HEIGHT + 20, &(soldier_left.GetCurrentFrame()), 0.75f)) {
				LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
			soldier_left_x -= 0.4f;
		}*/

		


		
	}

	if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN && App->sceneForest->IsEnabled())
	{
		//DO UNLOAD OF ALL THE TEXTURES ABOUT ANIM IN BACKGROUND LIKE SOLDIERS ETC
		//EXAMPLE:
		/*if (!App->textures->Unload(graphicsSoldier)) {
			LOG("Error unloading graphics in SceneCastle");
			status = UPDATE_ERROR;
		}
		graphicsSoldier = nullptr;
		*/
		App->enemies->Disable();
		App->particles->Disable();
		background_y = -SCREEN_HEIGHT;
	}


	//TODO change the position of the player to private to be more pro
	if ((App->player2->position.y < 0 || App->player->position.y < 0) && App->fade->FadeIsOver() /*delete this in big releases*/ ||(App->input->keyboard[SDL_SCANCODE_RETURN] == KEY_STATE::KEY_DOWN))
		App->fade->FadeToBlack(this, this, 1.0f);

	if (App->player->playerLost) {
		LOG("Player LOST");
		App->fade->FadeToBlack(this, App->scoreRanking);
	}

	if (App->player2->playerLost) {
		LOG("Player2 LOST");
		App->ui->p2 = false;
		App->player2->Disable();
	}

	//ENEMY SPAWN PHASE 

	{
		//bee
		if ((int)background_y == -2780 && spawned == 0) {
		
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, -10, -10, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH);
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, SCREEN_WIDTH, -20, ENEMY_MOVEMENT::BEE_CORNER_RIGHT_PATH);

			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 50, -30, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH2);
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, SCREEN_WIDTH /2 + 30, -29, ENEMY_MOVEMENT::BEE_CORNER_RIGHT_PATH2);
		}

		//big red turret + bee
		if ((int)background_y == -2760 && spawned == 0)
		{
			spawned = 1;
			App->enemies->AddEnemy(ENEMY_TYPES::BIG_RED_TURRET, 25, -70, ENEMY_MOVEMENT::STAY);
			App->enemies->AddEnemy(ENEMY_TYPES::BIG_RED_TURRET, 153, -85, ENEMY_MOVEMENT::STAY);
			
		}

		//metalic balloon
		if ((int)background_y == -2720 && spawned == 1) 
		{
			spawned = 2;
			App->enemies->AddEnemy(ENEMY_TYPES::METALLICBALLOON, 112, -70, ENEMY_MOVEMENT::BALLOON_PATH_FOREST);

			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 20, -30, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH2);
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 40, -40, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH);
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 80, -60, ENEMY_MOVEMENT::BEE_CORNER_RIGHT_PATH2);

			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 180, -80, ENEMY_MOVEMENT::BEE_CORNER_RIGHT_PATH2);

		}

		if ((int)background_y == -2600 && spawned == 2)
		{
			spawned = 3;
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 30, -20, ENEMY_MOVEMENT::BEE_CORNER_STRAIGHT);
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 130, -70 , ENEMY_MOVEMENT::BEE_CORNER_STRAIGHT);
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 160, -40, ENEMY_MOVEMENT::BEE_CORNER_STRAIGHT);

		}


		//flying machine + bee
		if ((int)background_y == -2500 && spawned == 3) {
			spawned = 4;
			App->enemies->AddEnemy(ENEMY_TYPES::FLYING_MACHINE, -80, 20, ENEMY_MOVEMENT::FLYING_MACHINE_PATH_1);

			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 50, -40, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH2);
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 130, -70, ENEMY_MOVEMENT::BEE_CORNER_STRAIGHT);
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 20, -40, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH);
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 80, -100, ENEMY_MOVEMENT::BEE_CORNER_RIGHT_PATH2);

		}

		//red turret
		if ((int)background_y == -2400 && spawned == 4)
		{
			spawned = 5;
			App->enemies->AddEnemy(ENEMY_TYPES::RED_TURRET, 190, -50, ENEMY_MOVEMENT::STAY);

			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 160, -40, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH2);
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, -40, -40, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH);
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 80, -100, ENEMY_MOVEMENT::BEE_CORNER_RIGHT_PATH2);
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, -10, -100, ENEMY_MOVEMENT::BEE_CORNER_RIGHT_PATH);

		}
		
		if ((int)background_y == -2200 && spawned == 5)
		{
			spawned = 6;
			App->enemies->AddEnemy(ENEMY_TYPES::RED_TURRET, -80, 55, ENEMY_MOVEMENT::RED_TURRET_LEFT_RIGTH);
			App->enemies->AddEnemy(ENEMY_TYPES::RED_TURRET, -80, -20, ENEMY_MOVEMENT::RED_TURRET_LEFT_RIGTH);

			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 20, -40, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH2);
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 160, -40, ENEMY_MOVEMENT::BEE_CORNER_STRAIGHT);
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 50, -100, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH);
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, -10, -100, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH2);


		}

		if ((int)background_y == -2150 && spawned == 6)
		{
			spawned = 7;
			App->enemies->AddEnemy(ENEMY_TYPES::RED_TURRET, -20, -20, ENEMY_MOVEMENT::RED_TURRET_LEFT_RIGTH);
			App->enemies->AddEnemy(ENEMY_TYPES::RED_TURRET, -20, -100, ENEMY_MOVEMENT::RED_TURRET_LEFT_RIGTH);

		}

		//red turret + red mecha
		if ((int)background_y == -2000 && spawned == 7)
		{
			spawned = 8;
			App->enemies->AddEnemy(ENEMY_TYPES::RED_TURRET, 234, -50, ENEMY_MOVEMENT::RED_TURRET_RIGHT_LEFT);
			App->enemies->AddEnemy(ENEMY_TYPES::TRUMP_RED_MECHA, 50, -50, ENEMY_MOVEMENT::TRUMP_RED_MECHA_PATH);

		}
		

		if ((int)background_y == -1600 && spawned == 8)
		{
			spawned = 9;
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, -10, -20, ENEMY_MOVEMENT::BEE_CORNER_STRAIGHT);
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 160, -50, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH2);
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 20, -80, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH);
			App->enemies->AddEnemy(ENEMY_TYPES::BEE, 80, -50, ENEMY_MOVEMENT::BEE_CORNER_RIGHT_PATH);
			
		}

	}
	

	if (App->input->keyboard[SDL_SCANCODE_KP_1] && !App->player2->IsEnabled()) 
	{
		App->ui->p2 = true;
		App->player2->playerLives = 3;
		App->player2->Enable();
		App->characterSelection->player2_joined = true;

		if(App->characterSelection->characterSelected_P1 = CHARACTER_SELECTED::VALNUS_SELECTED)
			App->characterSelection->characterSelected_P2 = CHARACTER_SELECTED::TETSU_SELECTED;

		App->audio->PlayFx(player2joined);
	}


	if (App->input->keyboard[SDL_SCANCODE_KP_1] && !App->player->IsEnabled())
	{
		App->ui->p2 = true;
		App->player->playerLives = 3;
		App->player->Enable();
		App->characterSelection->player2_joined = true;

		if (App->characterSelection->characterSelected_P2 = CHARACTER_SELECTED::VALNUS_SELECTED)
			App->characterSelection->characterSelected_P1 = CHARACTER_SELECTED::TETSU_SELECTED;

		App->audio->PlayFx(player2joined);
	}
	

	/*if (App->input->keyboard[SDL_SCANCODE_F9] == KEY_STATE::KEY_DOWN)
	{
	App->enemies->AddEnemy(ENEMY_TYPES::METALLICBALLOON, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, ENEMY_MOVEMENT::STAY);
	}*/

	return status;
}


bool ModuleSceneForest::CleanUp()
{
	LOG("Unloading SceneForest");

	bool ret = true;

	if (!App->textures->Unload(graphics)) {
		LOG("Error unloading graphics in SceneForest");
		ret = false;
	}
	
	App->collision->Disable();
	App->particles->Disable();
	App->enemies->Disable();
	App->ui->Disable();
	App->player->Disable();
	App->player2->Disable();

	return ret;
}