#include "Application.h"
#include "Enemy_TerrestialTurret.h"
#include "ModuleCollision.h"
#include "ModuleSceneCastle.h"
#include "ModulePlayer.h"
#include "SDL\include\SDL_timer.h"

#define PI 3.14159265 
#define ANGLE_RANGE 12.0f

#define RAD_TO_DEGREES (180.0 / PI)
#define DEGREES_TO_RAD (PI / 180.0)

#define SHOT_ENEMY_VEC 3
#define DELAY_SHOT_ENEMY 2000

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
	turretRight_11.PushBack({ 581, 356, 28, 41 });
	turretRight_11.PushBack({ 620, 356, 28, 41 });
	turretRight_11.PushBack({ 660, 356, 28, 41 });
	turretRight_11.PushBack({ 698, 356, 28, 41 });
	turretRight_11.PushBack({ 736, 356, 28, 41 });
	turretRight_11.PushBack({ 773, 356, 28, 41 });
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
	turretRight_14.PushBack({ 581, 400, 28, 44 });
	turretRight_14.PushBack({ 620, 400, 28, 44 });
	turretRight_14.PushBack({ 660, 400, 28, 44 });
	turretRight_14.PushBack({ 698, 400, 28, 44 });
	turretRight_14.PushBack({ 736, 400, 28, 44 });
	turretRight_14.PushBack({ 773, 400, 28, 44 });
	turretRight_14.loop = true;
	turretRight_14.speed = 0.2f;

	//RIGHT 15 - UP
	turretRight_15.PushBack({ 580, 448, 29, 44 });
	turretRight_15.PushBack({ 620, 448, 29, 44 });
	turretRight_15.PushBack({ 660, 448, 29, 44 });
	turretRight_15.PushBack({ 698, 448, 29, 44 });
	turretRight_15.PushBack({ 736, 448, 29, 44 });
	turretRight_15.PushBack({ 773, 448, 29, 44 });
	turretRight_15.loop = true;
	turretRight_15.speed = 0.2f;

	//RIGHT 16
	turretRight_16.PushBack({ 834, 213, 29, 45 });
	turretRight_16.PushBack({ 873, 213, 29, 45 });
	turretRight_16.PushBack({ 913, 213, 29, 45 });
	turretRight_16.PushBack({ 951, 213, 29, 45 });
	turretRight_16.PushBack({ 989, 213, 29, 45 });
	turretRight_16.PushBack({ 1026, 213, 29, 45 });
	turretRight_16.loop = true;
	turretRight_16.speed = 0.2f;

	//RIGHT 17
	turretRight_17.PushBack({ 834, 259, 29, 43 });
	turretRight_17.PushBack({ 873, 259, 29, 43 });
	turretRight_17.PushBack({ 913, 259, 29, 43 });
	turretRight_17.PushBack({ 951, 259, 29, 43 });
	turretRight_17.PushBack({ 989, 259, 29, 43 });
	turretRight_17.PushBack({ 1026, 259, 29, 43 });
	turretRight_17.loop = true;
	turretRight_17.speed = 0.2f;

	//RIGHT 18
	turretRight_18.PushBack({ 834, 304, 29, 44 });
	turretRight_18.PushBack({ 873, 304, 29, 44 });
	turretRight_18.PushBack({ 913, 304, 29, 44 });
	turretRight_18.PushBack({ 951, 304, 29, 44 });
	turretRight_18.PushBack({ 989, 304, 29, 44 });
	turretRight_18.PushBack({ 1026, 304, 29, 44 });
	turretRight_18.loop = true;
	turretRight_18.speed = 0.2f;

	//RIGHT 19
	turretRight_19.PushBack({ 834, 355, 29, 42 });
	turretRight_19.PushBack({ 873, 355, 29, 42 });
	turretRight_19.PushBack({ 913, 355, 29, 42 });
	turretRight_19.PushBack({ 951, 355, 29, 42 });
	turretRight_19.PushBack({ 989, 355, 29, 42 });
	turretRight_19.PushBack({ 1026, 355, 29, 42 });
	turretRight_19.loop = true;
	turretRight_19.speed = 0.2f;

	//RIGHT 20
	turretRight_20.PushBack({ 834, 402, 29, 42 });
	turretRight_20.PushBack({ 873, 402, 29, 42 });
	turretRight_20.PushBack({ 913, 402, 29, 42 });
	turretRight_20.PushBack({ 951, 402, 29, 42 });
	turretRight_20.PushBack({ 989, 402, 29, 42 });
	turretRight_20.PushBack({ 1026, 402, 29, 42 });
	turretRight_20.loop = true;
	turretRight_20.speed = 0.2f;

	//RIGHT 21
	turretRight_21.PushBack({ 834, 451, 29, 42 });
	turretRight_21.PushBack({ 873, 451, 29, 42 });
	turretRight_21.PushBack({ 913, 451, 29, 42 });
	turretRight_21.PushBack({ 951, 451, 29, 42 });
	turretRight_21.PushBack({ 989, 451, 29, 42 });
	turretRight_21.PushBack({ 1026, 451, 29, 42 });
	turretRight_21.loop = true;
	turretRight_21.speed = 0.2f;

	//RIGHT 22
	turretRight_22.PushBack({ 1086, 216, 29, 42 });
	turretRight_22.PushBack({ 1125, 216, 29, 42 });
	turretRight_22.PushBack({ 1165, 216, 29, 42 });
	turretRight_22.PushBack({ 1203, 216, 29, 42 });
	turretRight_22.PushBack({ 1242, 216, 29, 42 });
	turretRight_22.PushBack({ 1278, 216, 29, 42 });
	turretRight_22.loop = true;
	turretRight_22.speed = 0.2f;

	//RIGHT 23
	turretRight_23.PushBack({ 1086, 260, 29, 42 });
	turretRight_23.PushBack({ 1125, 260, 29, 42 });
	turretRight_23.PushBack({ 1165, 260, 29, 42 });
	turretRight_23.PushBack({ 1203, 260, 29, 42 });
	turretRight_23.PushBack({ 1241, 260, 29, 42 });
	turretRight_23.PushBack({ 1278, 260, 29, 42 });
	turretRight_23.loop = true;
	turretRight_23.speed = 0.2f;

	//RIGHT 24
	turretRight_24.PushBack({ 1088, 306, 29, 42 });
	turretRight_24.PushBack({ 1126, 306, 29, 42 });
	turretRight_24.PushBack({ 1166, 306, 29, 42 });
	turretRight_24.PushBack({ 1204, 306, 29, 42 });
	turretRight_24.PushBack({ 1242, 306, 29, 42 });
	turretRight_24.PushBack({ 1279, 306, 29, 42 });
	turretRight_24.loop = true;
	turretRight_24.speed = 0.2f;

	//RIGHT 25
	turretRight_25.PushBack({ 1087, 355, 29, 42 });
	turretRight_25.PushBack({ 1126, 355, 29, 42 });
	turretRight_25.PushBack({ 1166, 355, 29, 42 });
	turretRight_25.PushBack({ 1204, 355, 29, 42 });
	turretRight_25.PushBack({ 1242, 355, 29, 42 });
	turretRight_25.PushBack({ 1279, 355, 29, 42 });
	turretRight_25.loop = true;
	turretRight_25.speed = 0.2f;

	//RIGHT 26
	turretRight_26.PushBack({ 1087, 402, 29, 42 });
	turretRight_26.PushBack({ 1126, 402, 29, 42 });
	turretRight_26.PushBack({ 1166, 402, 29, 42 });
	turretRight_26.PushBack({ 1204, 402, 29, 42 });
	turretRight_26.PushBack({ 1242, 402, 29, 42 });
	turretRight_26.PushBack({ 1279, 402, 29, 42 });
	turretRight_26.loop = true;
	turretRight_26.speed = 0.2f;

	//RIGHT 27
	turretRight_27.PushBack({ 1087, 451, 29, 42 });
	turretRight_27.PushBack({ 1126, 451, 29, 42 });
	turretRight_27.PushBack({ 1166, 451, 29, 42 });
	turretRight_27.PushBack({ 1204, 451, 29, 42 });
	turretRight_27.PushBack({ 1242, 451, 29, 42 });
	turretRight_27.PushBack({ 1279, 451, 29, 42 });
	turretRight_27.loop = true;
	turretRight_27.speed = 0.2f;

	//RIGHT 28
	turretRight_28.PushBack({ 1344, 216, 29, 42 });
	turretRight_28.PushBack({ 1383, 216, 29, 42 });
	turretRight_28.PushBack({ 1423, 216, 29, 42 });
	turretRight_28.PushBack({ 1461, 216, 29, 42 });
	turretRight_28.PushBack({ 1499, 216, 29, 42 });
	turretRight_28.PushBack({ 1536, 216, 29, 42 });
	turretRight_28.loop = true;
	turretRight_28.speed = 0.2f;

	//RIGHT 28
	turretRight_29.PushBack({ 1344, 261, 29, 42 });
	turretRight_29.PushBack({ 1383, 261, 29, 42 });
	turretRight_29.PushBack({ 1423, 261, 29, 42 });
	turretRight_29.PushBack({ 1461, 261, 29, 42 });
	turretRight_29.PushBack({ 1499, 261, 29, 42 });
	turretRight_29.PushBack({ 1536, 261, 29, 42 });
	turretRight_29.loop = true;
	turretRight_29.speed = 0.2f;

	//DEATH anim
	death.PushBack({ 338,426,32,33 });
	death.loop = true;

	dead = false;

	collider = App->collision->AddCollider({ 0, 0, 30, 42 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	
	original_pos.x = x;
	original_pos.y = y;

	deadTimer = 0;
}

void Enemy_TerrestialTurret::Move() {

	//double deltaX =  ((App->player->position.x + (App->player->playerCollider->rect.w / 2))) - (position.x + 15);
	//double deltaY = ((App->player->position.y + (App->player->playerCollider->rect.h / 2))) - (position.y + 21);

	
	
	if (!dead) {

		position = original_pos + movement.GetCurrentPosition(&animation);

		float deltaX = (App->player->position.x - (position.x + 15));
		float deltaY = (App->player->position.y - (position.y + 21));
		float angle;

		if (deltaY != 0)
		{
			angle = atan2(deltaX, deltaY);
			angle *= RAD_TO_DEGREES;

			if (angle < 0) {
				angle = angle * -1;
				left = true;
			}

			if (!left)
			{
				if (angle >= 0 && angle < ANGLE_RANGE / 2)
					animation = &turretDownAnimation;
				else if(angle >= ANGLE_RANGE / 2 && angle < ANGLE_RANGE * (3 / 2))
					animation = &turretRight_1;
				else if (angle >= ANGLE_RANGE*(3 / 2) && angle < ANGLE_RANGE * (5 / 2))
					animation = &turretRight_2;
				else if (angle >= ANGLE_RANGE*(5 / 2) && angle < ANGLE_RANGE * (7 / 2))
					animation = &turretRight_3;
				else if (angle >= ANGLE_RANGE*(7 / 2) && angle < ANGLE_RANGE * (9 / 2))
					animation = &turretRight_4;
				else if (angle >= ANGLE_RANGE*(9 / 2) && angle < ANGLE_RANGE * (11 / 2))
					animation = &turretRight_5;
				else if (angle >= ANGLE_RANGE*(11 / 2) && angle < ANGLE_RANGE * (13 / 2))
					animation = &turretRight_6;
				else if (angle >= ANGLE_RANGE*(13 / 2) && angle < ANGLE_RANGE * (15 / 2))
					animation = &turretRight_7;
				else if (angle >= ANGLE_RANGE*(15 / 2) && angle < ANGLE_RANGE * (17 / 2))
					animation = &turretRight_8;
				else if (angle >= ANGLE_RANGE*(17 / 2) && angle < ANGLE_RANGE * (19 / 2))
					animation = &turretRight_9;
				else if (angle >= ANGLE_RANGE*(19 / 2) && angle < ANGLE_RANGE * (21 / 2))
					animation = &turretRight_10;
				else if (angle >= ANGLE_RANGE*(21 / 2) && angle < ANGLE_RANGE * (23 / 2))
					animation = &turretRight_11;
				else if (angle >= ANGLE_RANGE*(23 / 2) && angle < ANGLE_RANGE * (25 / 2))
					animation = &turretRight_12;
				else if (angle >= ANGLE_RANGE*(25 / 2) && angle < ANGLE_RANGE * (27 / 2))
					animation = &turretRight_13;
				else if (angle >= ANGLE_RANGE*(27 / 2) && angle < ANGLE_RANGE * (29 / 2))
					animation = &turretRight_14;
				else if (angle >= ANGLE_RANGE*(29 / 2 ) && angle < ANGLE_RANGE * 15)
					animation = &turretRight_15;
			

			}
			else
			{
				left = false;

				if (angle >= 0 && angle < ANGLE_RANGE / 2)
					animation = &turretDownAnimation;
				else if (angle >= ANGLE_RANGE / 2 && angle < ANGLE_RANGE * (3 / 2))
					animation = &turretRight_29;
				else if (angle >= ANGLE_RANGE*(3 / 2) && angle < ANGLE_RANGE * (5 / 2))
					animation = &turretRight_28;
				else if (angle >= ANGLE_RANGE*(5 / 2) && angle < ANGLE_RANGE * (7 / 2))
					animation = &turretRight_27;
				else if (angle >= ANGLE_RANGE*(7 / 2) && angle < ANGLE_RANGE * (9 / 2))
					animation = &turretRight_26;
				else if (angle >= ANGLE_RANGE*(9 / 2) && angle < ANGLE_RANGE * (11 / 2))
					animation = &turretRight_25;
				else if (angle >= ANGLE_RANGE*(11 / 2) && angle < ANGLE_RANGE * (13 / 2))
					animation = &turretRight_24;
				else if (angle >= ANGLE_RANGE*(13 / 2) && angle < ANGLE_RANGE * (15 / 2))
					animation = &turretRight_23;
				else if (angle >= ANGLE_RANGE*(15 / 2) && angle < ANGLE_RANGE * (17 / 2))
					animation = &turretRight_22;
				else if (angle >= ANGLE_RANGE*(17 / 2) && angle < ANGLE_RANGE * (19 / 2))
					animation = &turretRight_21;
				else if (angle >= ANGLE_RANGE*(19 / 2) && angle < ANGLE_RANGE * (21 / 2))
					animation = &turretRight_20;
				else if (angle >= ANGLE_RANGE*(21 / 2) && angle < ANGLE_RANGE * (23 / 2))
					animation = &turretRight_19;
				else if (angle >= ANGLE_RANGE*(23 / 2) && angle < ANGLE_RANGE * (25 / 2))
					animation = &turretRight_18;
				else if (angle >= ANGLE_RANGE*(25 / 2) && angle < ANGLE_RANGE * (27 / 2))
					animation = &turretRight_17;
				else if (angle >= ANGLE_RANGE*(27 / 2) && angle < ANGLE_RANGE * (29 / 2))
					animation = &turretRight_16;
				else if (angle >= ANGLE_RANGE*(29 / 2) && angle < ANGLE_RANGE * 15)
					animation = &turretRight_15;
			}
		}

		lastParticle = App->particles->enemyBasicShot;
	}
	else {
		deadTimer += 0.5f;
		if (deadTimer == 1.0f) {
			position.y += 1;
			deadTimer = 0.0f;
		}
	}
}


void Enemy_TerrestialTurret::Shoot()
{
	if (!dead) {
		left = false;
		double deltaX = ((App->player->position.x + (App->player->playerCollider->rect.w / 2))) - (position.x + 15);
		double deltaY = ((App->player->position.y + (App->player->playerCollider->rect.h / 2))) - (position.y + 21);
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
				App->particles->AddParticle(App->particles->enemyBasicShot_start, position.x + 15, position.y + 21, COLLIDER_TYPE::COLLIDER_NONE);
				App->particles->AddParticle(lastParticle, position.x + 15, position.y + 21, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);

				lastShot = currentTime;
			}

		}
	}
}

uint Enemy_TerrestialTurret::getLives() {
	return lives;
}

void Enemy_TerrestialTurret::OnCollision(Collider* collider) {

	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT|| collider->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {
		App->particles->AddParticle(App->particles->playerShotCollison, (collider->rect.x + (((collider->rect.w)) / 2)), (collider->rect.y + (((collider->rect.h)))));
			lives--;
	}

	if (lives <= 0) {
		if (this->collider != nullptr) {
			App->collision->EraseCollider(this->collider);
			this->collider = nullptr;
		}
		animation = &death;
		dead = true;
	}
}