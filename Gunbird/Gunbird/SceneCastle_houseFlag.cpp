#include "Application.h"
#include "SceneCastle_houseFlag.h"
#include "ModuleCollision.h"
#include "Path.h"

SceneCastle_houseFlag::SceneCastle_houseFlag(int x, int y) : Enemy(x, y)
{

	lives = 12;

	houseFlag.PushBack({ 433, 2, 95, 100 });
	houseFlag.PushBack({ 433, 104, 95, 100 });
	houseFlag.PushBack({ 433, 206, 95, 101 });
	houseFlag.PushBack({ 433, 309, 95, 101 });
	houseFlag.PushBack({ 433, 412, 95, 101 });
	houseFlag.PushBack({ 433, 515, 95, 101 });
	houseFlag.PushBack({ 433, 619, 95, 103 });
	houseFlag.PushBack({ 433, 723, 95, 103 });

	houseFlag.speed = 0.08f;
	houseFlag.loop = true;

	animation = &houseFlag;

	original_pos.x = x;
	original_pos.y = y;

	collider = App->collision->AddCollider({ 0, 0, 95, 101 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
}

void SceneCastle_houseFlag::Move()
{
	position = original_pos + movement.GetCurrentPosition(&animation);
}

void SceneCastle_houseFlag::OnCollision(Collider* collider) {
	lives--;
}
uint SceneCastle_houseFlag::getLives() {
	return lives;
}