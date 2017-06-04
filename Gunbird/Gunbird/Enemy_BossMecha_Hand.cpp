#include "Application.h"
#include "Enemy_BossMecha_Hand.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleSceneForest.h"
#include "ModulePlayer2.h"
#include <time.h>
#include "ModuleEnemies.h"
#include "SDL\include\SDL_timer.h"
#include <stdlib.h>

#define PI 3.14159265
#define RAD_TO_DEGREES (180.0 / PI)
#define ANGLE_CONVERT_REVERSE (PI / 180.0)

#define ENEMYSHOOTSPEED 3
#define ENEMYSHOOTDELAY 2000
#define ENEMY_DELAY_DOUBLE_SHOT 100

Enemy_BossMecha_Hand::Enemy_BossMecha_Hand(int x, int y) : Enemy(x, y)
{
	lives = 30;
	lastTime = 0;
	srand(time(NULL));
	randomTimer = (1000 + rand() % 2000);
	//opening hand
	opening.PushBack({ 1194,1430,46,62 }); // TODO_: get right coordinates
	opening.PushBack({ 1245,1430,46,62 });
	opening.PushBack({ 1296,1430,46,62 });
	opening.PushBack({ 1348,1430,46,62 });
	opening.speed = 0.08f;
	opening.loop = false;

	//turret turning
	rotation.PushBack({ 1400,1430,46,62 });
	rotation.PushBack({ 1121, 1931, 45, 62 });
	rotation.PushBack({ 1176, 1931, 45, 62 });
	rotation.PushBack({ 1238, 1931, 45, 62 });
	rotation.PushBack({ 1293, 1931, 45, 62 });
	rotation.PushBack({ 1348, 1931, 45, 62 });
	rotation.PushBack({ 1401, 1931, 45, 62 });
	rotation.speed = 0.08f;

	//closed
	handClosed.PushBack({ 1194,1430,46,62 });
	handClosed.speed = 0.08f;
	handClosed.loop = true;

	hitWhite.PushBack({ 1458, 1931, 45, 62 });
	hitWhite.speed = 0.1f;
	hitWhite.loop = false;



	/*
	//opening hand 
	1194,1430,46,62
	1245,1430,46,62
	1296,1430,46,62
	1348,1430,46,62

	//turret turn
	1400,1430,46,62
	1601, 1931, 45, 62
	1121, 1931, 45, 62
	1176, 1931, 45, 62
	1238, 1931, 45, 62
	1293, 1931, 45, 62
	1348, 1931, 45, 62
	1401, 1931, 45, 62
	*/

	collider = App->collision->AddCollider({ 0, 0, 42, 53 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	animation = &handClosed;


	original_pos.x = x;
	original_pos.y = y;
	bomb = false;
	bombTimer = 0;
	dead = false;
}

void Enemy_BossMecha_Hand::Move()
{
	if (App->enemies->bossDestroyed) {
		dead = true;
	}
	if (!dead) {
		if ((int)App->sceneForest->background_y == -1650)
			animation = &opening;

		if ((int)App->sceneForest->background_y == -1625)
			animation = &rotation;

		position = original_pos + movement.GetCurrentPosition(&animation);

		if (animation == &hitWhite && lastTime == 0) {
			lastTime = SDL_GetTicks();
		}

		currentTime = SDL_GetTicks();

		if (currentTime > (lastTime + 70)) {
			animation = &rotation;
			lastTime = 0;
		}


		lastParticle = App->particles->enemyBasicShot;
	}
	
}

void Enemy_BossMecha_Hand::OnCollision(Collider* collider) 
{
	if (!dead) {
		if (currentTime > bombTimer + 300 && bomb)
			bomb = false;
		if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT || collider->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {

			animation = &hitWhite;
			App->particles->AddParticle(App->particles->playerShotCollison, (collider->rect.x + (((collider->rect.w)) / 2)), (collider->rect.y - (((collider->rect.h)))));
			if (App->player->shotPower < 1)
				lives--;
			if (App->player->shotPower == 1) {
				if (lives < 2)
					lives = 0;
				else
					lives = lives - 2;
			}
		}
		if ((collider->type == COLLIDER_TYPE::COLLIDER_PLAYER2_BOMB || collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_BOMB) && !bomb) {
			bombTimer = currentTime;
			bomb = true;
			if (lives < 2)
				lives = 0;
			else
				lives = lives - 2;
			animation = &hitWhite;
		}
	}
	
}

uint Enemy_BossMecha_Hand::getLives() {
	return lives;
}

void Enemy_BossMecha_Hand::Shoot()
{
	if (!dead) {
		left = false;
		double deltaX = 0;
		double deltaY = 0;
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
		randomTimer = (1000 + rand() % 2000);
		if (currentTime >(lastShot + randomTimer))
		{
			App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 8, position.y + 16, COLLIDER_TYPE::COLLIDER_NONE);
			App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 22, position.y + 16, COLLIDER_TYPE::COLLIDER_NONE);

			App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 11, position.y + 10, COLLIDER_TYPE::COLLIDER_NONE);
			App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 11, position.y + 20, COLLIDER_TYPE::COLLIDER_NONE);

			lastParticle.speed.x = -1.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, position.x + 12, position.y + 11, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);

			lastParticle.speed.x = 2.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, position.x + 12, position.y + 21, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			lastParticle.speed.x = -2.0f;
			lastParticle.speed.y = 2.0f;

			App->particles->AddParticle(lastParticle, position.x + 9, position.y + 17, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);

			lastParticle.speed.x = 1.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, position.x + 23, position.y + 17, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);



			//App->particles->AddParticle(lastParticle, position.x + 10, position.y + 51, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			//App->particles->AddParticle(lastParticle, position.x + 24, position.y + 51, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);

			lastShot = currentTime;
		}
	}
	
}