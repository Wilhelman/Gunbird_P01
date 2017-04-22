#include "Application.h"
#include "Enemy_TerrestialTurret.h"
#include "ModuleCollision.h"
#include "ModuleSceneCastle.h"
#include "ModulePlayer.h"
#include "SDL\include\SDL_timer.h"

#define PI 3.14159265 
#define ANGLE_RANGE 0.20943951

#define ANGLE_CONVERT (180.0 / PI)
#define ANGLE_CONVERT_REVERSE (PI / 180.0)

#define ENEMYSHOOTSPEED 3
#define ENEMYSHOOTDELAY 2000

Enemy_TerrestialTurret::Enemy_TerrestialTurret(int x, int y) : Enemy(x, y)
{

	lives = 1;

	// DOWN
	turretDownAnimation.PushBack({ 31, 324, 28, 41 });
	turretDownAnimation.PushBack({ 70, 324, 28, 41 });
	turretDownAnimation.PushBack({ 110, 324, 28, 41 });
	turretDownAnimation.PushBack({ 148, 324, 28, 41 });
	turretDownAnimation.PushBack({ 186, 324, 28, 41 });
	turretDownAnimation.PushBack({ 223, 324, 28, 41 });
	turretDownAnimation.loop = true;
	turretDownAnimation.speed = 0.2f;

	// RIGHT 1
	turretRight_1.PushBack({ 31, 272, 28, 41 });
	turretRight_1.PushBack({ 70, 272, 28, 41 });
	turretRight_1.PushBack({ 110, 272, 28, 41 });
	turretRight_1.PushBack({ 148, 272, 28, 41 });
	turretRight_1.PushBack({ 186, 272, 28, 41 });
	turretRight_1.PushBack({ 223, 272, 28, 41 });
	turretRight_1.loop = true;
	turretRight_1.speed = 0.2f;

	//RIGHT 2
	turretRight_2.PushBack({ 31, 372, 28, 41 });
	turretRight_2.PushBack({ 70, 372, 28, 41 });
	turretRight_2.PushBack({ 110, 372, 28, 41 });
	turretRight_2.PushBack({ 148, 372, 28, 41 });
	turretRight_2.PushBack({ 186, 372, 28, 41 });
	turretRight_2.PushBack({ 223, 372, 28, 41 });
	turretRight_2.loop = true;
	turretRight_2.speed = 0.2f;

	//RIGHT 3
	turretRight_3.PushBack({ 31, 423, 28, 41 });
	turretRight_3.PushBack({ 70, 423, 28, 41 });
	turretRight_3.PushBack({ 110, 423, 28, 41 });
	turretRight_3.PushBack({ 148, 423, 28, 41 });
	turretRight_3.PushBack({ 186, 423, 28, 41 });
	turretRight_3.PushBack({ 223, 423, 28, 41 });
	turretRight_3.loop = true;
	turretRight_3.speed = 0.2f;

	//RIGHT 4
	turretRight_4.PushBack({ 31, 468, 28, 41 });
	turretRight_4.PushBack({ 70, 468, 28, 41 });
	turretRight_4.PushBack({ 110, 468, 28, 41 });
	turretRight_4.PushBack({ 148, 468, 28, 41 });
	turretRight_4.PushBack({ 186, 468, 28, 41 });
	turretRight_4.PushBack({ 223, 468, 28, 41 });
	turretRight_4.loop = true;
	turretRight_4.speed = 0.2f;

	//RIGHT 5
	turretRight_5.PushBack({ 31, 229, 28, 41 });
	turretRight_5.PushBack({ 70, 229, 28, 41 });
	turretRight_5.PushBack({ 110, 229, 28, 41 });
	turretRight_5.PushBack({ 148, 229, 28, 41 });
	turretRight_5.PushBack({ 186, 229, 28, 41 });
	turretRight_5.PushBack({ 223, 229, 28, 41 });
	turretRight_5.loop = true;
	turretRight_5.speed = 0.2f;

	//RIGHT 6
	turretRight_6.PushBack({ 31, 186, 28, 41 });
	turretRight_6.PushBack({ 70, 186, 28, 41 });
	turretRight_6.PushBack({ 110, 186, 28, 41 });
	turretRight_6.PushBack({ 148, 186, 28, 41 });
	turretRight_6.PushBack({ 186, 186, 28, 41 });
	turretRight_6.PushBack({ 223, 186, 28, 41 });
	turretRight_6.loop = true;
	turretRight_6.speed = 0.2f;

	//RIGHT 7
	turretRight_7.PushBack({ 31, 144, 28, 41 });
	turretRight_7.PushBack({ 70, 144, 28, 41 });
	turretRight_7.PushBack({ 110, 144, 28, 41 });
	turretRight_7.PushBack({ 148, 144, 28, 41 });
	turretRight_7.PushBack({ 186, 144, 28, 41 });
	turretRight_7.PushBack({ 223, 144, 28, 41 });
	turretRight_7.loop = true;
	turretRight_7.speed = 0.2f;

	//RIGHT 8
	turretRight_8.PushBack({ 31, 101, 28, 41 });
	turretRight_8.PushBack({ 70, 101, 28, 41 });
	turretRight_8.PushBack({ 110, 101, 28, 41 });
	turretRight_8.PushBack({ 148, 101, 28, 41 });
	turretRight_8.PushBack({ 186, 101, 28, 41 });
	turretRight_8.PushBack({ 223, 101, 28, 41 });
	turretRight_8.loop = true;
	turretRight_8.speed = 0.2f;

	//RIGHT 9
	turretRight_9.PushBack({ 31, 57, 28, 41 });
	turretRight_9.PushBack({ 70, 57, 28, 41 });
	turretRight_9.PushBack({ 110, 57, 28, 41 });
	turretRight_9.PushBack({ 148, 57, 28, 41 });
	turretRight_9.PushBack({ 186, 57, 28, 41 });
	turretRight_9.PushBack({ 223, 57, 28, 41 });
	turretRight_9.loop = true;
	turretRight_9.speed = 0.2f;

	//RIGHT 10
	turretRight_10.PushBack({ 31, 15, 28, 41 });
	turretRight_10.PushBack({ 70, 15, 28, 41 });
	turretRight_10.PushBack({ 110, 15, 28, 41 });
	turretRight_10.PushBack({ 148, 15, 28, 41 });
	turretRight_10.PushBack({ 186, 15, 28, 41 });
	turretRight_10.PushBack({ 223, 15, 28, 41 });
	turretRight_10.loop = true;
	turretRight_10.speed = 0.2f;

	//RIGHT 11
	turretRight_11.PushBack({ 581, 217, 28, 41 });
	turretRight_11.PushBack({ 620, 217, 28, 41 });
	turretRight_11.PushBack({ 660, 217, 28, 41 });
	turretRight_11.PushBack({ 698, 217, 28, 41 });
	turretRight_11.PushBack({ 736, 217, 28, 41 });
	turretRight_11.PushBack({ 773, 217, 28, 41 });

	turretRight_11.loop = true;
	turretRight_11.speed = 0.2f;

	//RIGHT 12
	turretRight_12.PushBack({ 581, 259, 28, 43 });
	turretRight_12.PushBack({ 620, 259, 28, 43 });
	turretRight_12.PushBack({ 660, 259, 28, 43 });
	turretRight_12.PushBack({ 698, 259, 28, 43 });
	turretRight_12.PushBack({ 736, 259, 28, 43 });
	turretRight_12.PushBack({ 773, 259, 28, 43 });
	
	turretRight_12.loop = true;
	turretRight_12.speed = 0.2f;

	//RIGHT 13
	turretRight_13.PushBack({ 580, 305, 28, 43 });
	turretRight_13.PushBack({ 619, 305, 28, 43 });
	turretRight_13.PushBack({ 659, 305, 28, 43 });
	turretRight_13.PushBack({ 697, 305, 28, 43 });
	turretRight_13.PushBack({ 735, 305, 28, 43 });
	turretRight_13.PushBack({ 772, 305, 28, 43 });
	turretRight_13.loop = true;
	turretRight_13.speed = 0.2f;
	
	//RIGHT 14
	turretRight_14.PushBack({ 580, 304, 28, 43 });
	turretRight_14.PushBack({ 619, 304, 28, 43 });
	turretRight_14.PushBack({ 659, 304, 28, 43 });
	turretRight_14.PushBack({ 697, 304, 28, 43 });
	turretRight_14.PushBack({ 735, 304, 28, 43 });
	turretRight_14.PushBack({ 772, 304, 28, 43 });
	turretRight_14.loop = true;
	turretRight_14.speed = 0.2f;

	//RIGHT 15
	turretRight_15.PushBack({ 581, 356, 28, 41 });
	turretRight_15.PushBack({ 620, 356, 28, 41 });
	turretRight_15.PushBack({ 660, 356, 28, 41 });
	turretRight_15.PushBack({ 698, 356, 28, 41 });
	turretRight_15.PushBack({ 736, 356, 28, 41 });
	turretRight_15.PushBack({ 773, 356, 28, 41 });
	turretRight_15.loop = true;
	turretRight_15.speed = 0.2f;

	//RIGHT 16
	turretRight_16.PushBack({ 581, 400, 28, 44 });
	turretRight_16.PushBack({ 620, 400, 28, 44 });
	turretRight_16.PushBack({ 660, 400, 28, 44 });
	turretRight_16.PushBack({ 698, 400, 28, 44 });
	turretRight_16.PushBack({ 736, 400, 28, 44 });
	turretRight_16.PushBack({ 773, 400, 28, 44 });
	turretRight_16.loop = true;
	turretRight_16.speed = 0.2f;

	collider = App->collision->AddCollider({ 0, 0, 30, 42 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	
	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_TerrestialTurret::Move() {

	double deltaX =  ((App->player->position.x + (App->player->playerCollider->rect.w / 2))) - (position.x + 15);
	double deltaY = ((App->player->position.y + (App->player->playerCollider->rect.h / 2))) - (position.y + 21);
	double angle;

	position = original_pos + movement.GetCurrentPosition(&animation);

	if (deltaY != 0)
	{
		angle = atan2(deltaX, deltaY);

		if (angle > - (ANGLE_RANGE) && angle <= (ANGLE_RANGE / 2))
			animation = &turretDownAnimation;
 		else if (angle > (ANGLE_RANGE / 2) && angle <= (3 / 2)*ANGLE_RANGE)
			animation = &turretRight_1;
		else if (angle > (3 / 2)*ANGLE_RANGE && angle <= (5 / 2)*ANGLE_RANGE)
			animation = &turretRight_2;
		else if (angle > (5 / 2)*ANGLE_RANGE && angle <= (7 / 2)*ANGLE_RANGE)
			animation = &turretRight_3;
		else if (angle > (7 / 2)*ANGLE_RANGE && angle <= (9 / 2)*ANGLE_RANGE)
			animation = &turretRight_4;
		else if (angle > (9 / 2)*ANGLE_RANGE && angle <= (11 / 2)*ANGLE_RANGE)
			animation = &turretRight_5;
		else if (angle > (11 / 2)*ANGLE_RANGE && angle <= (13 / 2)*ANGLE_RANGE)
			animation = &turretRight_6;
		else if (angle > (13 / 2)*ANGLE_RANGE && angle <= (15 / 2)*ANGLE_RANGE)
			animation = &turretRight_7;
		else if (angle > (15 / 2)*ANGLE_RANGE && angle <= (17 / 2)*ANGLE_RANGE)
			animation = &turretRight_9;
		else if (angle > (17 / 2)*ANGLE_RANGE && angle <= (19 / 2)*ANGLE_RANGE)
			animation = &turretRight_8;
		else if (angle > (19 / 2)*ANGLE_RANGE && angle <= (21 / 2)*ANGLE_RANGE)
			animation = &turretRight_10;
		else if (angle > (21 / 2)*ANGLE_RANGE && angle <= (23 / 2)*ANGLE_RANGE)
			animation = &turretRight_11;
		else if (angle > (23 / 2)*ANGLE_RANGE && angle <= (25 / 2)*ANGLE_RANGE)
			animation = &turretRight_12;
		else if (angle > (25 / 2)*ANGLE_RANGE && angle <= (27 / 2)*ANGLE_RANGE)
			animation = &turretRight_13;
		else if (angle > (27 / 2)*ANGLE_RANGE && angle <= (29 / 2)*ANGLE_RANGE)
			animation = &turretRight_14;
		else if (angle > (29 / 2)*ANGLE_RANGE && angle <= (31 / 2)*ANGLE_RANGE)
			animation = &turretRight_15;
		else if (angle > (31 / 2)*ANGLE_RANGE && angle <= (33 / 2)*ANGLE_RANGE)
			animation = &turretRight_16;

	}

	lastParticle = App->particles->enemyBasicShot;
}


void Enemy_TerrestialTurret::Shoot()
{
	left = false;
	double deltaX = ((App->player->position.x + (App->player->playerCollider->rect.w / 2))) - (position.x + 15);
	double deltaY = ((App->player->position.y + (App->player->playerCollider->rect.h / 2))) - (position.y + 21);
	float angle;

	angle = atan2(deltaX, deltaY);

	angle *= ANGLE_CONVERT;

	currentTime = SDL_GetTicks();

	if (angle < 0) {
		angle = angle * -1;
		left = true;
	}

	LOG("Angle %.2f", angle);
	if (currentTime >(lastShot + ENEMYSHOOTDELAY)) {

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
		}


		if (currentTime >(lastShot + ENEMYSHOOTDELAY)) {



			App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 9, position.y + 47, COLLIDER_TYPE::COLLIDER_NONE);
			App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 23, position.y + 47, COLLIDER_TYPE::COLLIDER_NONE);

			App->particles->AddParticle(lastParticle, position.x + 10, position.y + 51, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(lastParticle, position.x + 24, position.y + 51, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);



			lastShot = currentTime;
		}

	}

}

uint Enemy_TerrestialTurret::getLives() {
	return lives;
}

void Enemy_TerrestialTurret::OnCollision(Collider* collider) {

	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
			lives--;
	}
}