#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "Enemy.h"
#include "Enemy_Torpedo.h"
#include "Enemy_MetallicBalloon.h"
#include "Enemy_TerrestialTurret.h"

#define SPAWN_MARGIN 250

ModuleEnemies::ModuleEnemies()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;

	//torpedo movements
	diagonalPathL_R.PushBack({ 2.3f, 2.5f }, 100);
	diagonalPathL_R.loop = true;

	horizontalPathR_L.PushBack({ -3.0f, 0.0f }, 72);
	horizontalPathR_L.PushBack({ 0.0f, 0.0f }, 100);
	horizontalPathR_L.PushBack({ 0.0f, 3.0f }, 300);
	horizontalPathR_L.loop = false;
}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	/*sprites = App->textures->Load("Assets/maps/castle/enemies_castle.png");*/
	sprites = App->textures->Load("Assets/maps/castle/Enemies_Castle_definitive.png");

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
			if (enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				LOG("DeSpawning enemy at %d", enemies[i]->position.x * SCREEN_SIZE);
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
			default:
				break;
			}
			break;
		case ENEMY_TYPES::METALLICBALLOON:
			enemies[i] = new Enemy_MetallicBalloon(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::METALLICBALLOON;
			break;
		case ENEMY_TYPES::TERRESTIALTURRET:
			enemies[i] = new Enemy_TerrestialTurret(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::TERRESTIALTURRET;
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
 					App->particles->AddParticle(App->particles->balloonDeathExplosion, (c1->rect.x - ((101 - (c1->rect.w)) / 2)), (c1->rect.y - ((107 - (c1->rect.h)) / 2)));
					enemies[i] = nullptr;												// c1->rect.x - 31.5, c1->rect.y -27   
					delete enemies[i];	
					LOG("Result is: %f", c1->rect.x - ((42 - (c1->rect.w)) / 2));
					break;  
				}
			}
			/*if (enemies[i]->type == ENEMY_TYPES::TERRESTIALTURRET) {
				if (enemies[i]->getLives() == 0) {
					App->particles->AddParticle(App->particles->terrestialTurretExplosion, (c1->rect.x - ((101 - (c1->rect.w)) / 2)), (c1->rect.y - ((107 - (c1->rect.h)) / 2)));
					enemies[i] = nullptr;												// c1->rect.x - 31.5, c1->rect.y -27   
					delete enemies[i];
					LOG("Result is: %f", c1->rect.x - ((42 - (c1->rect.w)) / 2));
					break;
				}
			}*/

			else {
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			}
		}
	}
}