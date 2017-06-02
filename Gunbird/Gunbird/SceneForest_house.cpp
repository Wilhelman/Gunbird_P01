#include "Application.h"
#include "SceneForest_house.h"
#include "ModuleCollision.h"
#include "Path.h"
#include "SDL\include\SDL_timer.h"


SceneForest_house::SceneForest_house(int x, int y) : Enemy(x, y)
{
	lives = 2;

	Forest_house.PushBack({ 66,1128,129,100 });
	Forest_house.speed = 0.8f;
	Forest_house.loop = true;



	animation = &Forest_house;

	original_pos.x = x;
	original_pos.y = y;

	collider = App->collision->AddCollider({ 0, 22, 64, 80 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
}


void SceneForest_house::Move()
{
	position = original_pos + movement.GetCurrentPosition(&animation);
}

void SceneForest_house::OnCollision(Collider* collider) {

	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT || collider->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {
		App->particles->AddParticle(App->particles->playerShotCollison, (collider->rect.x + (((collider->rect.w)) / 2)), (collider->rect.y - (((collider->rect.h)))));
		lives--;
		
	}

}
uint SceneForest_house::getLives() {
	return lives;
}