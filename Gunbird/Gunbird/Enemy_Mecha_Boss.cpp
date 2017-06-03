#include "Application.h"
#include "Enemy_Mecha_Boss.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "SDL\include\SDL_timer.h"

#define PI 3.14159265
#define RAD_TO_DEGREES (180.0 / PI)
#define ANGLE_CONVERT_REVERSE (PI / 180.0)

#define ENEMYSHOOTSPEED 3
#define ENEMYSHOOTDELAY 2000
#define ENEMY_DELAY_DOUBLE_SHOT 100

Enemy_Mecha_Boss::Enemy_Mecha_Boss(int x, int y) : Enemy(x, y)
{
	lives = 100;

	lastTime = 0;

	idle.PushBack({ 56,2038,188,126 }); 
	idle.PushBack({ 285,2038,188,126 });
	idle.PushBack({ 517,2038,188,126 });
	idle.PushBack({ 745,2038,188,126 });
	idle.PushBack({ 991,2038,188,126 });
	idle.PushBack({ 1230,2038,188,126 });
	idle.speed = 0.1f;

	collider = App->collision->AddCollider({ 0, 0, 116, 100 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	animation = &idle;

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_Mecha_Boss::Move()
{

	position = original_pos + movement.GetCurrentPosition(&animation);

	if (animation == &hitWhite && lastTime == 0) {
		lastTime = SDL_GetTicks();
	}

	currentTime = SDL_GetTicks();

	if (currentTime > (lastTime + 70)) {
		animation = &idle;
		lastTime = 0;
	}

	if (lives <= 12 && animation != &hitWhite)
	{
		animation = &redNormal;
	}

	if (lives < 6 && lives > 3 && animation != &hitWhite)
	{
		animation = &redNormal_2;
	}

	if (lives <= 3 && animation != &hitWhite)
	{
		animation = &redNormal_3;
	}


	lastParticle = App->particles->enemyBasicShot;

}

void Enemy_Mecha_Boss::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT || collider->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT || collider->type == COLLIDER_TYPE::COLLIDER_PLAYER2_BOMB || collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_BOMB) {
		animation = &hitWhite;
		App->particles->AddParticle(App->particles->playerShotCollison, (collider->rect.x + (((collider->rect.w)) / 2)), (collider->rect.y - (((collider->rect.h)))));
		if (App->player->shotPower < 1)
			lives--;
		if (App->player->shotPower == 1)
			lives = lives - 2;
	}
}

uint Enemy_Mecha_Boss::getLives() {
	return lives;
}

void Enemy_Mecha_Boss::Shoot()
{
	left = false;
	double deltaX;
	double deltaY;
	if (App->player->IsEnabled()) {
		deltaX = ((App->player->position.x + (App->player->playerCollider->rect.w / 2))) - (position.x + 15);
		deltaY = ((App->player->position.y + (App->player->playerCollider->rect.h / 2))) - (position.y + 21);
	}
	else if (App->player2->IsEnabled()) {
		deltaX = ((App->player2->position.x + (App->player2->playerCollider->rect.w / 2))) - (position.x + 15);
		deltaY = ((App->player2->position.y + (App->player2->playerCollider->rect.h / 2))) - (position.y + 21);
	}

	float angle;

	angle = atan2(deltaX, deltaY);

	angle *= RAD_TO_DEGREES;


	if (angle < 0) {
		angle = angle * -1;
		left = true;
	}

	//LOG("Angle %.2f", angle);
	/*if (currentTime > (lastShot + ENEMYSHOOTDELAY)) {

	if (!left) {
	if ((angle < 90) && (angle >= 0)) {
	lastParticle.speed.x = ENEMYSHOOTSPEED * sin((angle + 10) * ANGLE_CONVERT_REVERSE);
	lastParticle.speed.y = ENEMYSHOOTSPEED * cos((angle + 10) * ANGLE_CONVERT_REVERSE);
	}
	else {
	lastParticle.speed.x = ENEMYSHOOTSPEED * sin((angle + 10) * ANGLE_CONVERT_REVERSE);
	lastParticle.speed.y = ENEMYSHOOTSPEED * cos((angle + 10) * ANGLE_CONVERT_REVERSE);
	}
	}
	else {
	if ((angle < 90) && (angle >= 0)) {
	lastParticle.speed.x = -ENEMYSHOOTSPEED * sin((angle + 10) * ANGLE_CONVERT_REVERSE);
	lastParticle.speed.y = ENEMYSHOOTSPEED * cos((angle + 10) * ANGLE_CONVERT_REVERSE);
	}
	else {
	lastParticle.speed.x = -ENEMYSHOOTSPEED * sin((angle + 10) * ANGLE_CONVERT_REVERSE);
	lastParticle.speed.y = ENEMYSHOOTSPEED * cos((angle + 10) * ANGLE_CONVERT_REVERSE);
	}
	}*/

	if (currentTime > (lastShot + ENEMYSHOOTDELAY)) {



		App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 9, position.y + 47, COLLIDER_TYPE::COLLIDER_NONE);
		App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 23, position.y + 47, COLLIDER_TYPE::COLLIDER_NONE);

		lastParticle.speed.x = -1.0f;
		lastParticle.speed.y = 2.0f;
		App->particles->AddParticle(lastParticle, position.x + 25, position.y + 56, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);

		lastParticle.speed.x = 1.0f;
		lastParticle.speed.y = 2.0f;
		App->particles->AddParticle(lastParticle, position.x + 15, position.y + 56, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);

		//App->particles->AddParticle(lastParticle, position.x + 10, position.y + 51, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
		//App->particles->AddParticle(lastParticle, position.x + 24, position.y + 51, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);

		lastShot = currentTime;
	}

}