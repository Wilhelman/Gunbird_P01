#include "Application.h"
#include "Enemy_MetallicBalloon.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "SDL\include\SDL_timer.h"

#define ENEMYSHOOTDELAY 2000

Enemy_MetallicBalloon::Enemy_MetallicBalloon(int x, int y) : Enemy(x, y)
{
	lives = 19;

	lastTime = 0;

	fly.PushBack({ 36, 522, 42, 53 }); // TODO_: get right coordinates
	fly.PushBack({ 89, 522, 42, 53 });
	fly.PushBack({ 141, 522, 42, 53 });
	fly.PushBack({ 193, 522, 42, 53 });
	fly.PushBack({ 244, 522, 42, 53 });
	fly.speed = 0.5f;

	redNormal.PushBack({ 36, 522, 42, 53 }); // TODO_: get right coordinates
	redNormal.PushBack({ 347, 522, 42, 53 });
	redNormal.PushBack({ 347, 522, 42, 53 });
	redNormal.PushBack({ 347, 522, 42, 53 });
	redNormal.PushBack({ 89, 522, 42, 53 });
	redNormal.PushBack({ 347, 522, 42, 53 });
	redNormal.PushBack({ 347, 522, 42, 53 });
	redNormal.PushBack({ 347, 522, 42, 53 });
	redNormal.PushBack({ 141, 522, 42, 53 });
	redNormal.PushBack({ 347, 522, 42, 53 });
	redNormal.PushBack({ 347, 522, 42, 53 });
	redNormal.PushBack({ 347, 522, 42, 53 });
	redNormal.PushBack({ 193, 522, 42, 53 });
	redNormal.PushBack({ 347, 522, 42, 53 });
	redNormal.PushBack({ 347, 522, 42, 53 });
	redNormal.PushBack({ 347, 522, 42, 53 });
	redNormal.PushBack({ 244, 522, 42, 53 });
	redNormal.PushBack({ 347, 522, 42, 53 });
	redNormal.PushBack({ 347, 522, 42, 53 });
	redNormal.PushBack({ 347, 522, 42, 53 });
	redNormal.speed = 0.5f;

	redNormal_2.PushBack({ 36, 522, 42, 53 }); // TODO_: get right coordinates
	redNormal_2.PushBack({ 347, 522, 42, 53 });
	redNormal_2.PushBack({ 347, 522, 42, 53 });
	redNormal_2.PushBack({ 89, 522, 42, 53 });
	redNormal_2.PushBack({ 347, 522, 42, 53 });
	redNormal_2.PushBack({ 347, 522, 42, 53 });
	redNormal_2.PushBack({ 141, 522, 42, 53 });
	redNormal_2.PushBack({ 347, 522, 42, 53 });
	redNormal_2.PushBack({ 347, 522, 42, 53 });
	redNormal_2.PushBack({ 193, 522, 42, 53 });
	redNormal_2.PushBack({ 347, 522, 42, 53 });
	redNormal_2.PushBack({ 347, 522, 42, 53 });
	redNormal_2.PushBack({ 244, 522, 42, 53 });
	redNormal_2.PushBack({ 347, 522, 42, 53 });
	redNormal_2.PushBack({ 347, 522, 42, 53 });
	redNormal_2.speed = 0.5f;

	redNormal_3.PushBack({ 36, 522, 42, 53 }); // TODO_: get right coordinates
	redNormal_3.PushBack({ 347, 522, 42, 53 });
	redNormal_3.PushBack({ 89, 522, 42, 53 });
	redNormal_3.PushBack({ 347, 522, 42, 53 });;
	redNormal_3.PushBack({ 141, 522, 42, 53 });
	redNormal_3.PushBack({ 347, 522, 42, 53 });
	redNormal_3.PushBack({ 193, 522, 42, 53 });
	redNormal_3.PushBack({ 347, 522, 42, 53 });
	redNormal_3.PushBack({ 244, 522, 42, 53 });
	redNormal_3.PushBack({ 347, 522, 42, 53 });
	redNormal_3.speed = 0.5f;


	hitWhite.PushBack({ 296, 522, 42, 53});
	hitWhite.speed = 0.5f;
	hitWhite.loop = true;

	collider = App->collision->AddCollider({ 0, 0, 42, 53 }, COLLIDER_TYPE::COLLIDER_ENEMY_FLYING, (Module*)App->enemies);

	animation = &fly;

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_MetallicBalloon::Move()
{

	position = original_pos + movement.GetCurrentPosition(&animation);

	if (animation == &hitWhite && lastTime == 0) {
		lastTime = SDL_GetTicks();
	}

	currentTime = SDL_GetTicks();

	if (currentTime > (lastTime + 70)) {
		animation = &fly;
		lastTime = 0;
	}

	if (lives <= 12)
	{
		animation = &redNormal;
	}
	
	if (lives < 12 && lives >= 6)
	{
		animation = &redNormal_2;
	}

	if(lives < 6)
	{
		animation = &redNormal_3;
	}
	
}

void Enemy_MetallicBalloon::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
		animation = &hitWhite;
		lives--;
	} 
}

uint Enemy_MetallicBalloon::getLives() {
	return lives;
}

void Enemy_MetallicBalloon::Shoot()
{
	unsigned int currentTime = 0;

	currentTime = SDL_GetTicks();

	if (currentTime > (lastShot + ENEMYSHOOTDELAY)) {
		
		App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 9, position.y + 47,COLLIDER_TYPE::COLLIDER_NONE);
		App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 23, position.y + 47, COLLIDER_TYPE::COLLIDER_NONE);

		App->particles->AddParticle(App->particles->enemyBasicShot, position.x + 10, position.y + 51, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->enemyBasicShot, position.x + 24, position.y + 51, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);

		lastShot = currentTime;
	}
	
}