#include "Application.h"
#include "Enemy_TerrestialTurret.h"
#include "ModuleCollision.h"

Enemy_TerrestialTurret::Enemy_TerrestialTurret(int x, int y) : Enemy(x, y)
{
	turret.PushBack({ 28,29,29,42 });
	turret.PushBack({ 68,29,29,42 });
	turret.PushBack({ 108,29,29,42 });
	turret.PushBack({ 146,29,29,42 });
	turret.PushBack({ 184,29,29,42 });
	turret.PushBack({ 221,31,29,42 });
	turret.PushBack({ 257,30,30,42 });
	turret.speed = 0.2f;

	animation = &turret;

	collider = App->collision->AddCollider({ 0, 0, 30, 42 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	
	original_y = y;

}

void Enemy_TerrestialTurret::Move() {

}