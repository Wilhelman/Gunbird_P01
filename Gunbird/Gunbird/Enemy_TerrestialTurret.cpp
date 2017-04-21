#include "Application.h"
#include "Enemy_TerrestialTurret.h"
#include "ModuleCollision.h"
#include "ModuleSceneCastle.h"
#include "ModulePlayer.h"
#define PI 3.14159265 //TODO: remove if not needed
#define ANGLE_RANGE 0.20943951

Enemy_TerrestialTurret::Enemy_TerrestialTurret(int x, int y) : Enemy(x, y)
{
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
 		else if (angle > (ANGLE_RANGE / 2) && angle <= (3/2)*ANGLE_RANGE)
			animation = &turretRight_1;
		else if (angle > (3/2)*ANGLE_RANGE && angle <= (5/2)*ANGLE_RANGE)
			animation = &turretRight_2;
		else if (angle > (5/2)*ANGLE_RANGE && angle <= (7/2)*ANGLE_RANGE)
			animation = &turretRight_3;
		else if (angle > (7/2)*ANGLE_RANGE && angle <= (9/2)*ANGLE_RANGE)
			animation = &turretRight_4;
		else if (angle > (9/2)*ANGLE_RANGE && angle <= (11/2)*ANGLE_RANGE)
			animation = &turretRight_5;
		else if (angle > (11/2)*ANGLE_RANGE && angle <= (13/2)*ANGLE_RANGE)
			animation = &turretRight_6;
		else if (angle > (13 / 2)*ANGLE_RANGE && angle <= (15 / 2)*ANGLE_RANGE)
			animation = &turretRight_7;
		else if (angle > (15 / 2)*ANGLE_RANGE && angle <= (17 / 2)*ANGLE_RANGE)
			animation = &turretRight_9;
		else if (angle > (17 / 2)*ANGLE_RANGE && angle <= (19 / 2)*ANGLE_RANGE)
			animation = &turretRight_8;
		else if (angle > (19 / 2)*ANGLE_RANGE && angle <= (21 / 2)*ANGLE_RANGE)
			animation = &turretRight_10;
	}
}

void Enemy_TerrestialTurret::OnCollision(Collider* collider) {

}