#include "Application.h"
#include "Enemy_Trump_Red_Mecha.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "SDL\include\SDL_timer.h"
#include "ModuleSceneForest.h"

#define ENEMYSHOOTSPEED 3
#define ENEMYSHOOTDELAY 2000

Enemy_Trump_Red_Mecha::Enemy_Trump_Red_Mecha(int x, int y) : Enemy(x, y)
{
	lives = 14;

	lastTime = 0;

	standing.PushBack({ 1362, 673, 60, 63 });
	standing.speed = 0.1f;

	walking_around.PushBack({ 1362, 673, 60, 63 });
	walking_around.PushBack({ 1437, 673, 60, 63 });
	walking_around.PushBack({ 1517, 673, 60, 63 });
	walking_around.PushBack({ 1596, 673, 60, 63 });
	walking_around.PushBack({ 1674, 673, 60, 63 });
	walking_around.PushBack({ 1364, 744, 60, 63 });
	walking_around.PushBack({ 1437, 744, 60, 63 });
	walking_around.PushBack({ 1519, 744, 60, 63 });
	walking_around.PushBack({ 1596, 744, 60, 63 });
	walking_around.PushBack({ 1673, 744, 60, 63 });
	walking_around.speed = 0.07f;

	collider = App->collision->AddCollider({ 0, 0, 60, 63 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	animation = &standing;

	original_pos.x = x;
	original_pos.y = y;
	lastShot = currentTime + 8000;
	lastParticle = App->particles->enemyBasicShot;
	shotCombo = 0;
}

void Enemy_Trump_Red_Mecha::Move()
{

	position = original_pos + movement.GetCurrentPosition(&animation);

	if ((int)App->sceneForest->background_y > -1600 && (int)App->sceneForest->background_y < -1440)
		animation = &standing;
	else
		animation = &walking_around;

}

void Enemy_Trump_Red_Mecha::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT || collider->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {
		App->particles->AddParticle(App->particles->playerShotCollison, (collider->rect.x + (((collider->rect.w)) / 2)), (collider->rect.y - (((collider->rect.h)))));
		if (App->player->shotPower < 1)
			lives--;
		if (App->player->shotPower == 1)
			lives = lives - 2;
	}
}

uint Enemy_Trump_Red_Mecha::getLives() {
	return lives;
}

void Enemy_Trump_Red_Mecha::Shoot()
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