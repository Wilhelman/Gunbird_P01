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
	turretDownAnimation.PushBack({ 111, 195, 28, 41 });
	turretDownAnimation.loop = true;
	turretDownAnimation.speed = 0.2f;

	// RIGHT 1
	//turretRight_1.PushBack({ 29, 30, 28, 41 });
	turretRight_1.PushBack({ 31, 272, 28, 41 });
	turretRight_1.PushBack({ 70, 272, 28, 41 });
	turretRight_1.PushBack({ 110, 272, 28, 41 });
	turretRight_1.PushBack({ 148, 272, 28, 41 });
	turretRight_1.PushBack({ 186, 272, 28, 41 });
	turretRight_1.PushBack({ 223, 272, 28, 41 });

	turretRight_1.loop = true;
	turretRight_1.speed = 0.2f;

	//RIGHT 2
	turretRight_2.PushBack({ 68, 30, 28, 41 });
	turretRight_2.loop = true;
	turretRight_2.speed = 0.2f;

	//RIGHT 3
	turretRight_3.PushBack({ 108, 29, 29, 42 });
	turretRight_3.loop = true;
	turretRight_3.speed = 0.2f;

	//RIGHT 4
	turretRight_4.PushBack({ 146, 29, 29, 42 });
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

	double deltaX =  (App->player->position.x + 21) - (position.x + 15);
	double deltaY = (App->player->position.y + 21) - (position.y + 15);
	double angle;

	position = original_pos + movement.GetCurrentPosition(&animation);

	if (deltaY != 0)
	{
		angle = atan2(deltaX, deltaY);

		if (angle == 0)
			animation = &turretDownAnimation;
 		else if (angle > 0 && angle <= ANGLE_RANGE)
			animation = &turretRight_1;
		else if (angle > ANGLE_RANGE && angle <= ANGLE_RANGE * 2)
			animation = &turretRight_2;
		else if (angle > ANGLE_RANGE * 2 && angle <= ANGLE_RANGE * 3)
			animation = &turretRight_3;
		else if (angle > ANGLE_RANGE * 3 && angle <= ANGLE_RANGE * 4)
			animation = &turretRight_4;
		else if (angle > ANGLE_RANGE * 4 && angle <= ANGLE_RANGE * 5)
			animation = &turretRight_5;
		else if (angle > ANGLE_RANGE * 5 && angle <= ANGLE_RANGE * 6)
			animation = &turretRight_6;
	}
}

void Enemy_TerrestialTurret::OnCollision(Collider* collider) {

}