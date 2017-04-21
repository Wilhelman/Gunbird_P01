#include "Application.h"
#include "SceneCastle_houseFlag2.h"
#include "ModuleCollision.h"
#include "Path.h"

SceneCastle_houseFlag2::SceneCastle_houseFlag2(int x, int y) : Enemy(x, y)
{

	lives = 12;

	houseFlag_2.PushBack({ 45, 659, 96, 99 });
	houseFlag_2.PushBack({ 162, 659, 98, 98 });
	houseFlag_2.PushBack({ 279, 659, 98, 100 });
	houseFlag_2.PushBack({ 45, 769, 96, 98 });
	houseFlag_2.PushBack({ 162, 769, 97, 98 });
	houseFlag_2.PushBack({ 279, 769, 98, 100 });
	houseFlag_2.PushBack({ 45, 870, 96, 98 });
	houseFlag_2.PushBack({ 162, 870, 98, 98 });


	houseFlag_2.speed = 0.08f;
	houseFlag_2.loop = true;

	animation = &houseFlag_2;

	original_pos.x = x;
	original_pos.y = y;

	collider = App->collision->AddCollider({ 0, 0, 98, 99 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
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