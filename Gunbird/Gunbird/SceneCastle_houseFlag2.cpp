#include "Application.h"
#include "SceneCastle_houseFlag2.h"
#include "ModuleCollision.h"
#include "Path.h"

SceneCastle_houseFlag2::SceneCastle_houseFlag2(int x, int y) : Enemy(x, y)
{

	lives = 12;

	houseFlag_2.PushBack({ 433, 2, 95, 100 });
	houseFlag_2.PushBack({ 433, 104, 95, 100 });
	houseFlag_2.PushBack({ 433, 206, 95, 101 });
	houseFlag_2.PushBack({ 433, 309, 95, 101 });
	houseFlag_2.PushBack({ 433, 412, 95, 101 });
	houseFlag_2.PushBack({ 433, 515, 95, 101 });
	houseFlag_2.PushBack({ 433, 619, 95, 103 });
	houseFlag_2.PushBack({ 433, 723, 95, 103 });

	houseFlag_2.speed = 0.08f;
	houseFlag_2.loop = true;

	animation = &houseFlag_2;

	original_pos.x = x;
	original_pos.y = y;

	collider = App->collision->AddCollider({ 0, 0, 95, 101 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
}

void SceneCastle_houseFlag2::Move()
{
	position.y += 1;
}

void SceneCastle_houseFlag2::OnCollision(Collider* collider) {
	lives--;
}
uint SceneCastle_houseFlag2::getLives() {
	return lives;
}