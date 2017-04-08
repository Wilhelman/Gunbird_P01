#include "Application.h"
#include "Enemy_Torpedo.h"
#include "ModuleCollision.h"

Enemy_Torpedo::Enemy_Torpedo(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 0, 37, 18, 32 });
	fly.PushBack({ 23, 38, 16, 32 });
	fly.PushBack({ 42, 38, 22, 32 });
	fly.PushBack({ 65, 38, 26, 32 });
	fly.PushBack({ 0, 74, 28, 32 });
	fly.PushBack({ 30, 74, 26, 32 });
	fly.PushBack({ 60, 74, 23, 32 });
	fly.PushBack({ 84, 74, 16, 32 });
	fly.speed = 0.2f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_Torpedo::Move()
{

	position.y += 2;

}
