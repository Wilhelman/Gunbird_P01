#include "Application.h"
#include "SceneCastle_Vase.h"
#include "ModuleCollision.h"
#include "Path.h"


SceneCastle_Vase::SceneCastle_Vase(int x, int y) : Enemy(x, y)
{

	vase.PushBack({ 552,578,33,49 });
	vase.loop = true;


	animation = &vase;

	original_pos.x = x;
	original_pos.y = y;

	collider = App->collision->AddCollider({ 0, 0, 33, 49 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}
void SceneCastle_Vase::Move()
{
	position = original_pos + movement.GetCurrentPosition(&animation);
}
void SceneCastle_Vase::OnCollision(Collider* collider) {

}