#include "Application.h"
#include "Enemy_Big_Red_Turret.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "SDL\include\SDL_timer.h"

#define ENEMYSHOOTSPEED 3
#define ENEMYSHOOTDELAY 2000

Enemy_Big_Red_Turret::Enemy_Big_Red_Turret(int x, int y) : Enemy(x, y)
{
	lives = 14;

	lastTime = 0;

	fly.PushBack({ 1040, 742, 46, 58 });
	fly.PushBack({ 1096, 742, 46, 58 });
	fly.PushBack({ 1153, 742, 46, 58 });
	fly.speed = 0.1f;

	collider = App->collision->AddCollider({ 0, 0, 46, 58 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	animation = &fly;

	original_pos.x = x;
	original_pos.y = y;
	lastShot = currentTime + 8000;
	lastParticle = App->particles->enemyBasicShot;
	shotCombo = 0;
}

void Enemy_Big_Red_Turret::Move()
{

	position = original_pos + movement.GetCurrentPosition(&animation);

}

void Enemy_Big_Red_Turret::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT || collider->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {
		App->particles->AddParticle(App->particles->playerShotCollison, (collider->rect.x + (((collider->rect.w)) / 2)), (collider->rect.y - (((collider->rect.h)))));
		if (App->player->shotPower < 1)
			lives--;
		if (App->player->shotPower == 1)
			lives = lives - 2;
	}
}

uint Enemy_Big_Red_Turret::getLives() {
	return lives;
}

void Enemy_Big_Red_Turret::Shoot()
{


	if (currentTime >(lastShot + ENEMYSHOOTDELAY)) {


		if (shotCombo == 0) {
			App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 14, position.y + 52, COLLIDER_TYPE::COLLIDER_NONE);
			App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 24, position.y + 52, COLLIDER_TYPE::COLLIDER_NONE);
			lastParticle.speed.x = -1.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, position.x + 15, position.y + 56, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			lastParticle.speed.x = 0.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, position.x + 25, position.y + 56, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			shotCombo = 1;
			lastComboShot = currentTime;
		}

		if (shotCombo == 1 && currentTime >(lastComboShot + 300)) {
			App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 14, position.y + 52, COLLIDER_TYPE::COLLIDER_NONE);
			App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 24, position.y + 52, COLLIDER_TYPE::COLLIDER_NONE);
			lastParticle.speed.x = 0.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, position.x + 15, position.y + 56, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			lastParticle.speed.x = 1.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, position.x + 25, position.y + 56, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			shotCombo = 2;
			lastComboShot = currentTime;

			
		}
		
		if (shotCombo == 2 && currentTime >(lastComboShot + 300)) {
			App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 14, position.y + 52, COLLIDER_TYPE::COLLIDER_NONE);
			App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 24, position.y + 52, COLLIDER_TYPE::COLLIDER_NONE);
			lastParticle.speed.x = 0.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, position.x + 15, position.y + 56, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			lastParticle.speed.x = 0.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, position.x + 25, position.y + 56, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			shotCombo = 3;
			lastComboShot = currentTime;
		}

		if (shotCombo == 3 && currentTime >(lastComboShot + 300)) {
			App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 14, position.y + 52, COLLIDER_TYPE::COLLIDER_NONE);
			App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 24, position.y + 52, COLLIDER_TYPE::COLLIDER_NONE);
			lastParticle.speed.x = -1.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, position.x + 15, position.y + 56, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			lastParticle.speed.x = 1.0f;
			lastParticle.speed.y = 2.0f;
			App->particles->AddParticle(lastParticle, position.x + 25, position.y + 56, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			shotCombo = 4;
			lastComboShot = currentTime;
		}

		if (shotCombo == 4 && currentTime >(lastComboShot + 300)) {
			App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 14, position.y + 52, COLLIDER_TYPE::COLLIDER_NONE);
			App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 24, position.y + 52, COLLIDER_TYPE::COLLIDER_NONE);
			lastParticle.speed.x = -2.0f;
			lastParticle.speed.y = 1.0f;
			App->particles->AddParticle(lastParticle, position.x + 15, position.y + 56, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			lastParticle.speed.x = 2.0f;
			lastParticle.speed.y = 1.0f;
			App->particles->AddParticle(lastParticle, position.x + 25, position.y + 56, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			shotCombo = 0;
			lastComboShot = currentTime;
			lastShot = currentTime;
		}
		
		
	}

	currentTime = SDL_GetTicks();

}