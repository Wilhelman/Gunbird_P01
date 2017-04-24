#include "Application.h"
#include "Enemy_Torpedo.h"
#include "ModuleCollision.h"
#include "Path.h"

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

	torpedo_white.PushBack({ 839,129,28,33 });
	torpedo_white.loop = false;

	animation = &fly;

	original_pos.x = x;
	original_pos.y = y;

	collider = App->collision->AddCollider({ 0, 0, 28, 32 }, COLLIDER_TYPE::COLLIDER_ENEMY_FLYING, (Module*)App->enemies);
}

void Enemy_Torpedo::Move()
{
	position = original_pos + movement.GetCurrentPosition(&animation);
}

void Enemy_Torpedo::OnCollision(Collider* collider)
{
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
		App->particles->AddParticle(App->particles->playerShotCollison, (collider->rect.x + (((collider->rect.w)) / 2)), (collider->rect.y - (((collider->rect.h)))));
		animation = &torpedo_white;
	}
}