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
	turretRight_4.loop = true;
	turretRight_4.speed = 0.2f;
	turretRight_4.loop = true;
	turretRight_4.speed = 0.2f;

	//RIGHT 5
	turretRight_5.PushBack({ 184, 29, 29, 42 });
	turretRight_5.loop = true;
	turretRight_5.speed = 0.2f;

	//RIGHT 6
	turretRight_6.PushBack({ 221, 31, 29, 42 });
	turretRight_6.loop = true;
	turretRight_6.speed = 0.2f;

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
		/*else if (angle > (9/2)*ANGLE_RANGE && angle <= (11/2)*ANGLE_RANGE)
			animation = &turretRight_5;
		else if (angle > (11/2)*ANGLE_RANGE && angle <= (13/2)*ANGLE_RANGE)
			animation = &turretRight_6;*/
	}
}

void Enemy_TerrestialTurret::OnCollision(Collider* collider) {

}