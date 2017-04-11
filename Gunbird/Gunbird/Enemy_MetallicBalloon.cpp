#include "Application.h"
#include "Enemy_MetallicBalloon.h"
#include "ModuleCollision.h"
#include "SDL\include\SDL_timer.h"

Enemy_MetallicBalloon::Enemy_MetallicBalloon(int x, int y) : Enemy(x, y)
{
	lives = 3;

	lastTime = 0;

	fly.PushBack({ 36, 522, 42, 53 }); // TODO_: get right coordinates
	fly.PushBack({ 89, 522, 42, 53 });
	fly.PushBack({ 141, 522, 42, 53 });
	fly.PushBack({ 193, 522, 42, 53 });
	fly.PushBack({ 244, 522, 42, 53 });
	fly.speed = 0.5f;

	hitWhiteRed.PushBack({ 296, 522, 42, 53});
	hitWhiteRed.PushBack({ 347, 522, 42, 53 });
	hitWhiteRed.speed = 0.5f;
	hitWhiteRed.loop = true;

	collider = App->collision->AddCollider({ 0, 0, 42, 53 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	animation = &fly;

	path.PushBack({ 0.0f, 1.5f }, 50, animation); // 64
	path.PushBack({ 0.0f, 0.0f }, 100, animation); // 155
	path.PushBack({ 0.0f, 1.5f }, 150, animation); // 70
	path.PushBack({ 0.0f, 0.0f }, 100, animation); // 294
	path.PushBack({ 0.0f, 1.5f }, 142, animation);

	path.loop = true;

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_MetallicBalloon::Move()
{

	position = original_pos + path.GetCurrentPosition(&animation);

	if (animation == &hitWhiteRed && lastTime == 0) {
		lastTime = SDL_GetTicks();
	}

	currentTime = SDL_GetTicks();

	if (currentTime > (lastTime + 70)) {
		animation = &fly;
		lastTime = 0;
	}
	
}

void Enemy_MetallicBalloon::OnCollision(Collider* collider) {
	animation = &hitWhiteRed;
	lives--;
}

uint Enemy_MetallicBalloon::getLives() {
	return lives;
}