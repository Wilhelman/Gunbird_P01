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
#define ANGLE_RANGE_CIRCLE 22.5f

#define SHOT_ENEMY_VEC 3
#define DELAY_SHOT_ENEMY 2000

Enemy_Flying_Machine::Enemy_Flying_Machine(int x, int y) : Enemy(x, y)
{
	shot_done = false;
	lives = 40;

	fly.PushBack({ 749,943,77,66 });
	fly.PushBack({ 836,941,77,66 });
	fly.PushBack({ 928,947,77,66 });
	fly.PushBack({ 1020,950,77,66 });
	fly.PushBack({ 750,1044,77,66 });
	fly.loop = true;
	fly.speed = 0.05f;

	shot_phase_anim_open.PushBack({ 843,1046,77,66 });
	shot_phase_anim_open.PushBack({ 926,1046,77,66 });
	shot_phase_anim_open.PushBack({ 1020,1049,77,66 });
	shot_phase_anim_open.PushBack({ 749,1141,77,66 });
	shot_phase_anim_open.PushBack({ 847,1140,77,66 });
	shot_phase_anim_open.loop = false;
	shot_phase_anim_open.speed = 0.05;

	shot_phase_anim_close.PushBack({ 843,1225,77,66 });
	shot_phase_anim_close.PushBack({ 926,1225,77,66 });
	shot_phase_anim_close.PushBack({ 1020,1228,77,66 });
	shot_phase_anim_close.PushBack({ 749,1298,77,66 });
	shot_phase_anim_close.PushBack({ 847,1297,77,66 });
	shot_phase_anim_close.loop = false;
	shot_phase_anim_close.speed = 0.05;
	

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

	if (position.x == 50)
		animation = &shot_phase_anim_open;

	if (shot_done == true && position.x == SCREEN_WIDTH - 100) 
	{
		shot_done = false;
		animation = &shot_phase_anim_open;
		shot_phase_anim_open.Reset();
	}
} 


void Enemy_Flying_Machine::Shoot()
{
	if (!dead) 
	{
		if (animation == &shot_phase_anim_open && shot_phase_anim_open.Finished() && shot_done == false)
		{
			int i = 1;
			
			shot_done = true;
			animation = &shot_phase_anim_close;
			

			App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 14, position.y + 22, COLLIDER_TYPE::COLLIDER_NONE);
			App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 54, position.y + 22, COLLIDER_TYPE::COLLIDER_NONE);
		
			// 1
			lastParticle.speed.x = SHOT_ENEMY_VEC * cos(ANGLE_RANGE_CIRCLE * i);
			lastParticle.speed.y = SHOT_ENEMY_VEC * sin(ANGLE_RANGE_CIRCLE* i);
			App->particles->AddParticle(lastParticle, position.x + 14, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(lastParticle, position.x + 54, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			i++;

			// 2
			lastParticle.speed.x = SHOT_ENEMY_VEC * cos(ANGLE_RANGE_CIRCLE * i);
			lastParticle.speed.y = SHOT_ENEMY_VEC * sin(ANGLE_RANGE_CIRCLE* i);
			App->particles->AddParticle(lastParticle, position.x + 14, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(lastParticle, position.x + 54, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			i++;

			// 3
			lastParticle.speed.x = SHOT_ENEMY_VEC * cos(ANGLE_RANGE_CIRCLE * i);
			lastParticle.speed.y = SHOT_ENEMY_VEC * sin(ANGLE_RANGE_CIRCLE* i);;
			App->particles->AddParticle(lastParticle, position.x + 14, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(lastParticle, position.x + 54, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			i++;

			// 4
			lastParticle.speed.x = SHOT_ENEMY_VEC * cos(ANGLE_RANGE_CIRCLE * i);
			lastParticle.speed.y = SHOT_ENEMY_VEC * sin(ANGLE_RANGE_CIRCLE* i);
			App->particles->AddParticle(lastParticle, position.x + 14, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(lastParticle, position.x + 54, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			i++;

			// 5
			lastParticle.speed.x = SHOT_ENEMY_VEC * cos(ANGLE_RANGE_CIRCLE * i);
			lastParticle.speed.y = SHOT_ENEMY_VEC * sin(ANGLE_RANGE_CIRCLE* i);
			App->particles->AddParticle(lastParticle, position.x + 14, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(lastParticle, position.x + 54, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			i++;

			// 6
			lastParticle.speed.x = SHOT_ENEMY_VEC * cos(ANGLE_RANGE_CIRCLE * i);
			lastParticle.speed.y = SHOT_ENEMY_VEC * sin(ANGLE_RANGE_CIRCLE* i);
			App->particles->AddParticle(lastParticle, position.x + 14, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(lastParticle, position.x + 54, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			i++;

			// 7
			lastParticle.speed.x = SHOT_ENEMY_VEC * cos(ANGLE_RANGE_CIRCLE * i);
			lastParticle.speed.y = SHOT_ENEMY_VEC * sin(ANGLE_RANGE_CIRCLE* i);
			App->particles->AddParticle(lastParticle, position.x + 14, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(lastParticle, position.x + 54, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			i++;

			// 8
			lastParticle.speed.x = SHOT_ENEMY_VEC * cos(ANGLE_RANGE_CIRCLE * i);
			lastParticle.speed.y = SHOT_ENEMY_VEC * sin(ANGLE_RANGE_CIRCLE* i);
			App->particles->AddParticle(lastParticle, position.x + 14, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(lastParticle, position.x + 54, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			i++;

			// 9
			lastParticle.speed.x = SHOT_ENEMY_VEC * cos(ANGLE_RANGE_CIRCLE * i);
			lastParticle.speed.y = SHOT_ENEMY_VEC * sin(ANGLE_RANGE_CIRCLE* i);
			App->particles->AddParticle(lastParticle, position.x + 14, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(lastParticle, position.x + 54, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			i++;

			// 10
			lastParticle.speed.x = SHOT_ENEMY_VEC * cos(ANGLE_RANGE_CIRCLE * i);
			lastParticle.speed.y = SHOT_ENEMY_VEC * sin(ANGLE_RANGE_CIRCLE* i);
			App->particles->AddParticle(lastParticle, position.x + 14, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(lastParticle, position.x + 54, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			i++;

			// 11
			lastParticle.speed.x = SHOT_ENEMY_VEC * cos(ANGLE_RANGE_CIRCLE * i);
			lastParticle.speed.y = SHOT_ENEMY_VEC * sin(ANGLE_RANGE_CIRCLE* i);
			App->particles->AddParticle(lastParticle, position.x + 14, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(lastParticle, position.x + 54, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			i++;

			// 12
			lastParticle.speed.x = SHOT_ENEMY_VEC * cos(ANGLE_RANGE_CIRCLE * i);
			lastParticle.speed.y = SHOT_ENEMY_VEC * sin(ANGLE_RANGE_CIRCLE* i);
			App->particles->AddParticle(lastParticle, position.x + 14, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(lastParticle, position.x + 54, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			i++;

			// 13
			lastParticle.speed.x = SHOT_ENEMY_VEC * cos(ANGLE_RANGE_CIRCLE * i);
			lastParticle.speed.y = SHOT_ENEMY_VEC * sin(ANGLE_RANGE_CIRCLE* i);
			App->particles->AddParticle(lastParticle, position.x + 14, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(lastParticle, position.x + 54, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			i++;

			// 14
			lastParticle.speed.x = SHOT_ENEMY_VEC * cos(ANGLE_RANGE_CIRCLE * i);
			lastParticle.speed.y = SHOT_ENEMY_VEC * sin(ANGLE_RANGE_CIRCLE* i);
			App->particles->AddParticle(lastParticle, position.x + 14, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(lastParticle, position.x + 54, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			i++;

			// 15
			lastParticle.speed.x = SHOT_ENEMY_VEC * cos(ANGLE_RANGE_CIRCLE * i);
			lastParticle.speed.y = SHOT_ENEMY_VEC * sin(ANGLE_RANGE_CIRCLE* i);
			App->particles->AddParticle(lastParticle, position.x + 14, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(lastParticle, position.x + 54, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			i++;

			// 16
			lastParticle.speed.x = SHOT_ENEMY_VEC * cos(ANGLE_RANGE_CIRCLE * i);
			lastParticle.speed.y = SHOT_ENEMY_VEC * sin(ANGLE_RANGE_CIRCLE* i);
			App->particles->AddParticle(lastParticle, position.x + 14, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(lastParticle, position.x + 54, position.y + 22, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);

		}
		if (shot_phase_anim_close.Finished())
			animation = &fly;
	}
}
	

uint Enemy_Flying_Machine::getLives() {
	return lives;
}

void Enemy_Flying_Machine::OnCollision(Collider* collider) {

	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT || collider->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT || collider->type == COLLIDER_TYPE::COLLIDER_PLAYER2_BOMB || collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_BOMB) {
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