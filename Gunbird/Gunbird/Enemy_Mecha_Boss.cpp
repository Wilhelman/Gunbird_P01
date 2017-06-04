#include "Application.h"
#include "Enemy_Mecha_Boss.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleEnemies.h"
#include "SDL\include\SDL_timer.h"

#define PI 3.14159265 
#define ANGLE_RANGE 12.0f

#define RAD_TO_DEGREES (180.0 / PI)
#define DEGREES_TO_RAD (PI / 180.0)

#define SHOT_ENEMY_VEC 3
#define DELAY_SHOT_ENEMY 2000

Enemy_Mecha_Boss::Enemy_Mecha_Boss(int x, int y) : Enemy(x, y)
{
	lives = 50;

	lastTime = 0;

	idle.PushBack({ 56,2038,188,126 }); 
	idle.PushBack({ 285,2038,188,126 });
	idle.PushBack({ 517,2038,188,126 });
	idle.PushBack({ 745,2038,188,126 });
	idle.PushBack({ 991,2038,188,126 });
	idle.PushBack({ 1230,2038,188,126 });
	idle.speed = 0.1f;

	redNormal.PushBack({ 56,2038,188,126 });
	redNormal.PushBack({ 56, 2185, 188, 126 }); //
	redNormal.PushBack({ 285,2038,188,126 });
	redNormal.PushBack({ 517,2038,188,126 });
	redNormal.PushBack({ 745,2038,188,126 });
	redNormal.PushBack({ 991,2038,188,126 });
	redNormal.PushBack({ 1230,2038,188,126 });
	redNormal.PushBack({ 56,2038,188,126 });
	redNormal.PushBack({ 285,2038,188,126 });
	redNormal.PushBack({ 517,2038,188,126 });
	redNormal.PushBack({ 745,2038,188,126 });
	redNormal.PushBack({ 991,2038,188,126 });
	redNormal.PushBack({ 1230,2038,188,126 });
	redNormal.PushBack({ 56,2038,188,126 });
	redNormal.PushBack({ 285,2038,188,126 });
	redNormal.PushBack({ 517,2038,188,126 });
	redNormal.PushBack({ 745,2038,188,126 });
	redNormal.PushBack({ 991,2038,188,126 });
	redNormal.PushBack({ 1230,2038,188,126 });
	redNormal.speed = 0.1f;


	redNormal_2.PushBack({ 56,2038,188,126 });
	redNormal_2.PushBack({ 56, 2185, 188, 126 }); // 
	redNormal_2.PushBack({ 285,2038,188,126 });
	redNormal_2.PushBack({ 517,2038,188,126 });
	redNormal_2.PushBack({ 745,2038,188,126 });
	redNormal_2.PushBack({ 991,2038,188,126 });
	redNormal_2.PushBack({ 1230,2038,188,126 });
	redNormal_2.PushBack({ 56,2038,188,126 });
	redNormal_2.PushBack({ 285,2038,188,126 });
	redNormal_2.PushBack({ 517,2038,188,126 });
	redNormal_2.PushBack({ 745,2038,188,126 });
	redNormal_2.PushBack({ 991,2038,188,126 });
	redNormal_2.PushBack({ 1230,2038,188,126 });
	redNormal_2.PushBack({ 56, 2038, 188, 126 });
	redNormal_2.PushBack({ 56, 2185, 188, 126 }); //
	redNormal_2.PushBack({ 285,2038,188,126 });
	redNormal_2.PushBack({ 517,2038,188,126 });
	redNormal_2.PushBack({ 745,2038,188,126 });
	redNormal_2.PushBack({ 991,2038,188,126 });
	redNormal_2.PushBack({ 1230,2038,188,126 });
	redNormal_2.PushBack({ 56,2038,188,126 });
	redNormal_2.PushBack({ 285,2038,188,126 });
	redNormal_2.PushBack({ 517,2038,188,126 });
	redNormal_2.PushBack({ 745,2038,188,126 });
	redNormal_2.PushBack({ 991,2038,188,126 });
	redNormal_2.PushBack({ 1230,2038,188,126 });
	redNormal_2.speed = 0.1f;

	redNormal_3.PushBack({ 56,2038,188,126 });
	redNormal_3.PushBack({ 56, 2185, 188, 126 }); // 
	redNormal_3.PushBack({ 285,2038,188,126 });
	redNormal_3.PushBack({ 517,2038,188,126 });
	redNormal_3.PushBack({ 745,2038,188,126 });
	redNormal_3.PushBack({ 991,2038,188,126 });
	redNormal_3.PushBack({ 56, 2185, 188, 126 }); //
	redNormal_3.PushBack({ 1230,2038,188,126 });
	redNormal_3.PushBack({ 56,2038,188,126 });
	redNormal_3.PushBack({ 285,2038,188,126 });
	redNormal_3.PushBack({ 517,2038,188,126 });
	redNormal_3.PushBack({ 745,2038,188,126 });
	redNormal_3.PushBack({ 56, 2185, 188, 126 }); //
	redNormal_3.PushBack({ 991,2038,188,126 });
	redNormal_3.PushBack({ 1230,2038,188,126 });
	redNormal_3.PushBack({ 56, 2038, 188, 126 });
	redNormal_3.PushBack({ 56, 2185, 188, 126 }); //
	redNormal_3.PushBack({ 285,2038,188,126 });
	redNormal_3.PushBack({ 517,2038,188,126 });
	redNormal_3.PushBack({ 745,2038,188,126 });
	redNormal_3.PushBack({ 991,2038,188,126 });
	redNormal_3.PushBack({ 1230,2038,188,126 });
	redNormal_3.PushBack({ 56, 2185, 188, 126 }); //
	redNormal_3.PushBack({ 56,2038,188,126 });
	redNormal_3.PushBack({ 285,2038,188,126 });
	redNormal_3.PushBack({ 517,2038,188,126 });
	redNormal_3.PushBack({ 745,2038,188,126 });
	redNormal_3.PushBack({ 991,2038,188,126 });
	redNormal_3.PushBack({ 56, 2185, 188, 126 }); //
	redNormal_3.PushBack({ 1230,2038,188,126 });
	redNormal_3.speed = 0.1f;


	hitWhite.PushBack({285, 2185, 186, 126});
	hitWhite.speed = 0.1f;
	hitWhite.loop = true;

	collider = App->collision->AddCollider({ 0, 0, 188, 126 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	animation = &idle;

	original_pos.x = x;
	original_pos.y = y;
	bomb = false;
	bombTimer = 0;
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
	if (currentTime > bombTimer + 300 && bomb)
		bomb = false;
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT || collider->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT ) {
		
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

uint Enemy_Mecha_Boss::getLives() {
	return lives;
}

void Enemy_Mecha_Boss::Shoot()
{
	if (App->enemies->handsDestroyed == 2) {
		if (burstCombo == 0 &&  currentTime > burstTimer + 1000) {
			lastParticle.speed.x = 1.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, 110, 136, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			lastParticle.speed.x = 0.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, 110, 136, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			lastParticle.speed.x = -1.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, 110, 136, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			burstTimer = currentTime;
			burstCombo = 1;
		}


		if (currentTime > burstTimer + 200 && burstCombo == 1) {

			lastParticle.speed.x = 1.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, 110, 136, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			lastParticle.speed.x = 0.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, 110, 136, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			lastParticle.speed.x = -1.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, 110, 136, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			burstTimer = currentTime;
			burstCombo = 2;
		}

		if (currentTime > burstTimer + 200 && burstCombo == 2) {
			lastParticle.speed.x = 1.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, 110, 136, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			lastParticle.speed.x = 0.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, 110, 136, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			lastParticle.speed.x = -1.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, 110, 136, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			burstTimer = currentTime;
			burstCombo = 3;
		}

		if (currentTime > burstTimer + 200 && burstCombo == 3) {
			lastParticle.speed.x = 1.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, 110, 136, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			lastParticle.speed.x = 0.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, 110, 136, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			lastParticle.speed.x = -1.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, 110, 136, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			burstTimer = currentTime;
			burstCombo = 0;
		}
	}

	left = false;
	double deltaX;
	double deltaY;
	if (App->player->IsEnabled()) {
		deltaX = ((App->player->position.x + (App->player->playerCollider->rect.w / 2))) - (position.x + 96);
		deltaY = ((App->player->position.y + (App->player->playerCollider->rect.h / 2))) - (position.y + 66);
	}
	else if (App->player2->IsEnabled()) {
		deltaX = ((App->player2->position.x + (App->player2->playerCollider->rect.w / 2))) - (position.x + 96);
		deltaY = ((App->player2->position.y + (App->player2->playerCollider->rect.h / 2))) - (position.y + 66);
	}

	float angle;

	angle = atan2(deltaX, deltaY);

	angle *= RAD_TO_DEGREES;

	currentTime = SDL_GetTicks();

	if (angle < 0) {
		angle = angle * -1;
		left = true;
	}

	//LOG("Angle %.2f", angle);
	if (currentTime > (lastShot + DELAY_SHOT_ENEMY)) {

		if (!left) {
			if ((angle < 90) && (angle >= 0)) {
				lastParticle.speed.x = SHOT_ENEMY_VEC * sin((angle + 10) * DEGREES_TO_RAD);
				lastParticle.speed.y = SHOT_ENEMY_VEC * cos((angle + 10) * DEGREES_TO_RAD);
			}
			else {
				lastParticle.speed.x = SHOT_ENEMY_VEC * sin((angle + 10) * DEGREES_TO_RAD);
				lastParticle.speed.y = SHOT_ENEMY_VEC * cos((angle + 10) * DEGREES_TO_RAD);
			}
		}
		else {
			if ((angle < 90) && (angle >= 0)) {
				lastParticle.speed.x = -SHOT_ENEMY_VEC * sin((angle + 10) * DEGREES_TO_RAD);
				lastParticle.speed.y = SHOT_ENEMY_VEC * cos((angle + 10) * DEGREES_TO_RAD);
			}
			else {
				lastParticle.speed.x = -SHOT_ENEMY_VEC * sin((angle + 10) * DEGREES_TO_RAD);
				lastParticle.speed.y = SHOT_ENEMY_VEC * cos((angle + 10) * DEGREES_TO_RAD);
			}
		}


		if (currentTime > (lastShot + DELAY_SHOT_ENEMY))
		{
			App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 92, position.y + 65, COLLIDER_TYPE::COLLIDER_NONE);

			App->particles->AddParticle(lastParticle, position.x + 93, position.y + 66, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);

			if (App->enemies->handsDestroyed == 2) {
				App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 6, position.y + 54, COLLIDER_TYPE::COLLIDER_NONE);

				App->particles->AddParticle(lastParticle, position.x + 6, position.y + 55, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 168, position.y + 54, COLLIDER_TYPE::COLLIDER_NONE);

				App->particles->AddParticle(lastParticle, position.x + 169, position.y + 55, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			}
			
			lastShot = currentTime;
		}


	}

}