#include "Application.h"
#include "Enemy_TerrestialTurret.h"
#include "ModuleCollision.h"
#include "ModuleSceneCastle.h"

Enemy_TerrestialTurret::Enemy_TerrestialTurret(int x, int y) : Enemy(x, y)
{
	turretAnimation.PushBack({ 28,29,29,42 });
	turretAnimation.PushBack({ 68,29,29,42 });
	turretAnimation.PushBack({ 108,29,29,42 });
	turretAnimation.PushBack({ 146,29,29,42 });
	turretAnimation.PushBack({ 184,29,29,42 });
	turretAnimation.PushBack({ 221,31,29,42 });
	turretAnimation.PushBack({ 257,30,30,42 });
	turretAnimation.loop = true;
	turretAnimation.speed = 0.2f;

	animation = &turretAnimation;

	collider = App->collision->AddCollider({ 0, 0, 30, 42 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	
	original_pos.x = x;
	original_pos.y = y;

	turret1_path.PushBack({ 0.7f,1.0f }, 45, &turretAnimation);
	turret1_path.PushBack({ 0.0f,1.0f }, 3000, &turretAnimation);
	turret1_path.loop = false;

	turret2_path.PushBack({ 0.7f, 1.0f }, 80, &turretAnimation);
	turret2_path.PushBack({ 0.0f,1.0f }, 3000, &turretAnimation);
	turret2_path.loop = false;

	turret3_path.PushBack({ 0.7f, 1.0f }, 60, &turretAnimation);
	turret3_path.PushBack({ 0.0f, 0.2f }, 15, &turretAnimation);
	turret3_path.PushBack({ 0.0f,1.0f }, 3000, &turretAnimation);
	turret3_path.loop = false;
}

void Enemy_TerrestialTurret::Move() {

	int castleBackground = App->sceneCastle->background_y;

	//position = original_pos + turret3_path.GetCurrentPosition(&animation);
	
	if((castleBackground > -1855) && (castleBackground < -1600))
	position = original_pos + turret1_path.GetCurrentPosition(&animation);

	/*if ((castleBackground > -1526) && (castleBackground < -1489))
		position = original_pos + turret2_path.GetCurrentPosition(&animation);

	if (castleBackground > -1489)
		position = original_pos + turret3_path.GetCurrentPosition(&animation);*/

}
void Enemy_TerrestialTurret::OnCollision(Collider* collider) {

}