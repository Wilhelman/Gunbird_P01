#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "ModuleUI.h"
#include "Enemy.h"
#include "Enemy_Torpedo.h"
#include "Enemy_Bee.h"
#include "Enemy_Red_Turret.h"
#include "Enemy_Big_Red_Turret.h"
#include "Enemy_Trump_Red_Mecha.h"
#include "Enemy_MetallicBalloon.h"
#include "Enemy_TerrestialTurret.h"
#include "Enemy_Flying_Machine.h"
#include "SceneCastle_houseFlag.h"
#include "SceneCastle_houseFlag2.h"
#include "SceneCastle_Vase.h"
#include "ModuleAudio.h"

#include "Coin.h"
#include "Power_Up.h"

#define SPAWN_MARGIN 500

ModuleEnemies::ModuleEnemies()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;

	//STAY
	stayPath.PushBack({ 0.0f, 0.5f }, 100);
	stayPath.loop = true;

	//torpedo movements
	diagonalPathL_R.PushBack({ 2.3f, 2.5f }, 100);
	diagonalPathL_R.loop = true;

	horizontalPathR_L.PushBack({ -3.0f, 0.0f }, 72);
	horizontalPathR_L.PushBack({ 0.0f, 0.0f }, 100);
	horizontalPathR_L.PushBack({ 0.0f, 3.0f }, 300);
	horizontalPathR_L.loop = false;

	strightOnPath.PushBack({ 0.0f, 2.5f }, 400);
	strightOnPath.loop = false;

	diagonalPath_R_Final.PushBack({ 0.0f,2.5f }, 50);
	diagonalPath_R_Final.PushBack({ -1.5f,3.0f }, 200);
	diagonalPath_R_Final.loop = false;

	diagonalPath_L_Final.PushBack({ 0.0f,2.5f }, 100);
	diagonalPath_L_Final.PushBack({ 1.5f,3.0f }, 200);
	diagonalPath_L_Final.loop = false;

	diagonalPath_R_Final2.PushBack({ 0.0f,2.5f }, 100);
	diagonalPath_R_Final2.PushBack({ -1.5f,3.0f }, 200);
	diagonalPath_R_Final2.loop = false;

	diagonalPath_L_Final2.PushBack({ 0.0f,2.0f }, 50);
	diagonalPath_L_Final2.PushBack({ 1.0f,2.5f }, 200);
	diagonalPath_L_Final2.loop = false;

	//balloon path castle
	balloonPathCastle.PushBack({ 0.0f, 0.9f }, 175); // 64
	balloonPathCastle.PushBack({ 0.0f, 0.4f }, 20); // 155
	balloonPathCastle.PushBack({ 0.0f, -0.35f }, 45); // 70
	balloonPathCastle.PushBack({ 0.0f, 0.8f }, 120); // 294
	balloonPathCastle.PushBack({ 0.0f, -0.35f }, 120);
	balloonPathCastle.PushBack({ 0.0f, 1.0f }, 1000);
	balloonPathCastle.loop = false;

	//Balloon path forest
	balloonPathForest.PushBack({ 0.0f, 1.5f }, 55);
	balloonPathForest.PushBack({ 0.0f, 1.2f }, 10);
	balloonPathForest.PushBack({ 0.0f, 1.0 }, 10);
	balloonPathForest.PushBack({ 0.0f, 0.0f }, 100);
	balloonPathForest.PushBack({ 1.0f, 1.5f }, 55);
	balloonPathForest.PushBack({ 0.8f, 1.3f }, 10);
	balloonPathForest.PushBack({ 0.0f, 0.0f }, 55);
	balloonPathForest.PushBack({ -1.0f, 1.5f }, 35);
	balloonPathForest.PushBack({ -0.8f, 1.3f }, 20);
	balloonPathForest.PushBack({ 0.0f, 0.0f }, 150);
	balloonPathForest.PushBack({ 0.0f, 0.25f }, 10);
	balloonPathForest.PushBack({ 0.0f, 1.5f }, 150);

	balloonPathForest.loop = false;

	//TerrestialTurret paths
	turret1_path.PushBack({ 0.6f,0.5f }, 70);
	turret1_path.PushBack({ 0.0f, 0.3f }, 45);
	turret1_path.PushBack({ 0.0f,0.5f }, 3000);
	turret1_path.loop = false;

	turret1_L_path.PushBack({ -0.6f,0.5f }, 60);
	turret1_L_path.PushBack({ 0.0f, 0.3f }, 35);
	turret1_L_path.PushBack({ 0.0f,0.5f }, 3000);
	turret1_L_path.loop = false;


	turret2_path.PushBack({ 0.6f, 0.5f }, 120);
	turret2_path.PushBack({ 0.0f,0.5f }, 3000);
	turret2_path.loop = false;

	turret3_path.PushBack({ 0.6f, 0.5f }, 60);
	turret3_path.PushBack({ 0.0f, 0.5f }, 3000);
	turret3_path.loop = false;

	//Bee paths
	bee_corner_left_path.PushBack({ 1.5f,2.5f }, 20);
	bee_corner_left_path.PushBack({ 0.0f, 0.0f }, 80);
	bee_corner_left_path.PushBack({ 1.0f,2.5f }, 3000);
	bee_corner_left_path.loop = false;

	bee_corner_right_path.PushBack({ -1.9f,2.5f }, 20);
	bee_corner_right_path.PushBack({ 0.0f, 0.0f }, 90);
	bee_corner_right_path.PushBack({ -0.3f,2.5f }, 3000);
	bee_corner_right_path.loop = false;

	bee_corner_left_path2.PushBack({ 1.5f,2.5f }, 20);
	bee_corner_left_path2.PushBack({ 0.0f, 0.0f }, 100);
	bee_corner_left_path2.PushBack({ -0.5f,2.5f }, 3000);
	bee_corner_left_path2.loop = false;

	bee_corner_right_path2.PushBack({ -0.3f,2.5f }, 30);
	bee_corner_right_path2.PushBack({ 0.0f, 0.0f }, 60);
	bee_corner_right_path2.PushBack({ -0.8f,2.5f }, 3000);
	bee_corner_right_path2.loop = false;

	bee_corner_straight.PushBack({ 0.0f , 0.5f }, 60);
	bee_corner_straight.PushBack({ 0.0f , 2.5f }, 30);
	bee_corner_straight.PushBack({ 0.0f , 2.5f }, 3000);
	bee_corner_right_path2.loop = false;

	//Trump red Mecha path
	trump_red_mecha_path.PushBack({ 0.0f,0.5f }, 300);
	trump_red_mecha_path.PushBack({ 0.0f, 0.0f }, 20);
	trump_red_mecha_path.PushBack({ 0.0f,0.5f }, 40);
	trump_red_mecha_path.PushBack({ 0.0f, 0.0f }, 20);
	trump_red_mecha_path.PushBack({ 0.0f,0.5f }, 30);
	trump_red_mecha_path.PushBack({ 0.0f, 0.0f }, 20);
	trump_red_mecha_path.PushBack({ 0.0f,0.5f }, 40);
	trump_red_mecha_path.PushBack({ 0.0f, 0.0f }, 20);
	trump_red_mecha_path.PushBack({ 0.0f,0.5f }, 40);
	trump_red_mecha_path.PushBack({ 0.0f, 0.0f }, 20);
	trump_red_mecha_path.PushBack({ 0.0f,0.5f }, 30);
	trump_red_mecha_path.PushBack({ 0.0f, 0.0f }, 20);
	trump_red_mecha_path.PushBack({ 0.0f,0.5f }, 40);
	trump_red_mecha_path.PushBack({ 0.0f, 0.0f }, 20);
	trump_red_mecha_path.PushBack({ 0.0f,0.5f }, 20);
	trump_red_mecha_path.PushBack({ 0.0f, 0.0f }, 20);
	trump_red_mecha_path.PushBack({ 0.0f, 0.5f }, 40);
	trump_red_mecha_path.PushBack({ -2.0f, 0.0f }, 200);
	trump_red_mecha_path.loop = false;


	//Flying Machine Path (forest)
	flying_machine_path1.PushBack({ 1.3f, 0.05f }, 100);
	flying_machine_path1.PushBack({ 0.8f, 0.05f }, 10);
	flying_machine_path1.PushBack({ 0.4f, 0.0f }, 10);
	flying_machine_path1.PushBack({ 0.0f, 0.0f }, 70);
	flying_machine_path1.PushBack({ 2.0f, 0.05f }, 110);
	flying_machine_path1.PushBack({ 0.0f, 1.0f }, 70);
	flying_machine_path1.PushBack({ -1.5f, 0.05f }, 120);
	flying_machine_path1.PushBack({ 0.0f, 0.0f }, 70);
	flying_machine_path1.PushBack({ -1.5f, 0.05f }, 120);
	flying_machine_path1.loop = false;

	//red turret
	red_turret_left_rigth.PushBack({ 0.5f, 0.5f }, 180);
	red_turret_left_rigth.PushBack({ 0.0f, 0.5f }, 3500);
	red_turret_left_rigth.loop = false;
	
	red_turret_rigth_left.PushBack({ -0.5f, 0.5f }, 180);
	red_turret_rigth_left.PushBack({ 0.0f, 0.5f }, 3500);
	red_turret_rigth_left.loop = false;

}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	/*sprites = App->textures->Load("Assets/maps/castle/enemies_castle.png");*/
	sprites = App->textures->Load("Assets/enemies/enemies_definitive.png");

	LOG("Loading audio fx for medium enemy explosion");
	medium_explosion = App->audio->LoadFx("Assets/audio/effects/medium_explosion.wav");
	
	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
			if (queue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				SpawnEnemy(queue[i]);
				queue[i].type = ENEMY_TYPES::NO_TYPE;
				LOG("Spawning enemy at %d", queue[i].x * SCREEN_SIZE);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleEnemies::Update()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Move();

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Shoot();

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Draw(sprites);

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			if (enemies[i]->position.x > SCREEN_WIDTH + SPAWN_MARGIN || enemies[i]->position.x < 0 - SPAWN_MARGIN)
			{
				LOG("DeSpawning enemy at %d", enemies[i]->position.x);
				//enemies[i]->GetCollider()->to_delete = true;
				delete enemies[i];
				enemies[i] = nullptr;
			}
			else if (enemies[i]->position.y > SCREEN_HEIGHT + SPAWN_MARGIN || enemies[i]->position.y < 0 - SPAWN_MARGIN) {
				LOG("DeSpawning enemy at %d", enemies[i]->position.y);
				//enemies[i]->GetCollider()->to_delete = true;
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	App->textures->Unload(sprites);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			//enemies[i]->GetCollider()->to_delete = true;
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPES type, int x, int y, ENEMY_MOVEMENT typeMovement)
{
	bool ret = false;

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type == ENEMY_TYPES::NO_TYPE)
		{
			queue[i].type = type;
			queue[i].x = x;
			queue[i].y = y;
			queue[i].typeMovement = typeMovement;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies::SpawnEnemy(const EnemyInfo& info)
{
	// find room for the new enemy
	uint i = 0;
	for (; enemies[i] != nullptr && i < MAX_ENEMIES; ++i);

	if (i != MAX_ENEMIES)
	{
		switch (info.type)
		{
		case ENEMY_TYPES::TORPEDO:
			enemies[i] = new Enemy_Torpedo(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::TORPEDO;
			switch (info.typeMovement)
			{
			case ENEMY_MOVEMENT::TORPEDO_DIAGONALL_R:
				enemies[i]->movement = diagonalPathL_R;
				break;
			case ENEMY_MOVEMENT::TORPEDO_HORIZONTALR_L:
				enemies[i]->movement = horizontalPathR_L;
				break;
			case ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON:
				enemies[i]->movement = strightOnPath;
				break;
			case ENEMY_MOVEMENT::TORPEDO_DIAGONAL_R_FINAL:
				enemies[i]->movement = diagonalPath_R_Final;
				break;
			case ENEMY_MOVEMENT::TORPEDO_DIAGONAL_L_FINAL:
				enemies[i]->movement = diagonalPath_L_Final;
				break;
			case ENEMY_MOVEMENT::TORPEDO_DIAGONAL_R_FINAL2:
				enemies[i]->movement = diagonalPath_R_Final2;
				break;
			case ENEMY_MOVEMENT::TORPEDO_DIAGONAL_L_FINAL2:
				enemies[i]->movement = diagonalPath_L_Final2;
				break;
			default:
				break;
			}
			break;
		case ENEMY_TYPES::METALLICBALLOON:
			enemies[i] = new Enemy_MetallicBalloon(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::METALLICBALLOON;
			switch (info.typeMovement)
			{
			case ENEMY_MOVEMENT::BALLOON_PATH_CASTLE:
				enemies[i]->movement = balloonPathCastle;
				break;
			case ENEMY_MOVEMENT::BALLOON_PATH_FOREST:
				enemies[i]->movement = balloonPathForest;
				break;
			default:
				break;
			}
			break;
		case ENEMY_TYPES::TERRESTIALTURRET:
			enemies[i] = new Enemy_TerrestialTurret(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::TERRESTIALTURRET;
			switch (info.typeMovement)
			{
			case ENEMY_MOVEMENT::TURRET_1_PATH:
				enemies[i]->movement = turret1_path;
				break;
			case ENEMY_MOVEMENT::TURRET1_L_PATH:
				enemies[i]->movement = turret1_L_path;
				break;
			case ENEMY_MOVEMENT::TURRET_2_PATH:
				enemies[i]->movement = turret2_path;
				break;
			case ENEMY_MOVEMENT::TURRET_3_PATH:
				enemies[i]->movement = turret3_path;
				break;
			case ENEMY_MOVEMENT::STAY:
				enemies[i]->movement = stayPath;
				break;

			default:
				break;
			}
			break;
		case ENEMY_TYPES::BEE:
			enemies[i] = new Enemy_Bee(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::BEE;
			switch (info.typeMovement)
			{
			case ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH:
				enemies[i]->movement = bee_corner_left_path;
				break;
			case ENEMY_MOVEMENT::BEE_CORNER_RIGHT_PATH:
				enemies[i]->movement = bee_corner_right_path;
				break;
			case ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH2:
				enemies[i]->movement = bee_corner_left_path2;
				break;
			case ENEMY_MOVEMENT::BEE_CORNER_RIGHT_PATH2:
				enemies[i]->movement = bee_corner_right_path2;
				break;  
			case ENEMY_MOVEMENT::BEE_CORNER_STRAIGHT:
				enemies[i]->movement = bee_corner_straight;
				break;
			default:
				break;
			}
			break;
		case ENEMY_TYPES::RED_TURRET:
			enemies[i] = new Enemy_Red_Turret(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::RED_TURRET;
			switch (info.typeMovement)
			{
			case ENEMY_MOVEMENT::STAY:
				enemies[i]->movement = stayPath;
				break;

			case ENEMY_MOVEMENT::RED_TURRET_LEFT_RIGTH:
				enemies[i]->movement = red_turret_left_rigth;
				break;
			
			case ENEMY_MOVEMENT::RED_TURRET_RIGHT_LEFT:
				enemies[i]->movement = red_turret_rigth_left;
				break;

			default:
				break;
			}
			break;
		case ENEMY_TYPES::BIG_RED_TURRET:
			enemies[i] = new Enemy_Big_Red_Turret(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::BIG_RED_TURRET;
			switch (info.typeMovement)
			{
			case ENEMY_MOVEMENT::STAY:
				enemies[i]->movement = stayPath;
				break;

			default:
				break;
			}
			break;
		case ENEMY_TYPES::TRUMP_RED_MECHA:
			enemies[i] = new Enemy_Trump_Red_Mecha(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::TRUMP_RED_MECHA;
			switch (info.typeMovement)
			{
			case ENEMY_MOVEMENT::TRUMP_RED_MECHA_PATH:
				enemies[i]->movement = trump_red_mecha_path;
				break;
			default:
				break;
			}
			break;
		case ENEMY_TYPES::FLYING_MACHINE:
			enemies[i] = new Enemy_Flying_Machine(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::FLYING_MACHINE;
			switch (info.typeMovement)
			{
			case ENEMY_MOVEMENT::FLYING_MACHINE_PATH_1:
				enemies[i]->movement = flying_machine_path1;
				break;
			case ENEMY_MOVEMENT::FLYING_MACHINE_PATH_2:
				enemies[i]->movement = flying_machine_path2;
				break;
			default:
				break;
			}
			break;
		case ENEMY_TYPES::CASTLE_HOUSEFLAG:
			enemies[i] = new SceneCastle_houseFlag(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::CASTLE_HOUSEFLAG;
			enemies[i]->movement = stayPath;
			break;
		case ENEMY_TYPES::CASTLE_HOUSEFLAG_2:
			enemies[i] = new SceneCastle_houseFlag2(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::CASTLE_HOUSEFLAG_2;
			enemies[i]->movement = stayPath;
			break;
		case ENEMY_TYPES::CASTLE_VASE:
			enemies[i] = new SceneCastle_Vase(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::CASTLE_VASE;
			enemies[i]->movement = stayPath;
			break;
		case ENEMY_TYPES::COIN:
			enemies[i] = new Coin(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::COIN;
			enemies[i]->movement = stayPath;
			break;
		case ENEMY_TYPES::POWER_UP:
			enemies[i] = new Power_Up(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::POWER_UP;
			break;
		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			enemies[i]->OnCollision(c2);
			if (enemies[i]->type == ENEMY_TYPES::METALLICBALLOON) {
				if (enemies[i]->getLives() == 0) {
					if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
						App->ui->score += 500;
						App->audio->PlayFx(medium_explosion);
						App->particles->AddParticle(App->particles->balloonDeathExplosion, (c1->rect.x - ((101 - (c1->rect.w)) / 2)), (c1->rect.y - ((107 - (c1->rect.h)) / 2)));
						this->AddEnemy(ENEMY_TYPES::POWER_UP, c1->rect.x, c1->rect.y, ENEMY_MOVEMENT::NO_MOVEMENT);
						delete enemies[i];
						enemies[i] = nullptr;
						LOG("Result is: %f", c1->rect.x - ((42 - (c1->rect.w)) / 2));
						break;
					}
					if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {
						App->ui->scoreP2 += 500;
						App->audio->PlayFx(medium_explosion);
						App->particles->AddParticle(App->particles->balloonDeathExplosion, (c1->rect.x - ((101 - (c1->rect.w)) / 2)), (c1->rect.y - ((107 - (c1->rect.h)) / 2)));
						this->AddEnemy(ENEMY_TYPES::POWER_UP, c1->rect.x, c1->rect.y, ENEMY_MOVEMENT::NO_MOVEMENT);
						delete enemies[i];
						enemies[i] = nullptr;
						LOG("Result is: %f", c1->rect.x - ((42 - (c1->rect.w)) / 2));
						break;
					}
				}
			}
			else if (enemies[i]->type == ENEMY_TYPES::BIG_RED_TURRET) {
				if (enemies[i]->getLives() == 0) {
					if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
						App->ui->score += 500;
						App->audio->PlayFx(medium_explosion);
						App->particles->AddParticle(App->particles->balloonDeathExplosion, (c1->rect.x - ((101 - (c1->rect.w)) / 2)), (c1->rect.y - ((107 - (c1->rect.h)) / 2)));
						this->AddEnemy(ENEMY_TYPES::POWER_UP, c1->rect.x, c1->rect.y, ENEMY_MOVEMENT::NO_MOVEMENT);
						delete enemies[i];
						enemies[i] = nullptr;
						LOG("Result is: %f", c1->rect.x - ((42 - (c1->rect.w)) / 2));
						break;
					}
					if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {
						App->ui->scoreP2 += 500;
						App->audio->PlayFx(medium_explosion);
						App->particles->AddParticle(App->particles->balloonDeathExplosion, (c1->rect.x - ((101 - (c1->rect.w)) / 2)), (c1->rect.y - ((107 - (c1->rect.h)) / 2)));
						this->AddEnemy(ENEMY_TYPES::POWER_UP, c1->rect.x, c1->rect.y, ENEMY_MOVEMENT::NO_MOVEMENT);
						delete enemies[i];
						enemies[i] = nullptr;
						LOG("Result is: %f", c1->rect.x - ((42 - (c1->rect.w)) / 2));
						break;
					}
				}
			}
			else if (enemies[i]->type == ENEMY_TYPES::TERRESTIALTURRET) {
				if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
					if (enemies[i]->getLives() == 0) {
						App->ui->score += 500;
						App->audio->PlayFx(medium_explosion);
						App->particles->AddParticle(App->particles->terrestialTurretExplosion, (c1->rect.x - ((58 - (c1->rect.w)) / 2)), (c1->rect.y - ((66 - (c1->rect.h)) / 2)));
						//delete enemies[i];
						//enemies[i] = nullptr;
						LOG("Result is: %f", c1->rect.x - ((42 - (c1->rect.w)) / 2));
						break;
					}
				}
				if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {
					if (enemies[i]->getLives() == 0) {
						App->ui->scoreP2 += 500;
						App->audio->PlayFx(medium_explosion);
						App->particles->AddParticle(App->particles->terrestialTurretExplosion, (c1->rect.x - ((58 - (c1->rect.w)) / 2)), (c1->rect.y - ((66 - (c1->rect.h)) / 2)));
						//delete enemies[i];
						//enemies[i] = nullptr;
						LOG("Result is: %f", c1->rect.x - ((42 - (c1->rect.w)) / 2));
						break;
					}
				}
			}
			else if (enemies[i]->type == ENEMY_TYPES::RED_TURRET) {
				if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
					if (enemies[i]->getLives() == 0) {
						App->ui->score += 500;
						App->audio->PlayFx(medium_explosion);
						App->particles->AddParticle(App->particles->terrestialTurretExplosion, (c1->rect.x - ((58 - (c1->rect.w)) / 2)), (c1->rect.y - ((66 - (c1->rect.h)) / 2)));
						delete enemies[i];
						enemies[i] = nullptr;
						LOG("Result is: %f", c1->rect.x - ((42 - (c1->rect.w)) / 2));
						break;
					}
				}
				if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {
					if (enemies[i]->getLives() == 0) {
						App->ui->scoreP2 += 500;
						App->audio->PlayFx(medium_explosion);
						App->particles->AddParticle(App->particles->terrestialTurretExplosion, (c1->rect.x - ((58 - (c1->rect.w)) / 2)), (c1->rect.y - ((66 - (c1->rect.h)) / 2)));
						delete enemies[i];
						enemies[i] = nullptr;
						LOG("Result is: %f", c1->rect.x - ((42 - (c1->rect.w)) / 2));
						break;
					}
				}
			}
			else if(enemies[i]->type == ENEMY_TYPES::TORPEDO){
				if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
					App->ui->score += 200;
					App->audio->PlayFx(medium_explosion);
					App->particles->AddParticle(App->particles->torpedoExplosion, (c1->rect.x - ((49 - (c1->rect.w)) / 2)), (c1->rect.y - ((35 - (c1->rect.h)) / 2)));
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
				if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {
					App->ui->scoreP2 += 200;
					App->audio->PlayFx(medium_explosion);
					App->particles->AddParticle(App->particles->torpedoExplosion, (c1->rect.x - ((49 - (c1->rect.w)) / 2)), (c1->rect.y - ((35 - (c1->rect.h)) / 2)));
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			else if (enemies[i]->type == ENEMY_TYPES::BEE) {
				if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
					App->ui->score += 200;
					App->audio->PlayFx(medium_explosion);
					App->particles->AddParticle(App->particles->torpedoExplosion, (c1->rect.x - ((49 - (c1->rect.w)) / 2)), (c1->rect.y - ((35 - (c1->rect.h)) / 2)));
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
				if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {
					App->ui->scoreP2 += 200;
					App->audio->PlayFx(medium_explosion);
					App->particles->AddParticle(App->particles->torpedoExplosion, (c1->rect.x - ((49 - (c1->rect.w)) / 2)), (c1->rect.y - ((35 - (c1->rect.h)) / 2)));
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			else if (enemies[i]->type == ENEMY_TYPES::TRUMP_RED_MECHA) {
				if (enemies[i]->getLives() == 0) {
					if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
						App->ui->score += 3000;
						App->audio->PlayFx(medium_explosion);
						App->particles->AddParticle(App->particles->balloonDeathExplosion, (c1->rect.x - ((101 - (c1->rect.w)) / 2)), (c1->rect.y - ((107 - (c1->rect.h)) / 2)));
						delete enemies[i];
						enemies[i] = nullptr;
						break;
					}
					if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {
						App->ui->scoreP2 += 3000;
						App->audio->PlayFx(medium_explosion);
						App->particles->AddParticle(App->particles->balloonDeathExplosion, (c1->rect.x - ((101 - (c1->rect.w)) / 2)), (c1->rect.y - ((107 - (c1->rect.h)) / 2)));
						delete enemies[i];
						enemies[i] = nullptr;
						break;
					}
				}
			}
			else if (enemies[i]->type == ENEMY_TYPES::FLYING_MACHINE) {
				if (enemies[i]->getLives() == 0) {
					if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
						App->ui->score += 3000;
						App->audio->PlayFx(medium_explosion);
						App->particles->AddParticle(App->particles->balloonDeathExplosion, (c1->rect.x - ((101 - (c1->rect.w)) / 2)), (c1->rect.y - ((107 - (c1->rect.h)) / 2)));
						delete enemies[i];
						enemies[i] = nullptr;
						break;
					}
					if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {
						App->ui->scoreP2 += 3000;
						App->audio->PlayFx(medium_explosion);
						App->particles->AddParticle(App->particles->balloonDeathExplosion, (c1->rect.x - ((101 - (c1->rect.w)) / 2)), (c1->rect.y - ((107 - (c1->rect.h)) / 2)));
						delete enemies[i];
						enemies[i] = nullptr;
						break;
					}
				}
			}
			else if (enemies[i]->type == ENEMY_TYPES::CASTLE_HOUSEFLAG) {
				if (enemies[i]->getLives() == 0) {
					if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
						App->ui->score += 3000;
						App->audio->PlayFx(medium_explosion);
						App->particles->AddParticle(App->particles->balloonDeathExplosion, (c1->rect.x - ((101 - (c1->rect.w)) / 2)), (c1->rect.y - ((107 - (c1->rect.h)) / 2)));
						delete enemies[i];
						enemies[i] = nullptr;
						break;
					}
					if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {
						App->ui->scoreP2 += 3000;
						App->audio->PlayFx(medium_explosion);
						App->particles->AddParticle(App->particles->balloonDeathExplosion, (c1->rect.x - ((101 - (c1->rect.w)) / 2)), (c1->rect.y - ((107 - (c1->rect.h)) / 2)));
						delete enemies[i];
						enemies[i] = nullptr;
						break;
					}
				}
			}

			else if (enemies[i]->type == ENEMY_TYPES::CASTLE_HOUSEFLAG_2) {
				if (enemies[i]->getLives() == 0) {
					if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
						App->ui->score += 3000;
						App->audio->PlayFx(medium_explosion);
						App->particles->AddParticle(App->particles->balloonDeathExplosion, (c1->rect.x - ((101 - (c1->rect.w)) / 2)), (c1->rect.y - ((107 - (c1->rect.h)) / 2)));
						delete enemies[i];
						enemies[i] = nullptr;
						break;
					}
					if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {
						App->ui->scoreP2 += 3000;
						App->audio->PlayFx(medium_explosion);
						App->particles->AddParticle(App->particles->balloonDeathExplosion, (c1->rect.x - ((101 - (c1->rect.w)) / 2)), (c1->rect.y - ((107 - (c1->rect.h)) / 2)));
						delete enemies[i];
						enemies[i] = nullptr;
						break;
					}
				}
			}

			else if (enemies[i]->type == ENEMY_TYPES::CASTLE_VASE) {
				if (enemies[i]->getLives() == 0) {
					if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
						App->ui->score += 500;
						App->audio->PlayFx(medium_explosion);
						App->particles->AddParticle(App->particles->vaseExplosion, (c1->rect.x - ((58 - (c1->rect.w)) / 2)), (c1->rect.y - ((66 - (c1->rect.h)) / 2)));
						this->AddEnemy(ENEMY_TYPES::COIN, c1->rect.x + 13, c1->rect.y + 28, ENEMY_MOVEMENT::STAY);
						delete enemies[i];
						enemies[i] = nullptr;
						LOG("Result is: %f", c1->rect.x - ((42 - (c1->rect.w)) / 2));
						break;
					}
					if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {
						App->ui->scoreP2 += 500;
						App->audio->PlayFx(medium_explosion);
						App->particles->AddParticle(App->particles->vaseExplosion, (c1->rect.x - ((58 - (c1->rect.w)) / 2)), (c1->rect.y - ((66 - (c1->rect.h)) / 2)));
						this->AddEnemy(ENEMY_TYPES::COIN, c1->rect.x + 13, c1->rect.y + 28, ENEMY_MOVEMENT::STAY);
						delete enemies[i];
						enemies[i] = nullptr;
						LOG("Result is: %f", c1->rect.x - ((42 - (c1->rect.w)) / 2));
						break;
					}
				}
			}
			else if (enemies[i]->type == ENEMY_TYPES::COIN && c2->type == COLLIDER_TYPE::COLLIDER_PLAYER) {
				App->ui->score += 200;
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			}
			else if (enemies[i]->type == ENEMY_TYPES::POWER_UP && c2->type == COLLIDER_TYPE::COLLIDER_PLAYER) {
				App->ui->score += 2000;
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			}
			else if (enemies[i]->type == ENEMY_TYPES::COIN && c2->type == COLLIDER_TYPE::COLLIDER_PLAYER2) {
				App->ui->scoreP2 += 200;
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			}
			else if (enemies[i]->type == ENEMY_TYPES::POWER_UP && c2->type == COLLIDER_TYPE::COLLIDER_PLAYER2) {
				App->ui->scoreP2 += 2000;
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			}
		}
	}
}