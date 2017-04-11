#include "Application.h"
#include "Enemy_Torpedo.h"
#include "ModuleCollision.h"
#include "ModuleSceneCastle.h"

Enemy_Torpedo::Enemy_Torpedo(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 717, 92, 28, 32 });
	fly.PushBack({ 746, 92, 28, 32 });
	fly.PushBack({ 777, 92, 28, 32 });
	fly.PushBack({ 806, 92, 28, 32 });
	fly.PushBack({ 717, 128, 28, 32 });
	fly.PushBack({ 746, 128, 28, 32 });
	fly.PushBack({ 777, 128, 28, 32 });
	fly.PushBack({ 806, 128, 28, 32 });
	fly.speed = 0.2f;

	animation = &fly;

	original_pos.x = x;
	original_pos.y = y;

	diagonalPathL_R.PushBack({ 2.3f, 2.5f }, 100, &fly);
	diagonalPathL_R.loop = true;

	horizontalPathR_L.PushBack({ -3.0f, 0.0f }, 72, &fly);
	horizontalPathR_L.PushBack({ 0.0f, 0.0f }, 100, &fly);
	horizontalPathR_L.PushBack({ 0.0f, 3.0f }, 300, &fly);
	horizontalPathR_L.loop = false;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
}

void Enemy_Torpedo::Move()
{
	int castleBackground = App->sceneCastle->background_y;

	if((castleBackground > -2050) && (castleBackground < -1750))
		position = original_pos + diagonalPathL_R.GetCurrentPosition(&animation);
	else if((castleBackground > -1650) && (castleBackground < -1250))
		position = original_pos + horizontalPathR_L.GetCurrentPosition(&animation);
}
