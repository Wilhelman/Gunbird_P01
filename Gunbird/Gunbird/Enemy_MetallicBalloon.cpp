#include "Application.h"
#include "Enemy_MetallicBalloon.h"
#include "ModuleCollision.h"

Enemy_MetallicBalloon::Enemy_MetallicBalloon(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 0, 37, 18, 32 }); // TODO_: get right coordinates
	fly.speed = 0.5f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	path.PushBack({ 0.0f, 1.0f }, 100, &fly);
	path.PushBack({ 0.0f, 0.0f }, 50, &fly);

	path.loop = true;

	original_pos.x = x;
	original_pos.y = y;

}

void Enemy_MetallicBalloon::Move()
{
	position = original_pos + path.GetCurrentPosition(&animation);
}
