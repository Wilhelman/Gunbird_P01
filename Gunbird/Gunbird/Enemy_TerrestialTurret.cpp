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

	
}

void Enemy_TerrestialTurret::Move() {

	position.y += 1;

	//position = original_pos + turret3_path.GetCurrentPosition(&animation);
	

}
void Enemy_TerrestialTurret::OnCollision(Collider* collider) {

}