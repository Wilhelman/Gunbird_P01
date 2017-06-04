#include "Application.h"
#include "Enemy_Bee.h"
#include "ModuleCollision.h"
#include "Path.h"

Enemy_Bee::Enemy_Bee(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 1036, 683, 30, 29 });
	fly.PushBack({ 1065, 683, 30, 29 });
	fly.PushBack({ 1095, 683, 30, 29 });
	fly.speed = 0.2f;

	//bee_white.PushBack({ 839,129,28,33 });
	//bee_white.loop = false;

	animation = &fly;

	original_pos.x = x;
	original_pos.y = y;

	collider = App->collision->AddCollider({ 0, 0, 30, 29 }, COLLIDER_TYPE::COLLIDER_ENEMY_FLYING, (Module*)App->enemies);
}

void Enemy_Bee::Move()
{
	position = original_pos + movement.GetCurrentPosition(&animation);
}

void Enemy_Bee::OnCollision(Collider* collider)
{
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT || collider->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {
		App->particles->AddParticle(App->particles->playerShotCollison, (collider->rect.x - (((collider->rect.w)) / 2)), (collider->rect.y - (((collider->rect.h)))));
		//animation = &bee_white;
	}
}