#include "Application.h"
#include "Enemy_MetallicBalloon.h"
#include "ModuleCollision.h"

Enemy_MetallicBalloon::Enemy_MetallicBalloon(int x, int y) : Enemy(x, y)
{
	lives = 3;

	fly.PushBack({ 36, 522, 42, 53 }); // TODO_: get right coordinates
	fly.PushBack({ 89, 522, 42, 53 });
	fly.PushBack({ 141, 522, 42, 53 });
	fly.PushBack({ 193, 522, 42, 53 });
	fly.PushBack({ 244, 522, 42, 53 });
	fly.speed = 0.5f;

	deathExplosion.PushBack({ 30, 665, 92, 86 });
	
	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 42, 53 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	path.PushBack({ 0.0f, 0.0f }, 35, &fly); 
	path.PushBack({ 0.0f, 1.5f }, 50, &fly); // 64
	path.PushBack({ 0.0f, 0.0f }, 100, &fly); // 155
	path.PushBack({ 0.0f, 1.5f }, 150, &fly); // 70
	path.PushBack({ 0.0f, 0.0f }, 100, &fly); // 294
	path.PushBack({ 0.0f, 1.5f }, 142, &fly);

	path.loop = true;

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_MetallicBalloon::Move()
{
	position = original_pos + path.GetCurrentPosition(&animation);
}

void Enemy_MetallicBalloon::OnCollision(Collider* collider) {
	lives--;
}

uint Enemy_MetallicBalloon::getLives() {
	return lives;
}