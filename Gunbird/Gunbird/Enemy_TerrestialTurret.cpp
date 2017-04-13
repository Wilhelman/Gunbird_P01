#include "Application.h"
#include "Enemy_TerrestialTurret.h"
#include "ModuleCollision.h"
#include "ModuleSceneCastle.h"
#include "ModulePlayer.h"

Enemy_TerrestialTurret::Enemy_TerrestialTurret(int x, int y) : Enemy(x, y)
{
	turretAnimation.PushBack({ 28,29,29,42 });
	turretAnimation.PushBack({ 68,29,29,42 });
	turretAnimation.PushBack({ 108,29,29,42 });
	turretAnimation.PushBack({ 146,29,29,42 });
	turretAnimation.PushBack({ 184,29,29,42 });
	turretAnimation.PushBack({ 221,31,29,42 });
	
	turretAnimation.loop = true;
	turretAnimation.speed = 0.2f;

	turretLeftAnimation.PushBack({ 297,133,30,42 });//left
	turretLeftAnimation.loop = true;
	turretLeftAnimation.speed = 0.2f;

	turretRightAnimation.PushBack({ 108,29,29,42 });//right
	turretRightAnimation.loop = true;
	turretRightAnimation.speed = 0.2f;

	animation = &turretAnimation;

	collider = App->collision->AddCollider({ 0, 0, 30, 42 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	
	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_TerrestialTurret::Move() {
	position = original_pos + movement.GetCurrentPosition(&animation);

	if (App->player->position.x > position.x) {
		animation = &turretRightAnimation;
	}
	else {
		animation = &turretLeftAnimation;
	}
}

void Enemy_TerrestialTurret::OnCollision(Collider* collider) {

}