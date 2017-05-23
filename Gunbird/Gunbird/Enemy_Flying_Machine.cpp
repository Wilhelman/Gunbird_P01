#include "Application.h"
#include "Enemy_Flying_Machine.h"
#include "ModuleCollision.h"
#include "ModuleSceneCastle.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "SDL\include\SDL_timer.h"

#define PI 3.14159265 
#define ANGLE_RANGE 12.0f

#define RAD_TO_DEGREES (180.0 / PI)
#define DEGREES_TO_RAD (PI / 180.0)

#define SHOT_ENEMY_VEC 3
#define DELAY_SHOT_ENEMY 2000

Enemy_Flying_Machine::Enemy_Flying_Machine(int x, int y) : Enemy(x, y)
{

	lives = 3;

	fly.PushBack({ 749,943,77,66 });
	fly.PushBack({ 836,941,77,66 });
	fly.PushBack({ 928,947,77,66 });
	fly.PushBack({ 1020,950,77,66 });
	fly.PushBack({ 750,1044,77,66 });
	fly.PushBack({ 843,1046,77,66 });
	fly.PushBack({ 926,1046,77,66 });
	fly.PushBack({ 1020,1049,77,66 });
	fly.PushBack({ 749,1141,77,66 });
	fly.PushBack({ 847,1140,77,66 });


	fly.loop = true;
	fly.speed = 0.05f;

	animation = &fly;
	dead = false;

	collider = App->collision->AddCollider({ 0, 0, 77, 66 }, COLLIDER_TYPE::COLLIDER_ENEMY_FLYING, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

	deadTimer = 0;
	lastParticle = App->particles->enemyBasicShot;
}

void Enemy_Flying_Machine::Move() {

	position = original_pos + movement.GetCurrentPosition(&animation);

}


void Enemy_Flying_Machine::Shoot()
{
	/*if (!dead) {
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

		currentTime = SDL_GetTicks();

		if (angle < 0) {
			angle = angle * -1;
			left = true;
		}

		//LOG("Angle %.2f", angle);
		if (currentTime >(lastShot + DELAY_SHOT_ENEMY)) {

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


			if (currentTime >(lastShot + DELAY_SHOT_ENEMY))
			{
				App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 11, position.y + 7, COLLIDER_TYPE::COLLIDER_NONE);
				App->particles->AddParticle(lastParticle, position.x + 12, position.y + 8, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);

				lastShot = currentTime;
			}

		}
	}*/
}

uint Enemy_Flying_Machine::getLives() {
	return lives;
}

void Enemy_Flying_Machine::OnCollision(Collider* collider) {

	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT || collider->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {
		App->particles->AddParticle(App->particles->playerShotCollison, (collider->rect.x + (((collider->rect.w)) / 2)), (collider->rect.y + (((collider->rect.h)))));
		lives--;
	}

	if (lives <= 0) {
		if (this->collider != nullptr) {
			App->collision->EraseCollider(this->collider);
			this->collider = nullptr;
		}
		dead = true;
	}
}